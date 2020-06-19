#include "DrawObject.h"
#include"MapObject.h"
#include"GameObject.h"

CDrawObject::CDrawObject()
{
}


CDrawObject::~CDrawObject()
{
}

/*�ƶ�����̨����ӡͼ��*/
void CDrawObject::printChar(int x, int y, char*pazChar, WORD wArr)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//���ù����Ϣ
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = false;    //����ʾ���
	SetConsoleCursorInfo(hOut, &cci);
	//2.�޸Ĺ���ڿ���̨�е�λ��
	COORD loc;
	loc.X = 2 * x;
	loc.Y = y;
	//2.���ÿ���̨�й���ӡ����ɫ
	SetConsoleTextAttribute(hOut, wArr);
	//3.���ÿ���̨�й���λ��
	SetConsoleCursorPosition(hOut, loc);
	printf(pazChar);
}
/*�����¼�������*/
int CDrawObject::KeyEventProc(KEY_EVENT_RECORD ker, int& index)
{
	int flag = 0;
	int y = 27;
	int coclor = 0x04;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (ker.bKeyDown)
	{
		switch (ker.wVirtualKeyCode)
		{

		case VK_ESCAPE:
			MessageBox(NULL, "��ͼ�༭����", "�˳�", 0);
			//1.����Ƿ���Ҫ�����ͼ
			break;
		case VK_UP:
		{
			if (index < 1) {
				index = 3;
			}
			else
				index--;
			break;
		}
		case VK_DOWN:
		{
			if (index > 3) {
				index = 1;
			}
			else
				index++;
			break;
		}
		case VK_RETURN:  //�����˳���ͼ�༭������༭��ͼ
			
			MessageBox(NULL, "�˳���ͼ�༭�ɹ�", "�˳�", 0);
			return ++flag;
		}
		//PrintGameMenu(index);
		return 0;
	}
	return 2;
}
/*��괦����*/
int g_num = 0;
void CDrawObject::MouseEventProc(MOUSE_EVENT_RECORD mer, int &flag)
{
	CMapObject map;
	if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)//����������,ѡ����ǽ
	{
		int X = mer.dwMousePosition.X /= 2;    //����X����
		int Y = mer.dwMousePosition.Y;       //����Y����
		if (X >= MAP_X&&Y == 3)
		{
			g_num = ��ǽ;
			return;
		}
		else if (X >= MAP_X&&Y == 5) {
			g_num = ��ǽ;
		}
		else if (X >= MAP_X&&Y == 7) {
			g_num = ����;
		}
		else if (X >= MAP_X&&Y == 9) {
			g_num = �ݵ�;
		}
		else if (X >= MAP_X&&Y == 11) {
			g_num = ����;
		}
	//ͨ��ѡ��ȷ��Ҫ��������
		switch (g_num)
		{
		case ��ǽ:
			if ((0<X&&X< MAP_X - 1) && (Y>0 && Y < MAP_Y - 1))
			{
				//1������ͼ���󣬸���ͼ��ֵ�������ϰ�������ͼ
				g_Map[Y][X] = ��ǽ;
				printChar(X, Y, "��");
			}
			break;
		case ��ǽ:
			if ((0<X&&X< MAP_X - 1) && (Y>0 && Y < MAP_Y - 1))
			{
				g_Map[Y][X] = ��ǽ;
				printChar(X, Y, "��", ��ɫ);
			}
			break;
		case ����:
			if ((0<X&&X< MAP_X - 1) && (Y>0 && Y < MAP_Y - 1))
			{
				g_Map[Y][X] = ����;
				printChar(X, Y, "��", ��ɫ);
			}
			break;
		case �ݵ�:
			if ((0<X&&X< MAP_X - 1) && (Y>0 && Y < MAP_Y - 1))
			{
				g_Map[Y][X] = �ݵ�;
				printChar(X, Y, "��", ��ɫ);
			}
			break;
		case ����:
			if ((0<X&&X< MAP_X - 1) && (Y>0 && Y < MAP_Y - 1))
			{
				g_Map[Y][X] = ����;
				printChar(X, Y, "��");
			}
			break;
		}
	}
	//�����Ҽ�
	else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED) 
	{
		//��ȡ����X�����Y����
		int X = mer.dwMousePosition.X /= 2;    
		int Y = mer.dwMousePosition.Y;
		//������ǰλ���ϰ���
		if ((0 < X&&X < MAP_X - 1) && (Y > 0 && Y < MAP_Y - 1)) {
			g_Map[Y][X] = �յ�;
			printChar(X, Y, " ");
		}
	}
	else if (mer.dwButtonState == DOUBLE_CLICK) 
	{
		flag = 1;
	}
	
}


/*���̺�������Ϣ������*/
int CDrawObject::MessageLoop() {
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD stcRecord = { 0 };
	DWORD dwRead;
	int flag = 0;
	static int index = 0;
	DWORD mode = GetConsoleMode(hStdin, &mode);
	SetConsoleMode(hStdin, mode|ENABLE_ECHO_INPUT |ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
	while (!flag)
	{
		//�ȴ��¼�
		ReadConsoleInput(hStdin, &stcRecord, 1, &dwRead);
		//�����¼�
		if (stcRecord.EventType == KEY_EVENT)
		{//�����¼�
			if (KeyEventProc(stcRecord.Event.KeyEvent, index) == 1)
			{
				return index;
				//break;
			}

		}//��괦���¼�
		else if (stcRecord.EventType == MOUSE_EVENT) {
			MouseEventProc(stcRecord.Event.MouseEvent, flag);
		}
		else if (stcRecord.EventType == VK_ESCAPE) {
			break;
		}
	}
	return 0;
}
//
//CONSOLE_CURSOR_INFO cci;
//cci.bVisible = TRUE;
//SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);