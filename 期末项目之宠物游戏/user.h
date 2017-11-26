#pragma once
#include"expets.h"
#include"classpets.h"
struct user_msg   //当前用户的信息
{
	int own_pets = 0;
	char user_name[11];
	char password[11];
	char petfilename[20];
	user_msg *next = NULL;
};
class user
{
public:
	user();
	void feed(pet &);//喂宠物
	void setpass();//更改密码函数
	void logup();//注册
	void login();//用户登录
	void displayuser();//输出当前用户
	void displaypets();//输出当前用户有的宠物
	void savepets();//保存当前宠物信息
	void getpetmsg();//读取当前用户的宠物
	void adoppet(string );//用户领养了宠物  
	user_msg* getuser()   //获取当前用户的接口//内联函数
	{
		return p;
	}
	int getusercount()
	{
		return user_count;
	}
	inline void hello()//内联函数
	{
		cout << "+++++++++++++++++";
		cout << "    欢迎到来   ";
		cout << "    WELLCOM    ";
		cout << "+++++++++++++++++"<<endl;
	}
	
	~user();
	pet *u_pets;
private :
	string inputpass();//输入密码操作
	bool have_pet;         //记录当前用户是否有宠物
	const int MAX = 10;//设置一个玩家最多十个宠物
	user_msg *p = NULL, *q = NULL, *head = NULL;
	int user_count = 0;//记录目前多少个玩家
};