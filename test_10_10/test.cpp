#define  _CRT_SECURE_NO_WARNINGS 1

#pragma once

namespace bit
{
	template<class T>
	class auto_ptr
	{
	public:
		// RAII
		// 像指针一样
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{}

		~auto_ptr()
		{
			cout << "delete:" << _ptr << endl;
			delete _ptr;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		// ap3(ap1)
		// 管理权转移
		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

	private:
		T* _ptr;
	};

	template<class T>
	class unique_ptr
	{
	public:
		// RAII
		// 像指针一样
		unique_ptr(T* ptr)
			:_ptr(ptr)
		{}

		~unique_ptr()
		{
			cout << "delete:" << _ptr << endl;
			delete _ptr;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		// ap3(ap1)
		// 管理权转移
		// 防拷贝
		unique_ptr(unique_ptr<T>& ap) = delete;
		unique_ptr<T>& operator=(unique_ptr<T>& ap) = delete;
	private:
		T* _ptr;
	};

	template<class T>
	class shared_ptr
	{
	public:
		// RAII
		// 像指针一样
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pcount(new int(1))
		{}

		~shared_ptr()
		{
			if (--(*_pcount) == 0)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
				delete _pcount;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		// sp3(sp1)
		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)
		{
			++(*_pcount);
		}

		// sp1 = sp5
		// sp6 = sp6
		// sp4 = sp5
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (_ptr == sp._ptr)
				return *this;

			if (--(*_pcount) == 0)
			{
				delete _ptr;
				delete _pcount;
			}

			_ptr = sp._ptr;
			_pcount = sp._pcount;
			++(*_pcount);

			return *this;
		}

		int use_count() const
		{
			return *_pcount;
		}

		T* get() const
		{
			return _ptr;
		}

	private:
		T* _ptr;
		int* _pcount;
	};


	template<class T>
	class weak_ptr
	{
	public:
		weak_ptr()
			:_ptr(nullptr)
		{}

		weak_ptr(const shared_ptr<T>& sp)
			:_ptr(sp.get())
		{}

		weak_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			_ptr = sp.get();
			return *this;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
	};
}#include<iostream>
#include<functional>
#include<vector>
using namespace std;

//int main()
//{
//	int a = 3, b = 4;
//	auto fun1 = [&](int c) {b = a + c; };
//	fun1(10);
//
//	cout << typeid(fun1).name() << endl;
//
//	return 0;
//}

//ret = func(x);
// 上面func可能是什么呢？那么func可能是函数名？函数指针？函数对象(仿函数对象)？也有可能是lamber表达式对象？所以这些都是可调用的类型！如此丰富的类型，可能会导致模板的效率低下！为什么呢？我们继续往下看
template<class F, class T>
T useF(F f, T x)
{
	static int count = 0;
	cout << "count:" << ++count << endl;
	cout << "count:" << &count << endl;

	return f(x);
}

double f(double i)
{
	return i / 2;
}

struct Functor
{
	double operator()(double d)
	{
		return d / 3;
	}
};

//int main()
//{
//
//	// 函数指针
//	cout << useF(f, 11.11) << endl;
//
//	// 函数对象
//	cout << useF(Functor(), 11.11) << endl;
//
//	// lambda表达式
//	cout << useF([](double d)->double { return d / 4; }, 11.11) << endl;
//
//	// 可调用对象存储到容器中
//	//vector<>
//
//	// 包装器 -- 可调用对象的类型问题
//	function<double(double)> f1 = f;
//	function<double(double)> f2 = [](double d)->double { return d / 4; };
//	function<double(double)> f3 = Functor();
//
//	//vector<function<double(double)>> v = { f1, f2, f3 };
//	vector<function<double(double)>> v = { f, [](double d)->double { return d / 4; }, Functor() };
//
//	double n = 3.3;
//	for (auto f : v)
//	{
//		cout << f(n++) << endl;
//	}
//
//	return 0;
//}

//int main()
//{
//	// 函数名
//	std::function<double(double)> func1 = f;
//	cout << useF(func1, 11.11) << endl;
//
//	// 函数对象
//	std::function<double(double)> func2 = Functor();
//	cout << useF(func2, 11.11) << endl;
//
//	// lamber表达式
//	std::function<double(double)> func3 = [](double d)->double { return d / 4; };
//	cout << useF(func3, 11.11) << endl;
//
//	return 0;
//}

int Sub(int a, int b)
{
	return a - b;
}

double Plus(int a, int b, double rate)
{
	return (a + b) * rate;
}

double PPlus(int a, double rate, int b)
{
	return  rate * (a + b);
}

//class Sub
//{
//public:
//	int sub(int a, int b)
//	{
//		return a - b;
//	}
//};

class SubType
{
public:
	static int sub(int a, int b)
	{
		return a - b;
	}

	int ssub(int a, int b, int rate)
	{
		return (a - b) * rate;
	}
};

//int main()
//{
//	// 休息20:25继续
//
//	/*function<int(int, int)> rSub = bind(Sub, placeholders::_1, placeholders::_2);
//	cout << rSub(10, 5) << endl;*/
//
//	function<int(int, int)> rSub = bind(Sub, placeholders::_2, placeholders::_1);
//	cout << rSub(10, 5) << endl;
//
//	function<double(int, int)> Plus1 = bind(Plus, placeholders::_1, placeholders::_2, 4.0);
//	function<double(int, int)> Plus2 = bind(Plus, placeholders::_1, placeholders::_2, 4.2);
//	function<double(int, int)> Plus3 = bind(Plus, placeholders::_1, placeholders::_2, 4.4);
//
//	cout << Plus1(5, 3) << endl;
//	cout << Plus2(5, 3) << endl;
//	cout << Plus3(5, 3) << endl;
//
//
//	// double PPlus(int a, double rate, int b)
//
//	function<double(int, int)> PPlus1 = bind(PPlus, placeholders::_1, 4.0, placeholders::_2);
//	function<double(int, int)> PPlus2 = bind(PPlus, placeholders::_1, 4.2, placeholders::_2);
//	cout << PPlus1(5, 3) << endl;
//	cout << PPlus2(5, 3) << endl;
//
//	function<double(int, int)> Sub1 = bind(&SubType::sub, placeholders::_1, placeholders::_2);
//
//	SubType st;
//	function<double(int, int)> Sub2 = bind(&SubType::ssub, &st, placeholders::_1, placeholders::_2, 3);
//	cout << Sub1(1, 2) << endl;
//	cout << Sub2(1, 2) << endl;
//
//	function<double(int, int)> Sub3 = bind(&SubType::ssub, SubType(), placeholders::_1, placeholders::_2, 3);
//	cout << Sub3(1, 2) << endl;
//
//	cout << typeid(Sub3).name() << endl;
//
//	return 0;
//}

int div()
{
	int a, b;
	cin >> a >> b;
	if (b == 0)
		throw invalid_argument("除0错误");

	return a / b;
}

//void f()
//{
//	pair<string, string>* p1 = new pair<string, string>;
//	pair<string, string>* p2 = new pair<string, string>;
//	pair<string, string>* p3 = new pair<string, string>;
//	pair<string, string>* p4 = new pair<string, string>;
//
//	try 
//	{
//		div();
//	}
//	catch (...)
//	{
//		delete p1;
//		cout << "delete:" << p1 << endl;
//		throw;
//	}
//
//	delete p1;
//	cout << "delete:" << p1 << endl;
//}
//
//int main()
//{
//	try
//	{
//		f();
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}

template<class T>
class SmartPtr
{
public:
	// RAII
	// 资源交给对象管理，对象生命周期内，资源有效，对象生命周期到了，释放资源
	// 1、RAII管控资源释放
	// 2、像指针一样
	// 3、拷贝问题
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}

	~SmartPtr()
	{
		cout << "delete:" << _ptr << endl;
		delete _ptr;
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
};

void f()
{
	// 21:15继续
	SmartPtr<pair<string, string>> sp1(new pair<string, string>("1111", "22222"));
	//div();
	SmartPtr<pair<string, string>> sp2(new pair<string, string>);
	SmartPtr<pair<string, string>> sp3(new pair<string, string>);
	SmartPtr<string> sp4(new string("xxxxx"));

	cout << *sp4 << endl;
	cout << sp1->first << endl;
	cout << sp1->second << endl;

	div();

	//delete p1;
	//cout << "delete:" << p1 << endl;
}

//int main()
//{
//	try
//	{
//		f();
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}

// C++98 auto_ptr
// 
// boost
// 
// C++11 unique_ptr
// C++11 shared_ptr
// C++11 weak_ptr

//int main()
//{
//	SmartPtr<string> sp1(new string("xxxxx"));
//	SmartPtr<string> sp2(new string("yyyyy"));
//
//	sp1 =sp2;
//
//	return 0;
//}

#include"SmartPtr.h"

class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a = 0)" << endl;
	}

	~A()
	{
		cout << this;
		cout << " ~A()" << endl;
	}
	//private:

	int _a;
};

//int main()
//{
//	// C++98 一般实践中，很多公司明确规定不要用这个
//	bit::auto_ptr<A> ap1(new A(1));
//	bit::auto_ptr<A> ap2(new A(2));
//
//	// 管理权转移，拷贝时，会把被拷贝对象的资源管理权转移给拷贝对象
//	// 隐患：导致被拷贝对象悬空，访问就会出问题
//	bit::auto_ptr<A> ap3(ap1);
//
//	// 崩溃
//	//ap1->_a++;
//	ap3->_a++;
//
//	return 0;
//}

//int main()
//{
//	// C++11  简单粗暴，不让拷贝
//	bit::unique_ptr<A> up1(new A(1));
//	bit::unique_ptr<A> up2(new A(2));
//
//	//bit::unique_ptr<A> up3(up1);
//	//up1 = up2;
//
//	return 0;
//}

//int main()
//{
//	// C++11
//	bit::shared_ptr<A> sp1(new A(1));
//	bit::shared_ptr<A> sp2(new A(2));
//
//	bit::shared_ptr<A> sp3(sp1);
//	sp1->_a++;
//	sp3->_a++;
//
//	cout << sp1->_a << endl;
//
//	bit::shared_ptr<A> sp4(sp2);
//	bit::shared_ptr<A> sp5(sp4);
//
//	sp1 = sp5;
//	sp3 = sp5;
//
//	bit::shared_ptr<A> sp6(new A(6));
//	sp6 = sp6;
//	sp4 = sp5;
//
//	// cout << sp6->_a << endl;
//
//	return 0;
//}

struct Node
{
	A _val;
	//Node* _next;
	//Node* _prev;

	//bit::shared_ptr<Node> _next;
	//bit::shared_ptr<Node> _prev;

	bit::weak_ptr<Node> _next;
	bit::weak_ptr<Node> _prev;
	// weak_ptr不是RAII智能指针，专门用来解决shared_ptr循环引用问题
	// weak_ptr不增加引用计数，可以访问资源，不参与资源释放的管理
};

int main()
{
	//Node* n1 = new Node;
	//Node* n2 = new Node;
	////...

	//delete n1;
	//delete n2;

	// 循环引用
	bit::shared_ptr<Node> sp1(new Node);
	bit::shared_ptr<Node> sp2(new Node);

	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;

	sp1->_next = sp2;
	sp2->_prev = sp1;

	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;

	return 0;
}