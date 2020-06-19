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
	void DrawObject();       //���ӵ�
	//��������̨���ӵ�
	void ClsObject();
	void ClsObject(int x,int y);
	void MoveObject();
	//�����ӵ�(���뱣��̹����Ϣ����������Ҫ����̹�˺��ӵ�����ײ
	CBulletObject GreatBullet(CTankObject tankobject,//�����ӵ���̹��
		vector<CTankObject>&vectankobject);//
	//�ӵ���ײ���
	bool canMoveBullet(CBulletObject&bulletobject,vector<CTankObject>&vectankobject);
	//�ӵ���ͼ�ϰ�����
	bool isBlock(int x, int y);

	//����һ�麯�����ڷ����ӵ������ԣ��ӵ�����ʱ��Ҫ�õ���Щ����
	/***************************�õ��ӵ�����****************************/
	bool getBulletisDie() { return m_nIsDie; }
	int getAlignment() { return m_Alignment; }
	int getBulletPosX() { return m_nPosX; }
	int getBulletPosY() { return m_nPosY; }
	int getBulletDir() { return m_nDir; }
	int getBulletType() { return m_nType; }
	int getBulletATK() { return m_nATK; }
	/***************************�����ӵ�����****************************/
	void setBulletisDie(bool IsDie) { m_nIsDie = IsDie; }
	void setAlignment(int Alignment) { m_Alignment = Alignment; }
	void setBulletPosX(int nPosX) { m_nPosX = nPosX; }
	void setBulletPosY(int nPosY) { m_nPosY = nPosY; }
	void setBulletDir(int nDir) { m_nDir = nDir; }
	void setBulletType(int nType) { m_nType = nType; }
	void setBulletATK(int ATK) { m_nATK = ATK; }
private:
	bool m_nIsDie;            //�Ƿ�����
	int m_Alignment;          //������Ӫ
	int m_nPosX;              //����
	int m_nPosY;              //����
	int m_nDir;               //����
	int m_nType;              //����  ������˫��
	int m_nATK;               //������
	
};

