#include"classpets.h"
#include<cstring>
void pet::play_result()
{
	if (0 >= now_hunger)
		cout << "����̫���˿�ȥι���ɣ�" << endl;
	else if (0 >= now_health)
		cout << "���ĳ���̫���ˣ�ȥϴϴ�ɣ�" << endl;
	else
	{
		now_close += add_close;
		now_close = now_close > full_close ? full_close:now_close;
		now_health -= desc_health;
		now_health = now_health < 0 ? 0 : now_health;
		cout << name <<"������ˣ�ܿ��ģ���ǰ���ܶȣ�" << now_close << endl;
		cout << "����С��Ū���ˣ���ǰ����ֵ��" << now_health << endl;
	}
}
void pet::eat_food(string name, int energy)
{
	now_hunger += energy;
	now_hunger=now_hunger > full_hunger?full_hunger:now_hunger;
	cout << name <<"����" << name << "��ǰ����ֵ" << now_hunger << endl;
}
void pet::drash_result()
{
	now_health = full_health;
	now_close -= desc_close;
	now_close = (now_close < 0 ? 0 : now_close);
	cout << name << "ϴ�ɾ���!" << endl;
}
void pet::display_all()
{
	cout << "============================" << endl;
	cout << "=   ��������:" << name<<endl;
	cout << "=   ����ֵ��" << now_health<<endl;
	cout << "=   ���ܶȣ�" << now_close<<endl;
	cout << "=   ����ֵ��" << now_hunger<<endl;
	cout << "============================" << endl;
}
void pet::name_pet(string s_name)
{
	name = s_name;
	cout << "============================" << endl;
	cout << "���ָ�����ɣ�" << name << "�ܿ��ģ�" << endl;
	//str_cast();
}
pet::pet(string s_name)
{
	name = s_name;
}
//void pet::str_cast()
//{
//	strncpy(c_name, name.c_str(), 15);
//}
ifstream & operator>>(ifstream &fin, pet &p) //�����������
{
	/*fin.read((char *)p.full_close,sizeof(p.full_close));  
	fin.read((char*)p.now_close, sizeof(p.now_close));
	fin.read((char*)p.full_health, sizeof(p.full_health));
	fin.read((char*)p.now_health, sizeof(p.now_health));
	fin.read((char*)p.full_hunger, sizeof(p.now_hunger));
	fin.read((char*)p.desc_health, sizeof(p.desc_health));
	fin.read((char*)p.desc_close, sizeof(p.desc_close));
	fin.read((char*)p.desc_hunger, sizeof(p.desc_hunger));
	fin.read((char*)p.c_name, sizeof(p.c_name));*/
	fin.read((char*)&p, sizeof(p));
	//strcpy(p.c_name,p.name.c_str());
	return fin;
}
ofstream & operator << (ofstream &fout, pet &p)
{
	/*fout.write((char *)p.full_close, sizeof(p.full_close));
	fout.write((char*)p.now_close, sizeof(p.now_close));
	fout.write((char*)p.full_health, sizeof(p.full_health));
	fout.write((char*)p.now_health, sizeof(p.now_health));
	fout.write((char*)p.full_hunger, sizeof(p.now_hunger));
	fout.write((char*)p.desc_health, sizeof(p.desc_health));
	fout.write((char*)p.desc_close, sizeof(p.desc_close));
	fout.write((char*)p.desc_hunger, sizeof(p.desc_hunger));
	fout.write((char*)p.c_name, sizeof(p.c_name));*/      //����˵Ӧ�ÿ��������������һ�䵫�����治��
	fout.write((char*)&p, sizeof(p));
	return fout;
}