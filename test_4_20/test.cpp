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

// �꺯�� 
// �ŵ�-- ����Ҫ����ջ֡����ߵ���Ч��
// ȱ��-- ���ӣ����׳����ɶ��Բ���ܵ���

// �����ڶ�С��Ƶ�����õĺ���
// inline���ڱ���������ֻ��һ�����飬�����Ƿ��Ϊinline���������Լ�����
// �����ƺ����ͼ���inlineҲ�ᱻ�����
// 1���Ƚϳ��ĺ���
// 2���ݹ麯��
// Ĭ��debugģʽ�£�inline���������ã����򲻷��������
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
//	// ��Ա����
//	void Init(int defaultCapacity = 4)
//	{
//		a = (int*)malloc(sizeof(int) * capacity);
//		if (nullptr == a)
//		{
//			perror("malloc����ռ�ʧ��");
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
//	// ��Ա����
//	int* a;
//	int top;
//	int capacity;
//};

// 20:12����
class Date
{
public:
	void Init(int year)
	{
		// �����year�����ǳ�Ա���������Ǻ����βΣ�
		_year = year;
	}
private:
	int _year; // year_
	int _month;
	int _day;
};

#include"Func.h"

// C++����c���ԡ� struct��ǰ���÷������Լ�����
// ͬʱstruct����������
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
//	// ��ʵ��������/������
//	Stack st1;
//	Stack st2;
//	//st1.top = 1;
//
//	// ����,�����top��������top���ܴ�����
//	//Stack::top = 1;
//
//	return 0;
//}

int main()
{
	// ��ʵ��������/������
	Stack st1;
	Stack st2;
	Stack st3;
	Stack st4;

	st1.top = 0;
	st1.Push(1);

	st2.top = 1;
	st2.Push(1);

	// ������ֻ�洢�ĳ�Ա������û�д洢��Ա����
	cout << sizeof(st1) << endl;

	return 0;
}