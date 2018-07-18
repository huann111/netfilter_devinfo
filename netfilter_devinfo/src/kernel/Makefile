#author:arvik
#date:2015/09/09

#CC=gcc
CC=/opt/buildroot-gcc342/bin/mipsel-linux-gcc

MODULE_NAME := flow_manage
#KERNELBUILD:=/usr/src/kernels/$(shell uname -r) 
KERNELBUILD:=/root/study/MTK3/MTK_source/linux-2.6.36.x

default:   
	make -C $(KERNELBUILD) M=$(shell pwd)

obj-m := $(MODULE_NAME).o
$(MODULE_NAME)-objs := flow_monitor.o maclist.o iplist.o flow_proc.o
	
flow_monitor.o:flow_monitor.c 
	$(CC) -o $@ flow_monitor.c 
	
maclist.o:maclist.c
	$(CC) -o $@ flow_monitor.c 
	
iplist.o:iplist.c
	$(CC) -o $@ iplist.c
	
flow_proc.o:flow_proc.c
	$(CC) -o $@ flow_proc.c

	
clean:  
	rm -rf *.o *.ko *.mod.c .*.cmd *.markers *.order *.symvers .tmp_versions 


	
	
	
