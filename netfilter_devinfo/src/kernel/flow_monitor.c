/*
author:arvik
description:pick up some information
date:2015/10/28
*/

#include <linux/module.h>  
#include <linux/kernel.h>  
#include <linux/init.h>  
#include <linux/types.h>  
#include <linux/netdevice.h>  
#include <linux/skbuff.h>  
#include <linux/netfilter_ipv4.h>  
#include <linux/inet.h>  
#include <linux/in.h>  
#include <linux/ip.h>  
#include <linux/tcp.h>
#include <linux/if_ether.h>
#include <linux/string.h>
#include <linux/delay.h>
#include <linux/kthread.h>
#include <linux/mutex.h>
#include <linux/fs.h>
#include <asm/uaccess.h>

#include "maclist.h"
#include "flow_proc.h"
#include "iplist.h"

#define THISMODULE "flow_manage.ko"
#define THISVERSION "1.0.0"
#define THISDATE "20151228"
#define THISAUTHOR "arvik"



MODULE_LICENSE("GPL");


typedef union
{
	uint32_t IP;
	uint8_t ip_buf[4];
}u_IP;
u_IP local_ip;


uint8_t KTHREAD_LOCK_FLAG=0;


static MAC_NODE *Mac_flow_tableTX = NULL;
//static MAC_NODE *Mac_flow_tableRx = NULL;
static IP_NODE *ip_flow_tableRx = NULL;

static struct task_struct *info_kthread = NULL;

struct mutex visit_mutex_rx;
struct mutex visit_mutex_tx;

//并没有进行越界检测，故buf必须足够大
uint8_t flow_buf[3000];
uint8_t flow_bufRx[3000];

int mac_func(void *data)
{		
	uint32_t len = 0;
	uint32_t lenRx = 0;
	
	while(!kthread_should_stop())
	{
		//ssleep(10);		
		msleep(500);
		
		mutex_lock(&visit_mutex_tx);
		len = strlen(flow_buf) + 40; 
		if(len < 1800)    //上传流量
		{
			memset(flow_buf, 0, len);
			//memset(flow_buf, 0, sizeof(flow_buf));
			delete_macnode_by_ct(Mac_flow_tableTX); //clear offline mac
			flow_format_and_clear(Mac_flow_tableTX, flow_buf);
		}
		else
		{	
			free_maclist(Mac_flow_tableTX); //clear all mac,there may be a lot of invalid mac!
			Mac_flow_tableTX = create_maclist(); //a new list			
		}
		mutex_unlock(&visit_mutex_tx);	
		
		msleep(500);
		mutex_lock(&visit_mutex_rx);
		lenRx = strlen(flow_bufRx) + 40;
		if(lenRx < 1800)  //下发流量,只有ip
		{
			memset(flow_bufRx, 0, lenRx);
			//memset(flow_bufRx, 0, sizeof(flow_bufRx));
			delete_ipnode_by_ct(ip_flow_tableRx);
			ipflow_format_and_clear(ip_flow_tableRx, flow_bufRx);
		}
		else
		{
			free_iplist(ip_flow_tableRx);
			ip_flow_tableRx = create_iplist();
		}
		mutex_unlock(&visit_mutex_rx);
		
			
	}
	
	return 1;
}

int k_threadinit(void)
{
	info_kthread = kthread_run(mac_func, NULL, "flow");
	if(NULL == info_kthread)
		return -1;
	return 1;
}

int k_threadstop(void)
{
	kthread_stop(info_kthread);
	info_kthread = NULL;
	return 1;
}



/*
目的:统计每个MAC的上传流量
*/
static unsigned int flow_hook_out(  
		unsigned int hooknum,  
		struct sk_buff * skb,  
		const struct net_device *in,  
		const struct net_device *out,  
		int (*okfn) (struct sk_buff *)) 
{
	struct ethhdr *eth;
	struct iphdr *ip;
	uint32_t ip1, ip2;
	
	if (!skb)  
        return NF_ACCEPT;
		
	if(skb->protocol != htons(0x0800)) 
		return NF_ACCEPT;
	
	eth = eth_hdr(skb);
	if(!eth)
	{
		printk("eth is error!\n");
		return NF_ACCEPT;
	}

	
	ip = ip_hdr(skb);
	if(!ip)
		return NF_ACCEPT;
	
	if(!strnicmp(in->name, "br0", strlen("br0")))//流出流量 ,在pre_routing统计，统计源mac,ip
	{
		ip1 = (ip->saddr)&0x00ffffff;
		ip2 = (local_ip.IP)&0x00ffffff;
		
		if(ip1 != ip2) //subnet
		{
			return NF_ACCEPT;
		}
		
		if(ip->saddr == local_ip.IP) //local
			return NF_ACCEPT;
		
		ip1 = ip1&0xff000000;
		if(ntohl(ip1)==255) //broadcast
			return NF_ACCEPT;
		
		//mutex_lock(&visit_mutex_tx);
		add_maclist_data(Mac_flow_tableTX, eth->h_source, ip->saddr, ntohs(ip->tot_len));
		//mutex_unlock(&visit_mutex_tx);
	}
	
	return NF_ACCEPT; 
}



/*
目的:统计每个MAC的下载流量
*/
static unsigned int flow_hook_in(  
		unsigned int hooknum,  
		struct sk_buff * skb,  
		const struct net_device *in,  
		const struct net_device *out,  
		int (*okfn) (struct sk_buff *)) 
{
	struct iphdr *ip;
	uint32_t ip1, ip2;
	
	
	if (!skb)  
        return NF_ACCEPT;
		
	if(skb->protocol != htons(0x0800)) //查看是否是IP数据包（排除ARP干扰）
		return NF_ACCEPT;
	
	//printk("srcmac:%x-%x-%x-%x-%x-%x\n", MACQUAD(eth->h_source));
	
	ip = ip_hdr(skb);
	if(!ip)
		return NF_ACCEPT;
	
	if(!strnicmp(out->name, "br0", strlen("br0")))//流入流量，在post_routing处统计，统计目的ip
	{	
		ip1 = (ip->daddr)&0x00ffffff;
		ip2 = (local_ip.IP)&0x00ffffff;
		
		if(ip1 != ip2) //subnet
		{
			return NF_ACCEPT;
		}
		
		if(ip->daddr == local_ip.IP) //local
			return NF_ACCEPT;
		
		
		ip1 = ip1&0xff000000;
		if(ntohl(ip1)==255) //broadcast
			return NF_ACCEPT;
		
	//	mutex_lock(&visit_mutex_rx);
		add_iplist_data(ip_flow_tableRx, ip->daddr, ntohs(ip->tot_len));
	//	mutex_unlock(&visit_mutex_rx);
	}
	
	return NF_ACCEPT; 
}


struct nf_hook_ops flow_ops_in = {  //流入流量
	.list =  {NULL,NULL},  
	.hook = flow_hook_in,  
	.pf = PF_INET,   
	//.hooknum = NF_INET_PRE_ROUTING, 
	//.priority = NF_IP_PRI_FIRST+1
	.hooknum = NF_INET_POST_ROUTING,  //必须放在NAT转发后
	.priority = NF_IP_PRI_LAST-1
};

struct nf_hook_ops flow_ops_out = {  //外出流量
	.list =  {NULL,NULL},  
	.hook = flow_hook_out,  
	.pf = PF_INET,   
	.hooknum = NF_INET_PRE_ROUTING, //必须在NAT转发前统计
	.priority = NF_IP_PRI_FIRST+1
	//.hooknum = NF_INET_POST_ROUTING,  
	//.priority = NF_IP_PRI_LAST-1
};
  
void str__(int8_t *p)
{	
	while(*p++)
	{
		if(*p == '.')
			*p = ' ';
	}
}  
  
  
//init read file,鑾峰彇local_ip
int read_conf_ip()
{
	struct file *p;
	mm_segment_t old_fs;
	ssize_t count = 0;
	char buf[24];
	int err;
	int a, b, c , d;
	
	p = filp_open("/var/conf_ip", O_RDONLY, 0);
	if(!p || IS_ERR(p))
	{
		printk("open conf_ip failed!\n");
		return -1;
	}	


	/**
	get_fs(),set_fs()鏄负浜嗘敼鍙樹簡鐢ㄦ埛绌洪棿鐨勯檺鍒讹紝
	鍗虫墿澶т簡鐢ㄦ埛绌洪棿鑼冨洿锛屼粠鑰屽湪鍐呮牳涓娇鐢ㄧ郴缁熻皟鐢ㄨ?屼笉浼氬嚭閿欙紙绯荤粺璋冪敤鐨勫弬鏁拌姹傚繀椤绘潵鑷敤鎴风┖闂达級锛?
	鍚﹀垯浼氭姤鍙傛暟鍦板潃瓒呰繃鐢ㄦ埛绌洪棿鍦板潃鐨勯敊璇??
	*/	
	old_fs = get_fs();
	set_fs(KERNEL_DS);
	count = p->f_op->read(p, buf, sizeof(buf), &p->f_pos);
	if(!count)
	{
		printk("read ip fail!\n");
		printk("please configure ip in /var/conf_ip and reload this module!\n");
		return -1;
	}	

	str__(buf);
	err = sscanf(buf, "%d %d %d %d", &a, &b, &c, &d);
	if(err>0)
	{
		local_ip.ip_buf[0] = a & 0x00ff;
		local_ip.ip_buf[1] = b & 0x00ff;
		local_ip.ip_buf[2] = c & 0x00ff;
		local_ip.ip_buf[3] = d & 0x00ff;
	}
	else
	{
		printk("parse conf_ip file fail\n");
		return -1;
	}
	printk("read config ip:%d.%d.%d.%d\n", a, b, c, d);
	
	set_fs(old_fs);
	
	filp_close(p, NULL);
	return 0;
}  


void p_help(void)
{
	printk("usage:\nyou must write this router ip into /var/conf_ip, thus you can insmod this module!\n");
	printk("eg. read conf_ip like this :\n\
								#cat /var/config_ip\n\
								192.168.16.1\n");
	printk("author:arvik\n");
}

static int __init m_init(void)
{

	local_ip.ip_buf[0] = 10;
	local_ip.ip_buf[1] = 10;
	local_ip.ip_buf[2] = 10;
	local_ip.ip_buf[3] = 254;
	
	if(read_conf_ip())
	{
		printk("error!\n");
		p_help();
		return -1;
	}
	memset(flow_buf, 0, sizeof(flow_buf));
	memset(flow_bufRx, 0, sizeof(flow_bufRx));
	
	mutex_init(&visit_mutex_rx);
	mutex_init(&visit_mutex_tx);
	
	Mac_flow_tableTX = create_maclist();
	ip_flow_tableRx = create_iplist();
	
	nf_register_hook(&flow_ops_in);
	nf_register_hook(&flow_ops_out);
	
	init_flowproc_moudle();
	k_threadinit();
	
	
	
	printk("local_ip:%0x\n", local_ip.IP);
	
	printk(" init ok\n");
	printk("welcome to use %s version=%s date=%s man=%s\n", THISMODULE, THISVERSION, THISDATE, THISAUTHOR);
	return 0;
}

static void __exit m_exit(void)
{
	
	k_threadstop();
	exit_flowproc_moudle();
	
	nf_unregister_hook(&flow_ops_out);
	nf_unregister_hook(&flow_ops_in);
	
	free_maclist(Mac_flow_tableTX);
	free_iplist(ip_flow_tableRx);
}

module_init(m_init);  
module_exit(m_exit); 


