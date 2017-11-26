/************************************
文件名：user2.cpp
文件描述：实现具体用户操作
*************************************/
#include"user.h"
void user::getpetmsg()//读取当前用户的宠物
{
	ifstream fin;
	fin.open(p->petfilename, ios::in);
	if (!fin.is_open())
		cout << "无法加载宠物信息" << endl;
	else
		have_pet = false;
	for (int i = 0; i < p->own_pets; i++)//重载输入宠物信息
	{
		fin >> u_pets[i];
		have_pet = true;
	}
}
void user::savepets()//保存当前宠物信息
{
	ofstream fout;
	if (!have_pet)
		return;
	else
	{
		fout.open(p->petfilename, ios::out);
		if (!fout.is_open())
		{
			cout << "异常错误宠物信息丢失！！" << endl;
			exit(0);
		}
		for (int i = 0; i < p->own_pets; i++)  //重载储存宠物信息
			fout << u_pets[i];
	}
}
void user::displayuser()//输出当前用户
{
	cout << "============================================" << endl;
	cout << "当前用户：" << p->user_name << "   " << "拥有宠物数:" << p->own_pets << endl;
}
void user::login()//用户登录
{
	char now_temp[11];
	cout << "=======================================" << endl;
	cout << "请登录：" << endl;
	while (1) 
	{
		user_msg *temp1 = head;
		cout << "用户名："; cin >> now_temp;
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
			cout << "用户名不存在，请重新输入：" << endl;
		}
	}
	while (1)
	{
		string t_pass;
		cout << endl << "密码:";
		t_pass = inputpass();
		cout << endl;
		if (strcmp(p->password, t_pass.c_str()) == 0)
			break;
		else
			cout << "密码错误，请重新输入" << endl;
	}
}
void user::displaypets()
{
	cout << "===========================================\n" << endl;
	if (p->own_pets == 0)
		cout << "当前无宠物宠物" << endl;
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
	if (adoptype == "小狗")
	{
		pettemp = new dog;
		u_pets[p->own_pets] = *pettemp;
	}
	else if (adoptype == "小猫")
	{
		pettemp = new cat;
		u_pets[p->own_pets] = *pettemp;
	}
	else if (adoptype == "小兔")
	{
		pettemp = new rabbit;
		u_pets[p->own_pets] = *pettemp;
	}
	else
		cout << "领养失败!!" << endl;
	p->own_pets++;
	pettemp->adopt_display();//这里实现了多态
}
void user::feed(pet &mypet)
{
	char chose;
	cout << "=======================================" << endl;
	cout << "=   1.苹果       2.白菜     3. 小鱼干  =" << endl;
	cout << "=  (水手牌)     (学委牌)    (黄氏秘制) =" << endl;
	cout << "=======================================" << endl;
	while (1)
	{
		cout << "亲选择：";
		cin.get(chose).get();
		switch (chose)
		{
		case'1':break;
		case'2':break;
		case '3':break;
		default:cout << "输入错误" << endl; continue; break;
		}
		break;
	}
	switch (chose)
	{
	case'1':mypet.eat_food("苹果", 40); break;
	case'2':mypet.eat_food("白菜", 60); break;
	case '3':mypet.eat_food("小鱼干", 75); break;
	default:cout << "输入错误" << endl; break;
	}
}