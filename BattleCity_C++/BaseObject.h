#pragma once


class CBaseObject
{
public:
	CBaseObject();
	~CBaseObject();
public:
	virtual bool DrawObject() = 0;       //������
	virtual bool ClsObject() = 0;        //�������
};

