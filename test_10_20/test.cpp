#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
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
// ����func������ʲô�أ���ôfunc�����Ǻ�����������ָ�룿��������(�º�������)��Ҳ�п�����lamber���ʽ����������Щ���ǿɵ��õ����ͣ���˷ḻ�����ͣ����ܻᵼ��ģ���Ч�ʵ��£�Ϊʲô�أ����Ǽ������¿�
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
//	// ����ָ��
//	cout << useF(f, 11.11) << endl;
//
//	// ��������
//	cout << useF(Functor(), 11.11) << endl;
//
//	// lambda���ʽ
//	cout << useF([](double d)->double { return d / 4; }, 11.11) << endl;
//
//	// �ɵ��ö���洢��������
//	//vector<>
//
//	// ��װ�� -- �ɵ��ö������������
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
//	// ������
//	std::function<double(double)> func1 = f;
//	cout << useF(func1, 11.11) << endl;
//
//	// ��������
//	std::function<double(double)> func2 = Functor();
//	cout << useF(func2, 11.11) << endl;
//
//	// lamber���ʽ
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
//	// ��Ϣ20:25����
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
		throw invalid_argument("��0����");

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
	// ��Դ������������������������ڣ���Դ��Ч�������������ڵ��ˣ��ͷ���Դ
	// 1��RAII�ܿ���Դ�ͷ�
	// 2����ָ��һ��
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
	// 21:15����
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
// 
// C++11 unique_ptr
// C++11 shared_ptr
// C++11 weak_ptr

int main()
{
	SmartPtr<string> sp1(new string("xxxxx"));
	SmartPtr<string> sp2(new string("yyyyy"));

	sp1 = sp2;

	return 0;
}