#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#include<stdlib.h>

//class Stack
//{
//public:
//	//Stack()
//	//{
//	//	cout << "Stack()" << endl;
//
//	//	_a = (int*)malloc(sizeof(int) * 4);
//	//	if (nullptr == _a)
//	//	{
//	//		perror("malloc申请空间失败");
//	//		return;
//	//	}
//
//	//	_capacity = 4;
//	//	_top = 0;
//	//}
//
//	Stack(int capacity = 4)
//	{
//		cout << "Stack()" << endl;
//
//		_a = (int*)malloc(sizeof(int) * capacity);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//
//		_capacity = capacity;
//		_top = 0;
//	}
//
//private:
//	int* _a = nullptr;
//	int _top = 0;
//	int _capacity;
//};
//
//struct TreeNode
//{
//	TreeNode* _left;
//	TreeNode* _right;
//	int _val;
//
//	TreeNode(int val = 0)
//	{
//		_left = nullptr;
//		_right = nullptr;
//		_val = val;
//	}
//};
//
//class Tree
//{
//private:
//	TreeNode* _root = nullptr;
//};
//
//class MyQueue
//{
//private:
//	Stack _pushst;
//	Stack _popst;
//};
//
//int main()
//{
//	Stack st1;
//	//Stack st1(); // 编译器无法很好区分st1是对象，还是函数名
//	//Stack st2(10);
//
//	Tree t1;
//
//	TreeNode n0;
//	TreeNode n1(1);
//	TreeNode n2(2);
//
//	MyQueue q;
//
//	return 0;
//}class Stack
//{
//public:
//	//Stack()
//	//{
//	//	cout << "Stack()" << endl;
//
//	//	_a = (int*)malloc(sizeof(int) * 4);
//	//	if (nullptr == _a)
//	//	{
//	//		perror("malloc申请空间失败");
//	//		return;
//	//	}
//
//	//	_capacity = 4;
//	//	_top = 0;
//	//}
//
//	Stack(int capacity = 4)
//	{
//		cout << "Stack()" << endl;
//
//		_a = (int*)malloc(sizeof(int) * capacity);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//
//		_capacity = capacity;
//		_top = 0;
//	}
//
//private:
//	int* _a = nullptr;
//	int _top = 0;
//	int _capacity;
//};
//
//struct TreeNode
//{
//	TreeNode* _left;
//	TreeNode* _right;
//	int _val;
//
//	TreeNode(int val = 0)
//	{
//		_left = nullptr;
//		_right = nullptr;
//		_val = val;
//	}
//};
//
//class Tree
//{
//private:
//	TreeNode* _root = nullptr;
//};
//
//class MyQueue
//{
//private:
//	Stack _pushst;
//	Stack _popst;
//};
//
//int main()
//{
//	Stack st1;
//	//Stack st1(); // 编译器无法很好区分st1是对象，还是函数名
//	//Stack st2(10);
//
//	Tree t1;
//
//	TreeNode n0;
//	TreeNode n1(1);
//	TreeNode n2(2);
//
//	MyQueue q;
//
//	return 0;
//}class Stack
//{
//public:
//	//Stack()
//	//{
//	//	cout << "Stack()" << endl;
//
//	//	_a = (int*)malloc(sizeof(int) * 4);
//	//	if (nullptr == _a)
//	//	{
//	//		perror("malloc申请空间失败");
//	//		return;
//	//	}
//
//	//	_capacity = 4;
//	//	_top = 0;
//	//}
//
//	Stack(int capacity = 4)
//	{
//		cout << "Stack()" << endl;
//
//		_a = (int*)malloc(sizeof(int) * capacity);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//
//		_capacity = capacity;
//		_top = 0;
//	}
//
//private:
//	int* _a = nullptr;
//	int _top = 0;
//	int _capacity;
//};
//
//struct TreeNode
//{
//	TreeNode* _left;
//	TreeNode* _right;
//	int _val;
//
//	TreeNode(int val = 0)
//	{
//		_left = nullptr;
//		_right = nullptr;
//		_val = val;
//	}
//};
//
//class Tree
//{
//private:
//	TreeNode* _root = nullptr;
//};
//
//class MyQueue
//{
//private:
//	Stack _pushst;
//	Stack _popst;
//};
//
//int main()
//{
//	Stack st1;
//	//Stack st1(); // 编译器无法很好区分st1是对象，还是函数名
//	//Stack st2(10);
//
//	Tree t1;
//
//	TreeNode n0;
//	TreeNode n1(1);
//	TreeNode n2(2);
//
//	MyQueue q;
//
//	return 0;
//}

class Stack
{
public:
	//Stack()
	//{
	//	cout << "Stack()" << endl;

	//	_a = (int*)malloc(sizeof(int) * 4);
	//	if (nullptr == _a)
	//	{
	//		perror("malloc申请空间失败");
	//		return;
	//	}

	//	_capacity = 4;
	//	_top = 0;
	//}

	Stack(int capacity = 4)
	{
		cout << "Stack()" << endl;

		_a = (int*)malloc(sizeof(int) * capacity);
		if (nullptr == _a)
		{
			perror("malloc申请空间失败");
			return;
		}

		_capacity = capacity;
		_top = 0;
	}

	// st2(st1)
	Stack(const Stack& st)
	{
		_a = (int*)malloc(sizeof(int) * st._capacity);
		if (nullptr == _a)
		{
			perror("malloc申请空间失败");
			return;
		}

		memcpy(_a, st._a, sizeof(int) * st._top);
		_top = st._top;
		_capacity = st._capacity;
	}

	~Stack()
	{
		cout << "~Stack()" << endl;
		free(_a);
		_a = nullptr;
		_capacity = _top = 0;
	}

private:
	int* _a = nullptr;
	int _top = 0;
	int _capacity;
};

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	// d2(d1)
//	//Date(Date& d)
//	//Date(const Date& d)
//	//{
//	//	cout << "Date(Date& d)" << endl;
//	//	this->_year = d._year;
//	//	_month = d._month;
//	//	_day = d._day;
//	//	/*d._year = _year;
//	//	d._month = _month;
//	//	d._day = _day;*/
//	//}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

class MyQueue
{
private:
	Stack _pushst;
	Stack _popst;
};

//void func(Date d)
//{
//
//}
//
//void func(int i)
//{
//
//}

//int main()
//{
//	//Stack st1;
//	//Date d1;
//	//MyQueue q;
//
//	// 可以不写，默认生成的拷贝构造就可以用
//	Date d1(2023, 4, 25);
//	Date d2(d1);
//
//	func(d1);
//	func(10);
//
//	// 必须自己实现，实现深拷贝
//	Stack st1;
//	Stack st2(st1);
//
//
//	return 0;
//}

//void func(Date d)
//void func(Date& d)
//{}
//
//void func(Stack& st)
//{}
//
////Stack& func()
////{
////	static Stack st;
////	return st;
////}
//
//Stack func()
//{
//	Stack st;
//	return st;
//}
//
//// 错误的
////Stack& func()
////{
////	Stack st;
////	return st;
////}
//
//int main()
//{
//	Date d1;
//	func(d1);
//
//	Stack st1;
//	func(st1);
//
//	func();
//
//	Stack ret = func();
//
//	return 0;
//}

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

private:
	int _year;
	int _month;
	int _day;
};

//bool Less(const Date& x1, const Date& x2)
//bool Func1(const Date& x1, const Date& x2)
//{
//	if (x1._year < x2._year)
//	{
//		return true;
//	}
//	else if (x1._year == x2._year && x1._month < x2._month)
//	{
//		return true;
//	}
//	else if (x1._year == x2._year && x1._month == x2._month && x1._day < x2._day)
//	{
//		return true;
//	}
//
//	return false;
//}
//
//bool Func2(const Date& x1, const Date& x2)
//{
//	if (x1._year > x2._year)
//	{
//		return true;
//	}
//	else if (x1._year == x2._year && x1._month > x2._month)
//	{
//		return true;
//	}
//	else if (x1._year == x2._year && x1._month == x2._month && x1._day > x2._day)
//	{
//		return true;
//	}
//
//	return false;
//}

bool operator<(const Date& x1, const Date& x2)
{
	if (x1._year < x2._year)
	{
		return true;
	}
	else if (x1._year == x2._year && x1._month < x2._month)
	{
		return true;
	}
	else if (x1._year == x2._year && x1._month == x2._month && x1._day < x2._day)
	{
		return true;
	}

	return false;
}

bool operator>(const Date& x1, const Date& x2)
{
	if (x1._year > x2._year)
	{
		return true;
	}
	else if (x1._year == x2._year && x1._month > x2._month)
	{
		return true;
	}
	else if (x1._year == x2._year && x1._month == x2._month && x1._day > x2._day)
	{
		return true;
	}

	return false;
}

int main()
{
	Date d1(2025, 4, 25);
	Date d2(2023, 5, 25);

	/*cout << Func1(d1, d2) << endl;
	cout << Func2(d1, d2) << endl;*/

	// 为什么内置类型可以直接比较，自定义类型不可以直接比较？
	cout << (d1 < d2) << endl;
	cout << (operator<(d1, d2)) << endl;

	cout << (d1 > d2) << endl;
	cout << (operator>(d1, d2)) << endl;

	return 0;
}