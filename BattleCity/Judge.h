#pragma once
#include"Data.h"
/*碰撞检测*/

/*判断坦克当前位置是否可以移动*/
//坦克移动之前应该先判断当前位置是否可以移动
int JudgeTankMove(TANK *ptank);
/*判断子弹是否命中目标*/
int JudgeBulletMove(TANK*ptank);

/*判断坦克是否被击中*/
int JudageTankViable(TANK*mytank, TANK*foetank);

/*判断敌我坦克中心点的位置以及中点以外的位置坐标是否相等*/
int JudgeTankPos();

/*判断草地*/
bool TankGrass(TANK*ptank);