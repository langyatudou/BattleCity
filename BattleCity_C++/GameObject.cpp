#include "GameObject.h"
#include"MapObject.h"
#include <stdlib.h>

CGameObject::CGameObject()
{
}


CGameObject::~CGameObject()
{
}

////欢迎界面
bool CGameObject::WelcomeUI(int index) 
{
	char picture[26][121] = {
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
	for (int i = 0; i < 26; i++) {
		printf("%s\n", picture[i]);
	}
	int y = 27;
		char GameMenu[6][25] = { "欢迎进入坦克大战游戏界面",
			"一、开始新游戏",
			"二、自定义游戏地图",
			"三、三读取游戏存档",
			"四、退出游戏",
			"请输入你的选择->" };
		for (int i = 1; i < 6; i++)
		{
			drawobject.printChar(28, y + i, GameMenu[i]);
		}
		
		return true;
}

//编辑地图菜单
void CGameObject::EditMapUI() 
{
	int y = 2;
	drawobject.printChar(MAP_X, y + 1, "铁墙：■->不能被子弹击毁");  //17
	drawobject.printChar(MAP_X, y + 3, "灰墙：□->可以被子弹击毁");  //17
	drawobject.printChar(MAP_X, y + 5, "河流：≡->子弹可以穿越，坦克不能");  //
	drawobject.printChar(MAP_X, y + 7, "草地：▓->子弹或坦克进去后会隐身");  //17
	drawobject.printChar(MAP_X, y + 9, "基地：★->被击中后游戏结束");  //17
}

//打印游戏玩家信息菜单
void CGameObject::printPlayerUI() 
{
	int y = 2;
	drawobject.printChar(MAP_X, y + 1, "            玩家1信息");  //17
	drawobject.printChar(MAP_X, y + 3, "  生命：  ");  //17
	printf("%d", vectankobject[0].getTankBlood());
	drawobject.printChar(MAP_X, y + 5, "  积分：  ");  //17
	printf("%d", vectankobject[0].getTankScore());
	
	//玩家二
	drawobject.printChar(MAP_X, y + 7, "            玩家2信息");  //17
	drawobject.printChar(MAP_X, y + 9, "  生命：  ");  //17
	printf("%d", vectankobject[1].getTankBlood());
	drawobject.printChar(MAP_X, y + 11, "  积分：  ");  //17
	printf("%d", vectankobject[1].getTankScore());

	//游戏控制介绍
	drawobject.printChar(MAP_X, MAP_Y/2+4, "            游戏操作介绍");  //17
	drawobject.printChar(MAP_X, MAP_Y / 2 + 7, "  玩家1方向控制：WSAD,子弹发射F");  //17
	drawobject.printChar(MAP_X, MAP_Y / 2 + 9, "  玩家2方向控制：IJKL,子弹发射P");  //17
	drawobject.printChar(MAP_X, MAP_Y / 2 + 11,"  玩家生命值为0时：游戏结束");  //17
	drawobject.printChar(MAP_X, MAP_Y / 2 + 13, "  g/G保存游戏");  //17
}
//关卡菜单
void CGameObject::ChoicLevelUI() {
	drawobject.printChar(MAP_X / 2, MAP_Y / 2,   "第一关");  //17
	drawobject.printChar(MAP_X / 2, MAP_Y / 2 + 2, "第二关");  //17
	drawobject.printChar(MAP_X / 2, MAP_Y / 2 + 4, "第三关");  //17
	drawobject.printChar(MAP_X / 2, MAP_Y / 2 + 6, "请选择-->");  //17
	scanf_s("%d", &m_level);
	m_level -= 1;
}
//选择保存地图菜单
void CGameObject::ChoiceSaveMapUI() 
{
	drawobject.printChar(MAP_X / 2, MAP_Y / 2 + 6, "请选择-->"); 
	scanf_s("%d", &m_level);
	m_level -= 1;
}


bool CGameObject::ReadMap() {

	FILE*pfile = NULL;
	//打开文件
	//路径
	//默认读取第0关地图
	sprintf_s(m_buff, "d:\\code\\BattleCity\\BattleCity_C++\\第%d关地图.txt", m_level);

	fopen_s(&pfile, m_buff, "rb");
	if (pfile == NULL) {
		MessageBox(NULL, "打开文件失败", "文件读取", 0);
		exit(0);
		return false;//读取文件失败
	}
	//读取文件
	//将文件内容读取到地图类中的地图数组
	fread(g_Map, sizeof(int) * MAP_X * MAP_Y, 1, pfile);
	fread(g_Mapname, sizeof(char) * 5 * 100, 1, pfile);
	//关闭文件
	fclose(pfile);
	return true;
}

//文件写入-保存游戏地图
bool CGameObject::SaveMap() {
	FILE*pfile = NULL;
	//打开文件
	int tempnNum = 0;
	sprintf_s(m_buff, "d:\\code\\BattleCity\\BattleCity_C++\\第%d关地图.txt", m_level);
	fopen_s(&pfile, m_buff, "wb+");
	if (pfile == NULL) {
		MessageBox(NULL, "打开文件失败", "文件写入", 0);
		return false;//读取文件失败
	}
	//写入
	//将地图对象中的地图数组保存到文件中去
	fwrite(g_Map, sizeof(int) * MAP_X * MAP_Y, 1, pfile);
	fwrite(g_Mapname, sizeof(char) * 5 * 100, 1, pfile);
	//关闭
	fclose(pfile);
	return true;
}

//保存游戏存档
bool CGameObject::SaveGame() {
	FILE*pfile = NULL;
	//打开文件
	fopen_s(&pfile, "d:\\code\\BattleCity\\BattleCity_C++\\游戏存档.txt", "wb+");
	if (pfile == NULL) {
		MessageBox(NULL, "打开文件失败", "文件写入", 0);
		return false;//读取文件失败
	}
	//vector<CTankObject>vectankobject;     //用游戏类的初始化函数给坦克和子弹左做初始化

	NPCTankNum = vectankobject.size();
	fwrite(&NPCTankNum, sizeof(int), 1, pfile);  //保存当前
	for (int i = 0; i < vectankobject.size(); i++) {
		fwrite(&vectankobject[i], sizeof(CTankObject), 1, pfile);
	}


	fwrite(g_Map, sizeof(int) * MAP_X * MAP_Y, 1, pfile);

	//关闭
	fclose(pfile);
	return true;
}
//读取游戏存档
bool CGameObject::ReadGame() {
	FILE*pfile = NULL;
	//打开文件
	fopen_s(&pfile, "d:\\code\\BattleCity\\BattleCity_C++\\游戏存档.txt", "rb");
	if (pfile == NULL) {
		MessageBox(NULL, "打开文件失败", "文件读取", 0);
		return false;//读取文件失败
	}
	CTankObject tempobj;
	NPCTankNum -= 2;
	fread(&NPCTankNum,sizeof(int), 1, pfile);  //保存当前
	for (int i = 0; i < NPCTankNum; i++) {
		
		fread(&tempobj, sizeof(CTankObject), 1, pfile);
		vectankobject.push_back(tempobj);
	}
	fread(g_Map, sizeof(int) * MAP_X * MAP_Y, 1, pfile);
	//关闭文件
	fclose(pfile);
	return true;
}

//初始化地图
void CGameObject::DrawMap() {

	for (int i = 0; i < MAP_Y; i++)
	{
		for (int j = 0; j < MAP_X; j++)
		{
			if (g_Map[i][j] == 地图边框)
			{
 				drawobject.printChar(j, i, "■");
			}
			else if (g_Map[i][j] == 铁墙) {
				drawobject.printChar(j, i, "■");
			}
			else if (g_Map[i][j] == 灰墙) {
				drawobject.printChar(j, i, "■", 灰色);
			}
			else if (g_Map[i][j] == 草地) {
				drawobject.printChar(j, i, "▓", 绿色);
			}
			else if (g_Map[i][j] == 河流) {
				drawobject.printChar(j, i, "≡", 蓝色);
			}
			else if (g_Map[i][j] == 基地) {
				drawobject.printChar(j, i, "★");
			}
		}
	}
	//打印外围墙壁
	drawobject.printChar(MAP_X, 0, "■■■■■■■■■■■■■■■■■");  //17
	drawobject.printChar(MAP_X, MAP_Y / 2, "■■■■■■■■■■■■■■■■■");  //17
	drawobject.printChar(MAP_X, MAP_Y - 1, "■■■■■■■■■■■■■■■■■");  //17
	for (int i = 0; i < MAP_Y; i++) {
		drawobject.printChar(MAP_X + 17, i, "■");
	}
}

//初始化自己和友军坦克信息
bool CGameObject::InitPlayerTankInfo()
{
	//1.定义临时对象，用于调用坦克成员函数
	CTankObject playertankobject1, playertankobject2;
	//初始化玩家1基本信息
	playertankobject1.setTankDir(上);                  //方向
	playertankobject1.setTankPosX(15);                 //坐标
	playertankobject1.setTankPosY(42);
	playertankobject1.setTankColocr(白色);             //颜色
	playertankobject1.setTankType(坦克1);              //类型
	playertankobject1.setTankScore(0);                 //积分
	playertankobject1.setTankBlood(3);                 //血量
	playertankobject1.setTankisDie(true);              //状态
	playertankobject1.setAlignment(0);             //阵营    0代表友军
	vectankobject.push_back(playertankobject1);
	//初始化玩家2基本信息
	playertankobject2.setTankDir(上);
	playertankobject2.setTankPosX(30);
	playertankobject2.setTankPosY(42);
	playertankobject2.setTankColocr(黄色);
	playertankobject2.setTankType(坦克1);      //
	playertankobject2.setTankScore(0);
	playertankobject2.setTankBlood(3);
	playertankobject2.setTankisDie(1);
	playertankobject2.setAlignment(0);
	vectankobject.push_back(playertankobject2);
	
	return true;
}

//初始NPC坦克信息
bool CGameObject::InitNPCTankInfo() 
{
	CTankObject NPCtankobject;
	srand((unsigned)time(NULL));
	int X, Y, dir, speed;
	

	for (int i = 2; i <NPCTankNum+2; i++) {
			X = rand() % (MAP_X - 8) + 4;
			Y = rand() % 6 + 4;
			dir = rand() % 4;
			speed = rand() % 50 + 100;
		NPCtankobject.setTankPosX(X);
		NPCtankobject.setTankPosY(Y);
		NPCtankobject.setTankDir(dir);
		//第三辆坦克为敌军老大，生命值不一样，颜色不一样
		if (i == 2) {
			NPCtankobject.setTankColocr(红色);
		}
		else {
			NPCtankobject.setTankColocr(蓝色);
		}
		NPCtankobject.setTankType(NPC坦克);
		NPCtankobject.setTankisDie(true);
		NPCtankobject.setAlignment(1);      //1代表敌军阵营
		NPCtankobject.setTankSpeed(speed);  //每辆坦克的速度
		vectankobject.push_back(NPCtankobject);
	}
	return true;
}

////通过键盘移动坦克
bool CGameObject::MovesSelfAndALLY(vector<CTankObject>&tankobject) 
{
	int ch1 = 0;
	if (_kbhit() != 0) {
		ch1 = _getch();
	}
	//玩家1
	switch (ch1)
	{
	case 'w':
	case'W'://价格标记，坦克没死才让控制
			if (tankobject[0].getTankDir() != 上) {
				//擦除坦克
				tankobject[0].ClsObject();
				tankobject[0].setTankDir(上);//将坦克方向修改为上
				tankobject[0].DrawObject();
			}
			else {
				
				tankobject[0].MoveTank();
			}
		break;
	case's':
	case'S':
			if (tankobject[0].getTankDir() != 下)
			{
				tankobject[0].ClsObject();
				tankobject[0].setTankDir(下);
				tankobject[0].DrawObject();
			}
			else {
				tankobject[0].MoveTank();
			}
		break;
	case'a':
	case'A':
			if (tankobject[0].getTankDir() != 左)
			{
				tankobject[0].ClsObject();
				tankobject[0].setTankDir(左);
				tankobject[0].DrawObject();
			}
			else {
				tankobject[0].MoveTank();
			}
		break;
	case'd':
	case'D':
			if (tankobject[0].getTankDir() != 右)
			{
				tankobject[0].ClsObject();
				tankobject[0].setTankDir(右);
				tankobject[0].DrawObject();
			}
			else {
				tankobject[0].MoveTank();
			}
			break;
	case'f':case'F'://玩家一发射子弹,子弹的第一个坐标不能等于地图边框和铁墙
	
		if(bulletobject.getBulletisDie()==false)
			bulletobject = bulletobject.GreatBullet(tankobject[0], vectankobject);    //初始化玩家1的子弹
		
		break;
	//玩家二
	case'i':case'I':
		if (tankobject[1].getTankDir() != 上) {
					//擦除坦克
					tankobject[1].ClsObject();
					tankobject[1].setTankDir(上);//将坦克方向修改为上
					tankobject[1].DrawObject();
				}
				else {
					//tankobject.setTankDir(上);//方向一致就不用修改方向
					tankobject[1].MoveTank();
				}
				break;
	case'K':case'k':

			if (tankobject[1].getTankDir() != 下)
			{
				tankobject[1].ClsObject();
				tankobject[1].setTankDir(下);
				tankobject[1].DrawObject();
			}
			else {
				tankobject[1].MoveTank();
			}

			break;
	case'j':case'J':

		if (tankobject[1].getTankDir() != 左)
		{
			tankobject[1].ClsObject();
			tankobject[1].setTankDir(左);
			tankobject[1].DrawObject();
		}
		else {
			tankobject[1].MoveTank();
		}
		break;
	case'l':case'L':
			if (tankobject[1].getTankDir() != 右)
			{
				tankobject[1].ClsObject();
				tankobject[1].setTankDir(右);
				tankobject[1].DrawObject();
			}
			else {
				tankobject[1].MoveTank();
			}
			break;
	case 'p':case 'P':
		if (bulletobject.getBulletisDie() == false)
			bulletobject = bulletobject.GreatBullet(tankobject[1], vectankobject);    //初始化玩家1的子弹
		break;
	case 'g':case'G'://保存游戏
		SaveGame();
		MessageBox(NULL, "保存游戏成功", "退出", 0);
		
	}
	return true;
}

//////通过随机或A*移动敌方坦克
//bool CGameObject::MoveNPC()
//{
//	srand((unsigned)time(NULL));
//	//随机让敌军坦克开火
//
//	for (int i = 2; i < vectankobject.size(); i++) 
//	{
//		int dir = rand() % 4;    //随机给坦克方向，开火    /*/
//		int fire = rand() % 5;
//		vectankobject[i].setTankDir(dir);
//		switch (vectankobject[i].getTankDir())
//		{
//		case 上:
//			if (vectankobject[i].getTankDir() != 上) {
//				//擦除坦克
//				vectankobject[i].ClsObject();
//				vectankobject[i].setTankDir(上);//将坦克方向修改为上
//				vectankobject[i].DrawObject();
//			}
//			else {
//				vectankobject[i].MoveTank();
//			}
//			break;
//		case 下:
//			if (vectankobject[i].getTankDir() != 下)
//			{
//				vectankobject[i].ClsObject();
//				vectankobject[i].setTankDir(下);
//				vectankobject[i].DrawObject();
//			}
//			else {
//				vectankobject[i].MoveTank();
//			}
//			break;
//		case 左:
//			if (vectankobject[i].getTankDir() != 左)
//			{
//				vectankobject[i].ClsObject();
//				vectankobject[i].setTankDir(左);
//				vectankobject[i].DrawObject();
//			}
//			else {
//				vectankobject[i].MoveTank();
//			}
//			break;
//		case 右:
//			if (vectankobject[i].getTankDir() != 右)
//			{
//				vectankobject[i].ClsObject();
//				vectankobject[i].setTankDir(右);
//				vectankobject[i].DrawObject();
//			}
//			else {
//				vectankobject[i].MoveTank();
//			}
//			break;
//			//case 4://
//			//	//if (bulletobject.getBulletisDie() == false)
//			//	//	bulletobject = bulletobject.GreatBullet(vectankobject[i], vectankobject);    //初始化玩家1的子弹
//			////}
//			//break;
//		}
//		if (fire == 1) //开火
//		{
//				if (bulletobject.getBulletisDie() == false)
//				{
//					bulletobject = bulletobject.GreatBullet(vectankobject[i], vectankobject);    //初始化玩家1的子弹
//				}
//		}
//		
//	}
//	return true;
//}

////通过随机或A*移动敌方坦克
bool CGameObject::MoveNPC()
{
	srand((unsigned)time(NULL));
	//随机让敌军坦克开火

	for (int i = 2; i < vectankobject.size(); i++)
	{
		int dir = rand() % 4;    //随机给坦克方向，开火    /*/
		int fire = rand() % 5;
		vectankobject[i].setTankDir(dir);
		switch (vectankobject[i].getTankDir())
		{
		case 上:
			if (vectankobject[i].getTankDir() != 上) {
				//擦除坦克
				vectankobject[i].ClsObject();
				vectankobject[i].setTankDir(上);//将坦克方向修改为上
				vectankobject[i].DrawObject();
			}
			else {
				vectankobject[i].MoveTank();
			}
			break;
		case 下:
			if (vectankobject[i].getTankDir() != 下)
			{
				vectankobject[i].ClsObject();
				vectankobject[i].setTankDir(下);
				vectankobject[i].DrawObject();
			}
			else {
				vectankobject[i].MoveTank();
			}
			break;
		case 左:
			if (vectankobject[i].getTankDir() != 左)
			{
				vectankobject[i].ClsObject();
				vectankobject[i].setTankDir(左);
				vectankobject[i].DrawObject();
			}
			else {
				vectankobject[i].MoveTank();
			}
			break;
		case 右:
			if (vectankobject[i].getTankDir() != 右)
			{
				vectankobject[i].ClsObject();
				vectankobject[i].setTankDir(右);
				vectankobject[i].DrawObject();
			}
			else {
				vectankobject[i].MoveTank();
			}
			break;
			//case 4://
			//	//if (bulletobject.getBulletisDie() == false)
			//	//	bulletobject = bulletobject.GreatBullet(vectankobject[i], vectankobject);    //初始化玩家1的子弹
			////}
			//break;
		}
		if (fire == 1) //开火
		{
			if (bulletobject.getBulletisDie() == false)
			{
				bulletobject = bulletobject.GreatBullet(vectankobject[i], vectankobject);    //初始化玩家1的子弹
			}
		}

	}
	return true;
}