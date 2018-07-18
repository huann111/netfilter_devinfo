/*
author:arvik
description:mac list
date:2015/11/5
*/
#include "maclist.h"

MAC_NODE *create_maclist(void)
{
	MAC_NODE *p;
	p = kmalloc(sizeof(MAC_NODE), GFP_ATOMIC);
	if(NULL == p)
		return NULL;
	memset(p, 0, sizeof(MAC_NODE));
	return p;
}

static int IF_maceq(uint8_t *mac1, uint8_t *mac2)
{
	if( (mac1[0]==mac2[0]) && \
		(mac1[1]==mac2[1]) && \
		(mac1[2]==mac2[2]) && \
		(mac1[3]==mac2[3]) && \
		(mac1[4]==mac2[4]) && \
		(mac1[5]==mac2[5]) )
		return ture;
	return false;
}

/*
static int IF_IPeq(uint32_t IP1, uint32_t IP2)
{
	if(IP1 == IP2)
		return true;
	return false;
}
*/
//bool add_maclist_data(MAC_NODE *head, uint8_t *smac, uint8_t *_ip, uint16_t flow)
bool add_maclist_data(MAC_NODE *head, uint8_t *smac, uint32_t _ip, uint16_t flow)
{
	MAC_NODE *p = NULL;
	
	if(head == NULL)
	{
		return false;
	}

	
	if(IF_maceq(head->mac, smac))
	{
		head->value += flow;
		//memcpy(head->ip, _ip, 4);
		head->ip = _ip;
	}
	else
	{
		while(NULL != head->next)
		{
			head = head->next;
			if(IF_maceq(head->mac, smac)) 
			{
				head->value += flow;
				//memcpy(head->ip, _ip, 4);
				head->ip = _ip;
				return true;
			}					
		}
		
		if(NULL == (p = create_maclist() ))
			return false;
			
		memcpy(p->mac, smac, 6);
		p->value = flow;
		//memcpy(head->ip, _ip, 4);
		p->ip = _ip;
			
		head->next = p;	
	}
	
	return true;
}

bool clear_all_listval(MAC_NODE *head)
{
	while(NULL != head)
	{
		//printk("head->value:%d\n", head->value);
		head->value = 0;
		head = head->next;
	}
	//printk("ok\n");
	return true;
}

bool delete_macnode_by_ct(MAC_NODE *head)
{
	MAC_NODE *p = NULL;
	if(head==NULL)
		return false;

	//忽略首节点
	p = head->next;
	while(NULL != p)
	{	
		if(p->count >= 20) //20秒没有上传流量则认为下线,发现有连续17秒都没数据的
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


bool flow_format_and_clear(MAC_NODE *head, uint8_t *buf)
{
	uint16_t pos;
	uint8_t *p = buf;
	
	while(NULL != head)
	{
		//printk("%2x-%2x-%2x-%2x-%2x-%2x %d.%d.%d.%d %d\n" , MACQUAD(head->mac), NIPQUAD(head->ip), head->value);
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
			sprintf(p+pos, "%02x:%02x:%02x:%02x:%02x:%02x %d.%d.%d.%d %d %lld\n" , MACQUAD(head->mac), NIPQUAD(head->ip), head->value, head->tot_flow);
			
		head->value = 0;
		//head->ip = 0;
		head = head->next;
	}
	
//	printk("*****\n%s\n", buf);
	return true;
}



/*模块卸载时调用*/
bool free_maclist(MAC_NODE *head)
{
	MAC_NODE *p = NULL;
		
	while(NULL != head)
	{
		p = head->next;
		
		kfree(head);
		head = p;
	}
	
	return true;
}

