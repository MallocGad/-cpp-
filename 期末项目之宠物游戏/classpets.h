#pragma once
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
class pet
{
public:
	pet(string name="宠物");
	void eat_food(string name,int energy);
	void play_result();
	void drash_result();
	void display_all();
	void name_pet(string s_name);
	string get_petname()
	{
		return name;
	}
	virtual void adopt_display() {};//这里输出的是领养时说出的信息  由于我要用到文件操作这里不用纯虚函数更方便
	friend ifstream & operator>>(ifstream &, pet &);
	friend ofstream & operator<<(ofstream &, pet &);
protected:
	//void str_cast();
	int full_close;    
	int now_close;
	int full_health;
	int now_health;
	int full_hunger;
	int now_hunger;
	int add_close;  //玩耍增加亲密度
	int desc_health;  //减少健康值
	int desc_close;
	int desc_hunger;
	string name;
	//char c_name[15];//用于储存之前，主要是为了方便文件操作
};