#pragma once
#include"MapObject.h"
#include <windows.h>
#include <vector>
using std::vector;
//坦克的4个方向
enum TANKDIR {
	上, 下, 左, 右
};
class CTankObject
{
public:
	CTankObject();
	~CTankObject();
	void DrawObject();     //画坦克
	void ClsObject();      //擦除坦克
public:
	bool CanMove(int X,int Y);
	//3*3写进地图
	bool CanWrite(int X, int Y);
	//擦除地图中的数据
	bool CanCls(int X, int Y);
	//移动坦克
	void MoveTank();
	//是不是坦克
	bool isTank(int x,int y);
	//创建一组函数用于返回坦克的属性，子弹创建时需要用到这些属性
	/***************************得到坦克属性****************************/
	bool getTankisDie(){   return m_IsDie; }
	int getAlignment(){    return m_Alignment; }
	int getTankPosX(){     return m_nPosX; }
	int getTankPosY(){     return m_nPosY; }
	int getTankDir(){      return m_nDir; }
	int getTankType(){     return m_nType; }
	int getTankBlood() {   return m_nBlood; }
	int getTankScore() {   return m_nScore; }
	int getTankColocr() {  return m_nCoclor; }
	int getTankeSpeed() {  return m_nSpeed; }
	/***************************设置坦克属性****************************/
	void setTankisDie(bool IsDie) {     m_IsDie= IsDie; }
	void setAlignment(int Alignment) {  m_Alignment= Alignment; }
	void setTankPosX(int nPosX) {       m_nPosX= nPosX; }
	void setTankPosY(int nPosY) {       m_nPosY= nPosY; }
	void setTankDir(int nDir) {         m_nDir= nDir; }
	void setTankType(int nType) {       m_nType= nType; }
	void setTankBlood(int nBlood) {     m_nBlood= nBlood; }
	void setTankScore(int nScore) {     m_nScore= nScore; }
	void setTankColocr(int nCoclor) {   m_nCoclor= nCoclor;}
	void setTankSpeed(int nSpeed) {     m_nSpeed = nSpeed; }
private:
	bool m_IsDie;                    //判断坦克是否死亡
	unsigned int m_Alignment;        //所属阵营
	unsigned int m_nPosX;            //坦克m_nPosX坐标
	unsigned int m_nPosY;            //坦克的m_nPosY坐标
	unsigned int m_nDir;             //方向
	unsigned int m_nType;            //坦克类型
	unsigned int m_nBlood;           //血量
	unsigned int m_nScore;           //分数
	unsigned int m_nSpeed;           //坦克的速度
	int m_nCoclor;                   //颜色
	CMapObject*m_pmapobject;         //地图对象指针
	int m_TankShape[4][3][3] = {}; 
};

