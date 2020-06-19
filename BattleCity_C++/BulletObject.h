#pragma once
#include "TankObject.h"
#include "DrawObject.h"
class CBulletObject
{
public:
	CBulletObject();
	~CBulletObject();

public:
	CDrawObject tempDraw;
	void DrawObject();       //画子弹
	//擦除控制台上子弹
	void ClsObject();
	void ClsObject(int x,int y);
	void MoveObject();
	//创建子弹(传入保存坦克信息的向量，主要用于坦克和子弹的碰撞
	CBulletObject GreatBullet(CTankObject tankobject,//发射子弹的坦克
		vector<CTankObject>&vectankobject);//
	//子弹碰撞检测
	bool canMoveBullet(CBulletObject&bulletobject,vector<CTankObject>&vectankobject);
	//子弹地图障碍物检测
	bool isBlock(int x, int y);

	//创建一组函数用于返回子弹的属性，子弹创建时需要用到这些属性
	/***************************得到子弹属性****************************/
	bool getBulletisDie() { return m_nIsDie; }
	int getAlignment() { return m_Alignment; }
	int getBulletPosX() { return m_nPosX; }
	int getBulletPosY() { return m_nPosY; }
	int getBulletDir() { return m_nDir; }
	int getBulletType() { return m_nType; }
	int getBulletATK() { return m_nATK; }
	/***************************设置子弹属性****************************/
	void setBulletisDie(bool IsDie) { m_nIsDie = IsDie; }
	void setAlignment(int Alignment) { m_Alignment = Alignment; }
	void setBulletPosX(int nPosX) { m_nPosX = nPosX; }
	void setBulletPosY(int nPosY) { m_nPosY = nPosY; }
	void setBulletDir(int nDir) { m_nDir = nDir; }
	void setBulletType(int nType) { m_nType = nType; }
	void setBulletATK(int ATK) { m_nATK = ATK; }
private:
	bool m_nIsDie;            //是否死亡
	int m_Alignment;          //所属阵营
	int m_nPosX;              //坐标
	int m_nPosY;              //坐标
	int m_nDir;               //方向
	int m_nType;              //类型  ，敌我双方
	int m_nATK;               //攻击力
	
};

