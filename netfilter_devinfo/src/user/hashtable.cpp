/*
author:arvik
date:2015/12/5
description: 
1. the application statistics user traffic. 
2. the application notice other application that user line up and down 
*/

#include <iostream>
//#include "oui_list.h"



extern "C"{
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "hashtable.h"
} 

#define CALLENofHASHELEM  //计算表元素拉链长

#ifdef CALLENofHASHELEM
int Hashlenbuf[TABLELEN];
#endif


/*创建hash表*/
HASH_TABLE *create_hash_table()
{
	HASH_TABLE *pHashTbl = (HASH_TABLE*)malloc(sizeof(HASH_TABLE));
	memset(pHashTbl, 0 ,sizeof(HASH_TABLE));
	return pHashTbl;
}

/*在hash表中查找数据*/
NODE* find_data_in_hash(HASH_TABLE *pHashTbl, ElemType index)
{
	NODE *pNode;
	if(NULL == pHashTbl)
		return NULL;

	if(NULL == (pNode = pHashTbl->value[index % TABLELEN]))
		return NULL;

	while(pNode)
	{	
//		printf("*"); //debug
		if(index == pNode->index)
			return pNode;
		pNode = pNode->next;
	}
	return NULL;
}

/*在hash表中插入数据*/
STATUS insert_data_into_hash(HASH_TABLE *pHashTbl, ElemType index, void *information)
{
	NODE *pNode;
	if(NULL == pHashTbl)
		return FALSE;
	
	if(NULL == pHashTbl->value[index % TABLELEN])
	{
		pNode = (NODE *)malloc(sizeof(NODE));
		memset(pNode, 0, sizeof(NODE));
		pNode->index = index;
		pNode->data = information;
		pHashTbl->value[index % TABLELEN] = pNode;
		return TRUE;
	}

	if(NULL != find_data_in_hash(pHashTbl, index))
		return FALSE;

	pNode = pHashTbl->value[index % TABLELEN];
	while(NULL != pNode->next)
		pNode = pNode->next;
	
	pNode->next = (NODE *)malloc(sizeof(NODE));
	memset(pNode->next, 0, sizeof(NODE));
	pNode->next->index = index;
	pNode->next->data = information;
//	pNode->next->next = NULL;
	return TRUE;

}

/*从hash中删除数据*/
STATUS delete_data_from_hash(HASH_TABLE *pHashTbl, ElemType index)
{
	NODE *pHead;
	NODE *pNode;
	if(NULL == pHashTbl || NULL == pHashTbl->value[index % TABLELEN])
		return FALSE;

	if(NULL == (pNode = find_data_in_hash(pHashTbl, index)))
		return FALSE;

	if(pNode == pHashTbl->value[index % TABLELEN])
	{
		pHashTbl->value[index % TABLELEN] = pNode->next;
		goto final;
	}

	pHead = pHashTbl->value[index % TABLELEN];
	while(pNode != pHead->next)
		pHead = pHead->next;
	pHead->next = pNode->next;

final:
	free(pNode);
	return TRUE;
}

/*计算拉链式hash表元素链长*/
//作用：用于统计分析
#ifdef CALLENofHASHELEM
STATUS cal_hash_len(HASH_TABLE *pHashTbl)
{
	int count=0, num=0;
	NODE *pNode;
	if(NULL == pHashTbl)
		return FALSE;

	if(NULL == pHashTbl->value[count])
		Hashlenbuf[count] = num;
	for(count = 0; count < TABLELEN; count++)
	{
		num = 0;
		if(NULL == pHashTbl->value[count])
			Hashlenbuf[count] = num;

		pNode = pHashTbl->value[count];
		while(NULL != pNode->next)
		{
			pNode = pNode->next;
			num++;
		}
		Hashlenbuf[count] = num;
	}
	return TRUE;
}
#endif


