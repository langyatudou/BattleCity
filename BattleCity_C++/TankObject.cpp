#include "TankObject.h"
#include "DrawObject.h"
#include "MapObject.h"

CTankObject::CTankObject()
{
}


CTankObject::~CTankObject()
{
}
CDrawObject tempDraw;
//�������ĵ��������̹��
void CTankObject::DrawObject()
{
	int x = m_nPosX;
	int y = m_nPosY;
	switch (m_nDir)
	{
	case ��:
		tempDraw.printChar(x - 1, y - 1, "  ��  ", m_nCoclor);
		tempDraw.printChar(x - 1, y,     "������", m_nCoclor);
		tempDraw.printChar(x - 1, y + 1, "��  ��", m_nCoclor);
		break;
	case ��:
		tempDraw.printChar(x - 1, y - 1, "��  ��", m_nCoclor);
		tempDraw.printChar(x - 1, y,     "������", m_nCoclor);
		tempDraw.printChar(x - 1, y + 1, "  ��  ", m_nCoclor);
		break;
	case ��:
		tempDraw.printChar(x - 1, y - 1, "  ����", m_nCoclor);
		tempDraw.printChar(x - 1, y,     "����  ", m_nCoclor);
		tempDraw.printChar(x - 1, y + 1, "  ����", m_nCoclor);
		break;
	case ��:
		tempDraw.printChar(x - 1, y - 1, "����  ", m_nCoclor);
		tempDraw.printChar(x - 1, y,     "  ����", m_nCoclor);
		tempDraw.printChar(x - 1, y + 1, "����  ", m_nCoclor);
		break;
	default:
		break;
	}

}
//����̹��
void CTankObject::ClsObject() {
	int x = m_nPosX;
	int y = m_nPosY;
	tempDraw.printChar(x-1, y - 1, "      ");
	tempDraw.printChar(x - 1, y,"      ");
	tempDraw.printChar(x - 1, y + 1, "      ");
}


bool CTankObject::CanMove(int X, int Y) {
	//���жϷ���
	//���ݷ����ж�ͷǰ�Ƿ����ϰ���
	switch (m_nDir) {
	case ��:
		for (int j = 0; j < 3; j++) {
			if (g_Map[Y - 1][X - 1 + j] == ��ͼ�߿� ||
				g_Map[Y - 1][X - 1 + j] == ��ǽ ||
				g_Map[Y - 1][X - 1 + j] == ��ǽ ||
				g_Map[Y - 1][X - 1 + j] == ����||
				g_Map[Y - 1][X - 1 + j] == ̹��1||
				g_Map[Y - 1][X - 1 + j] == NPC̹��||
				g_Map[Y - 1][X - 1 + j] == ����)
			{
				return false;
			}
		}
		break;
	case ��:
		for (int j = 0; j < 3; j++) {
			if (g_Map[Y + 1][X - 1 + j] == ��ͼ�߿� ||
				g_Map[Y + 1][X - 1 + j] == ��ǽ ||
				g_Map[Y + 1][X - 1 + j] == ��ǽ ||
				g_Map[Y + 1][X - 1 + j] == ����||
				g_Map[Y + 1][X - 1 + j] == ̹��1||
				g_Map[Y + 1][X - 1 + j] == NPC̹��||
				g_Map[Y + 1][X - 1 + j] == ����)
			{
				return false;
			}
		}
		break;
	case ��:
		for (int j = 0; j < 3; j++) {
			if (g_Map[Y -1+ j][X - 1] == ��ͼ�߿� ||
				g_Map[Y -1+ j][X - 1] == ��ǽ ||
				g_Map[Y -1+ j][X - 1] == ��ǽ ||
				g_Map[Y -1+ j][X - 1] == ����||
				g_Map[Y -1+ j][X - 1] == ̹��1||
				g_Map[Y - 1 + j][X - 1] == NPC̹��||
				g_Map[Y - 1 + j][X - 1] == ����)
			{
				return false;
			}
		}
		break;
	case ��:
		for (int j = 0; j < 3; j++) {
			if (g_Map[Y - 1 + j][X + 1] == ��ͼ�߿� ||
				g_Map[Y - 1 + j][X + 1] == ��ǽ ||
				g_Map[Y - 1 + j][X + 1] == ��ǽ ||
				g_Map[Y - 1 + j][X + 1] == ����||
				g_Map[Y - 1 + j][X + 1] == ̹��1||
				g_Map[Y - 1 + j][X + 1] == NPC̹��||
				g_Map[Y - 1 + j][X + 1] == ����)
			{
				return false;
			}
		}
		break;
	}
	return true;   //�����ƶ�
}
//3*3д����ͼ
bool CTankObject::CanWrite(int X, int Y) {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//����ƶ����̹��������ڲݴԣ��Ͳ���̹��д����ͼ
			if(g_Map[Y][X]!=�ݵ�)/*test*/
			g_Map[Y - 1 + i][X - 1 + j] = m_nType;  //�õ�ͼ���ڵ�ǰ��̹������
		}
	}
	return false;
}
//������ͼ�е�����
bool CTankObject::CanCls(int X, int Y) {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if(g_Map[Y][X]!=�ݵ�)
			g_Map[Y - 1 + i][X - 1 + j] =�յ�; 
		}
	}
	return true;
}

//3*3����ж�
bool CTankObject::isTank(int x, int y)
{
	if (x >= m_nPosX - 1 && x <= m_nPosX + 1) {
		if (y >= m_nPosY - 1 && y <= m_nPosY + 1) {
			return true;
		}
		return false;
	}
	return false;
}
	
////�ƶ�̹��
//void CTankObject::MoveTank(vector<CTankObject>&tankobject) 
//{
//	for (int i = 0; i < tankobject.size(); i++) {
//		int tempX = tankobject[i].getTankPosX();
//		int tempY = tankobject[i].getTankPosY();
//		int nDir = tankobject[i].getTankDir();   //��ȡ̹�˵ķ���
//		switch (nDir)
//		{
//		case ��:
//			//�ж�
//			tempY--;
//			if (CanMove(tempX, tempY) == true) //�ж��ܲ����ƶ�
//			{
//				ClsObject();//����ɵ�̹��
//				m_nPosY = tempY;//��ȡ������
//				DrawObject();   //���������껭��̹��
//			}
//			break;
//		case ��:
//			tempY++;
//			if (CanMove(tempX, tempY) == true) {
//				ClsObject();//����ɵ�̹��
//				m_nPosY = tempY;//��ȡ������
//				DrawObject();   //���������껭��̹��
//			}
//			break;
//		case ��:
//			tempX--;
//			if (CanMove(tempX, tempY) == true) {
//				ClsObject();//����ɵ�̹��
//				m_nPosX = tempX;//��ȡ������
//				DrawObject();   //���������껭��̹��
//			}
//			break;
//		case ��:
//			tempX++;
//			if (CanMove(tempX, tempY) == true) {
//				ClsObject();//����ɵ�̹��
//				m_nPosX = tempX;//��ȡ������
//				DrawObject();   //���������껭��̹��
//				break;
//			}
//
//		}
//	}
//}
//�ƶ�̹��
//void CTankObject::MoveTank()
//{
//	
//	//�����м����
//	//�ƶ�
//	//��������������
//	//��������д��ȥ
//	int tempX = m_nPosX;
//	int tempY = m_nPosY;
//	int nDir = m_nDir;   //��ȡ̹�˵ķ���
//	//1.�ƶ�֮ǰ�ж�3*3������Ȳ����ڵ�ͼ�е��ϰ��������ȣ�д��ȥ
//	//����
//	CanCls(m_nPosX, m_nPosY);
//	CanWrite(tempX,tempY);//������д����ͼ
//	
//		switch (nDir)
//		{
//		case ��:
//			tempY--;
//			if (CanMove(tempX, tempY) == true) //�ж��ܲ����ƶ�
//			{
//				//1.�ƶ�֮�󣬲�����ͼ��̹��
//				CanCls(m_nPosX, m_nPosY);
//				//2.����̹��д����ͼ
//				CanWrite(tempX, tempY);
//				ClsObject();//����ɵ�̹��
//				m_nPosY = tempY;//��ȡ������
//				
//				DrawObject();   //���������껭��̹��
//			}
//			break;
//		case ��:
//			tempY++;
//			if (CanMove(tempX, tempY) == true) {
//				//1.�ƶ�֮�󣬲�����ͼ��̹��
//				CanCls(m_nPosX, m_nPosY);
//				//2.����̹��д����ͼ
//				CanWrite(tempX, tempY);
//
//				ClsObject();//����ɵ�̹��
//				m_nPosY = tempY;//��ȡ������
//				DrawObject();   //���������껭��̹��
//			}
//			break;
//		case ��:
//			tempX--;
//			if (CanMove(tempX, tempY) == true) {
//				//1.�ƶ�֮�󣬲�����ͼ��̹��
//				CanCls(m_nPosX, m_nPosY);
//				//2.����̹��д����ͼ
//				CanWrite(tempX, tempY);
//
//				ClsObject();//����ɵ�̹��
//				m_nPosX = tempX;//��ȡ������
//				DrawObject();   //���������껭��̹��
//			}
//			break;
//		case ��:
//			tempX++;
//			if (CanMove(tempX, tempY) == true) {
//				//1.�ƶ�֮�󣬲�����ͼ��̹��
//				CanCls(m_nPosX, m_nPosY);
//				//2.����̹��д����ͼ
//				CanWrite(tempX, tempY);
//
//				ClsObject();//����ɵ�̹��
//				m_nPosX = tempX;//��ȡ������
//				DrawObject();   //���������껭��̹��
//				break;
//			}
//
//		}
//	}
void CTankObject::MoveTank()
{
	//�����м����
	//�ƶ�
	//��������������
	//��������д��ȥ
	int tempX = m_nPosX;
	int tempY = m_nPosY;
	int nDir = m_nDir;   //��ȡ̹�˵ķ���
	 //1.�ƶ�֮ǰ�ж�3*3������Ȳ����ڵ�ͼ�е��ϰ��������ȣ�д��ȥ
	CanCls(m_nPosX, m_nPosY);
	CanWrite(tempX, tempY);//������д����ͼ
	switch (nDir)
	{
	case ��:
		tempY--;
		if (CanMove(tempX, tempY) == true) //�ж��ܲ����ƶ�
		{
			//1.�ƶ�֮�󣬲�����ͼ�о�̹��
			CanCls(m_nPosX, m_nPosY);
			//2.����̹��д����ͼ
			CanWrite(tempX, tempY);

			//��������ڲݴԾͲ���
			if(g_Map[tempY-1][tempX]!=�ݵ�)
			ClsObject();//����ɵ�̹��
			m_nPosY = tempY;//��ȡ������

			if (g_Map[tempY-1][tempX] != �ݵ�)
			DrawObject();   //���������껭��̹��
		}
		break;
	case ��:
		tempY++;
		if (CanMove(tempX, tempY) == true) {
			//1.�ƶ�֮�󣬲�����ͼ��̹��
			CanCls(m_nPosX, m_nPosY);
			//2.����̹��д����ͼ
			CanWrite(tempX, tempY);
			if (g_Map[tempY+1][tempX] != �ݵ�)
			ClsObject();//����ɵ�̹��
			m_nPosY = tempY;//��ȡ������
			if (g_Map[tempY+1][tempX] != �ݵ�)
			DrawObject();   //���������껭��̹��
		}
		break;
	case ��:
		tempX--;
		if (CanMove(tempX, tempY) == true) {
			//1.�ƶ�֮�󣬲�����ͼ��̹��
			CanCls(m_nPosX, m_nPosY);
			//2.����̹��д����ͼ
			CanWrite(tempX, tempY);
			if (g_Map[tempY][tempX-1] != �ݵ�)
			ClsObject();//����ɵ�̹��
			m_nPosX = tempX;//��ȡ������
			if (g_Map[tempY][tempX-1] != �ݵ�)
			DrawObject();   //���������껭��̹��
		}
		break;
	case ��:
		tempX++;
		if (CanMove(tempX, tempY) == true) {
			//1.�ƶ�֮�󣬲�����ͼ��̹��
			CanCls(m_nPosX, m_nPosY);
			//2.����̹��д����ͼ
			CanWrite(tempX, tempY);
			if (g_Map[tempY][tempX+1] != �ݵ�)
			ClsObject();//����ɵ�̹��
			m_nPosX = tempX;//��ȡ������
			if (g_Map[tempY][tempX+1] != �ݵ�)
			DrawObject();   //���������껭��̹��
			break;
		}

	}
}