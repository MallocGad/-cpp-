#pragma once
#include"classpets.h"
class dog:public pet
{
public:
	dog(string name="小汪");   //初始化dog的所有信息
	void adopt_display();
};
class cat:public pet
{
public:
	cat(string name="小喵");   //初始化cat的所有信息
	void adopt_display();
};
class rabbit :public pet
{
public:
	rabbit(string name="小白");
	void adopt_display();
};