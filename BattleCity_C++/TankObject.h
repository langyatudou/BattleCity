#pragma once
#include"MapObject.h"
#include <windows.h>
#include <vector>
using std::vector;
//̹�˵�4������
enum TANKDIR {
	��, ��, ��, ��
};
class CTankObject
{
public:
	CTankObject();
	~CTankObject();
	void DrawObject();     //��̹��
	void ClsObject();      //����̹��
public:
	bool CanMove(int X,int Y);
	//3*3д����ͼ
	bool CanWrite(int X, int Y);
	//������ͼ�е�����
	bool CanCls(int X, int Y);
	//�ƶ�̹��
	void MoveTank();
	//�ǲ���̹��
	bool isTank(int x,int y);
	//����һ�麯�����ڷ���̹�˵����ԣ��ӵ�����ʱ��Ҫ�õ���Щ����
	/***************************�õ�̹������****************************/
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
	/***************************����̹������****************************/
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
	bool m_IsDie;                    //�ж�̹���Ƿ�����
	unsigned int m_Alignment;        //������Ӫ
	unsigned int m_nPosX;            //̹��m_nPosX����
	unsigned int m_nPosY;            //̹�˵�m_nPosY����
	unsigned int m_nDir;             //����
	unsigned int m_nType;            //̹������
	unsigned int m_nBlood;           //Ѫ��
	unsigned int m_nScore;           //����
	unsigned int m_nSpeed;           //̹�˵��ٶ�
	int m_nCoclor;                   //��ɫ
	CMapObject*m_pmapobject;         //��ͼ����ָ��
	int m_TankShape[4][3][3] = {}; 
};

