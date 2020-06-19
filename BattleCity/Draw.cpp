#include"Draw.h"
#include"API.h"
#include"Judge.h"

//��ȡ̹��ͼƬ
void readTankPicture() {

	FILE*pfile = NULL;
	//���ļ�
	fopen_s(&pfile,"d:\\code\\BattleCity\\BattleCity\\tankpicture.txt", "rb");
	if (pfile == NULL) {
		printf("��ȡ�ļ�ʧ��");
	}
	//��ȡ�ļ�
	fread(g_TankPicture, sizeof(char) * 30 * 140, 1, pfile);
	//�ر��ļ�
	fclose(pfile);
}
/*��ӡ̹��ͼƬ*/
void PrintPicture(char (*g_TankPicture)[141]) {
	
		printf("%s", g_TankPicture);
}
//��ӡ��Ϸ�˵�
void PrintGameMenu(char index) {
	int y = 27;
	char GameMenu[5][25] = { "��ӭ����̹�˴�ս��Ϸ����",
							 "һ����ʼ����Ϸ",
						     "�����Զ�����Ϸ��ͼ",
							 "�����˳���Ϸ",
							 "���������ѡ��->" };
	for (int i = 1; i < 5; i++) 
	{
		printChar(28, y+i, GameMenu[i]);
	}
	printChar(28, y+index, GameMenu[index],4);
}

//��Ϸ����
void GameSpeak() 
{
	//��ͼ�и��������ͼ��   ��   ��ɫ�Ĵ�����ǽ         ����ɫ�Ĵ�����ǽ    ��ɫ�ĺ�����     ���ء�    �ݵب�
	int y = 8;
	/*��Ϸ�ϰ������*/
		printChar(MAP_X+6, y-1 , "�ϰ������");  //17
		printChar(MAP_X , y+1, "��ǽ����->���ܱ��ӵ�����");  //17
		printChar(MAP_X , y+2, "��ǽ����->���Ա��ӵ�����", GRAY);  //17
		printChar(MAP_X , y+3, "��������->�ӵ����Դ�Խ��̹�˲���", COLOR_BLUE);  //
		printChar(MAP_X , y+4, "�ݵأ���->�ӵ���̹�˽�ȥ�������", 02);  //17
		printChar(MAP_X , y+5, "���أ���->�����к���Ϸ����", COLOR_GREEN);  //17
	/*��Ϸ��������*/
		printChar(MAP_X + 6,( MAP_Y / 2)+y-3, "��Ϸ��������");  //17
		printChar(MAP_X+6, (MAP_Y / 2) + y , "WASD->��������");  //17
		printChar(MAP_X+6, (MAP_Y / 2) + y +1, "F->�����ӵ�");  //17
		printChar(MAP_X + 6, (MAP_Y / 2) + y + 2, "���������û�ǽ");  //17
		printChar(MAP_X + 6, (MAP_Y / 2) + y + 3, "����Ҽ����ú���");  //17
}

/*����ͼ*/
void DrawMap()
{

	for (int i = 0; i < MAP_Y; i++)
	{
		for (int j = 0; j < MAP_X; j++)
		{
			if (i == 0 || j == 0 || i == MAP_X - 1 || j == MAP_Y - 1)
			{
				g_Map[i][j] = SIGN_WALL0;	//��ӡ��ͼ�߽���ǽ
				if (g_Map[i][j] = SIGN_WALL0) {
					printChar(j, i, "��");
				}

			}
			else if (g_Map[i][j] == SIGN_WALL1)
			{
				printChar(j, i, "��", GRAY);//��ӡ��ǽ
			}
			else if (g_Map[i][j] == SIGN_WATER)
			{
				printChar(j, i, "��", COLOR_BLUE);//��ӡ����
			}
			else if (g_Map[i][j] == SIGN_BASE)
			{
				printChar(j, i, "��", COLOR_GREEN);//��ӡ��Ӫ
			}
			else if (g_Map[i][j] == SIGN_GRASS)
			{
				printChar(j, i, "��", 0x02);//��ӡ�ݵ�
			}
		}
	}
	//��ӡ��Χǽ��
	printChar(MAP_X, 0,       "����������������������������������");  //17
	for (int i = 0; i < MAP_Y; i++) {
		printChar(MAP_X+17, i, "��");
	}
	printChar(MAP_X, MAP_Y/2, "����������������������������������");  //17
	printChar(MAP_X, MAP_Y-1, "����������������������������������");  //17
	GameSpeak();
}

/*��ʼ��̹������*/
void initTank(TANK*ptank,int inittank_x,int inittan_y,int coclor) {
	
	ptank->coclor = coclor;
	ptank->g_dir = ��;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			ptank->tank[i][j].X= (inittank_x - 1) + j;
			ptank->tank[i][j].Y= (inittan_y - 1) + i;
		}
	}
}
/*����̹��*/
void DrawTank(TANK*ptank)
{
	for (int i = 0; i < 3; i++)
		{
		for (int j = 0; j < 3; j++)
			{
				printChar(ptank->tank[i][j].X, ptank->tank[i][j].Y, "��", ptank->coclor);
			}
		}
		if (ptank->g_dir == ��){
			printChar(ptank->tank[0][0].X, ptank->tank[0][0].Y, " ");
			printChar(ptank->tank[0][2].X, ptank->tank[0][2].Y, " ");
		}
		else if (ptank->g_dir == ��) {
			printChar(ptank->tank[2][0].X, ptank->tank[2][0].Y, " ");
			printChar(ptank->tank[2][2].X, ptank->tank[2][2].Y, " ");
		}
		else if (ptank->g_dir == ��) {
			printChar(ptank->tank[0][0].X, ptank->tank[0][0].Y, " ");
			printChar(ptank->tank[2][0].X, ptank->tank[2][0].Y, " ");
		}
		else if (ptank->g_dir == ��) {
			printChar(ptank->tank[0][2].X, ptank->tank[0][2].Y, " ");
			printChar(ptank->tank[2][2].X, ptank->tank[2][2].Y, " ");
		}
}
/*����̹��*/
void WipeTank(TANK*ptank)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
		{
			printChar(ptank->tank[i][j].X, ptank->tank[i][j].Y, " ");

		}
	}
}
/*�ƶ�̹��*/
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
	if (temp.g_dir  == ��)
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
	if (temp.g_dir == ��) {

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {

				++temp.tank[i][j].Y;
			}
		}
			if (JudgeTankMove(&temp) == 0) {
				canMove = false;
			}
	}
	if (temp.g_dir == ��) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {

				--temp.tank[i][j].X;
			}
		}
			if (JudgeTankMove(&temp) == 0) {
				canMove = false;
			}
	}
	if (temp.g_dir == ��) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {

				++temp.tank[i][j].X;
			}
		}
			if (JudgeTankMove(&temp) == 0) {
				canMove = false;
			}
	}
	//�ȶ��ƶ������ʱ�������жϣ������Ƿ�����ϰ���
	//���ƶ����ֵ����tank
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
/*����̹��*/
void KeyDown(TANK*ptank)
{
	int ch = 0;
	if (_kbhit() != 0) {
		ch = _getch();
	}
	switch (ch) {
	case 'w':
	case'W':
		ptank->g_dir  = ��;
		if(TankGrass(ptank)!=0)
		WipeTank(ptank);
		moveTank(ptank);
		if (TankGrass(ptank) != 0)
		DrawTank(ptank);
		break;
	case 's':
	case'S':
		ptank->g_dir  = ��;
		if (TankGrass(ptank) != 0)
		WipeTank(ptank);
		moveTank(ptank);
		if (TankGrass(ptank) != 0)
		DrawTank(ptank);
		break;
	case 'a':
	case'A':
		ptank->g_dir  = ��;
		if (TankGrass(ptank) != 0)
		WipeTank(ptank);
		moveTank(ptank);
		if (TankGrass(ptank) != 0)
		DrawTank(ptank);
		break;
	case 'd':
	case'D':
		ptank->g_dir  = ��;
		if (TankGrass(ptank) != 0)
		WipeTank(ptank);
		moveTank(ptank);
		if (TankGrass(ptank) != 0)
		DrawTank(ptank);
		break;	
	case'f':
	case'F':
		/*̹�˷����ӵ����*/
		if (ptank->flagbullet == 0) //����ӵ���ǵ���0����ʾ���Է���
		{
			ptank->fire = 1;
			ptank->flagbullet = 1;
			InitBullet(ptank);    //��ʼ���ӵ�����
			break;
		}
		}

}

/*���Ƶз�̹��*/
void KeyDownFoe(TANK*ptank) {
	srand((unsigned)time(NULL));
	ptank->g_dir = rand() % 4;    //�����̹�˷���
	ptank->fire = rand() % 2;     //�����̹�˿���

	if (ptank->g_dir == ��) {
		WipeTank(ptank);
		moveTank(ptank);
		DrawTank(ptank);
	}
	else if (ptank->g_dir == ��) {
		WipeTank(ptank);
		moveTank(ptank);
		DrawTank(ptank);
	}
	else if (ptank->g_dir == ��) {
		WipeTank(ptank);
		moveTank(ptank);
		DrawTank(ptank);
	}
	else if (ptank->g_dir == ��) {
		WipeTank(ptank);
		moveTank(ptank);
		DrawTank(ptank);
	}
		/*̹�˷����ӵ����*/
	if (ptank->flagbullet == 0) 
	{
		if (ptank->fire ==1) {
			ptank->flagbullet = 1;
			InitBullet(&tank3);    //��ʼ���ӵ�����
		}
	}
}

/*��ʼ���ӵ�*/
void InitBullet(TANK *ptank ){
	
	if (ptank->g_dir == ��) {
		ptank->bullet.pos.X = ptank->tank[1][1].X;
		ptank->bullet.pos.Y= ptank->tank[1][1].Y - 1;
		ptank->bullet.dir = ptank->g_dir;
	}
	else if (ptank->g_dir == ��) {
		ptank->bullet.pos.X = ptank->tank[1][1].X;
		ptank->bullet.pos.Y = ptank->tank[1][1].Y + 1;
		ptank->bullet.dir = ptank->g_dir;
	}
	else if (ptank->g_dir == ��) {
		ptank->bullet.pos.X = ptank->tank[1][1].X-1;
		ptank->bullet.pos.Y = ptank->tank[1][1].Y ;
		ptank->bullet.dir = ptank->g_dir;
	}
	else if (ptank->g_dir == ��) {
		ptank->bullet.pos.X = ptank->tank[1][1].X +1;
		ptank->bullet.pos.Y = ptank->tank[1][1].Y;
		ptank->bullet.dir = ptank->g_dir;
	}
}
/*�����ӵ�*/
void DrawBullet(TANK *ptank) {
	printChar(ptank->bullet.pos.X,ptank->bullet.pos.Y, "��");
}
/*�����ӵ�*/
int WipeBullet(TANK*ptank) {
	bool flag = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if ((ptank->bullet.pos.X == ptank->tank[i][j].X)&&(ptank->bullet.pos.Y == ptank->tank[i][j].Y)) 
			{
				flag=1;//�ж��ӵ������Ƿ��������������
			}
		}
	}
	if(flag!=1){
		printChar(ptank->bullet.pos.X,ptank->bullet.pos.Y, " ");
		return 1;
	}
	return 2;
}
	
/*�ƶ��ӵ�*///����һ������
int MoveBullet(TANK*ptank) {
	
	bool canMove = true;
	TANK temp;
	temp.bullet.pos.X = ptank->bullet.pos.X;
	temp.bullet.pos.Y = ptank->bullet.pos.Y;
	temp.bullet.dir = ptank->bullet.dir;
	temp.flagbullet = ptank->flagbullet;
	 if(JudgeBulletMove(ptank) == 1)
		WipeBullet(ptank);//����㲻�����߶�ʮһ����ʼ���������ֱ�Ӳ�����������Ǵ����
	if (temp.bullet.dir == ��) {
		temp.bullet.pos.Y--;

		if (JudgeBulletMove(&temp) == 0) {
			ptank->fire = 0;   //��ǽ�ڣ��Ϳ��Լ��������ӵ�
			canMove = false;
		}
	}
	else if (temp.bullet.dir == ��) {
		temp.bullet.pos.Y++;
		if (JudgeBulletMove(&temp) == 0) {
			temp.fire = 0;
			//ptank->fire = 0;
			canMove = false;
		}
	}
	else if (temp.bullet.dir == ��) {
		temp.bullet.pos.X--;
		if (JudgeBulletMove(&temp) == 0) {
			temp.fire = 0;
			canMove = false;
		}
	}
	else if (temp.bullet.dir ==��) {
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

/*�����ӵ�*/
/*void KeyDownBullet(BULLET*pbullet, TANK(*ptank)[3]) {
	int ch = 0;
	if (_kbhit() != 0) {
		ch = _getch();
	}
	switch (ch) {
	case'f':
	case'F':
		//�����ӵ�
			
			pbullet->dir =��;
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