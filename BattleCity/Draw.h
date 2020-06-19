#pragma once
#include "Data.h"



/*画地图*/
void DrawMap();
/*初始化坦克坐标*/
void initTank(TANK*ptank,int,int,int);
/*画出坦克*/
void DrawTank(TANK*ptank);
/*擦除坦克*/
void WipeTank(TANK*ptank);
/*移动坦克*/
int moveTank(TANK*ptank);
/*控制坦克*/
void KeyDown(TANK*ptank);
/*控制敌方坦克*/
void KeyDownFoe(TANK*ptank);


/*初始化子弹*/
void InitBullet(TANK*ptank);
/*画出子弹*/
void DrawBullet(TANK*ptank);
/*擦除子弹*/
int WipeBullet(TANK*pantk);
/*移动子弹*/
int MoveBullet(TANK*ptank);
/*控制子弹*/
/*void KeyDownBullet(BULLET*pbullet, TANK(*ptank)[3]);*/


//读取坦克图片
void readTankPicture();
//打印坦克图片
void PrintPicture(char (*g_TankPicture)[141]);
//打印游戏菜单
void PrintGameMenu(char sel);
//游戏讲解
void GameSpeak();
