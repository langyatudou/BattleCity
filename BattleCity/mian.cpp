
#include "API.h"
#include "Draw.h"
#include "Data.h"
#include "Judge.h"
//1.win32api
//菜单
//2.map
//3tank
//4.zitan

//地图中各种事物的图标   ■   白色的代表铁墙         ■灰色的代表土墙    蓝色的河流≈     基地▲    草地▓

int main()
{
	//DrawMap();
	/********************初始化游戏数据***********************/
	/*使用事件间隔模拟多线程*/
	int nTime1 = clock();
	int nTime2 = 0;
	/*地方坦克休眠时间*/
	int nTime3 = clock();
	int nTime4 = 0;
	/*初始化玩家1的坦克*/
	PTANK ptank = &mytank;
	int InitTank1_x = CENTRE_X0;    //我的坦克初始化坐标
	int InitTank1_y = CENTRE_Y0;
	int IniTank1_Coclor = COLOR_YELLOW;   //坦克1的颜色
	/*初始化坦克3*/
	PTANK ptank3 = &tank3;
	int InitTank3_x = 3;    //坦克3初始化坐标
	int InitTank3_y = 3;
	int IniTank3_Coclor = COLOR_RED;   //坦克3的颜色
	initTank(ptank, InitTank1_x, InitTank1_y, IniTank1_Coclor);
	initTank(&tank3, InitTank3_x, InitTank3_y, IniTank3_Coclor);
	/**********************游戏选择界面***************************/
	int nCh = 0;
	readTankPicture();
	PrintPicture(g_TankPicture);
	PrintGameMenu(0);
	nCh =MessageLoop();    //通过键盘使劲按函数的返回值控制游戏选项，达到不使用scanfd 效果
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
			/***********************我方坦克**************************************/
			if (clock() - nTime1 >= 20) {
				nTime1 = clock();
				KeyDown(ptank);
			}
			//事件B间隔时间
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
			/***********************敌方坦克**************************************/
			//敌军坦克事件间隔时间
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
			/***********************我方坦克**************************************/
			if (clock() - nTime1 >= 20) {
				nTime1 = clock();
				KeyDown(ptank);
			}
			//事件B间隔时间
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
			/***********************敌方坦克**************************************/
			//敌军坦克事件间隔时间
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
		MessageBox(NULL, "退出游戏","退出游戏" ,0);
		exit(0);
		break;
	}
	return 0;
}
