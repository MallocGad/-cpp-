#pragma once
#include"classpets.h"
class dog:public pet
{
public:
	dog(string name="С��");   //��ʼ��dog��������Ϣ
	void adopt_display();
};
class cat:public pet
{
public:
	cat(string name="С��");   //��ʼ��cat��������Ϣ
	void adopt_display();
};
class rabbit :public pet
{
public:
	rabbit(string name="С��");
	void adopt_display();
};