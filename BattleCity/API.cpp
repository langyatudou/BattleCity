#include"API.h"
#include"Data.h"
#include "Draw.h"


/*�ƶ�����̨����ӡͼ��*/
void printChar(int x, int y, char*pazChar, WORD wArr)
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
int KeyEventProc(KEY_EVENT_RECORD ker,int& index)
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
			MessageBox(NULL, "��Ϸ����", "�˳�", 0);
			break;
		case VK_UP:
		{
			if (index <1) {
				index = 3;
			}else
			index--;
			break;
		}
		case VK_DOWN:
		{
			if (index > 3) {
				index = 1;
			}else
			index++;
			break;
		}
		case VK_RETURN:
			return ++flag;
		}
		PrintGameMenu(index);
		return 0;
	}
	return 2;
}
/*��괦����*/
void MouseEventProc(MOUSE_EVENT_RECORD mer,int &flag)
{
	mer.dwMousePosition.X /= 2;
	

		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
			//��ӡ��ͼ�߿�Ͳ˵�
			//if(//����������ٿ��⣬)
			if ((g_Map[mer.dwMousePosition.Y][mer.dwMousePosition.X] == LUNG)&&
				mer.dwMousePosition.X<MAP_X&&
				mer.dwMousePosition.Y<MAP_Y) {
	
				g_Map[mer.dwMousePosition.Y][mer.dwMousePosition.X] = SIGN_WALL1;

				printChar(mer.dwMousePosition.X, mer.dwMousePosition.Y, "��", GRAY);
			}
		}//�����Ҽ�
		else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED) {
			if ((g_Map[mer.dwMousePosition.Y][mer.dwMousePosition.X] == LUNG) &&
				mer.dwMousePosition.X< MAP_X&&
				mer.dwMousePosition.Y < MAP_Y) {
				g_Map[mer.dwMousePosition.Y][mer.dwMousePosition.X] = SIGN_WATER;
				printChar(mer.dwMousePosition.X, mer.dwMousePosition.Y, "��", COLOR_BLUE);
			}
		}
		else if (mer.dwButtonState == DOUBLE_CLICK) {
			
			flag = 1;
		}
	//	break;
	//case DOUBLE_CLICK:
	//	//˫��֮���˳���ͼ�༭
	//	flag = 1;
	//	break;
	//}
}


/*���̺�������Ϣ������*/
int MessageLoop() {
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD stcRecord = { 0 };
	DWORD dwRead;
	int flag = 0;
	static int index = 0;
	SetConsoleMode(hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
	while (!flag)
	{
		//�ȴ��¼�
		ReadConsoleInput(hStdin, &stcRecord, 1, &dwRead);
		//�����¼�
		if (stcRecord.EventType == KEY_EVENT)
		{//�����¼�
			if (KeyEventProc(stcRecord.Event.KeyEvent,index) == 1)
			{
				return index;
				//break;
			}

		}//��괦���¼�
		else if (stcRecord.EventType == MOUSE_EVENT) {
			MouseEventProc(stcRecord.Event.MouseEvent,flag);
		}
		else if (stcRecord.EventType == VK_ESCAPE) {
			break;
		}
	}
	return 0;
}
