#define  _CRT_SECURE_NO_WARNINGS 1

#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<list>
#include<array>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

struct Point
{
	//explicit Point(int x, int y)
	Point(int x, int y)
		:_x(x)
		, _y(y)
	{
		cout << "Point(int x, int y)" << endl;
	}

	int _x;
	int _y;
};

// һ�нԿ���{}��ʼ�������ҿ��Բ�д=
// �����ճ����壬��Ҫȥ��=����������Ҫ�ܿ���
//int main()
//{
//	int x = 1;
//	int y = { 2 };
//	int z{ 3 };
//
//	int a1[] = { 1,2,3 };
//	int a2[] { 1,2,3 };
//
//	// ���ʶ��ǵ��ù��캯��
//	Point p0(0, 0);
//	Point p1 = { 1,1 };  // ��������캯����ʽ����ת��
//	Point p2{ 2,2 };
//
//	const Point& r = { 3,3 };
//
//	int* ptr1 = new int[3]{ 1,2,3 };
//	Point* ptr2 = new Point[2]{p0,p1};
//	Point* ptr3 = new Point[2]{ {0,0},{1,1} };
//
//	return 0;
//}

#include"vector.h"

//////////////////////////////////////////////////////////////////////////////
//int main()
//{
//	// ��ͬ�Ĺ���
//	vector<int> v1 = { 1,2,3,4,3}; // ����initializer_list��vector���캯��
//	Point p1 = { 1,1};  // ֱ�ӵ������������Ĺ��� -- ��ʽ����ת��
//
//	auto il = { 10, 20, 30 };
//	//initializer_list<int> il = { 10, 20, 30 };
//	cout << typeid(il).name() << endl;
//	cout << sizeof(il) << endl;
//
//	bit::vector<int> v2 = { 1,2,3,4,54};
//	for (auto e : v2)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	//map<string, string> dict = { {"sort", "����"}, {"left", "���"} };
//
//	return 0;
//}

class A
{
private:
	decltype(malloc) pf2;
};

template<class Func>
class B
{
private:
	Func _f;
};

//int main()
//{
//	int i = 10;
//	auto p = &i;
//	auto pf = malloc;
//
//	//auto x;
//
//	cout << typeid(p).name() << endl;
//	cout << typeid(pf).name() << endl;
//	// typeid(pf).name() ptr; typeid�Ƴ�������һ���ַ�����ֻ�ܿ�������
//
//	auto pf1 = pf;
//
//	// decltype�Ƴ���������ͣ��ٶ��������������Ϊģ��ʵ��
//	// �����ȶ���һ����������
//	decltype(pf) pf2;
//
//	B<decltype(pf)> bb1;
//
//	const int x = 1;
//	double y = 2.2;
//
//	B<decltype(x * y)> bb2;
//
//	return 0;
//}
//
//void func(int x)
//{}
//
//void func(int* p)
//{}

// const enum inlineȥ�����
//int main()
//{
//	int* p = NULL; // int* p = 0;
//	func(NULL); // func(0);
//
//	return 0;
//}

//int main()
//{
//	int a1[10];
//	array<int, 10> a2;
//
//	cout << sizeof(a1) << endl;
//	cout << sizeof(a2) << endl;
//
//	a1[15] = 1;  // ָ��Ľ�����
//	a2[15] = 1;  // operator[]��������,�ڲ����
//
//	// �����Ҳ���ԣ��Ե�array�ܼ���
//	vector<int> a3(10, 0);
//
//	return 0;
//}

int fmin(int a, int b)
{
	return a < b ? a : b;
}

//int main()
//{
//	//const int a = 10;
//	//int b = a;
//	////a = 20;
//
//	// ���µ�ptr��b��c��*p������ֵ
//	int* ptr = new int(0);
//	int b = 1;
//	const int c = 2;
//	"xxxxx";
//	const char* p = "xxxxx";
//	p[2];
//
//	double x = 1.1, y = 2.2;
//	// ���¼������ǳ�������ֵ
//	10;
//	x + y;
//	fmin(x, y);
//
//	// cout << &10 << endl;
//	// cout << &(x+y)<< endl;
//	// cout << &(fmin(x, y)) << endl;
//	cout << &("xxxxx") << endl;
//	cout << &p[2] << endl;
//
//	return 0;
//}


//void func(const T& x)

// ��ֵ����  ��ֵ����
// ������ȡ����
// ��ֵ����:����ֵȡ����
// ��ֵ����:����ֵȡ����
//int main()
//{
//	double x = 1.1, y = 2.2;
//	// ��ֵ����:����ֵȡ����
//	int a = 0;
//	int& r1 = a;
//
//	// ��ֵ�����ܷ����ֵȡ������
//	// const��ֵ���ÿ���
//	const int& r2 = 10;
//	const double& r3 = x + y;
//	
//	// ��ֵ����:����ֵȡ����
//	int&& r5 = 10;
//	double&& r6 = x + y;
//
//	// ��ֵ�����ܷ����ֵȡ������
//	// ��ֵ���ÿ�������move�Ժ����ֵ
//	int&& r7 = move(a);
//
//	return 0;
//}

namespace bit
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			cout << "string(const char* str)" << endl;

			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		// s1.swap(s2)
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}

		// ��������
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- ���" << endl;

			//string tmp(s._str);
			//swap(tmp);
		}

		string(string&& s)
			:_str(nullptr)
		{
			cout << "string(string&& s) -- �ƶ�����" << endl;

			swap(s);
		}

		// ��ֵ����
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- ���" << endl;
			string tmp(s);
			swap(tmp);

			return *this;
		}

		string& operator=(string&& s)
		{
			cout << "string& operator=(string && s) -- �ƶ�����" << endl;
			swap(s);

			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;

				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		//string operator+=(char ch)
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity; // �������������ʶ��\0
	};
}

// ��ֵ���õ�ʹ�ó����ͼ�ֵ��ʲô��
// ʹ�ó�����1��������  2��������ֵ  ��ֵ->���ٿ���
//bit::string func()
//{
//	bit::string str("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
//	//cin >> str;
//	//....
//
//	return str;
//}bit::string func()
//{
//	bit::string str("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
//	//cin >> str;
//	//....
//
//	return str;
//}bit::string func()
//{
//	bit::string str("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
//	//cin >> str;
//	//....
//
//	return str;
//}bit::string func()
//{
//	bit::string str("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
//	//cin >> str;
//	//....
//
//	return str;
//}

//int main()
//{
//	bit::string ret1 = func();
//
//	//bit::string ret2;
//	////...
//	//ret2 = func();
//
//	std::string ret3("1111111111111111111111111111");
//	std::string copy1 = ret3;
//	move(ret3);
//	std::string copy2 = ret3; // ��������
//	std::string copy3 = move(ret3); // �ƶ�����
//
//	return 0;
//}

// �Ƿ񹹳ɺ������� -- ��
//void func(const int& r)
//{
//	cout << "void func(const int& r)" << endl;
//}
//
//void func(int&& r)
//{
//	cout << "void func(int&& r)" << endl;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 1;
//	func(a);
//
//	// �߸�ƥ��ģ�����ֵ���õ����أ��ͻ�����ֵ���ð汾
//	func(a + b);
//
//	return 0;
//}

//////////////////////////////////////////////////////////////////////////////
//int main()
//{
//	list<bit::string> lt;
//	bit::string s1("111111111111111111111");
//	lt.push_back(s1);
//
//	cout << endl << endl;
//	bit::string s2("111111111111111111111");
//	lt.push_back(move(s2));
//
//	cout << endl << endl;
//	lt.push_back("22222222222222222222222222222");
//
//	return 0;
//}

void Fun(int& x) { cout << "��ֵ����" << endl; }
void Fun(const int& x) { cout << "const ��ֵ����" << endl; }

void Fun(int&& x) { cout << "��ֵ����" << endl; }
void Fun(const int&& x) { cout << "const ��ֵ����" << endl; }

// �������ã��ȿ��Խ�����ֵ���ֿ��Խ�����ֵ
// ʵ����ֵ����������ֵ���ã������۵���
// ʵ����ֵ����������ֵ����
template<typename T>
void PerfectForward(T&& t)
{
	// ����ת����t����ֵ���ã�������ֵ����
	// ����ת����t����ֵ���ã�������ֵ����
	Fun(forward<T>(t));
}

//int main()
//{
//	PerfectForward(10);           // ��ֵ
//
//	int a;
//	PerfectForward(a);            // ��ֵ
//	PerfectForward(std::move(a)); // ��ֵ
//
//	const int b = 8;
//	PerfectForward(b);		      // const ��ֵ
//	PerfectForward(std::move(b)); // const ��ֵ
//
//	return 0;
//}

//void PerfectForward(int&& t)
//{
//	Fun(t);
//}
//
//int main()
//{
//	PerfectForward(10);           // ��ֵ
//
//	int a;
//	//PerfectForward(a);            // ��ֵ
//	PerfectForward(std::move(a)); // ��ֵ
//
//	const int b = 8;
//	//PerfectForward(b);		      // const ��ֵ
//	//PerfectForward(std::move(b)); // const ��ֵ
//
//	int& r = a;
//	int&& rr = move(a);
//	cout << &r << endl;
//	cout << &rr << endl;
//
//	// ��ֵ����ȡ��ַ����ֵҲ�����޸�
//	rr++;
//
//	int&& rrr = 10;
//	rrr++;
//	cout << &rrr << endl;
//
//	return 0;
//}

#include"list.h"

//int main()
//{
//	bit::list<bit::string> lt;
//	bit::string s1("111111111111111111111");
//	lt.push_back(s1);
//
//	cout << endl << endl;
//	bit::string s2("111111111111111111111");
//	lt.push_back(move(s2));
//
//	cout << endl << endl;
//	lt.push_back("22222222222222222222222222222");
//
//	return 0;
//}

struct Goods
{
	string _name;  // ����
	double _price; // �۸�
	int _evaluate; // ����

	Goods(const char* str, double price, int evaluate)
		:_name(str)
		, _price(price)
		, _evaluate(evaluate)
	{}
};

//struct ComparePriceLess
struct Compare1
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price < gr._price;
	}
};

//struct ComparePriceGreater
struct Compare2
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price > gr._price;
	}
};

struct CompareEvaluateGreater
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._evaluate > gr._evaluate;
	}
};

//int main()
//{
//	vector<Goods> v = { { "ƻ��", 2.1, 5 }, { "�㽶", 3, 4 }, { "����", 2.2, 3 }, { "����", 1.5, 4 } };
//
//	//sort(v.begin(), v.end(), Compare1());  // �۸�����
//
//	//sort(v.begin(), v.end(), Compare2());  // �۸���
//
//	//sort(v.begin(), v.end(), CompareEvaluateGreater());  // ���۵Ľ���
//
//	sort(v.begin(), v.end(), Compare1()); 
//	sort(v.begin(), v.end(), Compare2());
//
//	return 0;
//}

//int main()
//{
//	vector<Goods> v = { { "ƻ��", 2.1, 5 }, { "�㽶", 3, 4 }, { "����", 2.2, 3 }, { "����", 1.5, 4 } };
//	sort(v.begin(), v.end(), Compare1());
//	sort(v.begin(), v.end(), Compare2());
//
//	// �ֲ���������������
//	auto less = [](int x, int y)->bool {return x < y; };
//	cout << less(1, 2) << endl;
//
//	//auto goodsPriceLess = [](const Goods& x, const Goods& y)->bool {return x._price < y._price; };
//	auto goodsPriceLess = [](const Goods& x, const Goods& y){return x._price < y._price; };
//	cout << goodsPriceLess(v[0], v[1]) << endl;
//	sort(v.begin(), v.end(), goodsPriceLess);
//
//
//	sort(v.begin(), v.end(), [](const Goods& x, const Goods& y) {
//		return x._price < y._price; });
//
//	sort(v.begin(), v.end(), [](const Goods& x, const Goods& y) {
//		return x._price > y._price;});
//
//	sort(v.begin(), v.end(), [](const Goods& x, const Goods& y) {
//		return x._evaluate < y._evaluate;});
//
//	sort(v.begin(), v.end(), [](const Goods& x, const Goods& y) {
//		return x._evaluate > y._evaluate;});
//
//	return 0;
//}

void func()
{
	cout << "func()" << endl;
}

//int main()
//{
//	int a = 0, b = 2;
//	double rate = 2.555;
//	auto add1 = [](int x, int y)->int {return x + y; };
//	auto add2 = [](int x, int y) {return x + y; };
//
//	auto add3 = [rate](int x, int y) {return (x + y)* rate; };
//
//	cout << add1(a, b) << endl;
//	cout << add2(a, b) << endl;
//	cout << add3(a, b) << endl;
//
//
//	auto swap1 = [add1](int& x, int& y) {
//		int tmp = x;
//		x = y;
//		y = tmp;
//
//		cout << add1(x, y) << endl;
//		func();
//	};
//	swap1(a, b);
//
//
//	return 0;
//}

//int main()
//{
//	int x = 0, y = 2;
//	auto swap1 = [x, y]() mutable {
//	// mutable�ò�׽��x��y���Ըı��ˣ�
//	// ������������������x��y�Ŀ���
//		int tmp = x;
//		x = y;
//		y = tmp;
//	};
//	swap1();
//
//	// ���õķ�ʽ��׽
//	auto swap2 = [&x, &y](){
//		int tmp = x;
//		x = y;
//		y = tmp;
//	};
//	swap2();
//
//	int a = 0;
//	int b = 1;
//	int c = 2;
//	int d = 3;
//	const int e = 1;
//	cout << &e << endl;
//
//	// ���õķ�ʽ��׽���ж��󣬳���a
//	// a�ô�ֵ�ķ�ʽ��׽
//	auto func = [&, a] {
//		//a++;
//		b++;
//		c++;
//		d++;
//		//e++;
//		cout << &e << endl;
//	};
//
//	func();
//
//	return 0;
//}

//int main()
//{
//	auto f1 = [](int x, int y) {return x + y; };
//	auto f2 = [](int x, int y) {return x + y; };
//
//	//f1 = f2;
//	cout << typeid(f1).name() << endl;
//	cout << typeid(f2).name() << endl;
//
//	f1(1, 2);
//
//
//	return 0;
//}

class Rate
{
public:
	Rate(double rate) : _rate(rate)
	{}

	double operator()(double money, int year)
	{
		return money * _rate * year;
	}

private:
	double _rate;
};

//int main()
//{
//	// ��������
//	double rate = 0.49;
//	Rate r1(rate);
//	r1(10000, 2);
//
//	// lambda
//	auto r2 = [=](double monty, int year)->double {return monty * rate * year; };
//	r2(10000, 2);
//
//	return 0;
//}
//////////////////////////////////////////////////////////////////////////////////////////////
// ģ��ɱ����
//template <class ...Args>
//void ShowList(Args... args)
//{
//	cout << sizeof...(args) << endl;
//
//	// ��֧��������
//	for (size_t i = 0; i < sizeof...(args); i++)
//	{
//		cout << args[i] << endl;
//	}
//}

//void _ShowList()
//{
//	// ���������ĺ���
//	cout << endl;
//}
//
//template <class T, class ...Args>
//void _ShowList(T val, Args... args)
//{
//	cout << val << " ";
//	_ShowList(args...);
//}
//
////args����0-N�Ĳ�����
//template <class ...Args>
//void CppPrint(Args... args)
//{
//	_ShowList(args...);
//}
//
//int main()
//{
//	CppPrint();
//	CppPrint(1);
//	CppPrint(1, 2);
//	CppPrint(1, 2, 2.2);
//	CppPrint(1, 2, 2.2, string("xxxx"));
//
//	// ...
//
//	return 0;
//}

//void CppPrint()
//{
//	cout << endl;
//}
//
//template <class T>
//int PrintArg(T t)
//{
//	cout << t << " ";
//
//	return 0;
//}
//
////args����0-N�Ĳ�����
//template <class ...Args>
//void CppPrint(Args... args)
//{
//	int a[] = { PrintArg(args)...};
//	cout << endl;
//}
//
//int main()
//{
//	CppPrint();
//	CppPrint(1);
//	CppPrint(1, 2);
//	CppPrint(1, 2, 2.2);
//	CppPrint(1, 2, 2.2, string("xxxx"));
//
//	return 0;
//}

class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date����" << endl;
	}

	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		cout << "Date��������" << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};


template <class ...Args>
Date* Create(Args... args)
{
	Date* ret = new Date(args...);

	return ret;
}

//int main()
//{
//	Date* p1 = Create();
//	Date* p2 = Create(2023);
//	Date* p3 = Create(2023, 9);
//	Date* p4 = Create(2023, 9, 27);
//
//	Date d(2023, 1, 1);
//	Date* p5 = Create(d);
//
//
//
//	return 0;
//}

//int main()
//{
//	std::list< std::pair<int, char> > mylist;
//
//	// emplace_back֧�ֿɱ�������õ�����pair����Ĳ������Լ�ȥ��������
//	// ��ô���������ǿ��Կ��������÷��ϣ���push_backûʲô̫�������
//	mylist.emplace_back(10, 'a');
//	mylist.emplace_back(20, 'b');
//	mylist.emplace_back(make_pair(30, 'c'));
//
//	mylist.push_back(make_pair(40, 'd'));
//	mylist.push_back({ 50, 'e' });
//
//	for (auto e : mylist)
//		cout << e.first << ":" << e.second << endl;
//
//	return 0;
//}

//int main()
//{
//	// ����������һ�´��п���������ƶ������bit::string����������
//	// ���ǻᷢ����ʵ���Ҳ������emplace_back��ֱ�ӹ����ˣ�push_back
//	// ���ȹ��죬���ƶ����죬��ʵҲ���á�
//	std::list< std::pair<int, bit::string> > mylist;
//	mylist.emplace_back(10, "sort");
//	mylist.push_back(make_pair(30, "sort"));
//
//
//	std::list<Date> lt;
//	Date d(2023, 9, 27);
//	// ֻ�ܴ����������
//	lt.push_back(d);
//
//	// �����������
//	// �����������Ĳ�����
//	// ��������һ·���´���ֱ��ȥ������߿�������ڵ������������
//	lt.emplace_back(d);
//	lt.emplace_back(2023, 9, 27);
//
//	return 0;
//}

class Person
{
public:
	Person(const char* name = "", int age = 0)
		:_name(name)
		, _age(age)
	{}

	/*Person(const Person& p)
		:_name(p._name)
		,_age(p._age)
	{}*/

	/*Person& operator=(const Person& p)
	{
		if(this != &p)
		{
			_name = p._name;
			_age = p._age;
		}
		return *this;
	}*/

	Person(Person&& p) = default;
	Person(const Person& p) = default;


	~Person()
	{}

private:
	bit::string _name;
	int _age;
};

int main()
{
	Person s1;
	Person s2 = s1;
	Person s3 = std::move(s1);
	//Person s4;
	//s4 = std::move(s2);

	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
// ��װ��

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
//	// ����ָ��
//	cout << useF(f, 11.11) << endl;
//
//	// ��������
//	cout << useF(Functor(), 11.11) << endl;
//
//	// lambda���ʽ
//	cout << useF([](double d)->double { return d / 4; }, 11.11) << endl;
//
//	return 0;
//}