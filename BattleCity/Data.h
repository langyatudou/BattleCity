#pragma once
#include <windows.h>

/*��Ʒ��ɫ��*/
#define COLOR_YELLOW 0x0e
#define COLOR_GREEN 0x0b
#define COLOR_WHITE_1 0x07
#define COLOR_RED 0x04
#define COLOR_BLUE 0x09
#define GRAY 0x08   //��ɫ

/*��ͼ������Ⱥ͸߶�*/
#define MAP_X 48
#define MAP_Y 48
/*��ͼ�ϸ�����Ʒ�ĺ�*/
#define LUNG 0          //�յ�
#define SIGN_TANK1 1    //�ҵ�̹��
#define SIGN_TANK2 2    //�Ѿ�̹��
#define SIGN_TANK3 3    //�о�̹��3
#define SIGN_TANK4 4    //�о�̹��4
#define SIGN_TANK5 5    //�о�̹��5

#define SIGN_WALL0 10    //��ǽ
#define SIGN_WALL1 11    //��ǽ    //��ɫ��ǽ��
#define SIGN_BASE  12    //��Ӫ
#define SIGN_WATER 20     //��ɫ��ˮ
#define SIGN_GRASS 21    //�ݵ�

/*
// ��ǰ�о�̹������
*/
#define FOETANK_AMOUNT 3

/*̹�˵ķ���*/
#define �� 0
#define �� 1
#define �� 2
#define �� 3

/*̹�����ĵ�ĳ�ʼ������*/
#define CENTRE_X0 12       
#define CENTRE_Y0 44    
//��˼·��ֱ�ӽ�̹��һ�����ĵ�����ͼ��
//�ƶ�̹�˵�ʱ��ֱ��ȥ��ͼ��g_Map�޸�����

/*����һ���ӵ��ṹ��*/
typedef struct _BULLET {
	COORD pos;
	int speed;
	int dir;      //�ӵ��ķ���
}BULLET, *PBULLET;

/*̹�˽ṹ������*/
typedef struct _TANK {
	COORD tank[3][3];   //̹�˵�����
	BULLET bullet;      //̹�˵��ӵ�
	int hp;             //̹�˵�����ֵ
	int coclor;			//̹�˵���ɫ
	int speed;          //̹�˵��ƶ��ٶ�
	int g_dir ;         //̹�˵ķ���
	int fire;          //�����ӵ�
	bool flagbullet;    //�ж��ӵ��Ƿ��ڷ�����
}TANK, *PTANK;

/*����ǽ�Ľṹ��*/
typedef struct _WALL {
	int x;
	int y;
	int coclor;
}WALL,*PWALL;

/*����һ����ͼ*/
extern int g_Map[MAP_Y][MAP_X];
/*�������Լ���̹��*/
extern TANK mytank;
/*����һ�����Լ���̹���ӵ������Լ��ȼ���̹��1*/
extern BULLET bullet1;

/*�ط�̹��3*/
extern TANK tank3;
extern BULLET bullet3;

//���̹��ͼƬ
extern char g_TankPicture[30][141];