#pragma once
#include "Data.h"



/*����ͼ*/
void DrawMap();
/*��ʼ��̹������*/
void initTank(TANK*ptank,int,int,int);
/*����̹��*/
void DrawTank(TANK*ptank);
/*����̹��*/
void WipeTank(TANK*ptank);
/*�ƶ�̹��*/
int moveTank(TANK*ptank);
/*����̹��*/
void KeyDown(TANK*ptank);
/*���Ƶз�̹��*/
void KeyDownFoe(TANK*ptank);


/*��ʼ���ӵ�*/
void InitBullet(TANK*ptank);
/*�����ӵ�*/
void DrawBullet(TANK*ptank);
/*�����ӵ�*/
int WipeBullet(TANK*pantk);
/*�ƶ��ӵ�*/
int MoveBullet(TANK*ptank);
/*�����ӵ�*/
/*void KeyDownBullet(BULLET*pbullet, TANK(*ptank)[3]);*/


//��ȡ̹��ͼƬ
void readTankPicture();
//��ӡ̹��ͼƬ
void PrintPicture(char (*g_TankPicture)[141]);
//��ӡ��Ϸ�˵�
void PrintGameMenu(char sel);
//��Ϸ����
void GameSpeak();
