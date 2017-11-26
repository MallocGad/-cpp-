#include"tools.h"
void hellomenu()
{
	cout << "+++++++++++++++++++++++++++++++++++" << endl;
	cout << "+                                 +" << endl;
	cout << "+         欢迎来到宠物游戏        +" << endl;
	cout << "+                                 +" << endl;
	cout << "+++++++++++++++++++++++++++++++++++" << endl;
}
int logchose()
{
	char choose;
	cout << "---------------------------------------------" << endl;
	cout << "|    请选择：                                |" << endl;
	cout << "|    1.注册新用户      2.已有账号登录        |" << endl;
	cout << "---------------------------------------------" << endl;
	while (1)
	{
		(cin >> choose).get();
		if (choose == '1');
		else if (choose == '2');
		else
		{
			cout << "输入错误》》" << endl;
			
			continue;
		}
		break;
	}
	return choose-'0';
}
char startgame(user &user1)
{
	char choose,
		opratepet;//保存用户所查看的宠物
	while (1)
	{
		int petcount = user1.getuser()->own_pets;//保存当前用户的宠物数量
		cout << "===================================================" << endl;
		cout << "=              请     选    择    ：              =" << endl;
		cout << "=        1.领养宠物       2.查看宠物              =" << endl;
		cout << "===================================================" << endl;
		while (1)
		{
			cin.get(choose).get();
			if (choose == '1');
			else if (choose == '2');
			else
			{
				cout << "输入错误》》" << endl;
				continue;
			}
			break;
		}
		if (choose == '1')
		{
			if (petcount > 10)
			{
				cout << "您的宠物数量已达上限！" << endl;
				continue;
			}
			cout << "============================================" << endl;
			cout << "==       请   选   择 ：                  ==" << endl;
			cout << "==      1.小狗。  2.小兔。  3.小猫。      ==" << endl;
			cout << "============================================" << endl;
			char ch;
			while (1)
			{
				cin.get(ch).get();
				switch (ch)
				{
				case '1':
					user1.adoppet("小狗"); break;
				case '2':
					user1.adoppet("小兔"); break;
				case'3':
					user1.adoppet("小猫"); break;
				default:cout << "输入有误，重新输入：" << endl; continue;
						break;
				}
				break;
			}
		}
		else if (choose == '2')
		{
			if (petcount <= 0)
			{
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				cout << "!!         您当前 还没有宠物         !!" << endl;
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				continue;
			}
			while (1)
			{
				user1.displaypets();
				cout << "请输入你要查看的宠物序号：";
				cin.get(opratepet).get();
				cout << endl;
				if (opratepet - '0' <= 0 && opratepet - '0' > petcount)
				{
					cout << "输入有误" << endl;
					continue;
				}
				return opratepet;
			}
		}
	}
}