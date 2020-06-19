#include "TankObject.h"
#include "DrawObject.h"
#include "MapObject.h"

CTankObject::CTankObject()
{
}


CTankObject::~CTankObject()
{
}
CDrawObject tempDraw;
//根据中心点坐标绘制坦克
void CTankObject::DrawObject()
{
	int x = m_nPosX;
	int y = m_nPosY;
	switch (m_nDir)
	{
	case 上:
		tempDraw.printChar(x - 1, y - 1, "  ■  ", m_nCoclor);
		tempDraw.printChar(x - 1, y,     "■■■", m_nCoclor);
		tempDraw.printChar(x - 1, y + 1, "■  ■", m_nCoclor);
		break;
	case 下:
		tempDraw.printChar(x - 1, y - 1, "■  ■", m_nCoclor);
		tempDraw.printChar(x - 1, y,     "■■■", m_nCoclor);
		tempDraw.printChar(x - 1, y + 1, "  ■  ", m_nCoclor);
		break;
	case 左:
		tempDraw.printChar(x - 1, y - 1, "  ■■", m_nCoclor);
		tempDraw.printChar(x - 1, y,     "■■  ", m_nCoclor);
		tempDraw.printChar(x - 1, y + 1, "  ■■", m_nCoclor);
		break;
	case 右:
		tempDraw.printChar(x - 1, y - 1, "■■  ", m_nCoclor);
		tempDraw.printChar(x - 1, y,     "  ■■", m_nCoclor);
		tempDraw.printChar(x - 1, y + 1, "■■  ", m_nCoclor);
		break;
	default:
		break;
	}

}
//擦除坦克
void CTankObject::ClsObject() {
	int x = m_nPosX;
	int y = m_nPosY;
	tempDraw.printChar(x-1, y - 1, "      ");
	tempDraw.printChar(x - 1, y,"      ");
	tempDraw.printChar(x - 1, y + 1, "      ");
}


bool CTankObject::CanMove(int X, int Y) {
	//先判断方向
	//根据方向，判断头前是否右障碍物
	switch (m_nDir) {
	case 上:
		for (int j = 0; j < 3; j++) {
			if (g_Map[Y - 1][X - 1 + j] == 地图边框 ||
				g_Map[Y - 1][X - 1 + j] == 灰墙 ||
				g_Map[Y - 1][X - 1 + j] == 铁墙 ||
				g_Map[Y - 1][X - 1 + j] == 基地||
				g_Map[Y - 1][X - 1 + j] == 坦克1||
				g_Map[Y - 1][X - 1 + j] == NPC坦克||
				g_Map[Y - 1][X - 1 + j] == 河流)
			{
				return false;
			}
		}
		break;
	case 下:
		for (int j = 0; j < 3; j++) {
			if (g_Map[Y + 1][X - 1 + j] == 地图边框 ||
				g_Map[Y + 1][X - 1 + j] == 灰墙 ||
				g_Map[Y + 1][X - 1 + j] == 铁墙 ||
				g_Map[Y + 1][X - 1 + j] == 基地||
				g_Map[Y + 1][X - 1 + j] == 坦克1||
				g_Map[Y + 1][X - 1 + j] == NPC坦克||
				g_Map[Y + 1][X - 1 + j] == 河流)
			{
				return false;
			}
		}
		break;
	case 左:
		for (int j = 0; j < 3; j++) {
			if (g_Map[Y -1+ j][X - 1] == 地图边框 ||
				g_Map[Y -1+ j][X - 1] == 灰墙 ||
				g_Map[Y -1+ j][X - 1] == 铁墙 ||
				g_Map[Y -1+ j][X - 1] == 基地||
				g_Map[Y -1+ j][X - 1] == 坦克1||
				g_Map[Y - 1 + j][X - 1] == NPC坦克||
				g_Map[Y - 1 + j][X - 1] == 河流)
			{
				return false;
			}
		}
		break;
	case 右:
		for (int j = 0; j < 3; j++) {
			if (g_Map[Y - 1 + j][X + 1] == 地图边框 ||
				g_Map[Y - 1 + j][X + 1] == 灰墙 ||
				g_Map[Y - 1 + j][X + 1] == 铁墙 ||
				g_Map[Y - 1 + j][X + 1] == 基地||
				g_Map[Y - 1 + j][X + 1] == 坦克1||
				g_Map[Y - 1 + j][X + 1] == NPC坦克||
				g_Map[Y - 1 + j][X + 1] == 河流)
			{
				return false;
			}
		}
		break;
	}
	return true;   //可以移动
}
//3*3写进地图
bool CTankObject::CanWrite(int X, int Y) {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//如果移动后的坦克坐标等于草丛，就不将坦克写进地图
			if(g_Map[Y][X]!=草地)/*test*/
			g_Map[Y - 1 + i][X - 1 + j] = m_nType;  //让地图等于当前的坦克类型
		}
	}
	return false;
}
//擦除地图中的数据
bool CTankObject::CanCls(int X, int Y) {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if(g_Map[Y][X]!=草地)
			g_Map[Y - 1 + i][X - 1 + j] =空地; 
		}
	}
	return true;
}

//3*3体积判断
bool CTankObject::isTank(int x, int y)
{
	if (x >= m_nPosX - 1 && x <= m_nPosX + 1) {
		if (y >= m_nPosY - 1 && y <= m_nPosY + 1) {
			return true;
		}
		return false;
	}
	return false;
}
	
////移动坦克
//void CTankObject::MoveTank(vector<CTankObject>&tankobject) 
//{
//	for (int i = 0; i < tankobject.size(); i++) {
//		int tempX = tankobject[i].getTankPosX();
//		int tempY = tankobject[i].getTankPosY();
//		int nDir = tankobject[i].getTankDir();   //获取坦克的方向
//		switch (nDir)
//		{
//		case 上:
//			//判断
//			tempY--;
//			if (CanMove(tempX, tempY) == true) //判断能不能移动
//			{
//				ClsObject();//清除旧的坦克
//				m_nPosY = tempY;//获取新坐标
//				DrawObject();   //根据新坐标画出坦克
//			}
//			break;
//		case 下:
//			tempY++;
//			if (CanMove(tempX, tempY) == true) {
//				ClsObject();//清除旧的坦克
//				m_nPosY = tempY;//获取新坐标
//				DrawObject();   //根据新坐标画出坦克
//			}
//			break;
//		case 左:
//			tempX--;
//			if (CanMove(tempX, tempY) == true) {
//				ClsObject();//清除旧的坦克
//				m_nPosX = tempX;//获取新坐标
//				DrawObject();   //根据新坐标画出坦克
//			}
//			break;
//		case 右:
//			tempX++;
//			if (CanMove(tempX, tempY) == true) {
//				ClsObject();//清除旧的坦克
//				m_nPosX = tempX;//获取新坐标
//				DrawObject();   //根据新坐标画出坦克
//				break;
//			}
//
//		}
//	}
//}
//移动坦克
//void CTankObject::MoveTank()
//{
//	
//	//定义中间变量
//	//移动
//	//擦除旧坐标坐标
//	//把新坐标写进去
//	int tempX = m_nPosX;
//	int tempY = m_nPosY;
//	int nDir = m_nDir;   //获取坦克的方向
//	//1.移动之前判断3*3的坐标等不等于地图中的障碍物，如果不等，写进去
//	//擦除
//	CanCls(m_nPosX, m_nPosY);
//	CanWrite(tempX,tempY);//将坐标写进地图
//	
//		switch (nDir)
//		{
//		case 上:
//			tempY--;
//			if (CanMove(tempX, tempY) == true) //判断能不能移动
//			{
//				//1.移动之后，擦除地图旧坦克
//				CanCls(m_nPosX, m_nPosY);
//				//2.将新坦克写进地图
//				CanWrite(tempX, tempY);
//				ClsObject();//清除旧的坦克
//				m_nPosY = tempY;//获取新坐标
//				
//				DrawObject();   //根据新坐标画出坦克
//			}
//			break;
//		case 下:
//			tempY++;
//			if (CanMove(tempX, tempY) == true) {
//				//1.移动之后，擦除地图旧坦克
//				CanCls(m_nPosX, m_nPosY);
//				//2.将新坦克写进地图
//				CanWrite(tempX, tempY);
//
//				ClsObject();//清除旧的坦克
//				m_nPosY = tempY;//获取新坐标
//				DrawObject();   //根据新坐标画出坦克
//			}
//			break;
//		case 左:
//			tempX--;
//			if (CanMove(tempX, tempY) == true) {
//				//1.移动之后，擦除地图旧坦克
//				CanCls(m_nPosX, m_nPosY);
//				//2.将新坦克写进地图
//				CanWrite(tempX, tempY);
//
//				ClsObject();//清除旧的坦克
//				m_nPosX = tempX;//获取新坐标
//				DrawObject();   //根据新坐标画出坦克
//			}
//			break;
//		case 右:
//			tempX++;
//			if (CanMove(tempX, tempY) == true) {
//				//1.移动之后，擦除地图旧坦克
//				CanCls(m_nPosX, m_nPosY);
//				//2.将新坦克写进地图
//				CanWrite(tempX, tempY);
//
//				ClsObject();//清除旧的坦克
//				m_nPosX = tempX;//获取新坐标
//				DrawObject();   //根据新坐标画出坦克
//				break;
//			}
//
//		}
//	}
void CTankObject::MoveTank()
{
	//定义中间变量
	//移动
	//擦除旧坐标坐标
	//把新坐标写进去
	int tempX = m_nPosX;
	int tempY = m_nPosY;
	int nDir = m_nDir;   //获取坦克的方向
	 //1.移动之前判断3*3的坐标等不等于地图中的障碍物，如果不等，写进去
	CanCls(m_nPosX, m_nPosY);
	CanWrite(tempX, tempY);//将坐标写进地图
	switch (nDir)
	{
	case 上:
		tempY--;
		if (CanMove(tempX, tempY) == true) //判断能不能移动
		{
			//1.移动之后，擦除地图中旧坦克
			CanCls(m_nPosX, m_nPosY);
			//2.将新坦克写进地图
			CanWrite(tempX, tempY);

			//新坐标等于草丛就不擦
			if(g_Map[tempY-1][tempX]!=草地)
			ClsObject();//清除旧的坦克
			m_nPosY = tempY;//获取新坐标

			if (g_Map[tempY-1][tempX] != 草地)
			DrawObject();   //根据新坐标画出坦克
		}
		break;
	case 下:
		tempY++;
		if (CanMove(tempX, tempY) == true) {
			//1.移动之后，擦除地图旧坦克
			CanCls(m_nPosX, m_nPosY);
			//2.将新坦克写进地图
			CanWrite(tempX, tempY);
			if (g_Map[tempY+1][tempX] != 草地)
			ClsObject();//清除旧的坦克
			m_nPosY = tempY;//获取新坐标
			if (g_Map[tempY+1][tempX] != 草地)
			DrawObject();   //根据新坐标画出坦克
		}
		break;
	case 左:
		tempX--;
		if (CanMove(tempX, tempY) == true) {
			//1.移动之后，擦除地图旧坦克
			CanCls(m_nPosX, m_nPosY);
			//2.将新坦克写进地图
			CanWrite(tempX, tempY);
			if (g_Map[tempY][tempX-1] != 草地)
			ClsObject();//清除旧的坦克
			m_nPosX = tempX;//获取新坐标
			if (g_Map[tempY][tempX-1] != 草地)
			DrawObject();   //根据新坐标画出坦克
		}
		break;
	case 右:
		tempX++;
		if (CanMove(tempX, tempY) == true) {
			//1.移动之后，擦除地图旧坦克
			CanCls(m_nPosX, m_nPosY);
			//2.将新坦克写进地图
			CanWrite(tempX, tempY);
			if (g_Map[tempY][tempX+1] != 草地)
			ClsObject();//清除旧的坦克
			m_nPosX = tempX;//获取新坐标
			if (g_Map[tempY][tempX+1] != 草地)
			DrawObject();   //根据新坐标画出坦克
			break;
		}

	}
}