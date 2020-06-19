#include"API.h"
#include"Data.h"
#include "Draw.h"


/*移动控制台光标打印图形*/
void printChar(int x, int y, char*pazChar, WORD wArr)
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
			MessageBox(NULL, "游戏结束", "退出", 0);
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
/*鼠标处理函数*/
void MouseEventProc(MOUSE_EVENT_RECORD mer,int &flag)
{
	mer.dwMousePosition.X /= 2;
	

		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
			//打印地图边框和菜单
			//if(//把鼠标限制再框外，)
			if ((g_Map[mer.dwMousePosition.Y][mer.dwMousePosition.X] == LUNG)&&
				mer.dwMousePosition.X<MAP_X&&
				mer.dwMousePosition.Y<MAP_Y) {
	
				g_Map[mer.dwMousePosition.Y][mer.dwMousePosition.X] = SIGN_WALL1;

				printChar(mer.dwMousePosition.X, mer.dwMousePosition.Y, "■", GRAY);
			}
		}//单击右键
		else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED) {
			if ((g_Map[mer.dwMousePosition.Y][mer.dwMousePosition.X] == LUNG) &&
				mer.dwMousePosition.X< MAP_X&&
				mer.dwMousePosition.Y < MAP_Y) {
				g_Map[mer.dwMousePosition.Y][mer.dwMousePosition.X] = SIGN_WATER;
				printChar(mer.dwMousePosition.X, mer.dwMousePosition.Y, "≈", COLOR_BLUE);
			}
		}
		else if (mer.dwButtonState == DOUBLE_CLICK) {
			
			flag = 1;
		}
	//	break;
	//case DOUBLE_CLICK:
	//	//双击之后退出地图编辑
	//	flag = 1;
	//	break;
	//}
}


/*键盘和鼠标的消息处理函数*/
int MessageLoop() {
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD stcRecord = { 0 };
	DWORD dwRead;
	int flag = 0;
	static int index = 0;
	SetConsoleMode(hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
	while (!flag)
	{
		//等待事件
		ReadConsoleInput(hStdin, &stcRecord, 1, &dwRead);
		//处理事件
		if (stcRecord.EventType == KEY_EVENT)
		{//键盘事件
			if (KeyEventProc(stcRecord.Event.KeyEvent,index) == 1)
			{
				return index;
				//break;
			}

		}//鼠标处理事件
		else if (stcRecord.EventType == MOUSE_EVENT) {
			MouseEventProc(stcRecord.Event.MouseEvent,flag);
		}
		else if (stcRecord.EventType == VK_ESCAPE) {
			break;
		}
	}
	return 0;
}
