#include"user.h"
#include"tools.h"
int main()
{
	char c_petnum;
	int petnum;    //��¼�����ڼ�������
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
	user1.getpetmsg();//��ȡ������Ϣ
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
			cout << "1.������ˣ  2.����ϴ��  3.ιʳ  4.ȡ����  0.��������" << endl;
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
				cout << "���������֣�" << endl;
				cin >> name1;
				cin.get();
				user1.u_pets[petnum].name_pet(name1); break;
			}
			case'0':flag = false; break;
			default:
				cout << "��������>>" << endl;
				break;
			}
			if (!flag)
				break;
		}
		user1.savepets();//����
		cout << "======================================" << endl;
		cout << "=     1.������һ��     2�˳���Ϸ     =" << endl;
		cout << "======================================" << endl;
		char isexist;
		while (1)
		{
			cin.get(isexist).get();
			if (isexist == '1');
			else if (isexist == '2')
			{
				cout << "��ӭ�´ε�����" << endl;
				user1.~user();//���������������������Ϊexitֱ���˳������޷�ִ������
				exit(0);
			}
			else
			{
				cout << "======================" << endl;
				cout << "==     ��������     ==" << endl;
				cout << "======================" << endl;
				continue;
			}
			break;
		}
	}
	return 0;
}