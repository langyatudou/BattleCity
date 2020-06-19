#include"Data.h"


/*定义我自己的坦克*/
TANK mytank;
/*定义一个我自己的坦克子弹，我自己等价于坦克1*/
BULLET bullet1;

/*地方坦克3*/
 TANK tank3;
 BULLET bullet3;

 //存放坦克图片
 char g_TankPicture[30][141] = { 0 };

/*定义一个二维数组当地图，并将地图全部初始化为空地*/
int g_Map[MAP_Y][MAP_X] = { 
	{ 0 },
	{ 0},
	{ 0 },
	{ 0 },
	{ 0},
	{ 0 },
	{0,0,0,0,0,0,0,0,0,0,0,0,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,},
	{ 0,0,0,0,0,0,0,0,0,0,0,0,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11, },
	{},
	{},
	{},
	{},
	{0,11,11,11,11,11,11,11,11,11,11,11,11,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,11,11,11,11,11,11,11,11,11,11,11,11,11},
	{0,11,11,11,11,11,11,11,11,11,11,11,11,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,11,11,11,11,11,11,11,11,11,11,11,11,11 },
	{},
	{},
	{},
	{},
	{ 0,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,20,20,20,20,20,20,20,20,20,20,20,20,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,21,21,21,21,21,21,21,20,20,20,20,20,20,20,20,20,20,20,20,21,21,21,21,21,21,21 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,21,21,21,21,21,21,21,20,20,20,20,20,20,20,20,20,20,20,20,21,21,21,21,21,21,21 },
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,11,11,11,11,11,11,0,0,0,0,0,0,0,0,0,0,0,0,0,11,11,11,11,11,11},
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,11,11,11,11,11,11,0,0,0,0,0,0,0,0,0,0,0,0,0,11,11,11,11,11,11 },
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,11,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,11,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,11,0},
	{},
	{},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,11,11,11,11,11},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,12,12,12,12,11 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,12,12,12,12,11 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,12,12,12,12,11 },

	};
//
char nn[26][121] = {
	"	                                       																				 ",
	"                                                                 i.ri7YSXRgqBP                                          ",
	"                                                                EDv1bPYv5MBQBB                                          ",
	"                                                                7BBgZBBBEBXJ2g.                                         ",
	"                                                 Y.   7Ud7..rJb5JuS5uUKKqPKUUJXZPKgEDuSqY                               ",
	"                                         DDvv i:i7Sr7Ki:.i:5BBRQZXYL7rrYI17sKMPPXXEBBBBBQ                               ",
	"                                .:YLuvrv1QBX:iD2U:BQdB77rvJiK5XSbq1uPIKPdb1sSEPPPUXEgdZBB                               ",
	"ERQBBBBBBBBBBBBBBBBBBBBBBBQBBBBBBBBBBBBBbgiSPEir1SYdq7vJYSXvu7v1jUJKPPKqPXLsUDggPPgQQdEBQ                               ",
	"                                 i1vuIIddBKPBS.vS2jvr:vYPPKJEjvLJYsJEP5YL7YYUI5jbQBBBQgBB                               ",
	"                                         r.iSgZBBBBBQBQBBBBBBBQQQBQRQBBBBBRRQBB5   :                ..  .           ..  ",
	"                                 LBPv i7I7LUEPEPdKPPbPbqPPbPEDDPDgDbbPgZMgZbDERgr.:XKSPPERQQRdJ.rJv7BBBQBBBBBS     :BQ  ",
	"                          :YBBL. ZZSI1XDXurSBQMQQQQBQQPdPPEdqPqQKEbdEddbqDgI7KjEQgRgDPKbSXgMEqKBBBBBQBBBBBBBQi     .BB  ",
	"                            ZL  :QEP5PQMERMgQgDbDbddQQgPS2EKdJuPIPEPPISXEdMd5DDEQEgMEqdPdbMPbq5dDQBERQBQBQBBBgbr  .RQgBi",
	"                    vUU2IXYIEXj5SQZbgQMgZZEgdPIXSqSKEMggPPqdKEDMggZdPPqPZDdMggMQRQQQEEdggRgQggbPbZdDbdq5IY7KKEBBK.RBMBBM",
	"                  .ZBBBBBBBQBBBBBQQMRgQgBgBMBQBQQQQQgRgQRQQQQQBRQgBgBRBRBMQgRgRMgRMMMQQRgDMMDZQERgDgQgQdQMdMQqIqMgDDBBb ",
	"                .uBBMQgRDbPMDggZZggMEMdgdRDgddPRZDDDgEREggQDRRgPqPDQbQKgqgEEZZPDDDK5XgQKZEXqXPddZBX25X5uIbPQMRgPB5  gY  ",
	"                ..gBdZZuXRQEqRQ2gBBggbMQQBQPS1KRBQQZQMQEQgRZEQq1uUgMPggQRbgQBDgBBZX7SMQIgQDgQZQBdssPBPgEPusZMuBBBB  d1  ",
	"                 7QBBQgsiIPKSQQb5PBQbDRQgQMZbSEBERQZbRqPMdDdPQZqXDBEIgRQD5JZBEKgggbIqMPEXBRRZgQg5M5bDgQB5ZQKK  Bs.  BX  ",
	"                  YBQS5s: .u5s1d2XBQXPKXZEPSPqgK2s5qbIuUE2I5PqSddZBXJERgZjsuPK2uUPgZQbPX2gMPgQdsDZQUJY5P5DZDgr DB..BB   ",
	"                  UBqUKBRPZMR57dMSIQPBDKBgYYjLIQDZXPddPPSKKK5RDQQQgqPggDSPggqPPPbMQBQBMqDBQgKPMuZXPXK22ZgSSQRU  iQQX    ",
	"                  sBbQDdQBBQDRBPd5PEQQgSgBSjZPXQBQQRRUSqKRBDgQBddgDbBRDPqSdgQRBBgDQPKdMDBBQMdSQuPgbZBZDQBQQ5Dq          ",
	"                   BBBPibBRRXEQXZdZDgRBQERPK2KMgDgDRDqIIDMZgDgdSUuKQdDdMgdPPqQgggDDZEX7KdEgRRgdQbgQBBEdBZXXqK.          ",
	"                    JBBBBEggZb7vBBZgEgbKbEDDEDgbXsbQBEgDMEQPbRMPgZQdDPKbRDPZgZEbuYKDZEgMgQgXqdDgBP151vi.rYREi           ",
	"                      :XuBQIu:   BBDPP2PPXPZQBKQqj1PPqQBXDDqKgdPgBgqqXXZgQEBBPPXjJ5KKQBDPd5JSMQBi   ivPSE..             ",
	"                           rrbPP:RBQZUdKPXDEQQQSMD1SPgBBRIKZIqKDPBBDUPUSRQS5BBPIEsqbMSBBEuPs5ZQE..dKMrr                 ",
	"                               . i:sqEPSXbI. UDMdqXPS:.1bMPKSKDL iXQgdKKS5  7EQMKdKd7 :PRgPPPKj.vri      :vU7vuvYj:JJL: "
};

