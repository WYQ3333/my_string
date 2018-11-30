#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
using namespace std;
#if 0
class my_string
{
public:
	//构造函数
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
	//传统写法拷贝构造函数
	my_string(const my_string& s)
		:my_str(new char[strlen(s.my_str) + 1])
	{
		strcpy(my_str, s.my_str);
	}
	my_string& operator=(const my_string& s)
	{
		if (this != &s)//不是自己给自己拷贝
		{
			char *pstr = new char[strlen(s.my_str) + 1];//开辟新的空间
			strcpy(pstr, s.my_str);//将对象s的数据拷贝到新的空间中
			delete[] my_str;//释放旧的空间
			my_str = pstr;
		}
		return *this;
	}
	void display()
	{
		cout << my_str << endl;
	}
	//析构函数
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
	cout << "d1中存放空串";
	d1.display();
	my_string d2("hello world");
	cout << "d2:";
	d2.display();
	my_string d3 = d2;
	cout << "d3:";
	d3.display();
	my_string d4(d2);
	cout << "d4:";
	d4.display();
	my_string d5;
	d5 = d4;
	cout << "d5:";
	d5.display();
}
int main()
{
	test();
	system("pause");
	return 0;
}
#endif
#if 1
class my_string
{
public:
	//构造函数
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
	//现代写法拷贝构造函数
	my_string(const my_string& s)
		:my_str(nullptr)
	{
		//建立新的临时对象，完成交换，拷贝构造函数结束时tempstr空间释放
		my_string tempstr(s.my_str);
		swap(my_str, tempstr.my_str);
	}
	//赋值运算符重载
	my_string& operator=(my_string s)
	{
		swap(my_str, s.my_str);
		return *this;
	}
	void display()
	{
		cout << my_str << endl;
	}
	//析构函数
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
	cout << "d1中存放空串";
	d1.display();
	my_string d2("I love you");
	cout << "d2:";
	d2.display();
	my_string d3 = d2;
	cout << "d3:";
	d3.display();
	my_string d4(d2);
	cout << "d4:";
	d4.display();
	my_string d5;
	d5 = d4;
	cout << "d5:";
	d5.display();
}

int main()
{
	test();
	system("pause");
	return 0;
}
#endif