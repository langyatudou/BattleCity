#include<stdio.h>
#include <windows.h>
#include <conio.h>

#define 上 0
#define 下 1
#define 左 2
#define 右 3
#define CENTRE_X 10        //上部分第一个位置的坐标
#define CENTRE_Y  20       //坐标

int g_dir;
/*移动控制台光标打印图形*/
void printChar(int x,int y,char*pazChar,WORD wArr =0x07)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//设置光标信息
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = false;    //不显示光标
	SetConsoleCursorInfo(hOut, &cci);
	//2.修改光标在控制台中的位置
	COORD loc;
	loc.X = 2 * x;
	loc.Y = y;
	//2.设置控制台中光标的位置
	SetConsoleTextAttribute(hOut, wArr);
	SetConsoleCursorPosition(hOut,loc);
	printf(pazChar);
}
/*
 消息弹窗   MessageBox(NULL, "游戏结束", "退出", 0);
*/

/*键盘事件处理函数*/

int KeyEventProc(KEY_EVENT_RECORD ker) 
{
	int flag = 0;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (ker.bKeyDown) {
		if (ker.wVirtualKeyCode==VK_ESCAPE )//按键虚拟键值) 
		{
			MessageBox(NULL, "游戏结束", "退出", 0);
		}
		else if (ker.wVirtualKeyCode == VK_UP) {
			printChar(10, 10, "开始新游戏",0x70);
		}
		else if (ker.wVirtualScanCode == VK_RETURN) {
			printf("开始\n");
			return ++flag;
			//考虑设置标记位问题
		}
	}
}

/*鼠标处理函数*/
void MouseEventProc(MOUSE_EVENT_RECORD mer) 
{
	switch (mer.dwEventFlags)
	{
	case 0:
		//单击鼠标左键
		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {

		
		}//单击右键
		else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED) {

		}
		break;
	case DOUBLE_CLICK:
		//双击之后要做的事情


		break;
	}
}



/*键盘和鼠标的消息处理函数*/
int MessageLoop() {
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD stcRecord = { 0 };
	DWORD dwRead;
	SetConsoleMode(hStdin, ENABLE_WINDOW_INPUT|ENABLE_MOUSE_INPUT);
	while (1) 
	{
		//等待事件
		ReadConsoleInput(hStdin, &stcRecord, 1, &dwRead);
		//处理事件
		if (stcRecord.EventType == KEY_EVENT)
		{//键盘事件
			if (KeyEventProc(stcRecord.Event.KeyEvent) == 1)
			{
				break;
			}

		}//鼠标处理事件
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

	printChar(10, 10, "开始新游戏");
	printChar(10, 11, "载入游戏");
	printChar(10, 12, "保存游戏");
}










typedef struct _TANK {
	int x;
	int y;
}TANK,*PTANK;

TANK tank[3][3];

//初始化坦克坐标
void initTank(TANK(*ptank)[3]) {
	//坦克上部分坐标
	//CENTRE_X 10        //坦克的中心点的x坐标
	//CENTRE_Y  20       //坐标
	for (int i = 0; i < 3; i++) {
		ptank[0][i].x = CENTRE_X + i;
		ptank[0][i].y = CENTRE_Y;
	}

	//坦克中部坐标
	for (int i = 0; i < 3; i++) {
		ptank[1][i].x = CENTRE_X + i;
		ptank[1][i].y = CENTRE_Y+1;
	}

	//坦克下部分坐标
	for (int i = 0; i < 3; i++) {
		ptank[2][i].x = CENTRE_X + i;
		ptank[2][i].y = CENTRE_Y + 2;
	}
}
void DrawTank(TANK(*ptank)[3],int g_dir)
{
	if (g_dir == 上)
	{
		printChar(ptank[0][1].x, ptank[0][1].y, "■");
		for (int i = 0; i < 3; ++i)
		{
			printChar(ptank[1][i].x, ptank[1][i].y, "■");
		}
		for (int i = 0; i < 3; ++i)
		{
			if (i == 1) {
				printChar(ptank[2][i].x, ptank[2][i].y, " ");
			}
			else
				printChar(ptank[2][i].x, ptank[2][i].y, "■");
		}
	}

	if (g_dir == 下)
	{
		for (int i = 0; i < 3; ++i) {
			if (i == 1) {
				printChar(ptank[0][i].x, ptank[0][i].y, " ");
			}else
			printChar(ptank[0][i].x, ptank[0][i].y, "■");
		}
		for (int i = 0; i < 3; ++i)
		{
			printChar(ptank[1][i].x, ptank[1][i].y, "■");
		}
		for (int i = 0; i < 3; ++i)
		{
			if (i == 1) {
				printChar(ptank[2][i].x, ptank[2][i].y, "■");
			}
			else
				printChar(ptank[2][i].x, ptank[2][i].y, " ");
		}
	}
	//左
	if (g_dir == 左)
	{
		for (int i = 0; i < 3; ++i) {
			if (i == 0) {
				printChar(ptank[0][1].x, ptank[0][i].y, " ");
			}
			else
				printChar(ptank[0][i].x, ptank[0][i].y, "■");
		}
		for (int i = 0; i < 3; ++i)
		{
			if(i==2)
			printChar(ptank[1][i].x, ptank[1][i].y, " ");
			else
			printChar(ptank[1][i].x, ptank[1][i].y, "■");
		}
		for (int i = 0; i < 3; ++i)
		{
			if (i == 0) {
				printChar(ptank[2][i].x, ptank[2][i].y, " ");
			}
			else
				printChar(ptank[2][i].x, ptank[2][i].y, "■");
		}
	}
	//右
	if (g_dir == 右)
	{
		for (int i = 0; i < 3; ++i) {
			if (i == 2) {
				printChar(ptank[0][i].x, ptank[0][i].y, " ");
			}
			else
				printChar(ptank[0][i].x, ptank[0][i].y, "■");
		}
		for (int i = 0; i < 3; ++i)
		{
			if (i == 0)
				printChar(ptank[1][i].x, ptank[1][i].y, " ");
			else
				printChar(ptank[1][i].x, ptank[1][i].y, "■");
		}
		for (int i = 0; i < 3; ++i)
		{
			if (i == 2) {
				printChar(ptank[2][i].x, ptank[2][i].y, " ");
			}
			else
				printChar(ptank[2][i].x, ptank[2][i].y, "■");
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
	if (g_dir == 上) {
		//坦克上部分坐标
		//CENTRE_X 10        //坦克的中心点的x坐标
		//CENTRE_Y  20       //坐标
		for (int i = 0; i < 3; i++) {
			--ptank[0][i].y;
		}
		//坦克中部坐标
		for (int i = 0; i < 3; i++) {
			--ptank[1][i].y;
		}
		//坦克下部分坐标
		for (int i = 0; i < 3; i++) {
			--ptank[2][i].y ;
		}
	}
	if (g_dir == 下) {
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
	if (g_dir == 左) {
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
	if (g_dir == 右) {
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
		g_dir = 上;
			WipeTank(ptank);
			moveTank(ptank, g_dir);
			DrawTank(ptank, g_dir);
		break;
	case 's':
	case'S':
		g_dir = 下;
		WipeTank(ptank);
		moveTank(ptank, g_dir);
		DrawTank(ptank, g_dir);
		break;
	case 'a':
	case'A':
		g_dir = 左;
		WipeTank(ptank);
		moveTank(ptank, g_dir);
		DrawTank(ptank, g_dir);
		break;
	case 'd':
	case'D':
		g_dir = 右;
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
			printf("开始\n");
			break;
		case 1:
			printf("载入\n");
			break;
		case 3:
			printf("退出\n");
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