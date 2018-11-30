#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
using namespace std;
#if 0
class my_string
{
public:
	//���캯��
	my_string(const char *str="")
	{
		if (str == nullptr)
		{
			assert(str);
			return;
		}
		my_str = new char[strlen(str)+1];
		strcpy(my_str, str);
	}
	//�������캯��
	my_string(const my_string& s)
		:my_str(new char[strlen(s.my_str) + 1])
	{
		strcpy(my_str, s.my_str);
	}
	my_string& operator=(const my_string& s)
	{
		if (this != &s)//�����Լ����Լ�����
		{
			char *pstr = new char[strlen(s.my_str) + 1];//�����µĿռ�
			strcpy(pstr, s.my_str);//������s�����ݿ������µĿռ���
			delete[] my_str;//�ͷžɵĿռ�
			my_str = pstr;
		}
		return *this;
	}
	//��������
	~my_string()
	{
		if (nullptr != my_str)
		{
			delete[] my_str;
			my_str = nullptr;
		}
	}
private:
	char *my_str;
};

void test()
{
	my_string d1;
	my_string d2("hello world");
	my_string d3 = d2;
	my_string d4(d2);
	my_string d5;
	d5 = d2;
}
int main()
{
	test();
	system("pause");
	return 0;
}
#endif
class my_string
{
public:
	//���캯��
	my_string(const char *str = "")
	{
		if (str == nullptr)
		{
			assert(str);
			return;
		}
		my_str = new char[strlen(str) + 1];
		strcpy(my_str, str);
	}
	//�������캯��
	my_string(const my_string& s)
		:my_str(nullptr)
	{
		//�����µ���ʱ������ɽ������������캯������ʱtempstr�ռ��ͷ�
		my_string tempstr(s.my_str);
		swap(my_str, tempstr.my_str);
	}
	//��ֵ���������
	my_string& operator=(my_string s)
	{
		swap(my_str, s.my_str);
		return *this;
	}
	//��������
	~my_string()
	{
		if (my_str != nullptr)
		{
			delete[] my_str;
			my_str = nullptr;
		}
	}
private:
	char *my_str;
};

void test()
{
	my_string d1;
	my_string d2("hello world");
	my_string d3 = d2;
	my_string d4(d2);
	my_string d5;
	d5 = d4;
}

int main()
{
	test();
	system("pause");
	return 0;
}