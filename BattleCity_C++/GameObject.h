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
	/**************************************��������*************************************/
	//��ͼ����
	CDrawObject drawobject;
	//��ͼ����
	CMapObject mapobject;
	//����̹�˶�������
	vector<CTankObject>vectankobject;     //����Ϸ��ĳ�ʼ��������̹�˺��ӵ�������ʼ��
	//�����ӵ�����
	CBulletObject bulletobject;
	/**************************************��Ϸ�˵�*************************************/
	////��ӭ����
	bool WelcomeUI(int indem_nPosX);
	//��ʼ����ͼ
	void DrawMap();
	//��ӡ��Ϸ�����Ϣ�˵�
	void printPlayerUI();
	//�ؿ��˵�
	void ChoicLevelUI();
	//ѡ�񱣴��ͼ�˵�
	void ChoiceSaveMapUI();

	//�Զ����ͼ�˵�
	void EditMapUI();
	/**************************************�ļ�����*************************************/
	//�ļ���ȡ-��ȡ��Ϸ��ͼ
	bool ReadMap();
	//�ļ�д��-������Ϸ��ͼ
	bool SaveMap();
	//������Ϸ�浵
	bool SaveGame();
	//��ȡ��Ϸ�浵
	bool ReadGame();

	//1.����ͼ��ĵ�ͼ����д���ļ���ȥ
public:
	////��ʼ�����̹����Ϣ
	bool InitPlayerTankInfo();
	//��ʼ��Npc̹��
	bool InitNPCTankInfo();
	////ͨ�������ƶ�̹��
	bool MovesSelfAndALLY(vector<CTankObject>&tankobject);
	////ͨ�������A*�ƶ��з�̹��
	bool MoveNPC();
	//���ùؿ�
	int   getLevel() { return m_level; }
	void setLevel(int level) { m_level = level; }
	//���ù��
	void SetCusor() {
		HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
		SetConsoleMode(hStdin, 0xFFFFFFFF);
	}
	int NPCTankNum=5;      //���õ���̹������
private:
	char m_buff[100];      //��һ��5�е��ַ�������5����Ϸ�ؿ��ļ�����
	int m_level = 0;       //��Ϸ�ؿ�
};

