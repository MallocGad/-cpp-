#pragma once
#include"expets.h"
#include"classpets.h"
struct user_msg   //��ǰ�û�����Ϣ
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
	void feed(pet &);//ι����
	void setpass();//�������뺯��
	void logup();//ע��
	void login();//�û���¼
	void displayuser();//�����ǰ�û�
	void displaypets();//�����ǰ�û��еĳ���
	void savepets();//���浱ǰ������Ϣ
	void getpetmsg();//��ȡ��ǰ�û��ĳ���
	void adoppet(string );//�û������˳���  
	user_msg* getuser()   //��ȡ��ǰ�û��Ľӿ�//��������
	{
		return p;
	}
	int getusercount()
	{
		return user_count;
	}
	inline void hello()//��������
	{
		cout << "+++++++++++++++++";
		cout << "    ��ӭ����   ";
		cout << "    WELLCOM    ";
		cout << "+++++++++++++++++"<<endl;
	}
	
	~user();
	pet *u_pets;
private :
	string inputpass();//�����������
	bool have_pet;         //��¼��ǰ�û��Ƿ��г���
	const int MAX = 10;//����һ��������ʮ������
	user_msg *p = NULL, *q = NULL, *head = NULL;
	int user_count = 0;//��¼Ŀǰ���ٸ����
};