#pragma once


class CBaseObject
{
public:
	CBaseObject();
	~CBaseObject();
public:
	virtual bool DrawObject() = 0;       //画对象
	virtual bool ClsObject() = 0;        //清除对象
};

