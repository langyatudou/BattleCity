#pragma once
#include <windows.h>
#include <iostream>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
//��ͼ�࣬��Ҫ���ڻ���ָ��ͼ��


class CDrawObject
{
public:
	CDrawObject();
	~CDrawObject();
	/*�ƶ�����̨����ӡͼ��*/
	void printChar(int x,    
		int y,
		char*pazChar,        //��Ҫ��ӡ��ͼ��
		WORD wArr = 0x07);   //Ĭ��Ϊ��ɫ
	/*�����¼�������*/
	int KeyEventProc(KEY_EVENT_RECORD ker, int& index);
	/*��괦����*/
	void MouseEventProc(MOUSE_EVENT_RECORD,int&flag);
	/*���̺�������Ϣ������*/
	int MessageLoop();
	

	
public:
	
};

