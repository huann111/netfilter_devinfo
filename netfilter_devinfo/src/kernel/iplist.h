/*
author:arvik
description:mac list
date:2015/12/3
*/

#pragma once


typedef struct _IP_NODE
{ 
	uint32_t value;	
	//uint8_t ip[4];
	uint32_t ip;
	uint64_t tot_flow; 
	uint16_t count;
	struct _IP_NODE *next;
}IP_NODE;


IP_NODE *create_iplist(void);
bool add_iplist_data(IP_NODE *head, uint32_t _ip, uint16_t flow);
bool clear_all_iplistval(IP_NODE *head);
bool ipflow_format_and_clear(IP_NODE *head, uint8_t *buf);
bool free_iplist(IP_NODE *head);

bool delete_ipnode_by_ct(IP_NODE  *head);


