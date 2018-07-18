/*
author:arvik
date:2015/12/5
description: 
1. the application statistics user traffic. 
2. the application notice other application that user line up and down 
*/

#pragma once

extern "C"{
#include "stdio.h"
#include "unistd.h"
#include "string.h"
#include "hashtable.h"
}


#include <ctime>

#define dev_info_file  "dev_info"
#define online_notice_file "online_notice"
#define offline_notice_file  "offline_notice"

typedef struct _flow_info
{
	char mac[20];
	char ip[16];
	char upload[16];  //speed
	char download[16]; //speed
	char totalup[32];
	char totaldown[32];
	char dev_name[24];
	char dev_type[24];
	unsigned int loop; //the count that upload speed continuous is 0
	unsigned int looprx;//the count that download speed continuous is 0
	time_t alive;
	time_t s_time;  //the time that device first local in
	char NewOnlineD; //new online flag
	char wait_erase; //the offline waitting deleted;
}Flow_Info;


int cat_user_flow(HASH_TABLE *pMACtable);

int match_device(HASH_TABLE *pMACtable);
int write_dev_info(pid_t pid);














