
#include"Judge.h"
#include"API.h"
#include "Draw.h"
#include "Data.h"
/*��ײ���*/
//̹���ƶ�֮ǰӦ�����жϵ�ǰλ���Ƿ�����ƶ�
int JudgeTankMove(TANK*ptank) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (g_Map[ptank->tank[i][j].Y][ptank->tank[i][j].X] == SIGN_WALL0 ||
				g_Map[ptank->tank[i][j].Y][ptank->tank[i][j].X] == SIGN_WALL1 ||
				g_Map[ptank->tank[i][j].Y][ptank->tank[i][j].X] == SIGN_WATER||
				g_Map[ptank->tank[i][j].Y][ptank->tank[i][j].X] == SIGN_BASE
				) {
				return 0;   //�����ǰ̹�˵��������ǽ������,����ˮ
			}
		}
	}
	return 1;
}

/*�жϲݵ�*/
bool TankGrass(TANK*ptank) 
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (g_Map[ptank->tank[i][j].Y][ptank->tank[i][j].X] == SIGN_GRASS
				) {
				return false;   //�����ǰ̹�˵�������ڲݴԵ�����
			}
		}
	}
	return true;  //
}

/*�ж��ӵ��Ƿ�����Ŀ��*/
int JudgeBulletMove(TANK*ptank) 
{
	//������ǽ
	if (g_Map[ptank->bullet.pos.Y][ptank->bullet.pos.X] == SIGN_WALL0) {
		ptank->flagbullet = false;   //�����ǽ��
		return 0;
	}//������ǽ
	else if (g_Map[ptank->bullet.pos.Y][ptank->bullet.pos.X] == SIGN_WALL1) {
		printChar(ptank->bullet.pos.X,ptank->bullet.pos.Y, " ");
		g_Map[ptank->bullet.pos.Y][ptank->bullet.pos.X] = LUNG;    //�ӵ�������ǽ������ͼ�е���ǽ��Ϊ�յ�
		ptank->flagbullet = false;   //�����ǽ��,��ʾ�ӵ��Ѿ���ʧ�������ٴη���
		return 0;
	}//��������
	else if (g_Map[ptank->bullet.pos.Y][ptank->bullet.pos.X] == SIGN_WATER|| 
			g_Map[ptank->bullet.pos.Y][ptank->bullet.pos.X] == SIGN_GRASS) {
		return 2;//���ӵ�������ں�����ʱ�򣬲�����
	}
	
	return 1;
} 

/*�ж�̹���Ƿ񱻻���,��Ӫ�Ƿ񱻻���*/
int JudageTankViable(TANK*mytank, TANK*foetank) 
{
	srand((unsigned)time(NULL));
	int x = rand() % 43 + 3;
	int y = rand() % 2+2;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) 
		{//�з�̹�˱����1���ӵ�����
			if ((mytank->bullet.pos.X == foetank->tank[i][j].X) && (mytank->bullet.pos.Y == foetank->tank[i][j].Y)) 
			{
				//��һ�������ط�̹��
				if (g_Map[foetank->tank[i][j].Y][foetank->tank[i][j].X] != SIGN_GRASS)
				WipeTank(foetank);
				//�������ɵط�̹������
				initTank(foetank, x, y,foetank->coclor);
				//����̹��
				Sleep(300);
				DrawTank(foetank);
				return 0;
			}
			else if ((foetank->bullet.pos.X == mytank->tank[i][j].X) && (foetank->bullet.pos.Y == mytank->tank[i][j].Y)) {
				//��һ�������ҵ�̹��
				if(g_Map[mytank->tank[i][j].Y][mytank->tank[i][j].X]!=SIGN_GRASS)
				WipeTank(mytank);
				//��ʼ���ҵ�̹������
				initTank(mytank, CENTRE_X0, CENTRE_Y0,mytank->coclor);
				//����̹��
				Sleep(300);
				DrawTank(mytank);
				return 0;
			}

		}
	}
	//�жϻ����Ƿ񱻹���
	
			if (g_Map[foetank->bullet.pos.Y][foetank->bullet.pos.X] ==SIGN_BASE || 
				g_Map[mytank->bullet.pos.Y][mytank->bullet.pos.X] == SIGN_BASE) {
				printChar(19, 20, "�㱻�����ˣ�");
				system("pause");
				exit (0);
		
	}
	return 1;
}

/*�жϵ���̹�����ĵ��λ���Լ��е������λ�������Ƿ����*/
int JudgeTankPos()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if ((mytank.tank[i][j].X == tank3.tank[i][j].X) && (mytank.tank[i][j].Y == tank3.tank[i][j].Y)) {
				return 0;   //��������͵з�̹�˵��������
			}
		}
	}
	return 1;
}