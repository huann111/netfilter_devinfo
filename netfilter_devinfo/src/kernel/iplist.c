/*
author:arvik
description:mac list
date:2015/12/3
*/




/*
author:arvik
description:mac list
date:2015/11/5
*/
#include "maclist.h"
#include "iplist.h"

IP_NODE *create_iplist(void)
{
	IP_NODE *p;
	p = kmalloc(sizeof(IP_NODE), GFP_ATOMIC);
	if(NULL == p)
		return p;
	memset(p, 0, sizeof(IP_NODE));
	return p;
}


static int IF_IPeq(uint32_t IP1, uint32_t IP2)
{
	if(IP1 == IP2)
		return true;
	return false;
}

bool add_iplist_data(IP_NODE *head, uint32_t _ip, uint16_t flow)
{
	IP_NODE *p = NULL;
	
	if(head == NULL)
	{
		return false;
	}
	
	if(IF_IPeq(head->ip, _ip))
	{
		head->value += flow;
	}
	else
	{
		while(NULL != head->next)
		{
			head = head->next;
			if(IF_IPeq(head->ip, _ip)) 
			{
				head->value += flow;
				return true;
			}					
		}
		
		if(NULL == (p = create_iplist() ))
			return false;
			
		p->ip = _ip;
		p->value = flow;		
			
		head->next = p;	
	}
	
	return true;
}

bool clear_all_iplistval(IP_NODE *head)
{
	while(NULL != head)
	{
		//printk("head->value:%d\n", head->value);
		head->value = 0;
		head = head->next;
	}
	return true;
}


bool delete_ipnode_by_ct(IP_NODE  *head)
{
	IP_NODE  *p = NULL;
	if(head==NULL)
		return false;
	
		//忽略首节点
	p = head->next;
	while(NULL != p)
	{		
		if(p->count >= 14) //连续14秒没有下载流量则剔除该ip节点
		{
			head->next = p->next;
			kfree(p);
			p = head->next;
			continue;
		}
		
		head = head->next;
		p = head->next;		
	}
	return true;
}


bool ipflow_format_and_clear(IP_NODE *head, uint8_t *buf)
{
	uint16_t pos;
	uint8_t *p = buf;
	
	while(NULL != head)
	{
		head->tot_flow += head->value;
		if(head->value==0)
		{
			head->count = head->count + 1;
		}
		else
		{
			head->count = 0;
		}
		
		pos = strlen(p);
		if(pos<1920)
			sprintf(p+pos, "%d.%d.%d.%d %d %lld\n", NIPQUAD(head->ip), head->value, head->tot_flow);
				
		head->value = 0;
		head = head->next;
	}

	return true;
}



/*模块卸载时调用*/
bool free_iplist(IP_NODE *head)
{
	IP_NODE *p = NULL;
		
	while(NULL != head)
	{
		p = head->next;
		
		kfree(head);
		head = p;
	}
	
	return true;
}

