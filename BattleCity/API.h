#pragma once
#include <windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>



/*�ƶ�����̨����ӡͼ��*/
void printChar(int, int, char*,WORD wArr = 0x07);

/*�����¼�������*/
int KeyEventProc(KEY_EVENT_RECORD);
/*��괦����*/
void MouseEventProc(MOUSE_EVENT_RECORD);
/*���̺�������Ϣ������*/
int MessageLoop();
