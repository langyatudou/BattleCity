#pragma once
#include <windows.h>

/*物品颜色宏*/
#define COLOR_YELLOW 0x0e
#define COLOR_GREEN 0x0b
#define COLOR_WHITE_1 0x07
#define COLOR_RED 0x04
#define COLOR_BLUE 0x09
#define GRAY 0x08   //灰色

/*地图的最大宽度和高度*/
#define MAP_X 48
#define MAP_Y 48
/*地图上各种物品的宏*/
#define LUNG 0          //空地
#define SIGN_TANK1 1    //我的坦克
#define SIGN_TANK2 2    //友军坦克
#define SIGN_TANK3 3    //敌军坦克3
#define SIGN_TANK4 4    //敌军坦克4
#define SIGN_TANK5 5    //敌军坦克5

#define SIGN_WALL0 10    //铁墙
#define SIGN_WALL1 11    //土墙    //灰色的墙壁
#define SIGN_BASE  12    //大本营
#define SIGN_WATER 20     //蓝色的水
#define SIGN_GRASS 21    //草地

/*
// 当前敌军坦克总数
*/
#define FOETANK_AMOUNT 3

/*坦克的方向*/
#define 上 0
#define 下 1
#define 左 2
#define 右 3

/*坦克中心点的初始化坐标*/
#define CENTRE_X0 12       
#define CENTRE_Y0 44    
//新思路，直接将坦克一个中心点存进地图里
//移动坦克的时候，直接去地图里g_Map修改数据

/*声明一个子弹结构体*/
typedef struct _BULLET {
	COORD pos;
	int speed;
	int dir;      //子弹的方向
}BULLET, *PBULLET;

/*坦克结构体声明*/
typedef struct _TANK {
	COORD tank[3][3];   //坦克的坐标
	BULLET bullet;      //坦克的子弹
	int hp;             //坦克的生命值
	int coclor;			//坦克的颜色
	int speed;          //坦克的移动速度
	int g_dir ;         //坦克的方向
	int fire;          //发射子弹
	bool flagbullet;    //判断子弹是否在发射中
}TANK, *PTANK;

/*声明墙的结构体*/
typedef struct _WALL {
	int x;
	int y;
	int coclor;
}WALL,*PWALL;

/*声明一个地图*/
extern int g_Map[MAP_Y][MAP_X];
/*声明我自己的坦克*/
extern TANK mytank;
/*声明一个我自己的坦克子弹，我自己等价于坦克1*/
extern BULLET bullet1;

/*地方坦克3*/
extern TANK tank3;
extern BULLET bullet3;

//存放坦克图片
extern char g_TankPicture[30][141];