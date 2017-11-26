/*************************************
文件名：user.cpp
文件描述：实现所有用户信息的读取报错等不到具体用户的操作
**************************************/
#include"user.h"
#include<conio.h>
#include<cstring>
user::user()//读取所有的用户
{
	ifstream fin;
	u_pets = new pet[MAX];
	fin.open("user.txt", ios::in);
	if (!fin.is_open())
	{
		cout << "当前无用户！" << endl;
	}
	else
	{
		fin >> user_count;
		int n = user_count;
		while (n)
		{
			n--;
			p = new user_msg;  //链表
			if (head == NULL)
				head = q = p;
			else
				q->next = p;
			fin >> p->user_name;
			fin >> p->password;
			fin >> p->own_pets;
			fin >> p->petfilename;
			q = p;
		}
		fin.close();
	}
}
void user::logup()
{
	string pass1, pass2;
	bool flag;
	char now_name[11];
	if (head != NULL)
	{
		q = p;
		p = new user_msg;
		q->next = p;
	}
	else
		p = new user_msg;
	cout << "+++++++++++++++++" << endl;
	cout << "     欢迎注册！" << endl;
	cout << "+++++++++++++++++" << endl;
	while (1)
	{
		cout << "用户名(10字符以内)：";
		user_msg *tempp = head;
		cin >> now_name;
		cin.get();
		while (tempp)
		{
			if (strcmp(tempp->user_name, now_name) == 0)
				break;
			tempp = tempp->next;
		}
		if (tempp == NULL)
			break;
		cout << "==========================" << endl;
		cout << "该用户已经被注册了！" << endl;
		cout << "==========================" << endl;
	}
	strcpy(p->user_name, now_name);
	while (1)
	{
		cout << "密码：";
		pass1 = inputpass();
		cout << endl;
		cout << "确认密码：";
		pass2 = inputpass();
		cout << endl;
		if (pass1 == pass2)
		{
			cout << "+++++++++++++++++"<<endl;
			cout << "+    注册成功   +"<<endl;
			cout << "+    WELLCOM    +"<<endl;
			cout << "+++++++++++++++++" << endl;
			break;
		}
		else
		{
			cout << "!!!!!!!!!!!!!!!!!!!"<<endl;
			cout << "   两次输入不一致  "<<endl;
			cout << "    *重新输入*"<<endl;
			cout << "!!!!!!!!!!!!!!!!!!!" << endl;
			continue;
		}
	}
	strcpy(p->password, pass1.c_str());
	strcpy(p->petfilename, p->user_name);
	strcat(p->petfilename, ".dat");//将用户名作为文件名
	if (head == NULL)
		head = p;
	user_count++;
}
string user::inputpass()//用于输入密码的函数
{
	string s_pass;
	char pass[11],c;
	memset(pass, '\0',11);
	int i = 0;
	while (i<11)
	{
		c = getch();
		if (c != '\r')  //按回车getch()返回的是\r
		{
			pass[i++] = c;
			cout << "*";
		}
		else
			break;
	}
	s_pass = pass;
	return s_pass;
}
user::~user()
{
	ofstream fout;
	fout.open("user.txt", ios::out);
	if (!fout.is_open())
		cout << "无法创建用户信息文件!!" << endl;
	p = head;
	fout << user_count << " ";
	while (p!=NULL)
	{
		fout << p->user_name<<" ";
		fout << p->password<<" ";
		fout << p->own_pets<<" ";
		fout << p->petfilename<<" ";
		p = p->next;
	}
	fout.close();
}