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
	//MessageBox(NULL, "������Ϸ�ɹ�", "�˳�", 1);
	/**************************************��ʼ����Ϸ����************************************/
	int ch = 0;                            
	int nTime1 = clock();
	int nTime2 = 0;
	/*�ط�̹������ʱ��*/
	int nTime3 = clock();
	int nTime4 = 0;
	system("mode con cols=150 lines=50");   //���ÿ���̨��С
	//1.��ӭ���棬��Ϸѡ��
	CGameObject gameobject;                 //������Ϸ����
	gameobject.WelcomeUI(20);               //��ӡ��Ϸ��ӭ�˵�
	gameobject.mapobject.setMapValue();     //��ʼ����ͼ�߿�    
    //�û�ѡ����Ŀ
	scanf_s("%d", &ch);
	system("cls");
	int lv = 0;
	PlaySound("sound\\tank.wav", NULL, SND_ASYNC | SND_NODEFAULT| SND_LOOP);
	/*************************************************************************************/
	switch (ch)
	{
	case 1:
	/***************************************��ʼ����Ϸ************************************/
		//��ʼ����Ϸ  Ĭ��˫����Ϸ
		//Ĭ�ϴӵ�0�ŵ�ͼ��ʼ
		//�����Ҫ���ߵĹؿ�����Ҫ������Ϸ�������level������������
		gameobject.ChoicLevelUI();            //ѡ��ؿ�
		system("cls");
		gameobject.ReadMap();                 //������Ϸ���Ա����levle��ֵ��ȡ��ͼ
		gameobject.DrawMap();  
		gameobject.InitPlayerTankInfo();      //��ʼ�����̹��
		gameobject.InitNPCTankInfo();         //��ʼ���о�̹��
		for (int i = 0; i < gameobject.vectankobject.size(); i++)
		{
			gameobject.vectankobject[i].DrawObject();
		}
		while (1) {
			Sleep(20);
			//��ӡ��Ϸ�����Ϣ�˵�
			gameobject.printPlayerUI();
			if (clock() - nTime1 >= 20) {
				nTime1 = clock();
				gameobject.MovesSelfAndALLY(gameobject.vectankobject); //�������̹��
			}
			if (clock() - nTime2 >= 100)
			{
				nTime2 = clock();
				//�ƶ��ӵ�
				if (gameobject.bulletobject.getBulletisDie()) {
					//gameobject.bulletobject.DrawObject();

					if (gameobject.bulletobject.canMoveBullet(gameobject.bulletobject, gameobject.vectankobject))//���ƶ�
						gameobject.bulletobject.MoveObject();
					else gameobject.bulletobject.ClsObject();
				}
			}//���Ƶз�̹��
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
	/**************************************�Զ�����Ϸ��ͼ**********************************/
	case 2:
	{
		int tempch = 0;
		gameobject.mapobject.DrawMaprim();     //��ӡ��ͼ�༭�߿�
		gameobject.EditMapUI();				   //��ӡ�Զ�����Ϸ�˵�
		gameobject.drawobject.MessageLoop();   //�༭�Զ����ͼ							   									
		gameobject.SetCusor();                 //���ô�ӡ��ʾ
		printf("�����ͼ�밴 1 ��");           //��1�����ͼ�����򲻱���
		scanf_s("%d", &tempch);
		if (tempch == 1) {
			gameobject.ChoiceSaveMapUI();
			gameobject.SaveMap(); 
			MessageBox(NULL, "�����ͼ�ɹ�", "�˳�", 0);
		}else
		system("pause");
		break;
	}
	case 3:
	/**************************************��ȡ��Ϸ�浵************************************/
		gameobject.ReadGame();
		gameobject.DrawMap();
		for (int i = 0; i < gameobject.vectankobject.size(); i++)
		{
			gameobject.vectankobject[i].DrawObject();
		}
		while (1) {
			Sleep(20);
			//��ӡ��Ϸ�����Ϣ�˵�
			gameobject.printPlayerUI();
			if (clock() - nTime1 >= 20) {
				nTime1 = clock();
				gameobject.MovesSelfAndALLY(gameobject.vectankobject); //�������̹��
			}
			if (clock() - nTime2 >= 100)
			{
				nTime2 = clock();
				//�ƶ��ӵ�
				if (gameobject.bulletobject.getBulletisDie())//��������ӵ��ɹ�----����������ǽ�͵�ͼ�߿�
				{
					//gameobject.bulletobject.DrawObject();

					if (gameobject.bulletobject.canMoveBullet(gameobject.bulletobject, gameobject.vectankobject))//m_isdie!=false���ƶ�
						gameobject.bulletobject.MoveObject();
					else gameobject.bulletobject.ClsObject();//����������
				}
			}//���Ƶз�̹��
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
	/****************************************�˳���Ϸ**************************************/
		MessageBox(NULL, "�˳���Ϸ", "�˳�", 0);
		break;
	default:
		break;
	}
	system("pause");

	return 0;
}
