/*************************************
�ļ�����user.cpp
�ļ�������ʵ�������û���Ϣ�Ķ�ȡ����Ȳ��������û��Ĳ���
**************************************/
#include"user.h"
#include<conio.h>
#include<cstring>
user::user()//��ȡ���е��û�
{
	ifstream fin;
	u_pets = new pet[MAX];
	fin.open("user.txt", ios::in);
	if (!fin.is_open())
	{
		cout << "��ǰ���û���" << endl;
	}
	else
	{
		fin >> user_count;
		int n = user_count;
		while (n)
		{
			n--;
			p = new user_msg;  //����
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
	cout << "     ��ӭע�ᣡ" << endl;
	cout << "+++++++++++++++++" << endl;
	while (1)
	{
		cout << "�û���(10�ַ�����)��";
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
		cout << "���û��Ѿ���ע���ˣ�" << endl;
		cout << "==========================" << endl;
	}
	strcpy(p->user_name, now_name);
	while (1)
	{
		cout << "���룺";
		pass1 = inputpass();
		cout << endl;
		cout << "ȷ�����룺";
		pass2 = inputpass();
		cout << endl;
		if (pass1 == pass2)
		{
			cout << "+++++++++++++++++"<<endl;
			cout << "+    ע��ɹ�   +"<<endl;
			cout << "+    WELLCOM    +"<<endl;
			cout << "+++++++++++++++++" << endl;
			break;
		}
		else
		{
			cout << "!!!!!!!!!!!!!!!!!!!"<<endl;
			cout << "   �������벻һ��  "<<endl;
			cout << "    *��������*"<<endl;
			cout << "!!!!!!!!!!!!!!!!!!!" << endl;
			continue;
		}
	}
	strcpy(p->password, pass1.c_str());
	strcpy(p->petfilename, p->user_name);
	strcat(p->petfilename, ".dat");//���û�����Ϊ�ļ���
	if (head == NULL)
		head = p;
	user_count++;
}
string user::inputpass()//������������ĺ���
{
	string s_pass;
	char pass[11],c;
	memset(pass, '\0',11);
	int i = 0;
	while (i<11)
	{
		c = getch();
		if (c != '\r')  //���س�getch()���ص���\r
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
		cout << "�޷������û���Ϣ�ļ�!!" << endl;
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