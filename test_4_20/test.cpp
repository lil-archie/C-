#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#include"Func.h"

//int Add(int x, int y)
//{
//	return (x + y) * 10;
//}

//#define Add(int x, int y) return (x+y);
//#define Add(x, y) x+y
//#define Add(x, y) (x+y)
//#define Add(x, y) ((x)+(y))
//
//int main()
//{
//	for (int i = 0; i < 10000; i++)
//	{
//		cout << Add(i, i + 1) << endl;
//	}
//
//	if (Add(10, 20))
//	{
//
//	}
//
//	Add(10, 20) * 20;
//
//	int a = 1, b = 2;
//	Add(a | b, a & b); // (a | b + a & b)
//
//	return 0;
//}

// 宏函数 
// 优点-- 不需要建立栈帧，提高调用效率
// 缺点-- 复杂，容易出错、可读性差、不能调试

// 适用于短小的频繁调用的函数
// inline对于编译器仅仅只是一个建议，最终是否成为inline，编译器自己决定
// 像类似函数就加了inline也会被否决掉
// 1、比较长的函数
// 2、递归函数
// 默认debug模式下，inline不会起作用，否则不方便调试了
inline int Add(int x, int y)
{
	return (x + y) * 10;
}

//int main()
//{
//	for (int i = 0; i < 10000; i++)
//	{
//		cout << Add(i, i + 1) << endl;
//	}
//}

//#include "Func.h"
//
//int main()
//{
//	f(10);
//
//	return 0;
//}

//int main()
//{
//	int x = 10;
//	auto a = &x;
//	auto* b = &x;
//	auto& c = x;
//
//	int arr[] = { 1,2,3 };
//	for (auto& x : arr)
//	{
//		x++;
//	}
//
//	for (auto& x : arr)
//	{
//		cout << x << endl;
//	}
//
//	return 0;
//}


//void f(int)
//{
//	cout << "f(int)" << endl;
//}
//
//void f(int*)
//{
//	cout << "f(int*)" << endl;
//}
//
//int main()
//{
//	f(0);
//	f(NULL);
//	f(nullptr);
//}

struct Queue
{
	void Init()
	{

	}
};

//struct Stack
//class Stack
//{
//public:
//	// 成员函数
//	void Init(int defaultCapacity = 4)
//	{
//		a = (int*)malloc(sizeof(int) * capacity);
//		if (nullptr == a)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//
//		capacity = defaultCapacity;
//		top = 0;
//	}
//
//	void Push(int x)
//	{
//		//...
//		a[top++] = x;
//	}
//
//	void Destroy()
//	{
//		free(a);
//		a = nullptr;
//		top = capacity;
//	}
//
//	// ....
//private:
//	// 成员变量
//	int* a;
//	int top;
//	int capacity;
//};

// 20:12继续
class Date
{
public:
	void Init(int year)
	{
		// 这里的year到底是成员变量，还是函数形参？
		_year = year;
	}
private:
	int _year; // year_
	int _month;
	int _day;
};

#include"Func.h"

// C++兼容c语言。 struct以前的用法都可以继续用
// 同时struct升级成了类
//int main()
//{
//	struct Stack st1;
//	st1.Init(20);
//
//	Stack st2;
//	st2.Init();
//	st2.Push(1);
//	st2.Push(2);
//	st2.Push(3);
//	st2.Push(4);
//	st2.Destroy();
//
//	return 0;
//}

//int main()
//{
//	// 类实例化对象/对象定义
//	Stack st1;
//	Stack st2;
//	//st1.top = 1;
//
//	// 不能,类访问top是声明，top不能存数据
//	//Stack::top = 1;
//
//	return 0;
//}

int main()
{
	// 类实例化对象/对象定义
	Stack st1;
	Stack st2;
	Stack st3;
	Stack st4;

	st1.top = 0;
	st1.Push(1);

	st2.top = 1;
	st2.Push(1);

	// 对象中只存储的成员变量，没有存储成员函数
	cout << sizeof(st1) << endl;

	return 0;
}