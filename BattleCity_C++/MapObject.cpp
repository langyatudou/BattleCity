#include "MapObject.h"
#include "DrawObject.h"
#include "GameObject.h"

int g_Map[MAP_Y][MAP_X] = {空地};
char g_Mapname[5][100];//  
CMapObject::CMapObject()
{
}

CMapObject::~CMapObject()
{
}

//设置地图中指定位置的数据
bool CMapObject::setMapValue() 
{
	//1.设置地图边框数据
	for (int i = 0; i <MAP_Y; i++)
	{
		for (int j = 0; j <MAP_X; j++)
		{
			if (i == 0 || j == 0 || i == MAP_X-1 || j == MAP_Y-1)
			{
				g_Map[i][j] =地图边框;     //将地图四周设置成地图边框数据
			}
		}
	}
	
	return true;
}
 //获取地图指定位置的数据
int CMapObject::getMapValue(int nPosX, int nPOSy) 
{
	int nValue = g_Map[nPOSy][nPosX];   //获取地图中指定坐标的
	return nValue;

}

//打印地图边框
 bool CMapObject::DrawMaprim() 
 {
	 CDrawObject drawobject;    //画
	 for (int i = 0; i < MAP_Y; i++)
	 {
		 for (int j = 0; j < MAP_X; j++)
		 {
			 if(g_Map[i][j]==地图边框)
			 {
				drawobject.printChar(j, i, "■");
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
	 return true;
}

