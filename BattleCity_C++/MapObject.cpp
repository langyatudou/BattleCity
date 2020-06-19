#include "MapObject.h"
#include "DrawObject.h"
#include "GameObject.h"

int g_Map[MAP_Y][MAP_X] = {�յ�};
char g_Mapname[5][100];//  
CMapObject::CMapObject()
{
}

CMapObject::~CMapObject()
{
}

//���õ�ͼ��ָ��λ�õ�����
bool CMapObject::setMapValue() 
{
	//1.���õ�ͼ�߿�����
	for (int i = 0; i <MAP_Y; i++)
	{
		for (int j = 0; j <MAP_X; j++)
		{
			if (i == 0 || j == 0 || i == MAP_X-1 || j == MAP_Y-1)
			{
				g_Map[i][j] =��ͼ�߿�;     //����ͼ�������óɵ�ͼ�߿�����
			}
		}
	}
	
	return true;
}
 //��ȡ��ͼָ��λ�õ�����
int CMapObject::getMapValue(int nPosX, int nPOSy) 
{
	int nValue = g_Map[nPOSy][nPosX];   //��ȡ��ͼ��ָ�������
	return nValue;

}

//��ӡ��ͼ�߿�
 bool CMapObject::DrawMaprim() 
 {
	 CDrawObject drawobject;    //��
	 for (int i = 0; i < MAP_Y; i++)
	 {
		 for (int j = 0; j < MAP_X; j++)
		 {
			 if(g_Map[i][j]==��ͼ�߿�)
			 {
				drawobject.printChar(j, i, "��");
			 }
		}
	}
	 //��ӡ��Χǽ��
	 drawobject.printChar(MAP_X, 0, "����������������������������������");  //17
	 drawobject.printChar(MAP_X, MAP_Y / 2, "����������������������������������");  //17
	 drawobject.printChar(MAP_X, MAP_Y - 1, "����������������������������������");  //17
	 for (int i = 0; i < MAP_Y; i++) {
		 drawobject.printChar(MAP_X + 17, i, "��");
	 }
	 return true;
}

