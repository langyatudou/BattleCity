#include "BulletObject.h"
#include "GameObject.h"


CBulletObject::CBulletObject()
{
}


CBulletObject::~CBulletObject()
{
}

//���ӵ�
void CBulletObject::DrawObject() 
{
	if (m_nIsDie) {
		tempDraw.printChar(m_nPosX, m_nPosY, "��");
	}
}
//��������̨���ӵ�
void CBulletObject::ClsObject() {
	
	tempDraw.printChar(m_nPosX, m_nPosY, "  ");

}
void CBulletObject::ClsObject(int x, int y) {
	tempDraw.printChar(x, y, "  ");
}
//�����ӵ�(���뱣��̹����Ϣ����������Ҫ����̹�˺��ӵ�����ײ
CBulletObject CBulletObject::GreatBullet(CTankObject tankobject, vector<CTankObject>&vectankobject) 
{
	//1.����̹�������ʼ���ӵ����꣬��ֽ�ӵ�״̬��Ϊtrue,
	//���ݷ���ȷ���ӵ���λ��
	CBulletObject bullet;
	bullet.m_nDir = tankobject.getTankDir();
	switch (bullet.m_nDir) 
	{
	case ��:
		bullet.m_nPosX = tankobject.getTankPosX();
		bullet.m_nPosY = tankobject.getTankPosY() - 2;   //�ӵ���λ��Ϊ̹�˵�ͷ��ǰһ��λ��
		bullet.m_Alignment = tankobject.getAlignment();   //��ȡ�ǵз������ѷ���Ӫ���ӵ�
		if (g_Map[bullet.m_nPosY][bullet.m_nPosX] == ��ͼ�߿�||
			g_Map[bullet.m_nPosY][bullet.m_nPosX] == ��ǽ) {
			bullet.m_nIsDie = false;
		}
		else {
			bullet.m_nIsDie = true;
		}
		break;
	case ��:
		bullet.m_nPosX = tankobject.getTankPosX();
		bullet.m_nPosY = tankobject.getTankPosY() + 2;
		bullet.m_Alignment = tankobject.getAlignment();
		if (g_Map[bullet.m_nPosY][bullet.m_nPosX] == ��ͼ�߿�||
			g_Map[bullet.m_nPosY][bullet.m_nPosX] == ��ǽ) {
			bullet.m_nIsDie = false;
		}
		else {
			bullet.m_nIsDie = true;
		}
		break;
	case ��:
		bullet.m_nPosX = tankobject.getTankPosX() - 2;
		bullet.m_nPosY = tankobject.getTankPosY();
		bullet.m_Alignment = tankobject.getAlignment();

		if (g_Map[bullet.m_nPosY][bullet.m_nPosX] == ��ͼ�߿�||
			g_Map[bullet.m_nPosY][bullet.m_nPosX] == ��ǽ) {
			bullet.m_nIsDie = false;
		}
		else {
			bullet.m_nIsDie = true;
		}
	
		break;
	case ��:
		bullet.m_nPosX = tankobject.getTankPosX() + 2;
		bullet.m_nPosY = tankobject.getTankPosY();
		bullet.m_Alignment = tankobject.getAlignment();
		if (g_Map[bullet.m_nPosY][bullet.m_nPosX] == ��ͼ�߿�||
			g_Map[bullet.m_nPosY][bullet.m_nPosX] == ��ǽ) {
			bullet.m_nIsDie = false;
		}
		else {
			bullet.m_nIsDie = true;
		}
		
		break;
	}
	return bullet;
}

////�ӵ���ײ���
bool CBulletObject::canMoveBullet(CBulletObject&bulletobject, vector<CTankObject>&vectankobject)
{
	static int tempScore = 0;
	static unsigned int tempHP = 3;
	static unsigned int tempHP2 = 3;
	int tempX = m_nPosX;
	int tempY = m_nPosY;
	if (m_nDir == ��)
	{
		--tempY;
	}
	else if (m_nDir == ��)
	{
		++tempY;
	}
	else if (m_nDir == ��)
	{
		--tempX;
	}
	else if (m_nDir == ��)
	{
		++tempX;
	}
	for (int i = 0; i < vectankobject.size(); i++) {
		if (m_Alignment == 0)//������Ӫ�ӵ�
		{
			if (vectankobject[i].isTank(tempX,tempY)&& vectankobject[i].getAlignment()==1)//���ез�̹��
			{
				vectankobject[i].setTankisDie(false);    //�������е�̹�˱��Ϊ����
				m_nIsDie = false;//���ӵ����Ϊ����
				tempScore += 10;  
				vectankobject[0].setTankScore(tempScore);    //���ӻ���
														//��������̹�˽��д���
				//1.������ͼ�е�̹��
				vectankobject[i].CanCls(vectankobject[i].getTankPosX(), vectankobject[i].getTankPosY());
				//2.����̹�˶����������ԣ����øñ�ŵ�̹�����ƶ�  ------ɾ�����λ�õ�̹��
				if (vectankobject[i].getTankisDie() == false) //�������������ɾ������
				{
					//3.������Ļ�ϵ�̹��
					vectankobject[i].ClsObject();
					//ɾ��̹�˶���
					vectankobject.erase(vectankobject.begin() + i);
				}

			}else if (vectankobject[i].isTank(tempX, tempY) && vectankobject[i].getAlignment() == 0)//�ѷ�̹�˻����ѷ�̹��*******
			{
				m_nIsDie = false;//���ӵ����Ϊ����
			}
		}
		else if (m_Alignment == 1)//�з���Ӫ�ӵ�
		{
			if (vectankobject[i].isTank(tempX, tempY) && vectankobject[i].getAlignment() == 0)//���м���̹��
			{
				//�������к�����ֵ-1��������ֵΪ0ʱ��Ϸ����
				//�����߼������⣬��ô������ʱ���1�����У���Ӧ����I==0��������Ӧ�����ӵ��������̹��0������
				if (i == 0) //���һ������
				{
					tempHP -= 1;
					vectankobject[0].setTankBlood(tempHP);
				}
				else if(i == 1) {
					tempHP2 -= 1;
					vectankobject[1].setTankBlood(tempHP2);
				}
				m_nIsDie = false;

				if(vectankobject[0].getTankBlood()==false)//�������ֵΪ0����Ϸ����
				{
					MessageBox(NULL, "��Ϸ����", "�˳�", 0);
					exit(0);//��Ϸ����
				}
				//}
			}//�з�̹�˻��ез�̹��
			else if (vectankobject[i].isTank(tempX, tempY) && vectankobject[i].getAlignment() == 1)//****
			{
				m_nIsDie = false;
			}
		}
	}
	if (g_Map[tempY][tempX] == ��ǽ || g_Map[tempY][tempX] == ��ͼ�߿�)
	{
		m_nIsDie = false;
		//ClsObject();
	}
	else if (g_Map[tempY][tempX] == ��ǽ) {
		g_Map[tempY][tempX] = �յ�;
		ClsObject(tempX, tempY);  //������ͼ��ǽ
		m_nIsDie = false;
		//ClsObject();
	}
	else if(g_Map[tempY][tempX] == ����)//���ر���������Ϸ����
	{
		MessageBox(NULL, "��Ϸ����", "�˳�", 0);
		exit(0);
	}
	//ClsObject();
	return m_nIsDie;
}

//�ж��Ƶ��Ƿ���ڵ�ͼ�ϰ���
//�ӵ���ͼ�ϰ�����
bool CBulletObject::isBlock(int x, int y)
{
	//m_nIsDie = true;
	if (g_Map[m_nPosY][m_nPosX] == ��ǽ || g_Map[m_nPosY][m_nPosX] == ��ͼ�߿�)
	{
		m_nIsDie = false;
	}
	else if (g_Map[m_nPosY][m_nPosX] == ��ǽ) {
		g_Map[m_nPosY][m_nPosX] = �յ�;
		m_nIsDie = false;
	}
	return m_nIsDie;
}

//3.�ƶ��ӵ�
void CBulletObject::MoveObject() {
		//дһ���ж��ܲ����ƶ��ĺ���
	
		int tempX, tempY;
		tempX = m_nPosX;
		tempY = m_nPosY;
		
		//���ڼ������ƶ�
		//����������
		if(isBlock(m_nPosX,m_nPosY)==true)
		ClsObject();
		if (m_nIsDie) {
			switch (m_nDir)
			{
			case ��:
				tempY--;
				break;
			case ��:
				tempY++;
				break;
			case ��:
				tempX--;
				break;
			case ��:
				tempX++;
				break;
			}

		m_nPosX = tempX;
		m_nPosY = tempY;
		DrawObject();
		}
		//���ƶ���Ϊ��,���������껭�����ӵ�
		
	
}




