/*
author:arvik
date:2015/12/5
description: 
1. the application statistics user traffic. 
2. the application notice other application that user line up and down 
*/

#pragma once



/* Mac to vendor /device type*/

enum TOPO_Dev_Type
{
    DEV_TYPE_UNKNOWN = 0,
    DEV_TYPE_IPHONE,
    DEV_TYPE_IPAD,
    DEV_TYPE_Android,
    DEV_TYPE_MAC,
    DEV_TYPE_PC,

//  DEV_TYPE_MAGICBOX

};

/*
typedef struct index{
char *start;
char *end;
long start_pos;
long length;
}INDEX ;
*/

/*
INDEX index_array[]={
			{"00","0F",00,00},
			{"10","2F",00,00},
			{"30","5F",00,00},
			{"60","9F",00,00},
			{"A0","FF",00,00}};
*/

typedef struct _Code_to_Str_t
{
   int id;
   const char *des;
   const char *remark;
   const char *type;
}Code_to_Str_t;

/*
struct Code_to_Str_t macToTypeList[] =
{
	{ DEV_TYPE_IPHONE, "00:03:93",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:05:02",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:0A:27",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:0A:95",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:0D:93",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:10:FA",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:11:24",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:14:51",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:16:CB",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:17:F2",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:19:E3",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:1B:63",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:1C:B3",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:1D:4F",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:1E:52",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:1E:C2",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:1F:5B",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:1F:F3",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:21:E9",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:22:41",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:23:12",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:23:32",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:23:6C",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:23:DF",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:24:36",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:25:00",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:25:4B",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:25:BC",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:26:08",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:26:4A",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:26:B0",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:26:BB",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:30:65",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:3E:E1",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:50:E4",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:61:71",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:88:65",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:A0:40",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:C6:10",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:F4:B9",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "00:F7:6F",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "04:0C:CE",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "04:15:52",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "04:1E:64",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "04:26:65",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "04:48:9A",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "04:54:53",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "04:DB:56",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "04:E5:36",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "04:F1:3E",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "04:F7:E4",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "08:00:07",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "08:70:45",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "0C:30:21",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "0C:3E:9F",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "0C:4D:E9",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "0C:74:C2",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "0C:77:1A",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_Android, "00:9E:C8", "xiaomi","Android"}, //Xiaomi inc.
	{ DEV_TYPE_Android, "0C:1D:AF", "xiaomi","Android"}, //Xiaomi inc.
	{DEV_TYPE_Android, "00:18:82", "HuaWei","Android"},
	{DEV_TYPE_Android, "00:1E:10", "HuaWei","Android"},	
	{DEV_TYPE_Android, "00:25:68", "HuaWei","Android"},
	{DEV_TYPE_Android, "00:25:9E", "HuaWei","Android"},
	{DEV_TYPE_Android, "00:46:4B", "HuaWei","Android"},
	{DEV_TYPE_Android, "00:66:4B", "HuaWei","Android"},
	{DEV_TYPE_Android, "00:E0:FC", "HuaWei","Android"},
	{DEV_TYPE_Android, "04:BD:70", "HuaWei","Android"},
	{DEV_TYPE_Android, "04:C0:6F", "HuaWei","Android"},
	{DEV_TYPE_Android, "04:F9:38", "HuaWei","Android"},
	{DEV_TYPE_Android, "08:19:A6", "HuaWei","Android"},
	{DEV_TYPE_Android, "08:63:61", "HuaWei","Android"},
	{DEV_TYPE_Android, "08:7A:4C", "HuaWei","Android"},
	{DEV_TYPE_Android, "08:E8:4F", "HuaWei","Android"},
	{DEV_TYPE_Android, "0C:37:DC", "HuaWei","Android"},
	{DEV_TYPE_Android, "0C:96:BF", "HuaWei","Android"},
	{DEV_TYPE_Android, "00:00:E2", "acer", "PC"},
	{DEV_TYPE_Android, "00:01:24", "acer", "PC"},
	{DEV_TYPE_Android, "00:60:67", "acer", "PC"},
	{DEV_TYPE_Android, "00:A0:60", "acer", "PC"},
	{ DEV_TYPE_Android, "00:00:F0", "Samsung","Android"}, //SamsungE # SAMSUNG ELECTRONICS CO., LTD.
	{ DEV_TYPE_Android, "00:02:78", "Samsung","Android"}, //SamsungE # Samsung Electro-Mechanics 
	{ DEV_TYPE_Android, "00:07:AB", "Samsung","Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "00:09:18", "Samsung","Android"}, //SamsungT # SAMSUNG TECHWIN CO.,LTD
	{ DEV_TYPE_Android, "00:0D:AE", "Samsung","Android"}, //SamsungH # SAMSUNG HEAVY INDUSTRIES 
	{ DEV_TYPE_Android, "00:0D:E5", "Samsung","Android"}, //SamsungT # Samsung Thales
	{ DEV_TYPE_Android, "00:12:47", "Samsung","Android"}, //SamsungE # Samsung Electronics Co., Ltd.
	{ DEV_TYPE_Android, "00:12:FB", "Samsung","Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "00:13:77", "Samsung","Android"}, //SamsungE # Samsung Electronics CO., LTD
	{ DEV_TYPE_Android, "00:15:99", "Samsung","Android"}, //SamsungE # Samsung Electronics Co., LTD
	{ DEV_TYPE_Android, "00:15:B9", "Samsung","Android"}, //SamsungE # Samsung Electronics Co., Ltd.
	{ DEV_TYPE_Android, "00:16:32", "Samsung","Android"}, //SamsungE # SAMSUNG ELECTRONICS CO., LTD.
	{ DEV_TYPE_Android, "00:16:6B", "Samsung","Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "00:16:6C", "Samsung","Android"}, //SamsungE # Samsung Electonics Digital 
	{ DEV_TYPE_Android, "00:16:DB", "Samsung","Android"}, //SamsungE # Samsung Electronics Co., Ltd.
	{ DEV_TYPE_Android, "00:17:C9", "Samsung","Android"}, //SamsungE # Samsung Electronics Co., Ltd.
	{ DEV_TYPE_Android, "00:17:D5", "Samsung","Android"}, //SamsungE # Samsung Electronics Co., Ltd.
	{ DEV_TYPE_Android, "00:18:AF", "Samsung","Android"}, //SamsungE # Samsung Electronics Co., Ltd.
	{ DEV_TYPE_Android, "00:1A:8A", "Samsung","Android"}, //SamsungE # Samsung Electronics Co., Ltd.
	{ DEV_TYPE_Android, "00:1B:98", "Samsung","Android"}, //SamsungE # Samsung Electronics Co., Ltd.
	{ DEV_TYPE_Android, "00:1C:43", "Samsung","Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "00:1D:25", "Samsung","Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "00:1D:F6", "Samsung","Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "00:1E:7D", "Samsung","Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "00:1E:E1", "Samsung","Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "00:1E:E2", "Samsung","Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "00:1F:CC", "Samsung","Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "00:1F:CD", "Samsung","Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "00:21:19", "Samsung","Android"}, //SamsungE # Samsung Electro-Mechanics
	{ DEV_TYPE_Android, "00:21:4C", "Samsung","Android"}, //SamsungE # SAMSUNG ELECTRONICS CO., LTD.
	{ DEV_TYPE_Android, "00:21:D1", "Samsung","Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "00:21:D2", "Samsung","Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "00:23:39", "Samsung","Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "00:23:3A", "Samsung","Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "00:23:99", "Samsung","Android"}, //VdDivisi # VD Division, Samsung 
	{ DEV_TYPE_Android, "00:23:C2", "Samsung","Android"}, //SamsungE # SAMSUNG Electronics. Co. LTD
	{ DEV_TYPE_Android, "00:23:D6", "Samsung","Android"}, //SamsungE # Samsung Electronics Co.,LTD
	{ DEV_TYPE_Android, "00:23:D7", "Samsung","Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "00:24:54", "Samsung","Android"}, //SamsungE # Samsung Electronics Co., LTD
	{ DEV_TYPE_Android, "00:24:90", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,LTD
	{ DEV_TYPE_Android, "00:24:91", "Samsung", "Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "00:24:E9", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co., 
	{ DEV_TYPE_Android, "00:25:38", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co., 
	{ DEV_TYPE_Android, "00:25:66", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "00:25:67", "Samsung", "Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "00:26:37", "Samsung", "Android"}, //SamsungE # Samsung Electro-Mechanics
	{ DEV_TYPE_Android, "00:26:5D", "Samsung", "Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "00:26:5F", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "00:50:C2", "Samsung", "Android"}, //SamsungH # SAMSUNG HEAVY INDUSTRIES 
	{ DEV_TYPE_Android, "00:50:C2", "Samsung", "Android"}, //SamsungL # SAMSUNG LED Co.,Ltd.
	{ DEV_TYPE_Android, "00:E0:64", "Samsung", "Android"}, //SamsungE # SAMSUNG ELECTRONICS
	{ DEV_TYPE_Android, "04:18:0F", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "04:FE:31", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "08:08:C2", "Samsung", "Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "08:37:3D", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "08:D4:2B", "Samsung", "Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "08:FC:88", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "0C:14:20", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "0C:71:5D", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "0C:DF:A4", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	
	{ DEV_TYPE_Android, "00:02:61", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "00:05:C9", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "00:06:D0", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "00:0B:29", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "00:0C:6C", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "00:10:3F", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "00:12:56", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "00:13:A0", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "00:14:80", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "00:18:E3", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "00:19:A1", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "00:1C:62", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "00:1D:D7", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "00:1E:75", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "00:1E:B2", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "00:1F:6B", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "00:1F:E3", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "00:20:21", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "00:21:FB", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "00:22:A9", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "00:22:EE", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "00:23:90", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "00:23:DD", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "00:23:EC", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "00:24:83", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "00:25:E5", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "00:25:E6", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "00:26:E2", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "00:30:5A", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "00:40:BC", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "00:50:CE", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "00:90:02", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "00:AA:70", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "00:E0:91", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "08:00:41", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "08:00:7E", "LG", "Android"}, //lg
	{ DEV_TYPE_Android, "0C:F0:19", "LG", "Android"}, //lg
	
	{ DEV_TYPE_Android, "00:06:1B", "Lenovo", "PC"}, //NotebookNotebook
	{ DEV_TYPE_Android, "00:12:FE", "Lenovo", "PC"}, //LenovoMo
	{ DEV_TYPE_Android, "00:59:07", "Lenovo", "PC"}, //Lenovoe
	{DEV_TYPE_Android, "00:06:5B", "Dell", "PC"}, //DellCompDell
	{DEV_TYPE_Android, "00:08:74", "Dell", "PC"}, //DellCompDell
	{DEV_TYPE_Android, "00:0B:DB", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "00:0D:56", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "00:0F:1F", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "00:11:43", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "00:12:3F", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "00:13:72", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "00:14:22", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "00:15:C5", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "00:16:F0", "Dell", "PC"}, //Dell
	{DEV_TYPE_Android, "00:18:8B", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "00:19:B9", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "00:1A:A0", "Dell", "PC"}, //DellDell	
	{DEV_TYPE_Android, "00:1C:23", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "00:1D:09", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "00:1E:4F", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "00:1E:C9", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "00:21:70", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "00:21:9B", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "00:22:19", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "00:23:AE", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "00:24:E8", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "00:25:64", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "00:26:B9", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "00:B0:D0", "Dell", "PC"}, //DellCompDell
	{DEV_TYPE_Android, "00:C0:4F", "Dell", "PC"}, //DellCompDELL
	{DEV_TYPE_Android, "00:02:55", "IBM", "PC"}, //IbmIBM
	{DEV_TYPE_Android, "00:04:AC", "IBM", "PC"}, //IbmIBM
	{DEV_TYPE_Android, "00:06:29", "IBM", "PC"}, //IbmIBM
	{DEV_TYPE_Android, "00:09:6B", "IBM", "PC"}, //IbmIBM
	{DEV_TYPE_Android, "00:0D:60", "IBM", "PC"}, //IbmIBM
	{DEV_TYPE_Android, "00:10:D9", "IBM", "PC"}, //IbmJapanIBM
	{DEV_TYPE_Android, "00:11:25", "IBM", "PC"}, //IbmIBM
	{DEV_TYPE_Android, "00:14:5E", "IBM", "PC"}, //IbmIBM
	{DEV_TYPE_Android, "00:17:EF", "IBM", "PC"}, //IbmIBM
	{DEV_TYPE_Android, "00:18:B1", "IBM", "PC"}, //IbmIBM
	{DEV_TYPE_Android, "00:1A:64", "IBM", "PC"}, //IbmIBM
	{DEV_TYPE_Android, "00:20:35", "IBM", "PC"}, //IbmIBM
	{DEV_TYPE_Android, "00:21:5E", "IBM", "PC"}, //IbmIBM
	{DEV_TYPE_Android, "00:22:00", "IBM", "PC"}, //IbmIBM
	{DEV_TYPE_Android, "00:25:03", "IBM", "PC"}, //IbmIBM
	{DEV_TYPE_Android, "00:50:76", "IBM", "PC"}, //IbmIBM
	{DEV_TYPE_Android, "00:60:94", "IBM", "PC"}, //IbmIBM
	{DEV_TYPE_Android, "08:00:5A", "IBM", "PC"}, //IbmIBM
	{DEV_TYPE_Android, "08:17:F4", "IBM", "PC"}, //IbmIBM
	{DEV_TYPE_Android, "00:00:95", "SONY", "Android"}, //SonyTektSONY
	{DEV_TYPE_Android, "00:01:4A", "SONY", "Android"}, //SonySony
	{DEV_TYPE_Android, "00:04:1F", "SONY", "Android"}, //SonyCompSony
	{DEV_TYPE_Android, "00:0A:D9", "SONY", "Android"}, //SonyEricSony
	{DEV_TYPE_Android, "00:0E:07", "SONY", "Android"}, //SonyEricSony
	{DEV_TYPE_Android, "00:0F:DE", "SONY", "Android"}, //SonyEricSony
	{DEV_TYPE_Android, "00:12:EE", "SONY", "Android"}, //SonyEricSony
	{DEV_TYPE_Android, "00:13:15", "SONY", "Android"}, //SonyCompSONY
	{DEV_TYPE_Android, "00:13:A9", "SONY", "Android"}, //SonySony
	{DEV_TYPE_Android, "00:15:C1", "SONY", "Android"}, //SonyCompSONY
	{DEV_TYPE_Android, "00:16:20", "SONY", "Android"}, //SonyEricSony
	{DEV_TYPE_Android, "00:16:B8", "SONY", "Android"}, //SonyEricSony
	{DEV_TYPE_Android, "00:18:13", "SONY", "Android"}, //SonyEricSony
	{DEV_TYPE_Android, "00:19:63", "SONY", "Android"}, //SonyEricSony
	{DEV_TYPE_Android, "00:19:C5", "SONY", "Android"}, //SonyCompSONY
	{DEV_TYPE_Android, "00:1A:75", "SONY", "Android"}, //SonyEricSony
	{DEV_TYPE_Android, "00:1A:80", "SONY", "Android"}, //SonySony
	{DEV_TYPE_Android, "00:1B:59", "SONY", "Android"}, //SonyEricSony
	{DEV_TYPE_Android, "00:1C:A4", "SONY", "Android"}, //SonyEricSony
	{DEV_TYPE_Android, "00:1D:0D", "SONY", "Android"}, //SonyCompSony
	{DEV_TYPE_Android, "00:1D:28", "SONY", "Android"}, //SonyEricSony
	{DEV_TYPE_Android, "00:1D:BA", "SONY", "Android"}, //SonySony
	{DEV_TYPE_Android, "00:1E:45", "SONY", "Android"}, //SonyEricSony
	{DEV_TYPE_Android, "00:1E:DC", "SONY", "Android"}, //SonyEricSony
	{DEV_TYPE_Android, "00:1F:A7", "SONY", "Android"}, //SonyCompSony
	{DEV_TYPE_Android, "00:1F:E4", "SONY", "Android"}, //SonyEricSony
	{DEV_TYPE_Android, "00:21:9E", "SONY", "Android"}, //SonyEricSony
	{DEV_TYPE_Android, "00:22:98", "SONY", "Android"}, //SonyEricSony
	{DEV_TYPE_Android, "00:22:A6", "SONY", "Android"}, //SonyCompSony
	{DEV_TYPE_Android, "00:23:45", "SONY", "Android"}, //SonyEricSony
	{DEV_TYPE_Android, "00:23:F1", "SONY", "Android"}, //SonyEricSony
	{DEV_TYPE_Android, "00:24:8D", "SONY", "Android"}, //SonyCompSony
	{DEV_TYPE_Android, "00:24:BE", "SONY", "Android"}, //SonySony
	{DEV_TYPE_Android, "00:24:EF", "SONY", "Android"}, //SonyEricSony
	{DEV_TYPE_Android, "00:25:E7", "SONY", "Android"}, //SonyEricSony
	{DEV_TYPE_Android, "00:D9:D1", "SONY", "Android"}, //SonyCompSony
	{DEV_TYPE_Android, "00:EB:2D", "SONY", "Android"}, //SonyMobiSony
	{DEV_TYPE_Android, "08:00:46", "SONY", "Android"}, //SonySony
	{DEV_TYPE_Android, "00:02:D1", "Vivo", "Android"}, //Vivo
	{DEV_TYPE_Android, "00:0A:0E", "Vivo", "Android"}, //Vivo
	{DEV_TYPE_Android, "00:19:81", "Vivo", "Android"}, //Vivo
	{DEV_TYPE_Android, "00:00:DD", "TCL", "PC"}, //tcl
	{DEV_TYPE_Android, "00:0E:1F", "TCL", "PC"}, //
	{DEV_TYPE_Android, "00:1C:50", "TCL", "PC"}, //
	{DEV_TYPE_Android, "00:1D:FB", "TCL", "PC"}, //
	{DEV_TYPE_Android, "00:01:6B", "HTC", "Android"},//HTC
	{DEV_TYPE_Android, "00:07:14", "HTC", "Android"},
	{DEV_TYPE_Android, "00:09:2D", "HTC", "Android"},
	{DEV_TYPE_Android, "00:23:76", "HTC", "Android"},
	{DEV_TYPE_Android, "00:25:24", "HTC", "Android"},
	{DEV_TYPE_Android, "00:EE:BD", "HTC", "Android"},
	{DEV_TYPE_Android, "00:04:0F", "ASUS", "PC"},
	{DEV_TYPE_Android, "00:0C:6E", "ASUS", "PC"},
	{DEV_TYPE_Android, "00:0E:A6", "ASUS", "PC"},
	{DEV_TYPE_Android, "00:11:2F", "ASUS", "PC"},
	{DEV_TYPE_Android, "00:11:D8", "ASUS", "PC"},
	{DEV_TYPE_Android, "00:13:D4", "ASUS", "PC"},
	{DEV_TYPE_Android, "00:15:F2", "ASUS", "PC"},
	{DEV_TYPE_Android, "00:17:31", "ASUS", "PC"},
	{DEV_TYPE_Android, "00:18:F3", "ASUS", "PC"},
	{DEV_TYPE_Android, "00:1A:83", "ASUS", "PC"},
	{DEV_TYPE_Android, "00:1A:92", "ASUS", "PC"},
	{DEV_TYPE_Android, "00:1B:FC", "ASUS", "PC"},
	{DEV_TYPE_Android, "00:1D:60", "ASUS", "PC"},
	{DEV_TYPE_Android, "00:1E:8C", "ASUS", "PC"},
	{DEV_TYPE_Android, "00:1F:C6", "ASUS", "PC"},
	{DEV_TYPE_Android, "00:22:15", "ASUS", "PC"},
	{DEV_TYPE_Android, "00:23:54", "ASUS", "PC"},
	{DEV_TYPE_Android, "00:24:8C", "ASUS", "PC"},
	{DEV_TYPE_Android, "00:26:18", "ASUS", "PC"},
	{DEV_TYPE_Android, "00:E0:18", "ASUS", "PC"},
	{DEV_TYPE_Android, "08:60:6E", "ASUS", "PC"},
	{DEV_TYPE_Android, "00:0A:28", "Motorola", "Android"},
	{DEV_TYPE_Android, "00:0E:C7", "Motorola", "Android"},
	{DEV_TYPE_Android, "00:15:70", "Motorola", "Android"},
	{DEV_TYPE_Android, "00:20:75", "Motorola", "Android"},
	{DEV_TYPE_Android, "00:23:68", "Motorola", "Android"},
	{DEV_TYPE_Android, "00:24:37", "Motorola", "Android"},
	{DEV_TYPE_Android, "00:24:92", "Motorola", "Android"},
	{DEV_TYPE_Android, "00:A0:BF", "Motorola", "Android"},
	{DEV_TYPE_Android, "00:E0:0C", "Motorola", "Android"},
	{DEV_TYPE_Android, "00:09:47", "ZTE", "Android"},
	{DEV_TYPE_Android, "00:13:52", "ZTE", "Android"},
	{DEV_TYPE_Android, "00:15:EB", "ZTE", "Android"},
	{DEV_TYPE_Android, "00:19:C6", "ZTE", "Android"},
	{DEV_TYPE_Android, "00:1E:73", "ZTE", "Android"},
	{DEV_TYPE_Android, "00:22:93", "ZTE", "Android"},
	{DEV_TYPE_Android, "00:25:12", "ZTE", "Android"},
	{DEV_TYPE_Android, "00:26:ED", "ZTE", "Android"},
	{DEV_TYPE_Android, "08:18:1A", "ZTE", "Android"},
	{DEV_TYPE_Android, "0C:12:62", "ZTE", "Android"},
	{ DEV_TYPE_IPHONE, "10:00:E0",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "10:1C:0C",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "10:40:F3",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "10:93:E9",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "10:9A:DD",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "10:DD:B1",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "14:10:9F",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "14:5A:05",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "14:8F:C6",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "14:99:E2",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "18:20:32",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "18:34:51",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "18:9E:FC",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "18:AF:61",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "18:AF:8F",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "18:E7:F4",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "1C:1A:C0",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "1C:AB:A7",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "1C:E6:2B",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_Android, "14:F6:5A", "xiaomi", "Android"}, //Xiaomi inc.
	{DEV_TYPE_Android, "10:1B:54", "HuaWei", "Android"},
	{DEV_TYPE_Android, "10:47:80", "HuaWei", "Android"},
	{DEV_TYPE_Android, "10:51:72", "HuaWei", "Android"},
	{DEV_TYPE_Android, "10:C6:1F", "HuaWei", "Android"},
	{DEV_TYPE_Android, "14:B9:68", "HuaWei", "Android"},
	{DEV_TYPE_Android, "18:C5:8A", "HuaWei", "Android"},
	{DEV_TYPE_Android, "1C:1D:67", "HuaWei", "Android"},
	{DEV_TYPE_Android, "1C:8E:5C", "HuaWei", "Android"},
	{ DEV_TYPE_Android, "10:1D:C0", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "14:89:FD", "Samsung", "Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "14:F4:2A", "Samsung", "Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "18:3F:47", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "18:46:17", "Samsung", "Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "18:67:B0", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,LTD
	{ DEV_TYPE_Android, "18:E2:C2", "Samsung", "Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "1C:5A:3E", "Samsung", "Android"}, //SamsungE # Samsung Eletronics Co., Ltd 
	{ DEV_TYPE_Android, "1C:62:B8", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "1C:66:AA", "Samsung", "Android"}, //SamsungE # Samsung Electronics
		
	{ DEV_TYPE_Android, "10:68:3F", "LG", "Android"}, //LG
	{ DEV_TYPE_Android, "10:F9:6F", "LG", "Android"}, //LG
	{ DEV_TYPE_Android, "1C:08:C1", "LG", "Android"}, //LG
	
		
	{DEV_TYPE_Android, "14:FE:B5", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "18:03:73", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "18:A9:9B", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "18:FB:7B", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "10:00:5A", "IBM", "PC"}, //IbmIBM
	{DEV_TYPE_Android, "18:00:2D", "SONY", "Android"}, //SonyMobiSony
	{DEV_TYPE_Android, "1C:7B:21", "SONY", "Android"}, //SonyMobiSony
	{DEV_TYPE_Android, "10:12:12", "Vivo", "Android"}, //Vivo
	{DEV_TYPE_Android, "10:F6:81", "Vivo", "Android"}, //Vivo
	{DEV_TYPE_Android, "18:87:96", "HTC", "Android"},
	{DEV_TYPE_Android, "1C:B0:94", "HTC", "Android"},
	{DEV_TYPE_Android, "10:BF:48", "ASUS", "PC"},
	{DEV_TYPE_Android, "10:C3:7B", "ASUS", "PC"},
	{DEV_TYPE_Android, "14:DA:E9", "ASUS", "PC"},
	{DEV_TYPE_Android, "14:1A:A3", "Motorola", "Android"},
	{DEV_TYPE_Android, "14:30:C6", "Motorola", "Android"},
	{DEV_TYPE_Android, "14:60:80", "ZTE", "Android"},
	{ DEV_TYPE_Android, "14:36:C6", "Lenovo", "PC"}, //LenovoMoL
	{ DEV_TYPE_Android, "14:9F:E8", "Lenovo", "PC"}, //LenovoMo
	{ DEV_TYPE_IPHONE, "20:7D:74",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "20:C9:D0",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "24:A2:E1",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "24:AB:81",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "24:E3:14",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "28:0B:5C",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "28:37:37",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "28:6A:B8",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "28:6A:BA",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "28:CF:DA",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "28:CF:E9",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "28:E0:2C",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "28:E1:4C",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "28:E7:CF",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "2C:B4:3A",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "2C:BE:08",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "2C:F0:EE",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_Android, "28:E3:1F", "xiaomi", "Android"}, //Xiaomi inc.
	{DEV_TYPE_Android, "20:08:ED", "HuaWei", "Android"},
	{DEV_TYPE_Android, "20:0B:C7", "HuaWei", "Android"},
	{DEV_TYPE_Android, "20:2B:C1", "HuaWei", "Android"},
	{DEV_TYPE_Android, "20:F3:A3", "HuaWei", "Android"},
	{DEV_TYPE_Android, "24:09:95", "HuaWei", "Android"},
	{DEV_TYPE_Android, "24:69:A5", "HuaWei", "Android"},
	{DEV_TYPE_Android, "24:7F:3C", "HuaWei", "Android"},
	{DEV_TYPE_Android, "24:DB:AC", "HuaWei", "Android"},
	{DEV_TYPE_Android, "28:31:52", "HuaWei", "Android"},
	{DEV_TYPE_Android, "28:3C:E4", "HuaWei", "Android"},
	{DEV_TYPE_Android, "28:5F:DB", "HuaWei", "Android"},
	{DEV_TYPE_Android, "28:6E:D4", "HuaWei", "Android"},
	{ DEV_TYPE_Android, "20:13:E0", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "20:64:32", "Samsung", "Android"}, //SamsungE # SAMSUNG ELECTRO MECHANICS 
	{ DEV_TYPE_Android, "20:D5:BF", "Samsung", "Android"}, //SamsungE # Samsung Eletronics Co., Ltd
	{ DEV_TYPE_Android, "28:98:7B", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "28:CC:01", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "2C:44:01", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "20:21:A5", "LG", "Android"}, //LG
	{ DEV_TYPE_Android, "2C:3F:3E", "LG", "Android"}, //LG
	{ DEV_TYPE_Android, "2C:54:CF", "LG", "Android"}, //LG
	
	{ DEV_TYPE_Android, "20:76:93", "Lenovo", "PC"}, //LenovoBeLenovo
	{DEV_TYPE_Android, "24:B6:FD", "Dell", "PC"}, //DellDell	
	{DEV_TYPE_Android, "20:54:76", "SONY", "Android"}, //SonyMobiSony
	{DEV_TYPE_Android, "24:21:AB", "SONY", "Android"}, //SonyEricSony
	{DEV_TYPE_Android, "28:0D:FC", "SONY", "Android"}, //SonyCompSony
	{DEV_TYPE_Android, "2C:8A:72", "HTC", "Android"},
	{DEV_TYPE_Android, "20:CF:30", "ASUS", "PC"},
	{DEV_TYPE_Android, "20:89:86", "ZTE", "Android"},
	{DEV_TYPE_Android, "2C:26:C5", "ZTE", "Android"},
	{DEV_TYPE_Android, "2C:95:7F", "ZTE", "Android"},
	{ DEV_TYPE_IPHONE, "30:10:E4",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "30:90:AB",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "30:F7:C5",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "34:15:9E",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "34:51:C9",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "34:C0:59",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "34:E2:FD",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "38:0F:4A",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "38:48:4C",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "3C:07:54",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "3C:15:C2",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "3C:AB:8E",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "3C:D0:F8",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "3C:E0:72",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "40:30:04",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "40:3C:FC",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "40:6C:8F",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "40:A6:D9",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "40:B3:95",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "40:D3:2D",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "44:2A:60",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "44:4C:0C",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "44:D8:84",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "44:FB:42",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "48:60:BC",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "48:74:6E",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "48:D7:05",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "4C:8D:79",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "4C:B1:99",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "50:EA:D6",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "54:26:96",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "54:72:4F",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "54:AE:27",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "54:E4:3A",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "54:EA:A8",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "58:1F:AA",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "58:55:CA",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "58:B0:35",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "5C:59:48",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "5C:8D:4E",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "5C:95:AE",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "5C:96:9D",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "5C:97:F3",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "5C:F9:38",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_Android, "30:CD:A7", "Samsung", "Android"}, //SamsungE # Samsung Electronics ITS, 
	{ DEV_TYPE_Android, "34:C3:AC", "Samsung", "Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "38:01:97", "Samsung", "Android"}, //ToshibaS # Toshiba Samsung Storage 
	{ DEV_TYPE_Android, "38:0A:94", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "38:16:D1", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "38:AA:3C", "Samsung", "Android"}, //SamsungE # SAMSUNG ELECTRO-MECHANICS
	{ DEV_TYPE_Android, "38:EC:E4", "Samsung", "Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "3C:5A:37", "Samsung", "Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "3C:62:00", "Samsung", "Android"}, //SamsungE # Samsung electronics CO., LTD
	{ DEV_TYPE_Android, "3C:8B:FE", "Samsung", "Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "44:4E:1A", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "44:F4:59", "Samsung", "Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "48:44:F7", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co., LTD
	{ DEV_TYPE_Android, "4C:BC:A5", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "50:01:BB", "Samsung", "Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "50:32:75", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "50:A4:C8", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "50:B7:C3", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,LTD
	{ DEV_TYPE_Android, "50:CC:F8", "Samsung", "Android"}, //SamsungE # Samsung Electro Mechanics
	{ DEV_TYPE_Android, "50:F5:20", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "54:92:BE", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "54:9B:12", "Samsung", "Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "58:C3:8B", "Samsung", "Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "5C:0A:5B", "Samsung", "Android"}, //SamsungE # SAMSUNG ELECTRO-MECHANICS 
	{ DEV_TYPE_Android, "5C:A3:9D", "Samsung", "Android"}, //SamsungE # SAMSUNG ELECTRO-MECHANICS 
	{ DEV_TYPE_Android, "5C:E8:EB", "Samsung", "Android"}, //SamsungE # Samsung Electronics

	{ DEV_TYPE_Android, "30:76:6F", "LG", "Android"}, //LG 
	{ DEV_TYPE_Android, "34:4D:F7", "LG", "Android"}, //LG 
	{ DEV_TYPE_Android, "34:FC:EF", "LG", "Android"}, //LG 
	{ DEV_TYPE_Android, "3C:BD:D8", "LG", "Android"}, //LG 
	{ DEV_TYPE_Android, "3C:CD:93", "LG", "Android"}, //LG 
	{ DEV_TYPE_Android, "3C:E6:24", "LG", "Android"}, //LG 
	{ DEV_TYPE_Android, "40:B0:FA", "LG", "Android"}, //LG 
	{ DEV_TYPE_Android, "48:59:29", "LG", "Android"}, //LG 
	{ DEV_TYPE_Android, "4C:26:E7", "LG", "Android"}, //LG 
	{ DEV_TYPE_Android, "50:55:27", "LG", "Android"}, //LG 
	{ DEV_TYPE_Android, "58:A2:B5", "LG", "Android"}, //LG 
	{ DEV_TYPE_Android, "5C:17:D3", "LG", "Android"}, //LG 
	
	{DEV_TYPE_Android, "30:87:30", "HuaWei", "Android"},
	{DEV_TYPE_Android, "30:D1:7E", "HuaWei", "Android"},
	{DEV_TYPE_Android, "34:00:A3", "HuaWei", "Android"},
	{DEV_TYPE_Android, "34:6B:D3", "HuaWei", "Android"},
	{DEV_TYPE_Android, "34:CD:BE", "HuaWei", "Android"},
	{DEV_TYPE_Android, "38:F8:89", "HuaWei", "Android"},
	{DEV_TYPE_Android, "3C:DF:BD", "HuaWei", "Android"},
	{DEV_TYPE_Android, "3C:F8:08", "HuaWei", "Android"},
	{DEV_TYPE_Android, "40:4D:8E", "HuaWei", "Android"},
	{DEV_TYPE_Android, "40:CB:A8", "HuaWei", "Android"},
	{DEV_TYPE_Android, "48:46:FB", "HuaWei", "Android"},
	{DEV_TYPE_Android, "48:62:76", "HuaWei", "Android"},
	{DEV_TYPE_Android, "4C:1F:CC", "HuaWei", "Android"},
	{DEV_TYPE_Android, "4C:54:99", "HuaWei", "Android"},
	{DEV_TYPE_Android, "4C:8B:EF", "HuaWei", "Android"},
	{DEV_TYPE_Android, "4C:B1:6C", "HuaWei", "Android"},
	{DEV_TYPE_Android, "50:9F:27", "HuaWei", "Android"},
	{DEV_TYPE_Android, "54:39:DF", "HuaWei", "Android"},
	{DEV_TYPE_Android, "54:89:98", "HuaWei", "Android"},
	{DEV_TYPE_Android, "54:A5:1B", "HuaWei", "Android"},
	{DEV_TYPE_Android, "58:1F:28", "HuaWei", "Android"},
	{DEV_TYPE_Android, "5C:4C:A9", "HuaWei", "Android"},
	{DEV_TYPE_Android, "5C:7D:5E", "HuaWei", "Android"},
	{DEV_TYPE_Android, "5C:F9:6A", "HuaWei", "Android"},
	{ DEV_TYPE_Android, "38:BC:1A", "meizu", "Android"},
	{ DEV_TYPE_Android, "48:02:2a", "B-LINK", "Router"},
	{ DEV_TYPE_Android, "44:33:4c", "B-LINK", "Router"},
	{ DEV_TYPE_Android, "50:3C:C4", "Lenovo", "PC"}, //LenovoMoLenovo
	{DEV_TYPE_Android, "34:17:EB", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "34:E6:D7", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "44:A8:42", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "4C:76:25", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "54:9F:35", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "5C:26:0A", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "5C:F9:DD", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "34:40:B5", "IBM", "PC"},        //Ibm
	{DEV_TYPE_Android, "40:F2:E9", "IBM", "PC"},        //Ibm
	{DEV_TYPE_Android, "5C:F3:FC", "IBM", "PC"}, //IbmIBM
	{DEV_TYPE_Android, "30:17:C8", "SONY", "Android"}, //SonyEricSony
	{DEV_TYPE_Android, "30:39:26", "SONY", "Android"}, //SonyEricSony
	{DEV_TYPE_Android, "30:75:12", "SONY", "Android"}, //SonyMobiSony
	{DEV_TYPE_Android, "30:A8:DB", "SONY", "Android"}, //SonyMobiSony
	{DEV_TYPE_Android, "30:F9:ED", "SONY", "Android"}, //SonySony
	{DEV_TYPE_Android, "3C:07:71", "SONY", "Android"}, //SonySony
	{DEV_TYPE_Android, "40:2B:A1", "SONY", "Android"}, //SonyEricSony
	{DEV_TYPE_Android, "44:74:6C", "SONY", "Android"}, //SonyMobiSony
	{DEV_TYPE_Android, "44:D4:E0", "SONY", "Android"}, //SonyMobiSony
	{DEV_TYPE_Android, "4C:21:D0", "SONY", "Android"}, //SonyMobiSony
	{DEV_TYPE_Android, "54:42:49", "SONY", "Android"}, //SonySony
	{DEV_TYPE_Android, "54:53:ED", "SONY", "Android"}, //SonySony
	{DEV_TYPE_Android, "58:17:0C", "SONY", "Android"}, //SonyEricSony
	{DEV_TYPE_Android, "5C:B5:24", "SONY", "Android"}, //SonyEricSony
	{DEV_TYPE_Android, "38:E7:D8", "HTC", "Android"},
	{DEV_TYPE_Android, "50:2E:5C", "HTC", "Android"},
	{DEV_TYPE_Android, "34:BB:26", "Motorola", "Android"},
	{DEV_TYPE_Android, "40:78:6A", "Motorola", "Android"},
	{DEV_TYPE_Android, "40:83:DE", "Motorola", "Android"},
	{DEV_TYPE_Android, "48:2C:EA", "Motorola", "Android"},
	{DEV_TYPE_Android, "4C:CC:34", "Motorola", "Android"},
	{DEV_TYPE_Android, "5C:0E:8B", "Motorola", "Android"},
	{DEV_TYPE_Android, "30:85:A9", "ASUS", "PC"},
	{DEV_TYPE_Android, "38:2C:4A", "ASUS", "PC"},
	{DEV_TYPE_Android, "40:16:7E", "ASUS", "PC"},
	{DEV_TYPE_Android, "48:5B:39", "ASUS", "PC"},
	{DEV_TYPE_Android, "50:46:5D", "ASUS", "PC"},
	{DEV_TYPE_Android, "54:04:A6", "ASUS", "PC"},
	{DEV_TYPE_Android, "54:A0:50", "ASUS", "PC"},
	{DEV_TYPE_Android, "30:F3:1D", "ZTE", "Android"},
	{DEV_TYPE_Android, "34:4B:50", "ZTE", "Android"},
	{DEV_TYPE_Android, "34:4D:EA", "ZTE", "Android"},
	{DEV_TYPE_Android, "34:DE:34", "ZTE", "Android"},
	{DEV_TYPE_Android, "34:E0:CF", "ZTE", "Android"},
	{DEV_TYPE_Android, "38:46:08", "ZTE", "Android"},
	{DEV_TYPE_Android, "48:28:2F", "ZTE", "Android"},
	{DEV_TYPE_Android, "4C:09:B4", "ZTE", "Android"},
	{DEV_TYPE_Android, "4C:16:F1", "ZTE", "Android"},
	{DEV_TYPE_Android, "4C:AC:0A", "ZTE", "Android"},
	{DEV_TYPE_Android, "4C:CB:F5", "ZTE", "Android"},
	{DEV_TYPE_Android, "54:22:F8", "ZTE", "Android"},
	{DEV_TYPE_Android, "4C:14:A3", "TCL", "PC"}, //
	{DEV_TYPE_Android, "5C:36:B8", "TCL", "PC"}, //
	{ DEV_TYPE_IPHONE, "60:03:08",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "60:33:4B",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "60:69:44",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "60:92:17",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "60:C5:47",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "60:D9:C7",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "60:FA:CD",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "60:FB:42",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "60:FE:C5",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "64:20:0C",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "64:76:BA",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "64:A3:CB",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "64:B9:E8",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "64:E6:82",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "68:09:27",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "68:5B:35",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "68:96:7B",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "68:9C:70",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "68:A8:6D",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "68:AE:20",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "68:D9:3C",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "6C:3E:6D",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "6C:40:08",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "6C:70:9F",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "6C:C2:6B",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "70:11:24",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "70:56:81",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "70:73:CB",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "70:CD:60",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "70:DE:E2",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "74:E1:B6",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "74:E2:F5",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "78:31:C1",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "78:3A:84",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "78:6C:1C",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "78:A3:E4",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "78:CA:39",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "78:FD:94",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "7C:11:BE",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "7C:6D:62",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "7C:6D:F8",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "7C:C3:A1",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "7C:C5:37",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "7C:D1:C3",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "7C:F0:5F",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "7C:FA:DF",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "80:00:6E",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "80:49:71",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "80:92:9F",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "80:BE:05",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "80:E6:50",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "80:EA:96",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "84:29:99",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "84:38:35",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "84:78:8B",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "84:85:06",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "84:8E:0C",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "84:B1:53",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "84:FC:FE",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "88:1F:A1",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "88:53:95",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "88:63:DF",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "88:C6:63",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "88:CB:87",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "8C:00:6D",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "8C:29:37",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "8C:2D:AA",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "8C:58:77",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "8C:7B:9D",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "8C:7C:92",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "8C:FA:BA",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "90:27:E4",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "90:72:40",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "90:84:0D",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "90:B2:1F",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "90:B9:31",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "90:FD:61",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "94:94:26",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "98:03:D8",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "98:B8:E3",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "98:D6:BB",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "98:F0:AB",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "98:FE:94",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "9C:04:EB",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "9C:20:7B",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_Android, "64:09:80", "xiaomi", "Android"}, //Xiaomi inc.
	{ DEV_TYPE_Android, "64:B4:73", "xiaomi", "Android"}, //Xiaomi inc.
	{ DEV_TYPE_Android, "68:DF:DD", "xiaomi", "Android"}, //Xiaomi inc.
	{ DEV_TYPE_Android, "7C:1D:D9", "xiaomi", "Android"}, //Xiaomi inc.
	{ DEV_TYPE_Android, "8C:BE:BE", "xiaomi", "Android"}, //Xiaomi inc.
	{ DEV_TYPE_Android, "98:FA:E3", "xiaomi", "Android"}, //Xiaomi inc.
	{ DEV_TYPE_Android, "60:6B:BD", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co., LTD
	{ DEV_TYPE_Android, "60:A1:0A", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "60:D0:A9", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "64:77:91", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "64:B3:10", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "68:EB:AE", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "6C:83:36", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "6C:F3:73", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "70:F9:27", "Samsung", "Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "74:45:8A", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "74:5F:00", "Samsung", "Android"}, //SamsungS # Samsung Semiconductor Inc.
	{ DEV_TYPE_Android, "78:1F:DB", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "78:25:AD", "Samsung", "Android"}, //SamsungE # SAMSUNG ELECTRONICS CO., LTD.
	{ DEV_TYPE_Android, "78:47:1D", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "78:59:5E", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "78:9E:D0", "Samsung", "Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "78:D6:F0", "Samsung", "Android"}, //SamsungE # Samsung Electro Mechanics
	{ DEV_TYPE_Android, "80:18:A7", "Samsung", "Android"}, //SamsungE # Samsung Eletronics Co., Ltd
	{ DEV_TYPE_Android, "84:0B:2D", "Samsung", "Android"}, //SamsungE # SAMSUNG ELECTRO-MECHANICS
	{ DEV_TYPE_Android, "84:25:DB", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "84:51:81", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "88:32:9B", "Samsung", "Android"}, //SamsungE # Samsung Electro Mechanics
	{ DEV_TYPE_Android, "8C:71:F8", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "8C:77:12", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "8C:C8:CD", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co., LTD
	{ DEV_TYPE_Android, "90:18:7C", "Samsung", "Android"}, //SamsungE # Samsung Electro Mechanics 
	{ DEV_TYPE_Android, "94:51:03", "Samsung", "Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "94:63:D1", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "98:0C:82", "Samsung", "Android"}, //SamsungE # Samsung Electro Mechanics
	{ DEV_TYPE_Android, "98:52:B1", "Samsung", "Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "9C:02:98", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "9C:3A:AF", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "9C:E6:E7", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
		
	{ DEV_TYPE_Android, "64:89:9A", "LG", "Android"}, //LG
	{ DEV_TYPE_Android, "64:99:5D", "LG", "Android"}, //LG
	{ DEV_TYPE_Android, "6C:D0:32", "LG", "Android"}, //LG
	{ DEV_TYPE_Android, "6C:D6:8A", "LG", "Android"}, //LG
	{ DEV_TYPE_Android, "70:05:14", "LG", "Android"}, //LG
	{ DEV_TYPE_Android, "74:A7:22", "LG", "Android"}, //LG
	{ DEV_TYPE_Android, "88:C9:D0", "LG", "Android"}, //LG
	{ DEV_TYPE_Android, "8C:3A:E3", "LG", "Android"}, //LG
	{ DEV_TYPE_Android, "8C:54:1D", "LG", "Android"}, //LG
	{ DEV_TYPE_Android, "90:6D:C8", "LG", "Android"}, //LG
	{ DEV_TYPE_Android, "94:44:44", "LG", "Android"}, //LG
	{ DEV_TYPE_Android, "98:93:CC", "LG", "Android"}, //LG
	{ DEV_TYPE_Android, "98:D6:F7", "LG", "Android"}, //LG
		
	{DEV_TYPE_Android, "60:DE:44", "HuaWei", "Android"},
	{DEV_TYPE_Android, "60:E7:01", "HuaWei", "Android"},
	{DEV_TYPE_Android, "64:16:F0", "HuaWei", "Android"},
	{DEV_TYPE_Android, "64:3E:8C", "HuaWei", "Android"},
	{DEV_TYPE_Android, "68:A0:F6", "HuaWei", "Android"},
	{DEV_TYPE_Android, "70:54:F5", "HuaWei", "Android"},
	{DEV_TYPE_Android, "70:72:3C", "HuaWei", "Android"},
	{DEV_TYPE_Android, "70:7B:E8", "HuaWei", "Android"},
	{DEV_TYPE_Android, "70:A8:E3", "HuaWei", "Android"},
	{DEV_TYPE_Android, "74:88:2A", "HuaWei", "Android"},
	{DEV_TYPE_Android, "78:1D:BA", "HuaWei", "Android"},
	{DEV_TYPE_Android, "78:6A:89", "HuaWei", "Android"},
	{DEV_TYPE_Android, "78:D7:52", "HuaWei", "Android"},
	{DEV_TYPE_Android, "78:F5:FD", "HuaWei", "Android"},
	{DEV_TYPE_Android, "7C:60:97", "HuaWei", "Android"},
	{DEV_TYPE_Android, "80:71:7A", "HuaWei", "Android"},
	{DEV_TYPE_Android, "80:B6:86", "HuaWei", "Android"},
	{DEV_TYPE_Android, "80:D0:9B", "HuaWei", "Android"},
	{DEV_TYPE_Android, "80:FB:06", "HuaWei", "Android"},
	{DEV_TYPE_Android, "84:A8:E4", "HuaWei", "Android"},
	{DEV_TYPE_Android, "84:DB:AC", "HuaWei", "Android"},
	{DEV_TYPE_Android, "88:53:D4", "HuaWei", "Android"},
	{DEV_TYPE_Android, "88:86:03", "HuaWei", "Android"},
	{DEV_TYPE_Android, "88:CE:FA", "HuaWei", "Android"},
	{DEV_TYPE_Android, "88:E3:AB", "HuaWei", "Android"},
	{DEV_TYPE_Android, "90:17:AC", "HuaWei", "Android"},
	{DEV_TYPE_Android, "90:4E:2B", "HuaWei", "Android"},
	{DEV_TYPE_Android, "94:04:9C", "HuaWei", "Android"},
	{DEV_TYPE_Android, "9C:28:EF", "HuaWei", "Android"},
	{DEV_TYPE_Android, "9C:C1:72", "HuaWei", "Android"},
	{ DEV_TYPE_Android, "60:99:D1", "Lenovo", "PC"}, //Vuzix/LeVuzix
	{ DEV_TYPE_Android, "60:D9:A0", "Lenovo", "PC"}, //LenovoMoLenovo
	{ DEV_TYPE_Android, "6C:5F:1C", "Lenovo", "PC"}, //LenovoMoLenovo
	{ DEV_TYPE_Android, "70:72:0D", "Lenovo", "PC"}, //LenovoMoLenovo
	{ DEV_TYPE_Android, "80:CF:41", "Lenovo", "PC"}, //LenovoMoLenovo
	{ DEV_TYPE_Android, "88:70:8C", "Lenovo", "PC"}, //LenovoMoLenovo
	{ DEV_TYPE_Android, "98:FF:D0", "Lenovo", "PC"}, //LenovoMoLenovo
	{DEV_TYPE_Android, "74:86:7A", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "74:E6:E2", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "78:2B:CB", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "78:45:C4", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "84:2B:2B", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "84:8F:69", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "90:B1:1C", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "98:90:96", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "6C:AE:8B", "IBM", "PC"}, //IbmIBM
	{DEV_TYPE_Android, "74:99:75", "IBM", "PC"}, //IbmIBM
	{DEV_TYPE_Android, "98:BE:94", "IBM", "PC"},        //Ibm
	{DEV_TYPE_Android, "68:76:4F", "SONY", "Android"}, //SonyMobiSony
	{DEV_TYPE_Android, "6C:0E:0D", "SONY", "Android"}, //SonyEricSony
	{DEV_TYPE_Android, "6C:23:B9", "SONY", "Android"}, //SonyEricSony
	{DEV_TYPE_Android, "70:9E:29", "SONY", "Android"}, //SonyCompSony
	{DEV_TYPE_Android, "78:84:3C", "SONY", "Android"}, //SonySony
	{DEV_TYPE_Android, "84:00:D2", "SONY", "Android"}, //SonyEricSony
	{DEV_TYPE_Android, "84:8E:DF", "SONY", "Android"}, //SonyMobiSony
	{DEV_TYPE_Android, "8C:64:22", "SONY", "Android"}, //SonyEricSony
	{DEV_TYPE_Android, "90:C1:15", "SONY", "Android"}, //SonyEricSony
	{DEV_TYPE_Android, "94:CE:2C", "SONY", "Android"}, //SonyMobiSony
	{DEV_TYPE_Android, "64:A7:69", "HTC", "Android"},
	{DEV_TYPE_Android, "7C:61:93", "HTC", "Android"},
	{DEV_TYPE_Android, "84:7A:88", "HTC", "Android"},
	{DEV_TYPE_Android, "90:21:55", "HTC", "Android"},
	{DEV_TYPE_Android, "98:0D:2E", "HTC", "Android"},
	{DEV_TYPE_Android, "60:A4:4C", "ASUS", "PC"},
	{DEV_TYPE_Android, "74:D0:2B", "ASUS", "PC"},
	{DEV_TYPE_Android, "78:24:AF", "ASUS", "PC"},
	{DEV_TYPE_Android, "90:E6:BA", "ASUS", "PC"},
	{DEV_TYPE_Android, "60:BE:B5", "Motorola", "Android"},
	{DEV_TYPE_Android, "80:6C:1B", "Motorola", "Android"},
	{DEV_TYPE_Android, "84:24:8D", "Motorola", "Android"},
	{DEV_TYPE_Android, "90:68:C3", "Motorola", "Android"},
	{DEV_TYPE_Android, "9C:D9:17", "Motorola", "Android"},
	{DEV_TYPE_Android, "68:1A:B2", "ZTE", "Android"},
	{DEV_TYPE_Android, "6C:8B:2F", "ZTE", "Android"},
	{DEV_TYPE_Android, "70:9F:2D", "ZTE", "Android"},
	{DEV_TYPE_Android, "78:31:2B", "ZTE", "Android"},	
	{DEV_TYPE_Android, "78:E8:B6", "ZTE", "Android"},
	{DEV_TYPE_Android, "84:74:2A", "ZTE", "Android"},
	{DEV_TYPE_Android, "8C:E0:81", "ZTE", "Android"},
	{DEV_TYPE_Android, "90:1D:27", "ZTE", "Android"},
	{DEV_TYPE_Android, "98:6C:F5", "ZTE", "Android"},
	{DEV_TYPE_Android, "98:F5:37", "ZTE", "Android"},
	{DEV_TYPE_Android, "9C:A9:E4", "ZTE", "Android"},
	{DEV_TYPE_Android, "9C:D2:4B", "ZTE", "Android"},
	{DEV_TYPE_Android, "60:9E:64", "Vivo", "Android"}, //Vivo
	{DEV_TYPE_Android, "64:B6:4A", "Vivo", "Android"}, //Vivo
	{DEV_TYPE_Android, "6C:5A:B5", "TCL", "PC"}, //
	{DEV_TYPE_Android, "7C:B2:32", "TCL", "PC"}, //
	{ DEV_TYPE_IPHONE, "A0:ED:CD",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "A4:67:06",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "A4:B1:97",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "A4:C3:61",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "A4:D1:D2",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "A8:20:66",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "A8:86:DD",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "A8:88:08",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "A8:8E:24",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "A8:96:8A",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "A8:BB:CF",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "A8:FA:D8",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "AC:3C:0B",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "AC:7F:3E",  "apple", "iPhone"},  //iPhone
	{ DEV_TYPE_IPHONE, "AC:87:A3",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "AC:CF:5C",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "AC:FD:EC",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "B0:34:95",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "B0:65:BD",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "B0:9F:BA",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "B4:18:D1",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "B4:F0:AB",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "B8:17:C2",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "B8:78:2E",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "B8:8D:12",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "B8:C7:5D",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "B8:E8:56",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "B8:F6:B1",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "B8:FF:61",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "BC:3B:AF",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "BC:52:B7",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "BC:67:78",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "BC:92:6B",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "C0:63:94",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "C0:84:7A",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "C0:9F:42",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "C0:F2:FB",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "C4:2C:03",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "C8:2A:14",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "C8:33:4B",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "C8:6F:1D",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "C8:85:50",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "C8:B5:B7",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "C8:BC:C8",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "C8:E0:EB",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "C8:F6:50",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "CC:08:E0",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "CC:78:5F",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "D0:23:DB",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "D0:E1:40",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "D4:9A:20",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "D4:F4:6F",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "D8:00:4D",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "D8:30:62",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "D8:96:95",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "D8:9E:3F",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "D8:A2:5E",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "D8:CF:9C",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "D8:D1:CB",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "DC:2B:61",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "DC:86:D8",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "DC:9B:9C",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "E0:66:78",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "E0:B5:2D",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "E0:B9:BA",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "E0:C9:7A",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "E0:F5:C6",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "E0:F8:47",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "E4:25:E7",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "E4:8B:7F",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "E4:98:D6",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "E4:C6:3D",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "E4:CE:8F",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "E8:04:0B",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "E8:06:88",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "E8:80:2E",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "E8:8D:28",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "EC:35:86",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "EC:85:2F",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "F0:B4:79",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "F0:C1:F1",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "F0:CB:A1",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "F0:D1:A9",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "F0:DC:E2",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "F0:F6:1C",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "F4:1B:A1",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "F4:37:B7",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "F4:F1:5A",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "F4:F9:51",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "F8:1E:DF",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "F8:27:93",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_IPHONE, "FC:25:3F",  "apple", "iPhone"}, //iPhone
	{ DEV_TYPE_Android, "AC:F7:F3", "xiaomi", "Android"}, //Xiaomi inc.
	{ DEV_TYPE_Android, "C4:6A:B7", "xiaomi", "Android"}, //Xiaomi inc.
	{ DEV_TYPE_Android, "D4:97:0B", "xiaomi", "Android"}, //Xiaomi inc.
	{ DEV_TYPE_Android, "F8:A4:5F", "xiaomi", "Android"}, //Xiaomi inc.
	{ DEV_TYPE_Android, "B4:0B:44", "Smartisan", "Android"},
	{DEV_TYPE_Android, "E4:1F:13", "IBM", "PC"}, //IbmIBM
	{DEV_TYPE_Android, "FC:CF:62", "IBM", "PC"}, //IbmIBM
	{DEV_TYPE_Android, "A4:99:47", "HuaWei", "Android"},
	{DEV_TYPE_Android, "AC:4E:91", "HuaWei", "Android"},
	{DEV_TYPE_Android, "AC:85:3D", "HuaWei", "Android"},
	{DEV_TYPE_Android, "AC:E2:15", "HuaWei", "Android"},
	{DEV_TYPE_Android, "AC:E8:7B", "HuaWei", "Android"},
	{DEV_TYPE_Android, "B0:5B:67", "HuaWei", "Android"},
	{DEV_TYPE_Android, "B4:15:13", "HuaWei", "Android"},
	{DEV_TYPE_Android, "B4:30:52", "HuaWei", "Android"},
	{DEV_TYPE_Android, "BC:76:70", "HuaWei", "Android"},
	{DEV_TYPE_Android, "C0:70:09", "HuaWei", "Android"},
	{DEV_TYPE_Android, "C4:05:28", "HuaWei", "Android"},
	{DEV_TYPE_Android, "C8:D1:5E", "HuaWei", "Android"},
	{DEV_TYPE_Android, "CC:53:B5", "HuaWei", "Android"},
	{DEV_TYPE_Android, "CC:96:A0", "HuaWei", "Android"},
	{DEV_TYPE_Android, "CC:A2:23", "HuaWei", "Android"},
	{DEV_TYPE_Android, "CC:CC:81", "HuaWei", "Android"},
	{DEV_TYPE_Android, "D0:2D:B3", "HuaWei", "Android"},
	{DEV_TYPE_Android, "D0:7A:B5", "HuaWei", "Android"},
	{DEV_TYPE_Android, "D4:6A:A8", "HuaWei", "Android"},
	{DEV_TYPE_Android, "D4:6E:5C", "HuaWei", "Android"},
	{DEV_TYPE_Android, "D4:B1:10", "HuaWei", "Android"},
	{DEV_TYPE_Android, "D8:49:0B", "HuaWei", "Android"},
	{DEV_TYPE_Android, "DC:D2:FC", "HuaWei", "Android"},
	{DEV_TYPE_Android, "E0:19:1D", "HuaWei", "Android"},
	{DEV_TYPE_Android, "E0:24:7F", "HuaWei", "Android"},
	{DEV_TYPE_Android, "E0:97:96", "HuaWei", "Android"},
	{DEV_TYPE_Android, "E4:68:A3", "HuaWei", "Android"},
	{DEV_TYPE_Android, "E8:08:8B", "HuaWei", "Android"},
	{DEV_TYPE_Android, "E8:CD:2D", "HuaWei", "Android"},
	{DEV_TYPE_Android, "EC:23:3D", "HuaWei", "Android"},
	{DEV_TYPE_Android, "EC:CB:30", "HuaWei", "Android"},
	{DEV_TYPE_Android, "F4:55:9C", "HuaWei", "Android"},
	{DEV_TYPE_Android, "F4:9F:F3", "HuaWei", "Android"},
	{DEV_TYPE_Android, "F4:C7:14", "HuaWei", "Android"},
	{DEV_TYPE_Android, "F4:DC:F9", "HuaWei", "Android"},
	{DEV_TYPE_Android, "F8:01:13", "HuaWei", "Android"},
	{DEV_TYPE_Android, "F8:3D:FF", "HuaWei", "Android"},
	{DEV_TYPE_Android, "F8:4A:BF", "HuaWei", "Android"},
	{DEV_TYPE_Android, "F8:E8:11", "HuaWei", "Android"},
	{DEV_TYPE_Android, "FC:48:EF", "HuaWei", "Android"},
	{DEV_TYPE_Android, "C0:98:79", "acer", "PC"},
	{DEV_TYPE_Android, "DC:66:3A", "acer", "PC"},
	{ DEV_TYPE_Android, "A0:07:98", "Samsung", "Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "A0:0B:BA", "Samsung", "Android"}, //SamsungE # SAMSUNG ELECTRO-MECHANICS
	{ DEV_TYPE_Android, "A0:21:95", "Samsung", "Android"}, //SamsungE # Samsung Electronics Digital 
	{ DEV_TYPE_Android, "A0:75:91", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "A4:EB:D3", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "A8:06:00", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "A8:F2:74", "Samsung", "Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "B0:C4:E7", "Samsung", "Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "B0:D0:9C", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "B0:EC:71", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "B4:07:F9", "Samsung", "Android"}, //SamsungE # SAMSUNG ELECTRO-MECHANICS
	{ DEV_TYPE_Android, "B4:62:93", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "B8:C6:8E", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "B8:D9:CE", "Samsung", "Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "BC:20:A4", "Samsung", "Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "BC:47:60", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "BC:85:1F", "Samsung", "Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "BC:B1:F3", "Samsung", "Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "C4:73:1E", "Samsung", "Android"}, //SamsungE # Samsung Eletronics Co., Ltd
	{ DEV_TYPE_Android, "C4:88:E5", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "C8:19:F7", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "C8:7E:75", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "CC:05:1B", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "CC:3A:61", "Samsung", "Android"}, //SamsungE # SAMSUNG ELECTRO MECHANICS 
	{ DEV_TYPE_Android, "CC:F9:E8", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "CC:FE:3C", "Samsung", "Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "D0:17:6A", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "D0:66:7B", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co., LTD
	{ DEV_TYPE_Android, "D0:C1:B1", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "D0:DF:C7", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "D4:87:D8", "Samsung", "Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "D4:88:90", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "D4:E8:B2", "Samsung", "Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "D8:31:CF", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "D8:57:EF", "Samsung", "Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "DC:71:44", "Samsung", "Android"}, //SamsungE # Samsung Electro Mechanics
	{ DEV_TYPE_Android, "E4:7C:F9", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co., LTD
	{ DEV_TYPE_Android, "E4:B0:21", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "E4:E0:C5", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co., LTD
	{ DEV_TYPE_Android, "E8:03:9A", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,LTD
	{ DEV_TYPE_Android, "E8:11:32", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,LTD
	{ DEV_TYPE_Android, "E8:E5:D6", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "EC:E0:9B", "Samsung", "Android"}, //SamsungE # Samsung electronics CO., LTD
	{ DEV_TYPE_Android, "F0:08:F1", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "F0:6B:CA", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "F0:E7:7E", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "F4:7B:5E", "Samsung", "Android"}, //SamsungE # Samsung Eletronics Co., Ltd
	{ DEV_TYPE_Android, "F4:9F:54", "Samsung", "Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "F4:D9:FB", "Samsung", "Android"}, //SamsungE # Samsung Electronics CO., LTD
	{ DEV_TYPE_Android, "F8:D0:BD", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "FC:00:12", "Samsung", "Android"}, //ToshibaS # Toshiba Samsung Storage 
	{ DEV_TYPE_Android, "FC:1F:19", "Samsung", "Android"}, //SamsungE # SAMSUNG ELECTRO-MECHANICS 
	{ DEV_TYPE_Android, "FC:A1:3E", "Samsung", "Android"}, //SamsungE # Samsung Electronics
	{ DEV_TYPE_Android, "FC:C7:34", "Samsung", "Android"}, //SamsungE # Samsung Electronics Co.,Ltd
	{ DEV_TYPE_Android, "A8:16:B2", "LG", "Android"}, //LG 
	{ DEV_TYPE_Android, "A8:92:2C", "LG", "Android"}, //LG 
	{ DEV_TYPE_Android, "B0:61:C7", "LG", "Android"}, //LG 
	{ DEV_TYPE_Android, "B0:89:91", "LG", "Android"}, //LG 
	{ DEV_TYPE_Android, "B0:98:9F", "LG", "Android"}, //LG 
	{ DEV_TYPE_Android, "B4:0E:DC", "LG", "Android"}, //LG 
	{ DEV_TYPE_Android, "BC:F5:AC", "LG", "Android"}, //LG 
	{ DEV_TYPE_Android, "C0:41:F6", "LG", "Android"}, //LG 
	{ DEV_TYPE_Android, "C4:36:6C", "LG", "Android"}, //LG 
	{ DEV_TYPE_Android, "C4:43:8F", "LG", "Android"}, //LG 
	{ DEV_TYPE_Android, "C8:02:10", "LG", "Android"}, //LG 
	{ DEV_TYPE_Android, "C8:08:E9", "LG", "Android"}, //LG 
	{ DEV_TYPE_Android, "CC:2D:8C", "LG", "Android"}, //LG 
	{ DEV_TYPE_Android, "CC:FA:00", "LG", "Android"}, //LG 
	{ DEV_TYPE_Android, "E8:5B:5B", "LG", "Android"}, //LG 
	{ DEV_TYPE_Android, "E8:92:A4", "LG", "Android"}, //LG 
	{ DEV_TYPE_Android, "EC:2E:4E", "LG", "Android"}, //LG 
	{ DEV_TYPE_Android, "F0:1C:13", "LG", "Android"}, //LG 
	{ DEV_TYPE_Android, "F8:0C:F3", "LG", "Android"}, //LG 
	{ DEV_TYPE_Android, "F8:A9:D0", "LG", "Android"}, //LG 	
	
	{ DEV_TYPE_Android, "A4:8C:DB", "Lenovo", "PC"}, //Lenovo
	{ DEV_TYPE_Android, "AC:38:70", "Lenovo", "PC"}, //LenovoMoLenovo
	{ DEV_TYPE_Android, "C8:DD:C9", "Lenovo", "PC"}, //LenovoMoLenovo
	{ DEV_TYPE_Android, "CC:07:E4", "Lenovo", "PC"}, //LenovoMoLenovo
	{ DEV_TYPE_Android, "D4:22:3F", "Lenovo", "PC"}, //LenovoMoLenovo
	{ DEV_TYPE_Android, "D8:71:57", "Lenovo", "PC"}, //LenovoMoLenovo
	{ DEV_TYPE_Android, "EC:89:F5", "Lenovo", "PC"}, //LenovoMoLenovo
	{DEV_TYPE_Android, "A4:1F:72", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "A4:BA:DB", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "B0:83:FE", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "B8:2A:72", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "B8:AC:6F", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "B8:CA:3A", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "BC:30:5B", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "C8:1F:66", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "D0:67:E5", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "D4:AE:52", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "D4:BE:D9", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "E0:DB:55", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "EC:F4:BB", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "F0:1F:AF", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "F0:4D:A2", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "F8:B1:56", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "F8:BC:12", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "F8:DB:88", "Dell", "PC"}, //DellDell
	{DEV_TYPE_Android, "A8:97:DC", "IBM", "PC"},        //Ibm
	{DEV_TYPE_Android, "A0:E4:53", "SONY", "Android"}, //SonyMobiSony
	{DEV_TYPE_Android, "A8:E3:EE", "SONY", "Android"}, //SonyCompSony
	{DEV_TYPE_Android, "B4:52:7D", "SONY", "Android"}, //SonyMobiSony
	{DEV_TYPE_Android, "B4:52:7E", "SONY", "Android"}, //SonyMobiSony
	{DEV_TYPE_Android, "B8:F9:34", "SONY", "Android"}, //SonyEricSony
	{DEV_TYPE_Android, "BC:6E:64", "SONY", "Android"}, //SonyMobiSony
	{DEV_TYPE_Android, "D0:51:62", "SONY", "Android"}, //SonyMobiSony
	{DEV_TYPE_Android, "D8:D4:3C", "SONY", "Android"}, //SonySony
	{DEV_TYPE_Android, "E0:63:E5", "SONY", "Android"}, //SonyMobiSony
	{DEV_TYPE_Android, "F0:BF:97", "SONY", "Android"}, //SonySony
	{DEV_TYPE_Android, "F8:D0:AC", "SONY", "Android"}, //SonyCompSony
	{DEV_TYPE_Android, "FC:0F:E6", "SONY", "Android"}, //SonyCompSony
	{DEV_TYPE_Android, "FC:F1:52", "SONY", "Android"}, //SonySony
	{DEV_TYPE_Android, "C0:EE:FB", "OnePlus", "Android"}, //
	{DEV_TYPE_Android, "A0:F4:50", "HTC", "Android"},
	{DEV_TYPE_Android, "A8:26:D9", "HTC", "Android"},
	{DEV_TYPE_Android, "B4:CE:F6", "HTC", "Android"},
	{DEV_TYPE_Android, "BC:CF:CC", "HTC", "Android"},
	{DEV_TYPE_Android, "D4:0B:1A", "HTC", "Android"},
	{DEV_TYPE_Android, "D4:20:6D", "HTC", "Android"},
	{DEV_TYPE_Android, "D8:B3:77", "HTC", "Android"},
	{DEV_TYPE_Android, "E8:99:C4", "HTC", "Android"},
	{DEV_TYPE_Android, "F8:DB:7F", "HTC", "Android"},
	{DEV_TYPE_Android, "AC:22:0B", "ASUS", "PC"},
	{DEV_TYPE_Android, "AC:9E:17", "ASUS", "PC"},
	{DEV_TYPE_Android, "BC:AE:C5", "ASUS", "PC"},
	{DEV_TYPE_Android, "BC:EE:7B", "ASUS", "PC"},
	{DEV_TYPE_Android, "C8:60:00", "ASUS", "PC"},
	{DEV_TYPE_Android, "D8:50:E6", "ASUS", "PC"},
	{DEV_TYPE_Android, "E0:3F:49", "ASUS", "PC"},
	{DEV_TYPE_Android, "E0:CB:4E", "ASUS", "PC"},
	{DEV_TYPE_Android, "F4:6D:04", "ASUS", "PC"},
	{DEV_TYPE_Android, "A4:70:D6", "Motorola", "Android"},
	{DEV_TYPE_Android, "B0:79:94", "Motorola", "Android"},
	{DEV_TYPE_Android, "B4:C7:99", "Motorola", "Android"},
	{DEV_TYPE_Android, "C4:7D:CC", "Motorola", "Android"},
	{DEV_TYPE_Android, "CC:C3:EA", "Motorola", "Android"},
	{DEV_TYPE_Android, "E0:75:7D", "Motorola", "Android"},
	{DEV_TYPE_Android, "EC:88:92", "Motorola", "Android"},
	{DEV_TYPE_Android, "F4:F1:E1", "Motorola", "Android"},
	{DEV_TYPE_Android, "F8:E0:79", "Motorola", "Android"},
	{DEV_TYPE_Android, "F8:F1:B6", "Motorola", "Android"},
	{DEV_TYPE_Android, "FC:0A:81", "Motorola", "Android"},
	{DEV_TYPE_Android, "A0:EC:80", "ZTE", "Android"},
	{DEV_TYPE_Android, "A4:7E:39", "ZTE", "Android"},
	{DEV_TYPE_Android, "A8:A6:68", "ZTE", "Android"},
	{DEV_TYPE_Android, "B0:75:D5", "ZTE", "Android"},
	{DEV_TYPE_Android, "B4:98:42", "ZTE", "Android"},
	{DEV_TYPE_Android, "B4:B3:62", "ZTE", "Android"},
	{DEV_TYPE_Android, "C8:64:C7", "ZTE", "Android"},
	{DEV_TYPE_Android, "C8:7B:5B", "ZTE", "Android"},
	{DEV_TYPE_Android, "CC:1A:FA", "ZTE", "Android"},
	{DEV_TYPE_Android, "CC:7B:35", "ZTE", "Android"},
	{DEV_TYPE_Android, "D0:15:4A", "ZTE", "Android"},
	{DEV_TYPE_Android, "D0:5B:A8", "ZTE", "Android"},
	{DEV_TYPE_Android, "D4:37:D7", "ZTE", "Android"},
	{DEV_TYPE_Android, "D8:74:95", "ZTE", "Android"},
	{DEV_TYPE_Android, "DC:02:8E", "ZTE", "Android"},
	{DEV_TYPE_Android, "E0:C3:F3", "ZTE", "Android"},
	{DEV_TYPE_Android, "E4:77:23", "ZTE", "Android"},
	{DEV_TYPE_Android, "EC:1D:7F", "ZTE", "Android"},
	{DEV_TYPE_Android, "EC:8A:4C", "ZTE", "Android"},
	{DEV_TYPE_Android, "F0:84:C9", "ZTE", "Android"},
	{DEV_TYPE_Android, "F4:6D:E2", "ZTE", "Android"},
	{DEV_TYPE_Android, "F8:DF:A8", "ZTE", "Android"},
	{DEV_TYPE_Android, "FC:C8:97", "ZTE", "Android"},
	{-1, "", "", ""}
	//{-1,"", NULL, NULL}
};

*/



