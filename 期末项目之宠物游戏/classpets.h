#pragma once
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
class pet
{
public:
	pet(string name="����");
	void eat_food(string name,int energy);
	void play_result();
	void drash_result();
	void display_all();
	void name_pet(string s_name);
	string get_petname()
	{
		return name;
	}
	virtual void adopt_display() {};//���������������ʱ˵������Ϣ  ������Ҫ�õ��ļ��������ﲻ�ô��麯��������
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
	int add_close;  //��ˣ�������ܶ�
	int desc_health;  //���ٽ���ֵ
	int desc_close;
	int desc_hunger;
	string name;
	//char c_name[15];//���ڴ���֮ǰ����Ҫ��Ϊ�˷����ļ�����
};