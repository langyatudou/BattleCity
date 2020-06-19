#pragma once
#include <windows.h>
#include <iostream>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
//画图类，主要用于绘制指定图像


class CDrawObject
{
public:
	CDrawObject();
	~CDrawObject();
	/*移动控制台光标打印图形*/
	void printChar(int x,    
		int y,
		char*pazChar,        //需要打印的图形
		WORD wArr = 0x07);   //默认为白色
	/*键盘事件处理函数*/
	int KeyEventProc(KEY_EVENT_RECORD ker, int& index);
	/*鼠标处理函数*/
	void MouseEventProc(MOUSE_EVENT_RECORD,int&flag);
	/*键盘和鼠标的消息处理函数*/
	int MessageLoop();
	

	
public:
	
};

