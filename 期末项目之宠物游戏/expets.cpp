#include"expets.h"
cat::cat(string s_name):pet(s_name)
{
	full_close=100;
	now_close=0;
	full_health=120;
	now_health=120;
	full_hunger=100;
	now_hunger=100;
	add_close=10;  //玩耍增加亲密度
	desc_health=5;  //减少健康值
	desc_close=8;
	desc_hunger=8;
};
void cat::adopt_display()
{
	cout << "恭喜领养了！"<< name << endl;
	cout << "属性描述：" << endl;
	cout << name << "天生比较高冷不易亲近,玩耍加" << add_close << "亲密度" << endl;
	cout << "但你好好照顾她，冰雪也会融化！" << endl;
}
dog::dog(string s_name):pet(s_name)
{
	full_close = 120;
	now_close = 10;
	full_health = 120;
	now_health = 120;
	full_hunger = 90;
	now_hunger = 90;
	add_close = 15;  //玩耍增加亲密度
	desc_health = 8;  //减少健康值
	desc_close = 4;
	desc_hunger = 15;
}
void dog::adopt_display()
{
	cout << "恭喜领养了:" << name << endl;
	cout << "属性描述：" << endl;
	cout << name <<"天生就喜欢人类,性格活泼开朗" << endl;
	cout << "但他爱玩闹，爱吃，你好好照顾他！他会一直陪你左右！" << endl;
}
rabbit::rabbit(string s_name):pet(s_name)//初始化列表
{
	full_close = 110;
	now_close = 0;
	full_health = 90;
	now_health = 90;
	full_hunger = 100;
	now_hunger = 100;
	add_close = 10;  //玩耍增加亲密度
	desc_health = 5;  //减少健康值
	desc_close = 10;
	desc_hunger = 10;
}
void rabbit::adopt_display()
{
	cout << "恭喜领养了！"<<name << endl;
	cout << "属性描述：" << endl;
	cout << name <<"天生性格比较内向，但很爱干净，让主人很省心。" << endl;
	cout << "你好好照顾她，她是你们的小公主！" << endl;
}