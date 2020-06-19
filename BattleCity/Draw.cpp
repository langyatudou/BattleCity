#include"Draw.h"
#include"API.h"
#include"Judge.h"

//读取坦克图片
void readTankPicture() {

	FILE*pfile = NULL;
	//打开文件
	fopen_s(&pfile,"d:\\code\\BattleCity\\BattleCity\\tankpicture.txt", "rb");
	if (pfile == NULL) {
		printf("读取文件失败");
	}
	//读取文件
	fread(g_TankPicture, sizeof(char) * 30 * 140, 1, pfile);
	//关闭文件
	fclose(pfile);
}
/*打印坦克图片*/
void PrintPicture(char (*g_TankPicture)[141]) {
	
		printf("%s", g_TankPicture);
}
//打印游戏菜单
void PrintGameMenu(char index) {
	int y = 27;
	char GameMenu[5][25] = { "欢迎进入坦克大战游戏界面",
							 "一、开始新游戏",
						     "二、自定义游戏地图",
							 "三、退出游戏",
							 "请输入你的选择->" };
	for (int i = 1; i < 5; i++) 
	{
		printChar(28, y+i, GameMenu[i]);
	}
	printChar(28, y+index, GameMenu[index],4);
}

//游戏讲解
void GameSpeak() 
{
	//地图中各种事物的图标   ■   白色的代表铁墙         ■灰色的代表土墙    蓝色的河流≈     基地▲    草地▓
	int y = 8;
	/*游戏障碍物介绍*/
		printChar(MAP_X+6, y-1 , "障碍物介绍");  //17
		printChar(MAP_X , y+1, "铁墙：■->不能被子弹击毁");  //17
		printChar(MAP_X , y+2, "灰墙：■->可以被子弹击毁", GRAY);  //17
		printChar(MAP_X , y+3, "河流：≈->子弹可以穿越，坦克不能", COLOR_BLUE);  //
		printChar(MAP_X , y+4, "草地：▓->子弹或坦克进去后会隐身", 02);  //17
		printChar(MAP_X , y+5, "基地：▲->被击中后游戏结束", COLOR_GREEN);  //17
	/*游戏操作介绍*/
		printChar(MAP_X + 6,( MAP_Y / 2)+y-3, "游戏操作介绍");  //17
		printChar(MAP_X+6, (MAP_Y / 2) + y , "WASD->上下左右");  //17
		printChar(MAP_X+6, (MAP_Y / 2) + y +1, "F->发射子弹");  //17
		printChar(MAP_X + 6, (MAP_Y / 2) + y + 2, "鼠标左键设置灰墙");  //17
		printChar(MAP_X + 6, (MAP_Y / 2) + y + 3, "鼠标右键设置河流");  //17
}

/*画地图*/
void DrawMap()
{

	for (int i = 0; i < MAP_Y; i++)
	{
		for (int j = 0; j < MAP_X; j++)
		{
			if (i == 0 || j == 0 || i == MAP_X - 1 || j == MAP_Y - 1)
			{
				g_Map[i][j] = SIGN_WALL0;	//打印地图边界铁墙
				if (g_Map[i][j] = SIGN_WALL0) {
					printChar(j, i, "■");
				}

			}
			else if (g_Map[i][j] == SIGN_WALL1)
			{
				printChar(j, i, "■", GRAY);//打印灰墙
			}
			else if (g_Map[i][j] == SIGN_WATER)
			{
				printChar(j, i, "≈", COLOR_BLUE);//打印河流
			}
			else if (g_Map[i][j] == SIGN_BASE)
			{
				printChar(j, i, "▲", COLOR_GREEN);//打印大本营
			}
			else if (g_Map[i][j] == SIGN_GRASS)
			{
				printChar(j, i, "▓", 0x02);//打印草地
			}
		}
	}
	//打印外围墙壁
	printChar(MAP_X, 0,       "■■■■■■■■■■■■■■■■■");  //17
	for (int i = 0; i < MAP_Y; i++) {
		printChar(MAP_X+17, i, "■");
	}
	printChar(MAP_X, MAP_Y/2, "■■■■■■■■■■■■■■■■■");  //17
	printChar(MAP_X, MAP_Y-1, "■■■■■■■■■■■■■■■■■");  //17
	GameSpeak();
}

/*初始化坦克坐标*/
void initTank(TANK*ptank,int inittank_x,int inittan_y,int coclor) {
	
	ptank->coclor = coclor;
	ptank->g_dir = 上;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			ptank->tank[i][j].X= (inittank_x - 1) + j;
			ptank->tank[i][j].Y= (inittan_y - 1) + i;
		}
	}
}
/*画出坦克*/
void DrawTank(TANK*ptank)
{
	for (int i = 0; i < 3; i++)
		{
		for (int j = 0; j < 3; j++)
			{
				printChar(ptank->tank[i][j].X, ptank->tank[i][j].Y, "■", ptank->coclor);
			}
		}
		if (ptank->g_dir == 上){
			printChar(ptank->tank[0][0].X, ptank->tank[0][0].Y, " ");
			printChar(ptank->tank[0][2].X, ptank->tank[0][2].Y, " ");
		}
		else if (ptank->g_dir == 下) {
			printChar(ptank->tank[2][0].X, ptank->tank[2][0].Y, " ");
			printChar(ptank->tank[2][2].X, ptank->tank[2][2].Y, " ");
		}
		else if (ptank->g_dir == 左) {
			printChar(ptank->tank[0][0].X, ptank->tank[0][0].Y, " ");
			printChar(ptank->tank[2][0].X, ptank->tank[2][0].Y, " ");
		}
		else if (ptank->g_dir == 右) {
			printChar(ptank->tank[0][2].X, ptank->tank[0][2].Y, " ");
			printChar(ptank->tank[2][2].X, ptank->tank[2][2].Y, " ");
		}
}
/*擦除坦克*/
void WipeTank(TANK*ptank)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
		{
			printChar(ptank->tank[i][j].X, ptank->tank[i][j].Y, " ");

		}
	}
}
/*移动坦克*/
int moveTank(TANK*ptank)
{
	bool canMove = true;
	TANK temp = {};
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			temp.tank[i][j].X = ptank->tank[i][j].X;
			temp.tank[i][j].Y = ptank->tank[i][j].Y;
			temp.g_dir = ptank->g_dir;
		}
	}
	if (temp.g_dir  == 上)
	{
		
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {

					--temp.tank[i][j].Y;
				}
			}
			if (JudgeTankMove(&temp) == 0) {
				canMove = false;
			}
	}
	if (temp.g_dir == 下) {

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {

				++temp.tank[i][j].Y;
			}
		}
			if (JudgeTankMove(&temp) == 0) {
				canMove = false;
			}
	}
	if (temp.g_dir == 左) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {

				--temp.tank[i][j].X;
			}
		}
			if (JudgeTankMove(&temp) == 0) {
				canMove = false;
			}
	}
	if (temp.g_dir == 右) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {

				++temp.tank[i][j].X;
			}
		}
			if (JudgeTankMove(&temp) == 0) {
				canMove = false;
			}
	}
	//先对移动后的临时坐标做判断，看他是否等于障碍物
	//将移动后的值赋给tank
	if (JudgeTankMove(&temp) == 1) {
		if (canMove == true)
		{
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					ptank->tank[i][j].X = temp.tank[i][j].X;
					ptank->tank[i][j].Y = temp.tank[i][j].Y;
					ptank->g_dir = temp.g_dir;
				}
			}
		}
	}
	return 1;
}
/*控制坦克*/
void KeyDown(TANK*ptank)
{
	int ch = 0;
	if (_kbhit() != 0) {
		ch = _getch();
	}
	switch (ch) {
	case 'w':
	case'W':
		ptank->g_dir  = 上;
		if(TankGrass(ptank)!=0)
		WipeTank(ptank);
		moveTank(ptank);
		if (TankGrass(ptank) != 0)
		DrawTank(ptank);
		break;
	case 's':
	case'S':
		ptank->g_dir  = 下;
		if (TankGrass(ptank) != 0)
		WipeTank(ptank);
		moveTank(ptank);
		if (TankGrass(ptank) != 0)
		DrawTank(ptank);
		break;
	case 'a':
	case'A':
		ptank->g_dir  = 左;
		if (TankGrass(ptank) != 0)
		WipeTank(ptank);
		moveTank(ptank);
		if (TankGrass(ptank) != 0)
		DrawTank(ptank);
		break;
	case 'd':
	case'D':
		ptank->g_dir  = 右;
		if (TankGrass(ptank) != 0)
		WipeTank(ptank);
		moveTank(ptank);
		if (TankGrass(ptank) != 0)
		DrawTank(ptank);
		break;	
	case'f':
	case'F':
		/*坦克发射子弹标记*/
		if (ptank->flagbullet == 0) //如果子弹标记等于0，表示可以发射
		{
			ptank->fire = 1;
			ptank->flagbullet = 1;
			InitBullet(ptank);    //初始化子弹坐标
			break;
		}
		}

}

/*控制敌方坦克*/
void KeyDownFoe(TANK*ptank) {
	srand((unsigned)time(NULL));
	ptank->g_dir = rand() % 4;    //随机给坦克方向
	ptank->fire = rand() % 2;     //随机让坦克开火

	if (ptank->g_dir == 上) {
		WipeTank(ptank);
		moveTank(ptank);
		DrawTank(ptank);
	}
	else if (ptank->g_dir == 下) {
		WipeTank(ptank);
		moveTank(ptank);
		DrawTank(ptank);
	}
	else if (ptank->g_dir == 左) {
		WipeTank(ptank);
		moveTank(ptank);
		DrawTank(ptank);
	}
	else if (ptank->g_dir == 右) {
		WipeTank(ptank);
		moveTank(ptank);
		DrawTank(ptank);
	}
		/*坦克发射子弹标记*/
	if (ptank->flagbullet == 0) 
	{
		if (ptank->fire ==1) {
			ptank->flagbullet = 1;
			InitBullet(&tank3);    //初始化子弹坐标
		}
	}
}

/*初始化子弹*/
void InitBullet(TANK *ptank ){
	
	if (ptank->g_dir == 上) {
		ptank->bullet.pos.X = ptank->tank[1][1].X;
		ptank->bullet.pos.Y= ptank->tank[1][1].Y - 1;
		ptank->bullet.dir = ptank->g_dir;
	}
	else if (ptank->g_dir == 下) {
		ptank->bullet.pos.X = ptank->tank[1][1].X;
		ptank->bullet.pos.Y = ptank->tank[1][1].Y + 1;
		ptank->bullet.dir = ptank->g_dir;
	}
	else if (ptank->g_dir == 左) {
		ptank->bullet.pos.X = ptank->tank[1][1].X-1;
		ptank->bullet.pos.Y = ptank->tank[1][1].Y ;
		ptank->bullet.dir = ptank->g_dir;
	}
	else if (ptank->g_dir == 右) {
		ptank->bullet.pos.X = ptank->tank[1][1].X +1;
		ptank->bullet.pos.Y = ptank->tank[1][1].Y;
		ptank->bullet.dir = ptank->g_dir;
	}
}
/*画出子弹*/
void DrawBullet(TANK *ptank) {
	printChar(ptank->bullet.pos.X,ptank->bullet.pos.Y, "○");
}
/*擦除子弹*/
int WipeBullet(TANK*ptank) {
	bool flag = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if ((ptank->bullet.pos.X == ptank->tank[i][j].X)&&(ptank->bullet.pos.Y == ptank->tank[i][j].Y)) 
			{
				flag=1;//判断子弹坐标是否等于自生的坐标
			}
		}
	}
	if(flag!=1){
		printChar(ptank->bullet.pos.X,ptank->bullet.pos.Y, " ");
		return 1;
	}
	return 2;
}
	
/*移动子弹*///多来一个参数
int MoveBullet(TANK*ptank) {
	
	bool canMove = true;
	TANK temp;
	temp.bullet.pos.X = ptank->bullet.pos.X;
	temp.bullet.pos.Y = ptank->bullet.pos.Y;
	temp.bullet.dir = ptank->bullet.dir;
	temp.flagbullet = ptank->flagbullet;
	 if(JudgeBulletMove(ptank) == 1)
		WipeBullet(ptank);//这里，你不管三七二十一，初始化了坐标就直接擦除这个坐标是错误的
	if (temp.bullet.dir == 上) {
		temp.bullet.pos.Y--;

		if (JudgeBulletMove(&temp) == 0) {
			ptank->fire = 0;   //打到墙壁，就可以继续发射子弹
			canMove = false;
		}
	}
	else if (temp.bullet.dir == 下) {
		temp.bullet.pos.Y++;
		if (JudgeBulletMove(&temp) == 0) {
			temp.fire = 0;
			//ptank->fire = 0;
			canMove = false;
		}
	}
	else if (temp.bullet.dir == 左) {
		temp.bullet.pos.X--;
		if (JudgeBulletMove(&temp) == 0) {
			temp.fire = 0;
			canMove = false;
		}
	}
	else if (temp.bullet.dir ==右) {
		temp.bullet.pos.X++;
		if (JudgeBulletMove(&temp) == 0) {
			temp.fire = 0;
			canMove = false;
		}
	}
	if (canMove == true)
	{
		ptank->bullet.pos.X = temp.bullet.pos.X;
		ptank->bullet.pos.Y = temp.bullet.pos.Y;
		ptank->bullet.dir = temp.bullet.dir;
	}
	ptank->flagbullet = temp.flagbullet;
	return canMove;
}

/*控制子弹*/
/*void KeyDownBullet(BULLET*pbullet, TANK(*ptank)[3]) {
	int ch = 0;
	if (_kbhit() != 0) {
		ch = _getch();
	}
	switch (ch) {
	case'f':
	case'F':
		//发射子弹
			
			pbullet->dir =上;
			DrawBullet(pbullet);
			Sleep(500);
			WipeBullet(pbullet);
			MoveBullet(pbullet);

	
		break;
	case'a':
	case'A':
	case's':
	case'S':
	case'w':
	case'W':
	case'd':
	case'D':
		_ungetch(ch);
		break;
	}
}
*/