#pragma once
#include"Data.h"
/*��ײ���*/

/*�ж�̹�˵�ǰλ���Ƿ�����ƶ�*/
//̹���ƶ�֮ǰӦ�����жϵ�ǰλ���Ƿ�����ƶ�
int JudgeTankMove(TANK *ptank);
/*�ж��ӵ��Ƿ�����Ŀ��*/
int JudgeBulletMove(TANK*ptank);

/*�ж�̹���Ƿ񱻻���*/
int JudageTankViable(TANK*mytank, TANK*foetank);

/*�жϵ���̹�����ĵ��λ���Լ��е������λ�������Ƿ����*/
int JudgeTankPos();

/*�жϲݵ�*/
bool TankGrass(TANK*ptank);