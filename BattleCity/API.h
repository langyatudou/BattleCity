#pragma once
#include <windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>



/*移动控制台光标打印图形*/
void printChar(int, int, char*,WORD wArr = 0x07);

/*键盘事件处理函数*/
int KeyEventProc(KEY_EVENT_RECORD);
/*鼠标处理函数*/
void MouseEventProc(MOUSE_EVENT_RECORD);
/*键盘和鼠标的消息处理函数*/
int MessageLoop();
