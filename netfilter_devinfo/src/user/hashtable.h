/*
author:arvik
date:2015/12/5
description: 
1. the application statistics user traffic. 
2. the application notice other application that user line up and down 
*/

#pragma once
//#ifndef _HASHTABLE__H
//#define _HASHTABLE__H

typedef long ElemType;

typedef struct _NODE
{
	ElemType index;
	struct _NODE *next;
	void *data;
}NODE;


typedef enum _status
{
	FALSE = 0,
	TRUE = 1
}STATUS;

#define TABLELEN  131U 
typedef struct _HASH_TABLE
{
	NODE *value[TABLELEN];
}HASH_TABLE;


HASH_TABLE *create_hash_table();
NODE* find_data_in_hash(HASH_TABLE *pHashTbl, ElemType index);
STATUS insert_data_into_hash(HASH_TABLE *pHashTbl, ElemType index, void *information);
STATUS delete_data_from_hash(HASH_TABLE *pHashTbl, ElemType index);
STATUS cal_hash_len(HASH_TABLE *pHashTbl);




//#endif




