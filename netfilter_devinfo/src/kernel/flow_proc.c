/*
author:arvik
description:pick up some information
date:2015/11/9
*/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/string.h>
#include <linux/slab.h>
#include <linux/types.h> 
#include <linux/proc_fs.h>
#include <asm/uaccess.h> 


//保存proc结构体指针   
static struct proc_dir_entry *proc_entry; 
static struct proc_dir_entry *proc_entryRx; 

static struct proc_dir_entry *flow_root;

//extern struct mutex visit_mutex;
extern struct mutex visit_mutex_rx;
extern struct mutex visit_mutex_tx;


extern uint8_t flow_buf[2000];
extern uint8_t flow_bufRx[2000];

static int flow_read(char *page,char **start,off_t off, int count ,int *eof,void *data)
{
	int len;
	
	mutex_lock(&visit_mutex_tx);
	len = strlen(flow_buf);
	if(off > len)
	{
		mutex_unlock(&visit_mutex_tx);
		*eof = 1;
		return 0;
	}
	
	if(count > len-off)
	{
		count = len - off;
		*eof = 1;
	}
	
	memcpy(page, flow_buf, count);
	mutex_unlock(&visit_mutex_tx);
	
	*start = page + off;
	
	//*eof = 1;
	//return off + count;
	return count;
}

static int flow_readRx(char *page,char **start,off_t off, int count ,int *eof,void *data)
{
	int len;

	//printk("flow_readRx\n");
	mutex_lock(&visit_mutex_rx);
	len = strlen(flow_bufRx);
	if(off > len)
	{
		mutex_unlock(&visit_mutex_rx);
		*eof = 1;
		return 0;
	}
	
	if(count > len-off)
	{
		count = len - off;
		*eof = 1;
	}
	
	memcpy(page, flow_bufRx, count);
	mutex_unlock(&visit_mutex_rx);
	
	*start = page + off;
	
	//*eof = 1;
	//return off + count;
	return count;
}





int init_flowproc_moudle(void)
{
	int ret = 0;
	
	flow_root = proc_mkdir("flow_m", NULL);
	if(flow_root == NULL)
	{
		printk("create dir flow_root fail\n");
		return -1;
	}
	
	//Tx
	proc_entry = create_proc_entry("flowwatchTx", 0444, flow_root); 
	if(proc_entry==NULL) 
	{
		printk("fortune :couldn't create proc entry\n");
		ret = -2;
		
		return ret;
	}  
	proc_entry->read_proc = flow_read;

	//Rx
	proc_entryRx = create_proc_entry("flowwatchRx", 0444, flow_root); 
	if(proc_entryRx==NULL) 
	{
		printk("fortune :couldn't create proc entry\n");
		ret = -3;
		
		return ret;
	}  
	proc_entryRx->read_proc = flow_readRx;
	

	return ret;
}


void exit_flowproc_moudle(void)
{	
	remove_proc_entry("flowwatchTx", flow_root);   //删除文件
	remove_proc_entry("flowwatchRx", flow_root);   
	
    remove_proc_entry("flow_m", NULL); //删除目录
}


