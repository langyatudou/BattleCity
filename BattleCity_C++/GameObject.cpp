#include "GameObject.h"
#include"MapObject.h"
#include <stdlib.h>

CGameObject::CGameObject()
{
}


CGameObject::~CGameObject()
{
}

////��ӭ����
bool CGameObject::WelcomeUI(int index) 
{
	char picture[26][121] = {
		"	                                       																				 ",
		"                                                                 i.ri7YSXRgqBP                                          ",
		"                                                                EDv1bPYv5MBQBB                                          ",
		"                                                                7BBgZBBBEBXJ2g.                                         ",
		"                                                 Y.   7Ud7..rJb5JuS5uUKKqPKUUJXZPKgEDuSqY                               ",
		"                                         DDvv i:i7Sr7Ki:.i:5BBRQZXYL7rrYI17sKMPPXXEBBBBBQ                               ",
		"                                .:YLuvrv1QBX:iD2U:BQdB77rvJiK5XSbq1uPIKPdb1sSEPPPUXEgdZBB                               ",
		"ERQBBBBBBBBBBBBBBBBBBBBBBBQBBBBBBBBBBBBBbgiSPEir1SYdq7vJYSXvu7v1jUJKPPKqPXLsUDggPPgQQdEBQ                               ",
		"                                 i1vuIIddBKPBS.vS2jvr:vYPPKJEjvLJYsJEP5YL7YYUI5jbQBBBQgBB                               ",
		"                                         r.iSgZBBBBBQBQBBBBBBBQQQBQRQBBBBBRRQBB5   :                ..  .           ..  ",
		"                                 LBPv i7I7LUEPEPdKPPbPbqPPbPEDDPDgDbbPgZMgZbDERgr.:XKSPPERQQRdJ.rJv7BBBQBBBBBS     :BQ  ",
		"                          :YBBL. ZZSI1XDXurSBQMQQQQBQQPdPPEdqPqQKEbdEddbqDgI7KjEQgRgDPKbSXgMEqKBBBBBQBBBBBBBQi     .BB  ",
		"                            ZL  :QEP5PQMERMgQgDbDbddQQgPS2EKdJuPIPEPPISXEdMd5DDEQEgMEqdPdbMPbq5dDQBERQBQBQBBBgbr  .RQgBi",
		"                    vUU2IXYIEXj5SQZbgQMgZZEgdPIXSqSKEMggPPqdKEDMggZdPPqPZDdMggMQRQQQEEdggRgQggbPbZdDbdq5IY7KKEBBK.RBMBBM",
		"                  .ZBBBBBBBQBBBBBQQMRgQgBgBMBQBQQQQQgRgQRQQQQQBRQgBgBRBRBMQgRgRMgRMMMQQRgDMMDZQERgDgQgQdQMdMQqIqMgDDBBb ",
		"                .uBBMQgRDbPMDggZZggMEMdgdRDgddPRZDDDgEREggQDRRgPqPDQbQKgqgEEZZPDDDK5XgQKZEXqXPddZBX25X5uIbPQMRgPB5  gY  ",
		"                ..gBdZZuXRQEqRQ2gBBggbMQQBQPS1KRBQQZQMQEQgRZEQq1uUgMPggQRbgQBDgBBZX7SMQIgQDgQZQBdssPBPgEPusZMuBBBB  d1  ",
		"                 7QBBQgsiIPKSQQb5PBQbDRQgQMZbSEBERQZbRqPMdDdPQZqXDBEIgRQD5JZBEKgggbIqMPEXBRRZgQg5M5bDgQB5ZQKK  Bs.  BX  ",
		"                  YBQS5s: .u5s1d2XBQXPKXZEPSPqgK2s5qbIuUE2I5PqSddZBXJERgZjsuPK2uUPgZQbPX2gMPgQdsDZQUJY5P5DZDgr DB..BB   ",
		"                  UBqUKBRPZMR57dMSIQPBDKBgYYjLIQDZXPddPPSKKK5RDQQQgqPggDSPggqPPPbMQBQBMqDBQgKPMuZXPXK22ZgSSQRU  iQQX    ",
		"                  sBbQDdQBBQDRBPd5PEQQgSgBSjZPXQBQQRRUSqKRBDgQBddgDbBRDPqSdgQRBBgDQPKdMDBBQMdSQuPgbZBZDQBQQ5Dq          ",
		"                   BBBPibBRRXEQXZdZDgRBQERPK2KMgDgDRDqIIDMZgDgdSUuKQdDdMgdPPqQgggDDZEX7KdEgRRgdQbgQBBEdBZXXqK.          ",
		"                    JBBBBEggZb7vBBZgEgbKbEDDEDgbXsbQBEgDMEQPbRMPgZQdDPKbRDPZgZEbuYKDZEgMgQgXqdDgBP151vi.rYREi           ",
		"                      :XuBQIu:   BBDPP2PPXPZQBKQqj1PPqQBXDDqKgdPgBgqqXXZgQEBBPPXjJ5KKQBDPd5JSMQBi   ivPSE..             ",
		"                           rrbPP:RBQZUdKPXDEQQQSMD1SPgBBRIKZIqKDPBBDUPUSRQS5BBPIEsqbMSBBEuPs5ZQE..dKMrr                 ",
		"                               . i:sqEPSXbI. UDMdqXPS:.1bMPKSKDL iXQgdKKS5  7EQMKdKd7 :PRgPPPKj.vri      :vU7vuvYj:JJL: "
	};
	for (int i = 0; i < 26; i++) {
		printf("%s\n", picture[i]);
	}
	int y = 27;
		char GameMenu[6][25] = { "��ӭ����̹�˴�ս��Ϸ����",
			"һ����ʼ����Ϸ",
			"�����Զ�����Ϸ��ͼ",
			"��������ȡ��Ϸ�浵",
			"�ġ��˳���Ϸ",
			"���������ѡ��->" };
		for (int i = 1; i < 6; i++)
		{
			drawobject.printChar(28, y + i, GameMenu[i]);
		}
		
		return true;
}

//�༭��ͼ�˵�
void CGameObject::EditMapUI() 
{
	int y = 2;
	drawobject.printChar(MAP_X, y + 1, "��ǽ����->���ܱ��ӵ�����");  //17
	drawobject.printChar(MAP_X, y + 3, "��ǽ����->���Ա��ӵ�����");  //17
	drawobject.printChar(MAP_X, y + 5, "��������->�ӵ����Դ�Խ��̹�˲���");  //
	drawobject.printChar(MAP_X, y + 7, "�ݵأ���->�ӵ���̹�˽�ȥ�������");  //17
	drawobject.printChar(MAP_X, y + 9, "���أ���->�����к���Ϸ����");  //17
}

//��ӡ��Ϸ�����Ϣ�˵�
void CGameObject::printPlayerUI() 
{
	int y = 2;
	drawobject.printChar(MAP_X, y + 1, "            ���1��Ϣ");  //17
	drawobject.printChar(MAP_X, y + 3, "  ������  ");  //17
	printf("%d", vectankobject[0].getTankBlood());
	drawobject.printChar(MAP_X, y + 5, "  ���֣�  ");  //17
	printf("%d", vectankobject[0].getTankScore());
	
	//��Ҷ�
	drawobject.printChar(MAP_X, y + 7, "            ���2��Ϣ");  //17
	drawobject.printChar(MAP_X, y + 9, "  ������  ");  //17
	printf("%d", vectankobject[1].getTankBlood());
	drawobject.printChar(MAP_X, y + 11, "  ���֣�  ");  //17
	printf("%d", vectankobject[1].getTankScore());

	//��Ϸ���ƽ���
	drawobject.printChar(MAP_X, MAP_Y/2+4, "            ��Ϸ��������");  //17
	drawobject.printChar(MAP_X, MAP_Y / 2 + 7, "  ���1������ƣ�WSAD,�ӵ�����F");  //17
	drawobject.printChar(MAP_X, MAP_Y / 2 + 9, "  ���2������ƣ�IJKL,�ӵ�����P");  //17
	drawobject.printChar(MAP_X, MAP_Y / 2 + 11,"  �������ֵΪ0ʱ����Ϸ����");  //17
	drawobject.printChar(MAP_X, MAP_Y / 2 + 13, "  g/G������Ϸ");  //17
}
//�ؿ��˵�
void CGameObject::ChoicLevelUI() {
	drawobject.printChar(MAP_X / 2, MAP_Y / 2,   "��һ��");  //17
	drawobject.printChar(MAP_X / 2, MAP_Y / 2 + 2, "�ڶ���");  //17
	drawobject.printChar(MAP_X / 2, MAP_Y / 2 + 4, "������");  //17
	drawobject.printChar(MAP_X / 2, MAP_Y / 2 + 6, "��ѡ��-->");  //17
	scanf_s("%d", &m_level);
	m_level -= 1;
}
//ѡ�񱣴��ͼ�˵�
void CGameObject::ChoiceSaveMapUI() 
{
	drawobject.printChar(MAP_X / 2, MAP_Y / 2 + 6, "��ѡ��-->"); 
	scanf_s("%d", &m_level);
	m_level -= 1;
}


bool CGameObject::ReadMap() {

	FILE*pfile = NULL;
	//���ļ�
	//·��
	//Ĭ�϶�ȡ��0�ص�ͼ
	sprintf_s(m_buff, "d:\\code\\BattleCity\\BattleCity_C++\\��%d�ص�ͼ.txt", m_level);

	fopen_s(&pfile, m_buff, "rb");
	if (pfile == NULL) {
		MessageBox(NULL, "���ļ�ʧ��", "�ļ���ȡ", 0);
		exit(0);
		return false;//��ȡ�ļ�ʧ��
	}
	//��ȡ�ļ�
	//���ļ����ݶ�ȡ����ͼ���еĵ�ͼ����
	fread(g_Map, sizeof(int) * MAP_X * MAP_Y, 1, pfile);
	fread(g_Mapname, sizeof(char) * 5 * 100, 1, pfile);
	//�ر��ļ�
	fclose(pfile);
	return true;
}

//�ļ�д��-������Ϸ��ͼ
bool CGameObject::SaveMap() {
	FILE*pfile = NULL;
	//���ļ�
	int tempnNum = 0;
	sprintf_s(m_buff, "d:\\code\\BattleCity\\BattleCity_C++\\��%d�ص�ͼ.txt", m_level);
	fopen_s(&pfile, m_buff, "wb+");
	if (pfile == NULL) {
		MessageBox(NULL, "���ļ�ʧ��", "�ļ�д��", 0);
		return false;//��ȡ�ļ�ʧ��
	}
	//д��
	//����ͼ�����еĵ�ͼ���鱣�浽�ļ���ȥ
	fwrite(g_Map, sizeof(int) * MAP_X * MAP_Y, 1, pfile);
	fwrite(g_Mapname, sizeof(char) * 5 * 100, 1, pfile);
	//�ر�
	fclose(pfile);
	return true;
}

//������Ϸ�浵
bool CGameObject::SaveGame() {
	FILE*pfile = NULL;
	//���ļ�
	fopen_s(&pfile, "d:\\code\\BattleCity\\BattleCity_C++\\��Ϸ�浵.txt", "wb+");
	if (pfile == NULL) {
		MessageBox(NULL, "���ļ�ʧ��", "�ļ�д��", 0);
		return false;//��ȡ�ļ�ʧ��
	}
	//vector<CTankObject>vectankobject;     //����Ϸ��ĳ�ʼ��������̹�˺��ӵ�������ʼ��

	NPCTankNum = vectankobject.size();
	fwrite(&NPCTankNum, sizeof(int), 1, pfile);  //���浱ǰ
	for (int i = 0; i < vectankobject.size(); i++) {
		fwrite(&vectankobject[i], sizeof(CTankObject), 1, pfile);
	}


	fwrite(g_Map, sizeof(int) * MAP_X * MAP_Y, 1, pfile);

	//�ر�
	fclose(pfile);
	return true;
}
//��ȡ��Ϸ�浵
bool CGameObject::ReadGame() {
	FILE*pfile = NULL;
	//���ļ�
	fopen_s(&pfile, "d:\\code\\BattleCity\\BattleCity_C++\\��Ϸ�浵.txt", "rb");
	if (pfile == NULL) {
		MessageBox(NULL, "���ļ�ʧ��", "�ļ���ȡ", 0);
		return false;//��ȡ�ļ�ʧ��
	}
	CTankObject tempobj;
	NPCTankNum -= 2;
	fread(&NPCTankNum,sizeof(int), 1, pfile);  //���浱ǰ
	for (int i = 0; i < NPCTankNum; i++) {
		
		fread(&tempobj, sizeof(CTankObject), 1, pfile);
		vectankobject.push_back(tempobj);
	}
	fread(g_Map, sizeof(int) * MAP_X * MAP_Y, 1, pfile);
	//�ر��ļ�
	fclose(pfile);
	return true;
}

//��ʼ����ͼ
void CGameObject::DrawMap() {

	for (int i = 0; i < MAP_Y; i++)
	{
		for (int j = 0; j < MAP_X; j++)
		{
			if (g_Map[i][j] == ��ͼ�߿�)
			{
 				drawobject.printChar(j, i, "��");
			}
			else if (g_Map[i][j] == ��ǽ) {
				drawobject.printChar(j, i, "��");
			}
			else if (g_Map[i][j] == ��ǽ) {
				drawobject.printChar(j, i, "��", ��ɫ);
			}
			else if (g_Map[i][j] == �ݵ�) {
				drawobject.printChar(j, i, "��", ��ɫ);
			}
			else if (g_Map[i][j] == ����) {
				drawobject.printChar(j, i, "��", ��ɫ);
			}
			else if (g_Map[i][j] == ����) {
				drawobject.printChar(j, i, "��");
			}
		}
	}
	//��ӡ��Χǽ��
	drawobject.printChar(MAP_X, 0, "����������������������������������");  //17
	drawobject.printChar(MAP_X, MAP_Y / 2, "����������������������������������");  //17
	drawobject.printChar(MAP_X, MAP_Y - 1, "����������������������������������");  //17
	for (int i = 0; i < MAP_Y; i++) {
		drawobject.printChar(MAP_X + 17, i, "��");
	}
}

//��ʼ���Լ����Ѿ�̹����Ϣ
bool CGameObject::InitPlayerTankInfo()
{
	//1.������ʱ�������ڵ���̹�˳�Ա����
	CTankObject playertankobject1, playertankobject2;
	//��ʼ�����1������Ϣ
	playertankobject1.setTankDir(��);                  //����
	playertankobject1.setTankPosX(15);                 //����
	playertankobject1.setTankPosY(42);
	playertankobject1.setTankColocr(��ɫ);             //��ɫ
	playertankobject1.setTankType(̹��1);              //����
	playertankobject1.setTankScore(0);                 //����
	playertankobject1.setTankBlood(3);                 //Ѫ��
	playertankobject1.setTankisDie(true);              //״̬
	playertankobject1.setAlignment(0);             //��Ӫ    0�����Ѿ�
	vectankobject.push_back(playertankobject1);
	//��ʼ�����2������Ϣ
	playertankobject2.setTankDir(��);
	playertankobject2.setTankPosX(30);
	playertankobject2.setTankPosY(42);
	playertankobject2.setTankColocr(��ɫ);
	playertankobject2.setTankType(̹��1);      //
	playertankobject2.setTankScore(0);
	playertankobject2.setTankBlood(3);
	playertankobject2.setTankisDie(1);
	playertankobject2.setAlignment(0);
	vectankobject.push_back(playertankobject2);
	
	return true;
}

//��ʼNPC̹����Ϣ
bool CGameObject::InitNPCTankInfo() 
{
	CTankObject NPCtankobject;
	srand((unsigned)time(NULL));
	int X, Y, dir, speed;
	

	for (int i = 2; i <NPCTankNum+2; i++) {
			X = rand() % (MAP_X - 8) + 4;
			Y = rand() % 6 + 4;
			dir = rand() % 4;
			speed = rand() % 50 + 100;
		NPCtankobject.setTankPosX(X);
		NPCtankobject.setTankPosY(Y);
		NPCtankobject.setTankDir(dir);
		//������̹��Ϊ�о��ϴ�����ֵ��һ������ɫ��һ��
		if (i == 2) {
			NPCtankobject.setTankColocr(��ɫ);
		}
		else {
			NPCtankobject.setTankColocr(��ɫ);
		}
		NPCtankobject.setTankType(NPC̹��);
		NPCtankobject.setTankisDie(true);
		NPCtankobject.setAlignment(1);      //1����о���Ӫ
		NPCtankobject.setTankSpeed(speed);  //ÿ��̹�˵��ٶ�
		vectankobject.push_back(NPCtankobject);
	}
	return true;
}

////ͨ�������ƶ�̹��
bool CGameObject::MovesSelfAndALLY(vector<CTankObject>&tankobject) 
{
	int ch1 = 0;
	if (_kbhit() != 0) {
		ch1 = _getch();
	}
	//���1
	switch (ch1)
	{
	case 'w':
	case'W'://�۸��ǣ�̹��û�����ÿ���
			if (tankobject[0].getTankDir() != ��) {
				//����̹��
				tankobject[0].ClsObject();
				tankobject[0].setTankDir(��);//��̹�˷����޸�Ϊ��
				tankobject[0].DrawObject();
			}
			else {
				
				tankobject[0].MoveTank();
			}
		break;
	case's':
	case'S':
			if (tankobject[0].getTankDir() != ��)
			{
				tankobject[0].ClsObject();
				tankobject[0].setTankDir(��);
				tankobject[0].DrawObject();
			}
			else {
				tankobject[0].MoveTank();
			}
		break;
	case'a':
	case'A':
			if (tankobject[0].getTankDir() != ��)
			{
				tankobject[0].ClsObject();
				tankobject[0].setTankDir(��);
				tankobject[0].DrawObject();
			}
			else {
				tankobject[0].MoveTank();
			}
		break;
	case'd':
	case'D':
			if (tankobject[0].getTankDir() != ��)
			{
				tankobject[0].ClsObject();
				tankobject[0].setTankDir(��);
				tankobject[0].DrawObject();
			}
			else {
				tankobject[0].MoveTank();
			}
			break;
	case'f':case'F'://���һ�����ӵ�,�ӵ��ĵ�һ�����겻�ܵ��ڵ�ͼ�߿����ǽ
	
		if(bulletobject.getBulletisDie()==false)
			bulletobject = bulletobject.GreatBullet(tankobject[0], vectankobject);    //��ʼ�����1���ӵ�
		
		break;
	//��Ҷ�
	case'i':case'I':
		if (tankobject[1].getTankDir() != ��) {
					//����̹��
					tankobject[1].ClsObject();
					tankobject[1].setTankDir(��);//��̹�˷����޸�Ϊ��
					tankobject[1].DrawObject();
				}
				else {
					//tankobject.setTankDir(��);//����һ�¾Ͳ����޸ķ���
					tankobject[1].MoveTank();
				}
				break;
	case'K':case'k':

			if (tankobject[1].getTankDir() != ��)
			{
				tankobject[1].ClsObject();
				tankobject[1].setTankDir(��);
				tankobject[1].DrawObject();
			}
			else {
				tankobject[1].MoveTank();
			}

			break;
	case'j':case'J':

		if (tankobject[1].getTankDir() != ��)
		{
			tankobject[1].ClsObject();
			tankobject[1].setTankDir(��);
			tankobject[1].DrawObject();
		}
		else {
			tankobject[1].MoveTank();
		}
		break;
	case'l':case'L':
			if (tankobject[1].getTankDir() != ��)
			{
				tankobject[1].ClsObject();
				tankobject[1].setTankDir(��);
				tankobject[1].DrawObject();
			}
			else {
				tankobject[1].MoveTank();
			}
			break;
	case 'p':case 'P':
		if (bulletobject.getBulletisDie() == false)
			bulletobject = bulletobject.GreatBullet(tankobject[1], vectankobject);    //��ʼ�����1���ӵ�
		break;
	case 'g':case'G'://������Ϸ
		SaveGame();
		MessageBox(NULL, "������Ϸ�ɹ�", "�˳�", 0);
		
	}
	return true;
}

//////ͨ�������A*�ƶ��з�̹��
//bool CGameObject::MoveNPC()
//{
//	srand((unsigned)time(NULL));
//	//����õо�̹�˿���
//
//	for (int i = 2; i < vectankobject.size(); i++) 
//	{
//		int dir = rand() % 4;    //�����̹�˷��򣬿���    /*/
//		int fire = rand() % 5;
//		vectankobject[i].setTankDir(dir);
//		switch (vectankobject[i].getTankDir())
//		{
//		case ��:
//			if (vectankobject[i].getTankDir() != ��) {
//				//����̹��
//				vectankobject[i].ClsObject();
//				vectankobject[i].setTankDir(��);//��̹�˷����޸�Ϊ��
//				vectankobject[i].DrawObject();
//			}
//			else {
//				vectankobject[i].MoveTank();
//			}
//			break;
//		case ��:
//			if (vectankobject[i].getTankDir() != ��)
//			{
//				vectankobject[i].ClsObject();
//				vectankobject[i].setTankDir(��);
//				vectankobject[i].DrawObject();
//			}
//			else {
//				vectankobject[i].MoveTank();
//			}
//			break;
//		case ��:
//			if (vectankobject[i].getTankDir() != ��)
//			{
//				vectankobject[i].ClsObject();
//				vectankobject[i].setTankDir(��);
//				vectankobject[i].DrawObject();
//			}
//			else {
//				vectankobject[i].MoveTank();
//			}
//			break;
//		case ��:
//			if (vectankobject[i].getTankDir() != ��)
//			{
//				vectankobject[i].ClsObject();
//				vectankobject[i].setTankDir(��);
//				vectankobject[i].DrawObject();
//			}
//			else {
//				vectankobject[i].MoveTank();
//			}
//			break;
//			//case 4://
//			//	//if (bulletobject.getBulletisDie() == false)
//			//	//	bulletobject = bulletobject.GreatBullet(vectankobject[i], vectankobject);    //��ʼ�����1���ӵ�
//			////}
//			//break;
//		}
//		if (fire == 1) //����
//		{
//				if (bulletobject.getBulletisDie() == false)
//				{
//					bulletobject = bulletobject.GreatBullet(vectankobject[i], vectankobject);    //��ʼ�����1���ӵ�
//				}
//		}
//		
//	}
//	return true;
//}

////ͨ�������A*�ƶ��з�̹��
bool CGameObject::MoveNPC()
{
	srand((unsigned)time(NULL));
	//����õо�̹�˿���

	for (int i = 2; i < vectankobject.size(); i++)
	{
		int dir = rand() % 4;    //�����̹�˷��򣬿���    /*/
		int fire = rand() % 5;
		vectankobject[i].setTankDir(dir);
		switch (vectankobject[i].getTankDir())
		{
		case ��:
			if (vectankobject[i].getTankDir() != ��) {
				//����̹��
				vectankobject[i].ClsObject();
				vectankobject[i].setTankDir(��);//��̹�˷����޸�Ϊ��
				vectankobject[i].DrawObject();
			}
			else {
				vectankobject[i].MoveTank();
			}
			break;
		case ��:
			if (vectankobject[i].getTankDir() != ��)
			{
				vectankobject[i].ClsObject();
				vectankobject[i].setTankDir(��);
				vectankobject[i].DrawObject();
			}
			else {
				vectankobject[i].MoveTank();
			}
			break;
		case ��:
			if (vectankobject[i].getTankDir() != ��)
			{
				vectankobject[i].ClsObject();
				vectankobject[i].setTankDir(��);
				vectankobject[i].DrawObject();
			}
			else {
				vectankobject[i].MoveTank();
			}
			break;
		case ��:
			if (vectankobject[i].getTankDir() != ��)
			{
				vectankobject[i].ClsObject();
				vectankobject[i].setTankDir(��);
				vectankobject[i].DrawObject();
			}
			else {
				vectankobject[i].MoveTank();
			}
			break;
			//case 4://
			//	//if (bulletobject.getBulletisDie() == false)
			//	//	bulletobject = bulletobject.GreatBullet(vectankobject[i], vectankobject);    //��ʼ�����1���ӵ�
			////}
			//break;
		}
		if (fire == 1) //����
		{
			if (bulletobject.getBulletisDie() == false)
			{
				bulletobject = bulletobject.GreatBullet(vectankobject[i], vectankobject);    //��ʼ�����1���ӵ�
			}
		}

	}
	return true;
}