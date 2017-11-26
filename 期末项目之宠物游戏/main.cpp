#include"user.h"
#include"tools.h"
int main()
{
	char c_petnum;
	int petnum;    //记录操作第几个宠物
	hellomenu();
	user user1;
	if (user1.getusercount())
	{
		if (logchose() == 2)
			user1.login();
		else
			user1.logup();
	}
	else
		user1.logup();
	user1.getpetmsg();//读取宠物信息
	user1.hello();
	system("pause");
	system("cls");
	while (1)
	{
		char ch;
		user1.displayuser();
		user1.displaypets();
		c_petnum=startgame(user1);
		while (1)
		{
			bool flag = true;
			petnum = c_petnum - '0'-1;
			user1.u_pets[petnum].display_all();
			cout << "===================================================" << endl;
			cout << "1.和他玩耍  2.给他洗澡  3.喂食  4.取名字  0.结束操作" << endl;
			cin.get(ch).get();
			switch (ch)
			{
			case'1':
				user1.u_pets[petnum].play_result(); break;
			case'2':
				user1.u_pets[petnum].drash_result(); break;
			case '3':
				user1.feed(user1.u_pets[petnum]); break;
			case'4':
			{
				char name1[12];
				cout << "请输入名字：" << endl;
				cin >> name1;
				cin.get();
				user1.u_pets[petnum].name_pet(name1); break;
			}
			case'0':flag = false; break;
			default:
				cout << "输入有误>>" << endl;
				break;
			}
			if (!flag)
				break;
		}
		user1.savepets();//储存
		cout << "======================================" << endl;
		cout << "=     1.返回上一级     2退出游戏     =" << endl;
		cout << "======================================" << endl;
		char isexist;
		while (1)
		{
			cin.get(isexist).get();
			if (isexist == '1');
			else if (isexist == '2')
			{
				cout << "欢迎下次到来！" << endl;
				user1.~user();//在这里调用析构函数，因为exit直接退出程序无法执行析构
				exit(0);
			}
			else
			{
				cout << "======================" << endl;
				cout << "==     输入有误     ==" << endl;
				cout << "======================" << endl;
				continue;
			}
			break;
		}
	}
	return 0;
}