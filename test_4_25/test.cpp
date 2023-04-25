#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//class A
//{
//public:
//	// 健身房 篮球场等等
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
////private:
//	// 卧室，厨房等等
//	char _a;
//};
//
//int main()
//{
//	A aa1;
//	A aa2;
//	A aa3;
//	cout << sizeof(A) << endl;
//	cout << sizeof(aa1) << endl;
//	aa1._a = 1;
//	aa1.PrintA();
//
//	return 0;
//}

// 类中既有成员变量，又有成员函数
class A1 {
public:
	void f1() {}
private:
	char _ch;
	//int _a;
	double _d;
};

// 类中仅有成员函数
class A2 {
public:
	void f2() {}
};

// 类中什么都没有---空类
class A3
{};

//int main()
//{
//    //cout << sizeof(A1) << endl;
//
//    // 没有成员变量的类对象，需要1byte，是为了占位，表示对象存在
//    // 不存储有效数据
//    cout << sizeof(A2) << endl;
//    cout << sizeof(A3) << endl;
//    A2 aa1;
//    A2 aa2;
//    cout << &aa1 << endl;
//    cout << &aa2 << endl;
//
//    return 0;
//}

//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	// d1.Print();
//	// d2.Print();
//	void Print()
//	{
//		// this不能在形参和实参显示传递，但是可以在函数内部显示使用
//		//this = nullptr;
//		cout << this << endl;
//		cout << this->_year << "-" << _month << "-" << _day << endl;
//	}
//
//	// 编译器会成员函数的处理
//	/*void Print(Date* const this)
//	{
//		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
//	}*/
//
////private:
//	int _year;     // 年   声明
//	int _month;    // 月
//	int _day;      // 日
//};
//
//int main()
//{
//	Date d1, d2;
//	d1.Init(2022, 1, 11);
//	d2.Init(2022, 1, 12);
//	d1.Print();
//	d2.Print();
//
//	//Date::_year;
//	//d1._year;
//
//	/*d1.Print(&d1);
//	d2.Print(&d2);*/
//
//    return 0;
//}

//class A
//{
//public:
//	void Print()
//	{
//		cout << "Print()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = nullptr;
//	p->Print();
//
//	/*A::Print(nullptr);
//	A::Print(p);*/
//
//
//	return 0;
//}

typedef int DataType;
class Stack
{
public:
	Stack(DataType* a, int n)
	{
		cout << "Stack(DataType* a, int n)" << endl;
		_array = (DataType*)malloc(sizeof(DataType) * n);
		if (NULL == _array)
		{
			perror("malloc申请空间失败!!!");
			return;
		}
		memcpy(_array, a, sizeof(DataType) * n);

		_capacity = n;
		_size = n;
	}

	Stack(int capacity = 4)
	{
		cout << "Stack(int capacity = 4)" << endl;
		_array = (DataType*)malloc(sizeof(DataType) * capacity);
		if (NULL == _array)
		{
			perror("malloc申请空间失败!!!");
			return;
		}

		_capacity = capacity;
		_size = 0;
	}

	/*void Init()
	{
		_array = (DataType*)malloc(sizeof(DataType) * 4);
		if (NULL == _array)
		{
			perror("malloc申请空间失败!!!");
			return;
		}

		_capacity = 4;
		_size = 0;
	}*/

	void Push(DataType data)
	{
		CheckCapacity();
		_array[_size] = data;
		_size++;
	}

	void Pop()
	{
		if (Empty())
			return;
		_size--;
	}

	DataType Top() { return _array[_size - 1]; }
	int Empty() { return 0 == _size; }
	int Size() { return _size; }

	//void Destroy()
	//{
	//	if (_array)
	//	{
	//		free(_array);
	//		_array = NULL;
	//		_capacity = 0;
	//		_size = 0;
	//	}
	//}

	~Stack()
	{
		cout << "~Stack()" << endl;
		if (_array)
		{
			free(_array);
			_array = NULL;
			_capacity = 0;
			_size = 0;
		}
	}

private:
	void CheckCapacity()
	{
		if (_size == _capacity)
		{
			int newcapacity = _capacity * 2;
			DataType* temp = (DataType*)realloc(_array, newcapacity * sizeof(DataType));
			if (temp == NULL)
			{
				perror("realloc申请空间失败!!!");
				return;
			}
			_array = temp;
			_capacity = newcapacity;
		}
	}
private:
	DataType* _array;
	int _capacity;
	int _size;
};

//int main()
//{
//	Stack s;
//	//s.Init();
//
//	s.Push(1);
//	s.Push(2);
//	s.Push(3);
//	s.Push(4);
//
//	printf("%d\n", s.Top());
//	printf("%d\n", s.Size());
//
//	s.Pop();
//	s.Pop();
//	printf("%d\n", s.Top());
//	printf("%d\n", s.Size());
//
//	//s.Destroy();
//	return 0;
//}

class Date
{
public:
	// 构成函数重载
	// 但是无参调用存在歧义？
	/*Date()
	{
		_year = 1;
		_month = 1;
		_day = 1;
	}*/

	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	// 内置类型
	// C++11支持，这里不是初始化，因为这里只是声明
	// 这里给的是默认的缺省值，给编译器生成默认构造函数用
	int _year = 1;
	int _month = 1;
	int _day = 1;

	// 自定义类型
	//Stack _st;
};

// 1、一般情况下，有内置类型成员，就需要自己写构造函数，不能用编译器自己生成的。
// 2、全部都是自定义类型成员，可以考虑让编译器自己生成

int main()
{
	// 构造函数的调用跟普通函数也不一样
	Date d1;
	//Date d1(); // 不可以这样写，会跟函数声明有点冲突，编译器不好识别
	Date d2(2023, 11, 11);
	d1.Print();
	d2.Print();

	Date d3(2000);
	d3.Print();

	//Date d1;
	//d1.Date();
	//Date d2;
	//d2.Date(2023, 1, 1);

	return 0;
}
