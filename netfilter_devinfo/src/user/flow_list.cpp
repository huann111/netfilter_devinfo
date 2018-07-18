/*
author:arvik
date:2015/12/5
description: 
1. the application statistics user traffic. 
2. the application notice other application that user line up and down 
*/

//#include <vector>
#include <iostream>
#include <list>
//#include <fstream>
#include "flow_list.h"
#include "oui_list.h"

#include "MACstr_to10.h"
extern "C"{
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/file.h>
}

typedef std::list<Flow_Info> F_list;
F_list Flow_table;


int write_info(const char *buf, const char *filename, const char *mode);

/*
name:match_device
description: match device for mac 
*/
int match_device(HASH_TABLE *pMACtable)
{
	char buf[12];
	ElemType val;
	NODE *MACdataNode = NULL;
	
	for(F_list::iterator f_list_iter=Flow_table.begin(); f_list_iter != Flow_table.end(); f_list_iter++)
	{
		memset(buf, 0, sizeof(buf));
		memcpy(buf, (*f_list_iter).mac, 8);
		val = (ElemType)(MAC_str_to10)(buf);
		MACdataNode = find_data_in_hash(pMACtable, val);
		if(MACdataNode == NULL)
			return -1;
		else //find success
		{
			memcpy((*f_list_iter).dev_name, ((Code_to_Str_t *)MACdataNode->data)->remark, strlen(((Code_to_Str_t *)MACdataNode->data)->remark)+1);
			memcpy((*f_list_iter).dev_type, ((Code_to_Str_t *)MACdataNode->data)->type, strlen(((Code_to_Str_t *)MACdataNode->data)->type)+1);
		}	
	}
	
	return 0;
}


/*
name:cat_user_flow
description: 
cat /proc/flow_m/flowwatchTx
cat /proc/flow_m/flowwatchRx
*/
int cat_user_flow(HASH_TABLE *pMACtable)
{
	Flow_Info temflow;
	char up_buf[80];
	char down_buf[80];	
	FILE *up_flow;
	FILE *down_flow;

	char flag=0;
	time_t currenttime;
	
	up_flow = fopen("flowwatchTx", "r");
	down_flow = fopen("flowwatchRx", "r");
	if(up_flow==NULL)
	{
		std::cout<<"open file fail!"<<std::endl;
		return -1;
	}
	
	if(down_flow==NULL)
	{
		std::cout<<"open file fail!"<<std::endl;
		return -1;
	}
	
	//read first line and drop out 
	if(NULL == fgets(up_buf, sizeof(up_buf), up_flow))
	{
		//error or end of file
		std::cout<<"read file failed!"<<std::endl;
		fclose(up_flow);
		fclose(down_flow);
		return -2;
	}
	if(NULL == fgets(down_buf, sizeof(down_buf), down_flow))
	{
		//error or end of file
		std::cout<<"read file failed!"<<std::endl;
		fclose(up_flow);
		fclose(down_flow);
		return -2;
	}
	
	currenttime = time((time_t *)NULL);
	std::cout<<"currenttime:"<<currenttime<<std::endl;
	
	
	for(;;) //Tx
	{
		memset(up_buf, 0, sizeof(up_buf));
		if(NULL == fgets(up_buf, sizeof(up_buf), up_flow)) //error or end of file
			break;
		
		memset(&temflow, 0, sizeof(temflow));
		sscanf(up_buf, "%s %s %s %s", temflow.mac, temflow.ip, temflow.upload, temflow.totalup);
		
		if(strncmp(temflow.ip, "0.0.0.0", strlen("0.0.0.0")) == 0)
			continue;
		//update list
		for(F_list::iterator f_list_iter=Flow_table.begin(); f_list_iter != Flow_table.end(); f_list_iter++)
		{				
			if( 0 == strncmp((*f_list_iter).mac, temflow.mac, strlen(temflow.mac)) ) 
			{
				memcpy((*f_list_iter).ip, temflow.ip, strlen(temflow.ip)+1); //add additional a null character
				memcpy((*f_list_iter).upload, temflow.upload, strlen(temflow.upload)+1);
				
				memcpy((*f_list_iter).totalup, temflow.totalup, strlen(temflow.totalup)+1);
				
				(*f_list_iter).loop=0;
				
				(*f_list_iter).alive = currenttime - (*f_list_iter).s_time;
				
				flag=1;
				break;
			}
		}
		
		if(!flag)  //new online device
		{
			char buf[12];
			NODE *MACdataNode = NULL;
			ElemType val = 0;
			
			memset(buf, 0, sizeof(buf));
			memcpy(buf, temflow.mac, 8);
			//get local time
			temflow.s_time = time((time_t *)NULL);
			temflow.NewOnlineD = 1; //online action
			
			//std::cout<<"*-*-*-*-*-*-*-*"<<std::endl;
			val = (ElemType)(MAC_str_to10)(buf);
			MACdataNode = find_data_in_hash(pMACtable, val);
			if(MACdataNode == NULL)
			{
				std::cout<<"find no data!\n"<<std::endl;
				//unfound!
				memcpy(temflow.dev_name,"unknown", strlen("unknown"));
				memcpy(temflow.dev_type,"unknown", strlen("unknown"));
			}
			else //find success
			{
				memcpy(temflow.dev_name, ((Code_to_Str_t *)MACdataNode->data)->remark, strlen(((Code_to_Str_t *)MACdataNode->data)->remark)+1);
				memcpy(temflow.dev_type, ((Code_to_Str_t *)MACdataNode->data)->type, strlen(((Code_to_Str_t *)MACdataNode->data)->type)+1);
			}
			
			Flow_table.push_back(temflow);
						
		}
		
		flag = 0;
		
	}
	
	if(Flow_table.empty())
	{
		std::cout<<"Flow_table is empty"<<std::endl;
		fclose(up_flow);
		fclose(down_flow);
		char buf[4];
		memset(buf, 0, sizeof(buf));
		write_info(buf, dev_info_file, "w+");
		return -3;
	}
		
	while(1) //combine Tx with Rx
	{
		memset(down_buf, 0, sizeof(down_buf));
		if(NULL == fgets(down_buf, sizeof(down_buf), down_flow)) //error or end of file
			break;
		
		memset(&temflow, 0, sizeof(temflow));
		sscanf(down_buf, "%s %s %s", temflow.ip, temflow.download, temflow.totaldown);
		
		for(F_list::iterator f_list_iter=Flow_table.begin(); f_list_iter != Flow_table.end(); f_list_iter++)//compare ip
		{
			if( 0 == strncmp((*f_list_iter).ip, temflow.ip, strlen(temflow.ip)) ) 
			{
				memcpy((*f_list_iter).download, temflow.download, strlen(temflow.download)+1);
				memcpy((*f_list_iter).totaldown, temflow.totaldown, strlen(temflow.totaldown)+1);
				(*f_list_iter).looprx = 0;
				
				break; //this ip insert ok!
			}	//if not find , ignore it!		
		}
	}
	
	for(F_list::iterator f_list_iter=Flow_table.begin(); f_list_iter != Flow_table.end(); f_list_iter++)
	{
		(*f_list_iter).loop = (*f_list_iter).loop + 1;
		(*f_list_iter).looprx = (*f_list_iter).looprx + 1;
	}	
	
	fclose(up_flow);
	fclose(down_flow);
/*
	for(F_list::iterator f_list_iter=Flow_table.begin(); f_list_iter != Flow_table.end(); f_list_iter++)
	{
		std::cout<<"****************"<<std::endl;
		std::cout<<(*f_list_iter).mac<<" "<<(*f_list_iter).ip<<" "<<(*f_list_iter).totalup<<std::endl;
	}
*/	
	return 0;
	
}



/*
name:
description: notice other some information 
*/
//#define ONLINE_NOTICE_FILE "online_notice"
int write_info(const char *buf, const char *filename, const char *mode)
{

	FILE *pINFO;
	int ret;
	
	pINFO = fopen(filename, mode);
	if(NULL == pINFO)
	{
		printf("open file error! filename:%s\n", filename);
		return -1;
	}
	ret = flock(fileno(pINFO), LOCK_EX); //may block the progress
	if (ret != 0)
	{
		fprintf(stderr, "flock() failed:%s!\n", strerror(errno));
		//printf("flock() failed\n");
		fclose(pINFO);
		return -1;
	}
	
	fwrite(buf, strlen(buf), 1, pINFO);  //flush data!
	
	ret = flock(fileno(pINFO), LOCK_UN);
	if (ret != 0)
	{
		fprintf(stderr, "flock() failed:%s!\n", strerror(errno));
	}
	fclose(pINFO);
	

	return 0;
}


/*
name:
description: notice other some information 
*/

int write_dev_info(pid_t pid)
{
	char buf[256];
	
	memset(buf, 0, sizeof(buf));
	write_info(buf, dev_info_file, "w+");	//clear dev_info_file
	for(F_list::iterator f_list_iter=Flow_table.begin(); f_list_iter != Flow_table.end(); f_list_iter++)
	{
		memset(buf, 0, sizeof(buf));
		sprintf(buf, "%d,%s,%s,%s,%s,%s,%s,%s,%s,%ld,%d\n", Flow_table.size(), 
									(*f_list_iter).mac, 
									(*f_list_iter).ip, 
									(*f_list_iter).upload,
									(*f_list_iter).download,
									(*f_list_iter).totalup,
									(*f_list_iter).totaldown,
									(*f_list_iter).dev_name,
									(*f_list_iter).dev_type,
									(*f_list_iter).alive,
									(*f_list_iter).loop
									);
									
		printf("-------\n%s\n", buf);
		write_info(buf, dev_info_file, "a+");
		if(((*f_list_iter).loop > 5) && ((*f_list_iter).looprx > 5)) //offline check and notice
		{
			memset(buf, 0, sizeof(buf));
			sprintf(buf, "%s,%s,%s\n", (*f_list_iter).mac, (*f_list_iter).dev_type, (*f_list_iter).dev_name);
			printf("*******\n offline notice: %s,%s,%s\n", (*f_list_iter).mac, (*f_list_iter).dev_type, (*f_list_iter).dev_name);
			if(!write_info(buf, offline_notice_file, "a+"))
			{
			//kill(pid, SIGUSR1);
			}
		
			//set the flag for waitting delete;
			(*f_list_iter).wait_erase = 1;
		}
		else if((*f_list_iter).NewOnlineD==1) //online check and notice
		{
			(*f_list_iter).NewOnlineD = 0; //clear flag
			memset(buf, 0, sizeof(buf));
			sprintf(buf, "%s,%s,%s\n", (*f_list_iter).mac, (*f_list_iter).dev_type, (*f_list_iter).dev_name);
			printf("*******\n online notice: %s,%s,%s\n", (*f_list_iter).mac, (*f_list_iter).dev_type, (*f_list_iter).dev_name);
			if(!write_info(buf, online_notice_file, "a+"))
			{
			//kill(pid, SIGUSR2);
			}
		}
	}
	
	//clear_offline_dev
	//Flow_table.erase(f_list_iter);	
deletedev:
	for(F_list::iterator f_list_iter=Flow_table.begin(); f_list_iter != Flow_table.end(); f_list_iter++)
	{
		if((*f_list_iter).wait_erase == 1)
		{
			printf("clear offline dev!\n");
			Flow_table.erase(f_list_iter);
			goto deletedev;
		}
	}
	
	return 0;
}



//int clear_offline_dev()
//{
	
//}


