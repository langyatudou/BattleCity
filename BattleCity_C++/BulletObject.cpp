#include "BulletObject.h"
#include "GameObject.h"


CBulletObject::CBulletObject()
{
}


CBulletObject::~CBulletObject()
{
}

//画子弹
void CBulletObject::DrawObject() 
{
	if (m_nIsDie) {
		tempDraw.printChar(m_nPosX, m_nPosY, "⑥");
	}
}
//擦除控制台上子弹
void CBulletObject::ClsObject() {
	
	tempDraw.printChar(m_nPosX, m_nPosY, "  ");

}
void CBulletObject::ClsObject(int x, int y) {
	tempDraw.printChar(x, y, "  ");
}
//创建子弹(传入保存坦克信息的向量，主要用于坦克和子弹的碰撞
CBulletObject CBulletObject::GreatBullet(CTankObject tankobject, vector<CTankObject>&vectankobject) 
{
	//1.根据坦克坐标初始化子弹坐标，将纸子弹状态置为true,
	//根据方向确定子弹的位置
	CBulletObject bullet;
	bullet.m_nDir = tankobject.getTankDir();
	switch (bullet.m_nDir) 
	{
	case 上:
		bullet.m_nPosX = tankobject.getTankPosX();
		bullet.m_nPosY = tankobject.getTankPosY() - 2;   //子弹的位置为坦克的头的前一个位置
		bullet.m_Alignment = tankobject.getAlignment();   //获取是敌方还是友方阵营的子弹
		if (g_Map[bullet.m_nPosY][bullet.m_nPosX] == 地图边框||
			g_Map[bullet.m_nPosY][bullet.m_nPosX] == 铁墙) {
			bullet.m_nIsDie = false;
		}
		else {
			bullet.m_nIsDie = true;
		}
		break;
	case 下:
		bullet.m_nPosX = tankobject.getTankPosX();
		bullet.m_nPosY = tankobject.getTankPosY() + 2;
		bullet.m_Alignment = tankobject.getAlignment();
		if (g_Map[bullet.m_nPosY][bullet.m_nPosX] == 地图边框||
			g_Map[bullet.m_nPosY][bullet.m_nPosX] == 铁墙) {
			bullet.m_nIsDie = false;
		}
		else {
			bullet.m_nIsDie = true;
		}
		break;
	case 左:
		bullet.m_nPosX = tankobject.getTankPosX() - 2;
		bullet.m_nPosY = tankobject.getTankPosY();
		bullet.m_Alignment = tankobject.getAlignment();

		if (g_Map[bullet.m_nPosY][bullet.m_nPosX] == 地图边框||
			g_Map[bullet.m_nPosY][bullet.m_nPosX] == 铁墙) {
			bullet.m_nIsDie = false;
		}
		else {
			bullet.m_nIsDie = true;
		}
	
		break;
	case 右:
		bullet.m_nPosX = tankobject.getTankPosX() + 2;
		bullet.m_nPosY = tankobject.getTankPosY();
		bullet.m_Alignment = tankobject.getAlignment();
		if (g_Map[bullet.m_nPosY][bullet.m_nPosX] == 地图边框||
			g_Map[bullet.m_nPosY][bullet.m_nPosX] == 铁墙) {
			bullet.m_nIsDie = false;
		}
		else {
			bullet.m_nIsDie = true;
		}
		
		break;
	}
	return bullet;
}

////子弹碰撞检测
bool CBulletObject::canMoveBullet(CBulletObject&bulletobject, vector<CTankObject>&vectankobject)
{
	static int tempScore = 0;
	static unsigned int tempHP = 3;
	static unsigned int tempHP2 = 3;
	int tempX = m_nPosX;
	int tempY = m_nPosY;
	if (m_nDir == 上)
	{
		--tempY;
	}
	else if (m_nDir == 下)
	{
		++tempY;
	}
	else if (m_nDir == 左)
	{
		--tempX;
	}
	else if (m_nDir == 右)
	{
		++tempX;
	}
	for (int i = 0; i < vectankobject.size(); i++) {
		if (m_Alignment == 0)//己方阵营子弹
		{
			if (vectankobject[i].isTank(tempX,tempY)&& vectankobject[i].getAlignment()==1)//击中敌方坦克
			{
				vectankobject[i].setTankisDie(false);    //将被击中的坦克标记为死亡
				m_nIsDie = false;//将子弹标记为死亡
				tempScore += 10;  
				vectankobject[0].setTankScore(tempScore);    //增加积分
														//对死亡的坦克进行处理
				//1.擦除地图中的坦克
				vectankobject[i].CanCls(vectankobject[i].getTankPosX(), vectankobject[i].getTankPosY());
				//2.擦除坦克对象所有属性，不让该编号的坦克再移动  ------删除这个位置的坦克
				if (vectankobject[i].getTankisDie() == false) //如果对象死亡，删除对象
				{
					//3.擦除屏幕上的坦克
					vectankobject[i].ClsObject();
					//删除坦克对象
					vectankobject.erase(vectankobject.begin() + i);
				}

			}else if (vectankobject[i].isTank(tempX, tempY) && vectankobject[i].getAlignment() == 0)//友方坦克击中友方坦克*******
			{
				m_nIsDie = false;//将子弹标记为死亡
			}
		}
		else if (m_Alignment == 1)//敌方阵营子弹
		{
			if (vectankobject[i].isTank(tempX, tempY) && vectankobject[i].getAlignment() == 0)//击中己方坦克
			{
				//当被击中后生命值-1，当生命值为0时游戏结束
				//这里逻辑有问题，怎么才能算时玩家1被击中，不应该是I==0，理论上应该是子弹坐标等于坦克0的坐标
				if (i == 0) //玩家一被击中
				{
					tempHP -= 1;
					vectankobject[0].setTankBlood(tempHP);
				}
				else if(i == 1) {
					tempHP2 -= 1;
					vectankobject[1].setTankBlood(tempHP2);
				}
				m_nIsDie = false;

				if(vectankobject[0].getTankBlood()==false)//如果生命值为0，游戏结束
				{
					MessageBox(NULL, "游戏结束", "退出", 0);
					exit(0);//游戏结束
				}
				//}
			}//敌方坦克击中敌方坦克
			else if (vectankobject[i].isTank(tempX, tempY) && vectankobject[i].getAlignment() == 1)//****
			{
				m_nIsDie = false;
			}
		}
	}
	if (g_Map[tempY][tempX] == 铁墙 || g_Map[tempY][tempX] == 地图边框)
	{
		m_nIsDie = false;
		//ClsObject();
	}
	else if (g_Map[tempY][tempX] == 灰墙) {
		g_Map[tempY][tempX] = 空地;
		ClsObject(tempX, tempY);  //擦除地图灰墙
		m_nIsDie = false;
		//ClsObject();
	}
	else if(g_Map[tempY][tempX] == 基地)//基地被攻击，游戏结束
	{
		MessageBox(NULL, "游戏结束", "退出", 0);
		exit(0);
	}
	//ClsObject();
	return m_nIsDie;
}

//判断制单是否等于地图障碍物
//子弹地图障碍物检测
bool CBulletObject::isBlock(int x, int y)
{
	//m_nIsDie = true;
	if (g_Map[m_nPosY][m_nPosX] == 铁墙 || g_Map[m_nPosY][m_nPosX] == 地图边框)
	{
		m_nIsDie = false;
	}
	else if (g_Map[m_nPosY][m_nPosX] == 灰墙) {
		g_Map[m_nPosY][m_nPosX] = 空地;
		m_nIsDie = false;
	}
	return m_nIsDie;
}

//3.移动子弹
void CBulletObject::MoveObject() {
		//写一个判断能不能移动的函数
	
		int tempX, tempY;
		tempX = m_nPosX;
		tempY = m_nPosY;
		
		//现在假设能移动
		//擦除旧坐标
		if(isBlock(m_nPosX,m_nPosY)==true)
		ClsObject();
		if (m_nIsDie) {
			switch (m_nDir)
			{
			case 上:
				tempY--;
				break;
			case 下:
				tempY++;
				break;
			case 左:
				tempX--;
				break;
			case 右:
				tempX++;
				break;
			}

		m_nPosX = tempX;
		m_nPosY = tempY;
		DrawObject();
		}
		//能移动，为真,根据新坐标画出新子弹
		
	
}




