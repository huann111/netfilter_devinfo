/*
author:arvik
description:mac list
date:2015/11/5
*/

#pragma once

#include <linux/string.h>
#include <linux/slab.h>
#include <linux/types.h> 

#ifndef true
#define ture 1
#endif

#ifndef false
#define false 0
#endif

#define MACQUAD(mac) \
	mac[0], \
	mac[1], \
	mac[2], \
	mac[3], \
	mac[4], \
	mac[5] 	

#define NIPQUAD(addr) \
	((unsigned char *)&addr)[0], \
	((unsigned char *)&addr)[1], \
	((unsigned char *)&addr)[2], \
	((unsigned char *)&addr)[3]  


typedef struct _MAC_NODE
{ 
	uint32_t value;	
	//uint8_t ip[4];
	uint32_t ip;
	uint64_t tot_flow; 
	uint8_t mac[6];
	uint16_t count; //if (speed ==0) count++;
	struct _MAC_NODE *next;
}MAC_NODE;


MAC_NODE *create_maclist(void);
//bool add_maclist_data(MAC_NODE *head, uint8_t *smac, uint8_t *_ip, uint16_t flow);
bool add_maclist_data(MAC_NODE *head, uint8_t *smac, uint32_t _ip, uint16_t flow);
bool clear_all_listval(MAC_NODE *head);
bool free_maclist(MAC_NODE *head);
bool flow_format_and_clear(MAC_NODE *head, uint8_t *buf);

bool delete_macnode_by_ct(MAC_NODE *head);


