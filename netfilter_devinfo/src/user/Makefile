#author:arvik
#date:2015/12/5
#description: 
#1. the application statistics user traffic. 
#2. the application notice other application that user line up and down 
###############################################



#CC=g++
CC=/opt/buildroot-gcc342/bin/mipsel-linux-g++

#头文件搜索路径
#CFLAGS = 

PRO_FILE = user_flow.cpp MACstr_to10.cpp flow_list.cpp hashtable.cpp 

TARGET = usr_flow_manage


$(TARGET):
	$(CC) -o $(TARGET) $(PRO_FILE)


	
clean:  
	rm -rf usr_flow_manage	