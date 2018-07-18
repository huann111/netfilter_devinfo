/*
author:arvik
date:2015/12/5
description: 
1. the application statistics user traffic. 
2. the application notice other application that user line up and down 
*/

#include <iostream>


#include "flow_list.h"

#include "hashtable.h"
#include "MACstr_to10.h"

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

extern "C"
{
#include "oui_list.h"
//extern Code_to_Str_t macToTypeList[];
}

#include "user_flow.h"

#define APPVERSION "1.0.0"
#define APPDATE "20151228"

int main(int argc, char *argv[])
{
	HASH_TABLE *pMACtable;
	NODE *MACdataNode;
	ElemType index = 0;
	int n;
	int err;
	char pidbuf[16];
	pid_t pid;
	FILE *p;
	
	if(argc == 2)
	{
		if(strcmp("-h", argv[1]) == 0)
		{
			std::cout<<"Command:"<<std::endl<<"	-h	print help"<<std::endl<<"	-v	check the app version"<<std::endl;
			return -1;
		}
		else if(strcmp("-v", argv[1]) == 0)
		{
			std::cout<<APPVERSION<<"_"<<APPDATE<<std::endl;
			return -1;
		}
		else
		{
			std::cout<<"unfound command! try command -h!"<<std::endl;
			return -1;
		}
	}
	
	p = fopen("/var/run/blink_cloud.pid", "r");
	if(p == NULL)
	{
		std::cout<<"open /var/run/blink_cloud.pid fail"<<std::endl;
		return -1;
	}
	fread(pidbuf, sizeof(pidbuf), 1, p);
	fclose(p);
	
	pid = atoi(pidbuf);
	if(pid==0)
	{
		std::cout<<"/var/run/blink_cloud.pid error"<<std::endl;
		return -1;
	}
	
	std::cout<<"create hash table!"<<std::endl;
	pMACtable = create_hash_table();
	std::cout<<"putting the data into hash table!"<<std::endl;
	
	for(n=0; macToTypeList[n].id != -1; n++)
	{
		index = (ElemType)(MAC_str_to10)(macToTypeList[n].des);
		insert_data_into_hash(pMACtable, index, (void*)(&macToTypeList[n]));
	}
	std::cout<<"data import ok!"<<std::endl;
	
	for(;;)
	{
		err = system("cat \"/proc/flow_m/flowwatchTx\" > flowwatchTx");
		switch(err)
		{
			case -1:
				std::cout<<"call system err!"<<std::endl;
				return -1;
			case 127:
				std::cout<<"exec shell cat fail!"<<std::endl;
			default:
				break;
		}

		err = system("cat \"/proc/flow_m/flowwatchRx\" > flowwatchRx");
		switch(err)
		{
			case -1:
				std::cout<<"call system err!"<<std::endl;
				return -1;
			case 127:
				std::cout<<"exec shell cat fail!"<<std::endl;
			default:
				break;
		}
		
		cat_user_flow(pMACtable);
		write_dev_info(pid);
		sleep(1);
	}
}





