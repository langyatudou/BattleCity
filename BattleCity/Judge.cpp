
#include"Judge.h"
#include"API.h"
#include "Draw.h"
#include "Data.h"
/*碰撞检测*/
//坦克移动之前应该先判断当前位置是否可以移动
int JudgeTankMove(TANK*ptank) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (g_Map[ptank->tank[i][j].Y][ptank->tank[i][j].X] == SIGN_WALL0 ||
				g_Map[ptank->tank[i][j].Y][ptank->tank[i][j].X] == SIGN_WALL1 ||
				g_Map[ptank->tank[i][j].Y][ptank->tank[i][j].X] == SIGN_WATER||
				g_Map[ptank->tank[i][j].Y][ptank->tank[i][j].X] == SIGN_BASE
				) {
				return 0;   //如果当前坦克的坐标等于墙的坐标,或者水
			}
		}
	}
	return 1;
}

/*判断草地*/
bool TankGrass(TANK*ptank) 
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (g_Map[ptank->tank[i][j].Y][ptank->tank[i][j].X] == SIGN_GRASS
				) {
				return false;   //如果当前坦克的坐标等于草丛的坐标
			}
		}
	}
	return true;  //
}

/*判断子弹是否命中目标*/
int JudgeBulletMove(TANK*ptank) 
{
	//命中铁墙
	if (g_Map[ptank->bullet.pos.Y][ptank->bullet.pos.X] == SIGN_WALL0) {
		ptank->flagbullet = false;   //如果打到墙壁
		return 0;
	}//命中土墙
	else if (g_Map[ptank->bullet.pos.Y][ptank->bullet.pos.X] == SIGN_WALL1) {
		printChar(ptank->bullet.pos.X,ptank->bullet.pos.Y, " ");
		g_Map[ptank->bullet.pos.Y][ptank->bullet.pos.X] = LUNG;    //子弹命中土墙，将地图中的土墙置为空地
		ptank->flagbullet = false;   //如果打到墙壁,表示子弹已经消失，可以再次发射
		return 0;
	}//经过河流
	else if (g_Map[ptank->bullet.pos.Y][ptank->bullet.pos.X] == SIGN_WATER|| 
			g_Map[ptank->bullet.pos.Y][ptank->bullet.pos.X] == SIGN_GRASS) {
		return 2;//当子弹坐标等于河流的时候，不擦除
	}
	
	return 1;
} 

/*判断坦克是否被击中,大本营是否被击中*/
int JudageTankViable(TANK*mytank, TANK*foetank) 
{
	srand((unsigned)time(NULL));
	int x = rand() % 43 + 3;
	int y = rand() % 2+2;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) 
		{//敌方坦克被玩家1的子弹击中
			if ((mytank->bullet.pos.X == foetank->tank[i][j].X) && (mytank->bullet.pos.Y == foetank->tank[i][j].Y)) 
			{
				//第一步擦除地方坦克
				if (g_Map[foetank->tank[i][j].Y][foetank->tank[i][j].X] != SIGN_GRASS)
				WipeTank(foetank);
				//从新生成地方坦克坐标
				initTank(foetank, x, y,foetank->coclor);
				//画除坦克
				Sleep(300);
				DrawTank(foetank);
				return 0;
			}
			else if ((foetank->bullet.pos.X == mytank->tank[i][j].X) && (foetank->bullet.pos.Y == mytank->tank[i][j].Y)) {
				//第一步擦除我的坦克
				if(g_Map[mytank->tank[i][j].Y][mytank->tank[i][j].X]!=SIGN_GRASS)
				WipeTank(mytank);
				//初始化我的坦克坐标
				initTank(mytank, CENTRE_X0, CENTRE_Y0,mytank->coclor);
				//画出坦克
				Sleep(300);
				DrawTank(mytank);
				return 0;
			}

		}
	}
	//判断基地是否被攻击
	
			if (g_Map[foetank->bullet.pos.Y][foetank->bullet.pos.X] ==SIGN_BASE || 
				g_Map[mytank->bullet.pos.Y][mytank->bullet.pos.X] == SIGN_BASE) {
				printChar(19, 20, "你被击败了！");
				system("pause");
				exit (0);
		
	}
	return 1;
}

/*判断敌我坦克中心点的位置以及中点以外的位置坐标是否相等*/
int JudgeTankPos()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if ((mytank.tank[i][j].X == tank3.tank[i][j].X) && (mytank.tank[i][j].Y == tank3.tank[i][j].Y)) {
				return 0;   //如果几方和敌方坦克的坐标相等
			}
		}
	}
	return 1;
}