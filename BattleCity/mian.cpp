
#include "API.h"
#include "Draw.h"
#include "Data.h"
#include "Judge.h"
//1.win32api
//�˵�
//2.map
//3tank
//4.zitan

//��ͼ�и��������ͼ��   ��   ��ɫ�Ĵ�����ǽ         ����ɫ�Ĵ�����ǽ    ��ɫ�ĺ�����     ���ء�    �ݵب�

int main()
{
	//DrawMap();
	/********************��ʼ����Ϸ����***********************/
	/*ʹ���¼����ģ����߳�*/
	int nTime1 = clock();
	int nTime2 = 0;
	/*�ط�̹������ʱ��*/
	int nTime3 = clock();
	int nTime4 = 0;
	/*��ʼ�����1��̹��*/
	PTANK ptank = &mytank;
	int InitTank1_x = CENTRE_X0;    //�ҵ�̹�˳�ʼ������
	int InitTank1_y = CENTRE_Y0;
	int IniTank1_Coclor = COLOR_YELLOW;   //̹��1����ɫ
	/*��ʼ��̹��3*/
	PTANK ptank3 = &tank3;
	int InitTank3_x = 3;    //̹��3��ʼ������
	int InitTank3_y = 3;
	int IniTank3_Coclor = COLOR_RED;   //̹��3����ɫ
	initTank(ptank, InitTank1_x, InitTank1_y, IniTank1_Coclor);
	initTank(&tank3, InitTank3_x, InitTank3_y, IniTank3_Coclor);
	/**********************��Ϸѡ�����***************************/
	int nCh = 0;
	readTankPicture();
	PrintPicture(g_TankPicture);
	PrintGameMenu(0);
	nCh =MessageLoop();    //ͨ������ʹ���������ķ���ֵ������Ϸѡ��ﵽ��ʹ��scanfd Ч��
	//scanf_s("%c", &nCh, 1);
	system("cls");
	switch (nCh)
	{
	case 1:
		DrawMap();
		DrawTank(ptank);
		DrawTank(&tank3);
		while (1)
		{
			Sleep(18);
			/***********************�ҷ�̹��**************************************/
			if (clock() - nTime1 >= 20) {
				nTime1 = clock();
				KeyDown(ptank);
			}
			//�¼�B���ʱ��
			if (clock() - nTime2 >= 10)
			{
				nTime2 = clock();
				if (ptank->flagbullet)
				{
					if (MoveBullet(ptank) == 1 && JudgeBulletMove(ptank) != 2)
					{
						DrawBullet(ptank);
					}
				}
			}
			/***********************�з�̹��**************************************/
			//�о�̹���¼����ʱ��
			if (clock() - nTime3 >= 200)
			{
				nTime3 = clock();
				KeyDownFoe(&tank3);
			}
			if (clock() - nTime4 >= 10)
			{
				nTime4 = clock();
				if (tank3.flagbullet)
				{
					if (MoveBullet(&tank3) == 1 && JudgeBulletMove(&tank3) != 2)
					{
						DrawBullet(&tank3);
					}
				}
			}
			JudageTankViable(ptank, &tank3);
		}
		break;
		
	case 2:
		MessageLoop();
		DrawMap();
		DrawTank(ptank);
		DrawTank(&tank3);
		while (1)
		{
			Sleep(18);
			/***********************�ҷ�̹��**************************************/
			if (clock() - nTime1 >= 20) {
				nTime1 = clock();
				KeyDown(ptank);
			}
			//�¼�B���ʱ��
			if (clock() - nTime2 >= 10)
			{
				nTime2 = clock();
				if (ptank->flagbullet)
				{
					if (MoveBullet(ptank) == 1 && JudgeBulletMove(ptank) != 2)
					{
						DrawBullet(ptank);
					}
				}
			}
			/***********************�з�̹��**************************************/
			//�о�̹���¼����ʱ��
			if (clock() - nTime3 >= 200)
			{
				nTime3 = clock();
				KeyDownFoe(&tank3);
			}
			if (clock() - nTime4 >= 10)
			{
				nTime4 = clock();
				if (tank3.flagbullet)
				{
					if (MoveBullet(&tank3) == 1 && JudgeBulletMove(&tank3) != 2)
					{
						DrawBullet(&tank3);
					}
				}
			}
			JudageTankViable(ptank, &tank3);
		}
		break;
	case 3:
		MessageBox(NULL, "�˳���Ϸ","�˳���Ϸ" ,0);
		exit(0);
		break;
	}
	return 0;
}
