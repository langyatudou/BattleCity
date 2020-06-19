#include "DrawObject.h"
#include"MapObject.h"
#include"GameObject.h"

CDrawObject::CDrawObject()
{
}


CDrawObject::~CDrawObject()
{
}

/*移动控制台光标打印图形*/
void CDrawObject::printChar(int x, int y, char*pazChar, WORD wArr)
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
	//2.设置控制台中光标打印的颜色
	SetConsoleTextAttribute(hOut, wArr);
	//3.设置控制台中光标的位置
	SetConsoleCursorPosition(hOut, loc);
	printf(pazChar);
}
/*键盘事件处理函数*/
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
			MessageBox(NULL, "地图编辑结束", "退出", 0);
			//1.输出是否需要保存地图
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
		case VK_RETURN:  //代表退出地图编辑，保存编辑地图
			
			MessageBox(NULL, "退出地图编辑成功", "退出", 0);
			return ++flag;
		}
		//PrintGameMenu(index);
		return 0;
	}
	return 2;
}
/*鼠标处理函数*/
int g_num = 0;
void CDrawObject::MouseEventProc(MOUSE_EVENT_RECORD mer, int &flag)
{
	CMapObject map;
	if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)//鼠标左键按下,选择画铁墙
	{
		int X = mer.dwMousePosition.X /= 2;    //鼠标的X坐标
		int Y = mer.dwMousePosition.Y;       //鼠标的Y坐标
		if (X >= MAP_X&&Y == 3)
		{
			g_num = 铁墙;
			return;
		}
		else if (X >= MAP_X&&Y == 5) {
			g_num = 灰墙;
		}
		else if (X >= MAP_X&&Y == 7) {
			g_num = 河流;
		}
		else if (X >= MAP_X&&Y == 9) {
			g_num = 草地;
		}
		else if (X >= MAP_X&&Y == 11) {
			g_num = 基地;
		}
	//通过选择，确定要画的类型
		switch (g_num)
		{
		case 铁墙:
			if ((0<X&&X< MAP_X - 1) && (Y>0 && Y < MAP_Y - 1))
			{
				//1创建地图对象，给地图赋值，画出障碍物，保存地图
				g_Map[Y][X] = 铁墙;
				printChar(X, Y, "■");
			}
			break;
		case 灰墙:
			if ((0<X&&X< MAP_X - 1) && (Y>0 && Y < MAP_Y - 1))
			{
				g_Map[Y][X] = 灰墙;
				printChar(X, Y, "█", 灰色);
			}
			break;
		case 河流:
			if ((0<X&&X< MAP_X - 1) && (Y>0 && Y < MAP_Y - 1))
			{
				g_Map[Y][X] = 河流;
				printChar(X, Y, "≡", 蓝色);
			}
			break;
		case 草地:
			if ((0<X&&X< MAP_X - 1) && (Y>0 && Y < MAP_Y - 1))
			{
				g_Map[Y][X] = 草地;
				printChar(X, Y, "▓", 绿色);
			}
			break;
		case 基地:
			if ((0<X&&X< MAP_X - 1) && (Y>0 && Y < MAP_Y - 1))
			{
				g_Map[Y][X] = 基地;
				printChar(X, Y, "★");
			}
			break;
		}
	}
	//单击右键
	else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED) 
	{
		//获取鼠标的X坐标和Y坐标
		int X = mer.dwMousePosition.X /= 2;    
		int Y = mer.dwMousePosition.Y;
		//擦除当前位置障碍物
		if ((0 < X&&X < MAP_X - 1) && (Y > 0 && Y < MAP_Y - 1)) {
			g_Map[Y][X] = 空地;
			printChar(X, Y, " ");
		}
	}
	else if (mer.dwButtonState == DOUBLE_CLICK) 
	{
		flag = 1;
	}
	
}


/*键盘和鼠标的消息处理函数*/
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
		//等待事件
		ReadConsoleInput(hStdin, &stcRecord, 1, &dwRead);
		//处理事件
		if (stcRecord.EventType == KEY_EVENT)
		{//键盘事件
			if (KeyEventProc(stcRecord.Event.KeyEvent, index) == 1)
			{
				return index;
				//break;
			}

		}//鼠标处理事件
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