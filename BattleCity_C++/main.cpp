#include <iostream>
#include<windows.h>
#pragma  comment(lib,"winmm.lib")
#include "BaseObject.h"
#include "DrawObject.h"
#include "MapObject.h"
#include "GameObject.h"
#include "TankObject.h"
#include <time.h>
int main() {
	//MessageBox(NULL, "保存游戏成功", "退出", 1);
	/**************************************初始化游戏界面************************************/
	int ch = 0;                            
	int nTime1 = clock();
	int nTime2 = 0;
	/*地方坦克休眠时间*/
	int nTime3 = clock();
	int nTime4 = 0;
	system("mode con cols=150 lines=50");   //设置控制台大小
	//1.欢迎界面，游戏选项
	CGameObject gameobject;                 //创建游戏对象
	gameobject.WelcomeUI(20);               //打印游戏欢迎菜单
	gameobject.mapobject.setMapValue();     //初始化地图边框    
    //用户选择项目
	scanf_s("%d", &ch);
	system("cls");
	int lv = 0;
	PlaySound("sound\\tank.wav", NULL, SND_ASYNC | SND_NODEFAULT| SND_LOOP);
	/*************************************************************************************/
	switch (ch)
	{
	case 1:
	/***************************************开始新游戏************************************/
		//开始新游戏  默认双人游戏
		//默认从第0张地图开始
		//如果需要完后边的关卡，需要调用游戏类的设置level函数进行设置
		gameobject.ChoicLevelUI();            //选择关卡
		system("cls");
		gameobject.ReadMap();                 //根据游戏类成员变量levle的值读取地图
		gameobject.DrawMap();  
		gameobject.InitPlayerTankInfo();      //初始化玩家坦克
		gameobject.InitNPCTankInfo();         //初始化敌军坦克
		for (int i = 0; i < gameobject.vectankobject.size(); i++)
		{
			gameobject.vectankobject[i].DrawObject();
		}
		while (1) {
			Sleep(20);
			//打印游戏玩家信息菜单
			gameobject.printPlayerUI();
			if (clock() - nTime1 >= 20) {
				nTime1 = clock();
				gameobject.MovesSelfAndALLY(gameobject.vectankobject); //控制玩家坦克
			}
			if (clock() - nTime2 >= 100)
			{
				nTime2 = clock();
				//移动子弹
				if (gameobject.bulletobject.getBulletisDie()) {
					//gameobject.bulletobject.DrawObject();

					if (gameobject.bulletobject.canMoveBullet(gameobject.bulletobject, gameobject.vectankobject))//能移动
						gameobject.bulletobject.MoveObject();
					else gameobject.bulletobject.ClsObject();
				}
			}//控制敌方坦克
			if (clock() - nTime3 >= 100)
			{
				nTime3 = clock();
				gameobject.MoveNPC();
			}if (clock() - nTime4 >= 00)
			{
				nTime4 = clock();
				if (gameobject.bulletobject.getBulletisDie()) {
					//gameobject.bulletobject.DrawObject();

					if (gameobject.bulletobject.canMoveBullet(gameobject.bulletobject, gameobject.vectankobject))
						gameobject.bulletobject.MoveObject();
					else gameobject.bulletobject.ClsObject();
				}
			}
		}
		break;
	/**************************************自定义游戏地图**********************************/
	case 2:
	{
		int tempch = 0;
		gameobject.mapobject.DrawMaprim();     //打印地图编辑边框
		gameobject.EditMapUI();				   //打印自定义游戏菜单
		gameobject.drawobject.MessageLoop();   //编辑自定义地图							   									
		gameobject.SetCusor();                 //设置打印显示
		printf("保存地图请按 1 ：");           //按1保存地图，否则不保存
		scanf_s("%d", &tempch);
		if (tempch == 1) {
			gameobject.ChoiceSaveMapUI();
			gameobject.SaveMap(); 
			MessageBox(NULL, "保存地图成功", "退出", 0);
		}else
		system("pause");
		break;
	}
	case 3:
	/**************************************读取游戏存档************************************/
		gameobject.ReadGame();
		gameobject.DrawMap();
		for (int i = 0; i < gameobject.vectankobject.size(); i++)
		{
			gameobject.vectankobject[i].DrawObject();
		}
		while (1) {
			Sleep(20);
			//打印游戏玩家信息菜单
			gameobject.printPlayerUI();
			if (clock() - nTime1 >= 20) {
				nTime1 = clock();
				gameobject.MovesSelfAndALLY(gameobject.vectankobject); //控制玩家坦克
			}
			if (clock() - nTime2 >= 100)
			{
				nTime2 = clock();
				//移动子弹
				if (gameobject.bulletobject.getBulletisDie())//如果创建子弹成功----》不等于铁墙和地图边框
				{
					//gameobject.bulletobject.DrawObject();

					if (gameobject.bulletobject.canMoveBullet(gameobject.bulletobject, gameobject.vectankobject))//m_isdie!=false能移动
						gameobject.bulletobject.MoveObject();
					else gameobject.bulletobject.ClsObject();//擦除旧坐标
				}
			}//控制敌方坦克
			if (clock() - nTime3 >= 100)
			{
				nTime3 = clock();
				gameobject.MoveNPC();
			}if (clock() - nTime4 >= 100)
			{
				nTime4 = clock();
				if (gameobject.bulletobject.getBulletisDie()) {
					//gameobject.bulletobject.DrawObject();

					if (gameobject.bulletobject.canMoveBullet(gameobject.bulletobject, gameobject.vectankobject))
						gameobject.bulletobject.MoveObject();
					else gameobject.bulletobject.ClsObject();
				}
			}
		}
		break;
	case 4:
	/****************************************退出游戏**************************************/
		MessageBox(NULL, "退出游戏", "退出", 0);
		break;
	default:
		break;
	}
	system("pause");

	return 0;
}
