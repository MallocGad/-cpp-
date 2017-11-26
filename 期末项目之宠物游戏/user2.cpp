/************************************
�ļ�����user2.cpp
�ļ�������ʵ�־����û�����
*************************************/
#include"user.h"
void user::getpetmsg()//��ȡ��ǰ�û��ĳ���
{
	ifstream fin;
	fin.open(p->petfilename, ios::in);
	if (!fin.is_open())
		cout << "�޷����س�����Ϣ" << endl;
	else
		have_pet = false;
	for (int i = 0; i < p->own_pets; i++)//�������������Ϣ
	{
		fin >> u_pets[i];
		have_pet = true;
	}
}
void user::savepets()//���浱ǰ������Ϣ
{
	ofstream fout;
	if (!have_pet)
		return;
	else
	{
		fout.open(p->petfilename, ios::out);
		if (!fout.is_open())
		{
			cout << "�쳣���������Ϣ��ʧ����" << endl;
			exit(0);
		}
		for (int i = 0; i < p->own_pets; i++)  //���ش��������Ϣ
			fout << u_pets[i];
	}
}
void user::displayuser()//�����ǰ�û�
{
	cout << "============================================" << endl;
	cout << "��ǰ�û���" << p->user_name << "   " << "ӵ�г�����:" << p->own_pets << endl;
}
void user::login()//�û���¼
{
	char now_temp[11];
	cout << "=======================================" << endl;
	cout << "���¼��" << endl;
	while (1) 
	{
		user_msg *temp1 = head;
		cout << "�û�����"; cin >> now_temp;
		cin.get();
		while (temp1)
		{
			if (strcmp(p->user_name, now_temp) == 0)
			{
				p = temp1;
				break;
			}
			temp1 = temp1->next;
		}
		if (temp1 != NULL)
			break;
		else
		{
			cout << "===============================" << endl;
			cout << "�û��������ڣ����������룺" << endl;
		}
	}
	while (1)
	{
		string t_pass;
		cout << endl << "����:";
		t_pass = inputpass();
		cout << endl;
		if (strcmp(p->password, t_pass.c_str()) == 0)
			break;
		else
			cout << "�����������������" << endl;
	}
}
void user::displaypets()
{
	cout << "===========================================\n" << endl;
	if (p->own_pets == 0)
		cout << "��ǰ�޳������" << endl;
	else
	for (int i = 0; i < p->own_pets; i++)
	{
		cout << "   " << i + 1 << "." << u_pets[i].get_petname() << "   ";
		if (i % 2 != 0)
			cout <<endl;
	}
	cout << "\n===========================================" << endl;
}
void user::adoppet(string adoptype)
{
	pet *pettemp;
	if (adoptype == "С��")
	{
		pettemp = new dog;
		u_pets[p->own_pets] = *pettemp;
	}
	else if (adoptype == "Сè")
	{
		pettemp = new cat;
		u_pets[p->own_pets] = *pettemp;
	}
	else if (adoptype == "С��")
	{
		pettemp = new rabbit;
		u_pets[p->own_pets] = *pettemp;
	}
	else
		cout << "����ʧ��!!" << endl;
	p->own_pets++;
	pettemp->adopt_display();//����ʵ���˶�̬
}
void user::feed(pet &mypet)
{
	char chose;
	cout << "=======================================" << endl;
	cout << "=   1.ƻ��       2.�ײ�     3. С���  =" << endl;
	cout << "=  (ˮ����)     (ѧί��)    (��������) =" << endl;
	cout << "=======================================" << endl;
	while (1)
	{
		cout << "��ѡ��";
		cin.get(chose).get();
		switch (chose)
		{
		case'1':break;
		case'2':break;
		case '3':break;
		default:cout << "�������" << endl; continue; break;
		}
		break;
	}
	switch (chose)
	{
	case'1':mypet.eat_food("ƻ��", 40); break;
	case'2':mypet.eat_food("�ײ�", 60); break;
	case '3':mypet.eat_food("С���", 75); break;
	default:cout << "�������" << endl; break;
	}
}