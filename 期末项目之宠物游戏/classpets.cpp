#include"classpets.h"
#include<cstring>
void pet::play_result()
{
	if (0 >= now_hunger)
		cout << "宠物太饿了快去喂它吧！" << endl;
	else if (0 >= now_health)
		cout << "您的宠物太脏了，去洗洗吧！" << endl;
	else
	{
		now_close += add_close;
		now_close = now_close > full_close ? full_close:now_close;
		now_health -= desc_health;
		now_health = now_health < 0 ? 0 : now_health;
		cout << name <<"和你玩耍很开心，当前亲密度：" << now_close << endl;
		cout << "但不小心弄脏了，当前健康值：" << now_health << endl;
	}
}
void pet::eat_food(string name, int energy)
{
	now_hunger += energy;
	now_hunger=now_hunger > full_hunger?full_hunger:now_hunger;
	cout << name <<"吃了" << name << "当前饥饿值" << now_hunger << endl;
}
void pet::drash_result()
{
	now_health = full_health;
	now_close -= desc_close;
	now_close = (now_close < 0 ? 0 : now_close);
	cout << name << "洗干净了!" << endl;
}
void pet::display_all()
{
	cout << "============================" << endl;
	cout << "=   宠物姓名:" << name<<endl;
	cout << "=   健康值：" << now_health<<endl;
	cout << "=   亲密度：" << now_close<<endl;
	cout << "=   饥饿值：" << now_hunger<<endl;
	cout << "============================" << endl;
}
void pet::name_pet(string s_name)
{
	name = s_name;
	cout << "============================" << endl;
	cout << "名字更改完成，" << name << "很开心！" << endl;
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
ifstream & operator>>(ifstream &fin, pet &p) //重载输入输出
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
	fout.write((char*)p.c_name, sizeof(p.c_name));*/      //按理说应该可以用上面代替这一句但是上面不行
	fout.write((char*)&p, sizeof(p));
	return fout;
}