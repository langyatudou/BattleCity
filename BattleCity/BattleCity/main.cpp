#include<stdio.h>
#include <windows.h>
#include <conio.h>

#define �� 0
#define �� 1
#define �� 2
#define �� 3
#define CENTRE_X 10        //�ϲ��ֵ�һ��λ�õ�����
#define CENTRE_Y  20       //����

int g_dir;
/*�ƶ�����̨����ӡͼ��*/
void printChar(int x,int y,char*pazChar,WORD wArr =0x07)
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
	//2.���ÿ���̨�й���λ��
	SetConsoleTextAttribute(hOut, wArr);
	SetConsoleCursorPosition(hOut,loc);
	printf(pazChar);
}
/*
 ��Ϣ����   MessageBox(NULL, "��Ϸ����", "�˳�", 0);
*/

/*�����¼�������*/

int KeyEventProc(KEY_EVENT_RECORD ker) 
{
	int flag = 0;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (ker.bKeyDown) {
		if (ker.wVirtualKeyCode==VK_ESCAPE )//���������ֵ) 
		{
			MessageBox(NULL, "��Ϸ����", "�˳�", 0);
		}
		else if (ker.wVirtualKeyCode == VK_UP) {
			printChar(10, 10, "��ʼ����Ϸ",0x70);
		}
		else if (ker.wVirtualScanCode == VK_RETURN) {
			printf("��ʼ\n");
			return ++flag;
			//�������ñ��λ����
		}
	}
}

/*��괦����*/
void MouseEventProc(MOUSE_EVENT_RECORD mer) 
{
	switch (mer.dwEventFlags)
	{
	case 0:
		//����������
		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {

		
		}//�����Ҽ�
		else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED) {

		}
		break;
	case DOUBLE_CLICK:
		//˫��֮��Ҫ��������


		break;
	}
}



/*���̺�������Ϣ������*/
int MessageLoop() {
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD stcRecord = { 0 };
	DWORD dwRead;
	SetConsoleMode(hStdin, ENABLE_WINDOW_INPUT|ENABLE_MOUSE_INPUT);
	while (1) 
	{
		//�ȴ��¼�
		ReadConsoleInput(hStdin, &stcRecord, 1, &dwRead);
		//�����¼�
		if (stcRecord.EventType == KEY_EVENT)
		{//�����¼�
			if (KeyEventProc(stcRecord.Event.KeyEvent) == 1)
			{
				break;
			}

		}//��괦���¼�
		else if (stcRecord.EventType == MOUSE_EVENT) {
			MouseEventProc(stcRecord.Event.MouseEvent);
		}
		else if (stcRecord.EventType == VK_ESCAPE) {
			break;
		}
	}
	return 0;
}


void puttest() {

	printChar(10, 10, "��ʼ����Ϸ");
	printChar(10, 11, "������Ϸ");
	printChar(10, 12, "������Ϸ");
}










typedef struct _TANK {
	int x;
	int y;
}TANK,*PTANK;

TANK tank[3][3];

//��ʼ��̹������
void initTank(TANK(*ptank)[3]) {
	//̹���ϲ�������
	//CENTRE_X 10        //̹�˵����ĵ��x����
	//CENTRE_Y  20       //����
	for (int i = 0; i < 3; i++) {
		ptank[0][i].x = CENTRE_X + i;
		ptank[0][i].y = CENTRE_Y;
	}

	//̹���в�����
	for (int i = 0; i < 3; i++) {
		ptank[1][i].x = CENTRE_X + i;
		ptank[1][i].y = CENTRE_Y+1;
	}

	//̹���²�������
	for (int i = 0; i < 3; i++) {
		ptank[2][i].x = CENTRE_X + i;
		ptank[2][i].y = CENTRE_Y + 2;
	}
}
void DrawTank(TANK(*ptank)[3],int g_dir)
{
	if (g_dir == ��)
	{
		printChar(ptank[0][1].x, ptank[0][1].y, "��");
		for (int i = 0; i < 3; ++i)
		{
			printChar(ptank[1][i].x, ptank[1][i].y, "��");
		}
		for (int i = 0; i < 3; ++i)
		{
			if (i == 1) {
				printChar(ptank[2][i].x, ptank[2][i].y, " ");
			}
			else
				printChar(ptank[2][i].x, ptank[2][i].y, "��");
		}
	}

	if (g_dir == ��)
	{
		for (int i = 0; i < 3; ++i) {
			if (i == 1) {
				printChar(ptank[0][i].x, ptank[0][i].y, " ");
			}else
			printChar(ptank[0][i].x, ptank[0][i].y, "��");
		}
		for (int i = 0; i < 3; ++i)
		{
			printChar(ptank[1][i].x, ptank[1][i].y, "��");
		}
		for (int i = 0; i < 3; ++i)
		{
			if (i == 1) {
				printChar(ptank[2][i].x, ptank[2][i].y, "��");
			}
			else
				printChar(ptank[2][i].x, ptank[2][i].y, " ");
		}
	}
	//��
	if (g_dir == ��)
	{
		for (int i = 0; i < 3; ++i) {
			if (i == 0) {
				printChar(ptank[0][1].x, ptank[0][i].y, " ");
			}
			else
				printChar(ptank[0][i].x, ptank[0][i].y, "��");
		}
		for (int i = 0; i < 3; ++i)
		{
			if(i==2)
			printChar(ptank[1][i].x, ptank[1][i].y, " ");
			else
			printChar(ptank[1][i].x, ptank[1][i].y, "��");
		}
		for (int i = 0; i < 3; ++i)
		{
			if (i == 0) {
				printChar(ptank[2][i].x, ptank[2][i].y, " ");
			}
			else
				printChar(ptank[2][i].x, ptank[2][i].y, "��");
		}
	}
	//��
	if (g_dir == ��)
	{
		for (int i = 0; i < 3; ++i) {
			if (i == 2) {
				printChar(ptank[0][i].x, ptank[0][i].y, " ");
			}
			else
				printChar(ptank[0][i].x, ptank[0][i].y, "��");
		}
		for (int i = 0; i < 3; ++i)
		{
			if (i == 0)
				printChar(ptank[1][i].x, ptank[1][i].y, " ");
			else
				printChar(ptank[1][i].x, ptank[1][i].y, "��");
		}
		for (int i = 0; i < 3; ++i)
		{
			if (i == 2) {
				printChar(ptank[2][i].x, ptank[2][i].y, " ");
			}
			else
				printChar(ptank[2][i].x, ptank[2][i].y, "��");
		}
	}
}
void WipeTank(TANK(*ptank)[3])
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printChar(ptank[i][j].x, ptank[i][j].y, " ");
		}
	}
}
void moveTank(TANK(*ptank)[3],int g_dir) 
{
	if (g_dir == ��) {
		//̹���ϲ�������
		//CENTRE_X 10        //̹�˵����ĵ��x����
		//CENTRE_Y  20       //����
		for (int i = 0; i < 3; i++) {
			--ptank[0][i].y;
		}
		//̹���в�����
		for (int i = 0; i < 3; i++) {
			--ptank[1][i].y;
		}
		//̹���²�������
		for (int i = 0; i < 3; i++) {
			--ptank[2][i].y ;
		}
	}
	if (g_dir == ��) {
		for (int i = 0; i < 3; i++) {
			++ptank[0][i].y;
		}

		for (int i = 0; i < 3; i++) {
			++ptank[1][i].y;
		}
		for (int i = 0; i < 3; i++) {
			++ptank[2][i].y;
		}
	}
	if (g_dir == ��) {
		for (int i = 0; i < 3; i++) {
			--ptank[0][i].x;
		}
		for (int i = 0; i < 3; i++) {
			--ptank[1][i].x;	
		}
		for (int i = 0; i < 3; i++) {
			--ptank[2][i].x;
		}
	}
	if (g_dir == ��) {
		for (int i = 0; i < 3; i++) {
			++ptank[0][i].x;
		}
		for (int i = 0; i < 3; i++) {
			++ptank[1][i].x;
		}
		for (int i = 0; i < 3; i++) {
			++ptank[2][i].x;
		}

	}
}
void KeyDown(TANK(*ptank)[3])
{
	int ch = 0;
	if (_kbhit() != 0) {
		ch = _getch();
	}
	switch (ch) {
	case 'w':
	case'W':
		g_dir = ��;
			WipeTank(ptank);
			moveTank(ptank, g_dir);
			DrawTank(ptank, g_dir);
		break;
	case 's':
	case'S':
		g_dir = ��;
		WipeTank(ptank);
		moveTank(ptank, g_dir);
		DrawTank(ptank, g_dir);
		break;
	case 'a':
	case'A':
		g_dir = ��;
		WipeTank(ptank);
		moveTank(ptank, g_dir);
		DrawTank(ptank, g_dir);
		break;
	case 'd':
	case'D':
		g_dir = ��;
		WipeTank(ptank);
		moveTank(ptank, g_dir);
		DrawTank(ptank, g_dir);
		break;
	}
}






int main() {
	
	int ch2 = 0;
	//puttest();
	/*while (1) {
		MessageLoop();
		
		switch (ch2) {
		case 5:
			printf("��ʼ\n");
			break;
		case 1:
			printf("����\n");
			break;
		case 3:
			printf("�˳�\n");
			break;
		}
	}*/
	
	TANK*Ptank = NULL;
	TANK (*ptank)[3] = tank;
	initTank(ptank);
	DrawTank(ptank,g_dir);
	while (1) {
		KeyDown(ptank);
	}
	
	system("pause");
	return 0;
}