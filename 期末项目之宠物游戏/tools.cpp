#include"tools.h"
void hellomenu()
{
	cout << "+++++++++++++++++++++++++++++++++++" << endl;
	cout << "+                                 +" << endl;
	cout << "+         ��ӭ����������Ϸ        +" << endl;
	cout << "+                                 +" << endl;
	cout << "+++++++++++++++++++++++++++++++++++" << endl;
}
int logchose()
{
	char choose;
	cout << "---------------------------------------------" << endl;
	cout << "|    ��ѡ��                                |" << endl;
	cout << "|    1.ע�����û�      2.�����˺ŵ�¼        |" << endl;
	cout << "---------------------------------------------" << endl;
	while (1)
	{
		(cin >> choose).get();
		if (choose == '1');
		else if (choose == '2');
		else
		{
			cout << "������󡷡�" << endl;
			
			continue;
		}
		break;
	}
	return choose-'0';
}
char startgame(user &user1)
{
	char choose,
		opratepet;//�����û����鿴�ĳ���
	while (1)
	{
		int petcount = user1.getuser()->own_pets;//���浱ǰ�û��ĳ�������
		cout << "===================================================" << endl;
		cout << "=              ��     ѡ    ��    ��              =" << endl;
		cout << "=        1.��������       2.�鿴����              =" << endl;
		cout << "===================================================" << endl;
		while (1)
		{
			cin.get(choose).get();
			if (choose == '1');
			else if (choose == '2');
			else
			{
				cout << "������󡷡�" << endl;
				continue;
			}
			break;
		}
		if (choose == '1')
		{
			if (petcount > 10)
			{
				cout << "���ĳ��������Ѵ����ޣ�" << endl;
				continue;
			}
			cout << "============================================" << endl;
			cout << "==       ��   ѡ   �� ��                  ==" << endl;
			cout << "==      1.С����  2.С�á�  3.Сè��      ==" << endl;
			cout << "============================================" << endl;
			char ch;
			while (1)
			{
				cin.get(ch).get();
				switch (ch)
				{
				case '1':
					user1.adoppet("С��"); break;
				case '2':
					user1.adoppet("С��"); break;
				case'3':
					user1.adoppet("Сè"); break;
				default:cout << "���������������룺" << endl; continue;
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
				cout << "!!         ����ǰ ��û�г���         !!" << endl;
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				continue;
			}
			while (1)
			{
				user1.displaypets();
				cout << "��������Ҫ�鿴�ĳ�����ţ�";
				cin.get(opratepet).get();
				cout << endl;
				if (opratepet - '0' <= 0 && opratepet - '0' > petcount)
				{
					cout << "��������" << endl;
					continue;
				}
				return opratepet;
			}
		}
	}
}