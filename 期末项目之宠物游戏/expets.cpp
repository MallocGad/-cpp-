#include"expets.h"
cat::cat(string s_name):pet(s_name)
{
	full_close=100;
	now_close=0;
	full_health=120;
	now_health=120;
	full_hunger=100;
	now_hunger=100;
	add_close=10;  //��ˣ�������ܶ�
	desc_health=5;  //���ٽ���ֵ
	desc_close=8;
	desc_hunger=8;
};
void cat::adopt_display()
{
	cout << "��ϲ�����ˣ�"<< name << endl;
	cout << "����������" << endl;
	cout << name << "�����Ƚϸ��䲻���׽�,��ˣ��" << add_close << "���ܶ�" << endl;
	cout << "����ú��չ�������ѩҲ���ڻ���" << endl;
}
dog::dog(string s_name):pet(s_name)
{
	full_close = 120;
	now_close = 10;
	full_health = 120;
	now_health = 120;
	full_hunger = 90;
	now_hunger = 90;
	add_close = 15;  //��ˣ�������ܶ�
	desc_health = 8;  //���ٽ���ֵ
	desc_close = 4;
	desc_hunger = 15;
}
void dog::adopt_display()
{
	cout << "��ϲ������:" << name << endl;
	cout << "����������" << endl;
	cout << name <<"������ϲ������,�Ը���ÿ���" << endl;
	cout << "���������֣����ԣ���ú��չ���������һֱ�������ң�" << endl;
}
rabbit::rabbit(string s_name):pet(s_name)//��ʼ���б�
{
	full_close = 110;
	now_close = 0;
	full_health = 90;
	now_health = 90;
	full_hunger = 100;
	now_hunger = 100;
	add_close = 10;  //��ˣ�������ܶ�
	desc_health = 5;  //���ٽ���ֵ
	desc_close = 10;
	desc_hunger = 10;
}
void rabbit::adopt_display()
{
	cout << "��ϲ�����ˣ�"<<name << endl;
	cout << "����������" << endl;
	cout << name <<"�����Ը�Ƚ����򣬵��ܰ��ɾ��������˺�ʡ�ġ�" << endl;
	cout << "��ú��չ������������ǵ�С������" << endl;
}