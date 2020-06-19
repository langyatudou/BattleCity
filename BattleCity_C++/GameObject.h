#pragma once
#include "DrawObject.h"
#include "MapObject.h"
#include "TankObject.h"
#include "BulletObject.h"
#include <vector>
#include <time.h>
using std::vector;
class CGameObject
{
public:
	CGameObject();
	~CGameObject();
public:
	/**************************************创建对象*************************************/
	//画图对象
	CDrawObject drawobject;
	//地图对象
	CMapObject mapobject;
	//定义坦克对象数组
	vector<CTankObject>vectankobject;     //用游戏类的初始化函数给坦克和子弹左做初始化
	//创建子弹对象
	CBulletObject bulletobject;
	/**************************************游戏菜单*************************************/
	////欢迎界面
	bool WelcomeUI(int indem_nPosX);
	//初始化地图
	void DrawMap();
	//打印游戏玩家信息菜单
	void printPlayerUI();
	//关卡菜单
	void ChoicLevelUI();
	//选择保存地图菜单
	void ChoiceSaveMapUI();

	//自定义地图菜单
	void EditMapUI();
	/**************************************文件操作*************************************/
	//文件读取-读取游戏地图
	bool ReadMap();
	//文件写入-保存游戏地图
	bool SaveMap();
	//保存游戏存档
	bool SaveGame();
	//读取游戏存档
	bool ReadGame();

	//1.将地图类的地图数组写入文件中去
public:
	////初始化玩家坦克信息
	bool InitPlayerTankInfo();
	//初始化Npc坦克
	bool InitNPCTankInfo();
	////通过键盘移动坦克
	bool MovesSelfAndALLY(vector<CTankObject>&tankobject);
	////通过随机或A*移动敌方坦克
	bool MoveNPC();
	//设置关卡
	int   getLevel() { return m_level; }
	void setLevel(int level) { m_level = level; }
	//设置光标
	void SetCusor() {
		HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
		SetConsoleMode(hStdin, 0xFFFFFFFF);
	}
	int NPCTankNum=5;      //设置电脑坦克数量
private:
	char m_buff[100];      //用一个5行的字符串保留5个游戏关卡文件名称
	int m_level = 0;       //游戏关卡
};

