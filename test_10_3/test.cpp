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

// 一切皆可用{}初始化，并且可以不写=
// 建议日常定义，不要去掉=，但是我们要能看懂
//int main()
//{
//	int x = 1;
//	int y = { 2 };
//	int z{ 3 };
//
//	int a1[] = { 1,2,3 };
//	int a2[] { 1,2,3 };
//
//	// 本质都是调用构造函数
//	Point p0(0, 0);
//	Point p1 = { 1,1 };  // 多参数构造函数隐式类型转换
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
//	// 不同的规则
//	vector<int> v1 = { 1,2,3,4,3}; // 调用initializer_list的vector构造函数
//	Point p1 = { 1,1};  // 直接调用两个参数的构造 -- 隐式类型转换
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
//	//map<string, string> dict = { {"sort", "排序"}, {"left", "左边"} };
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
//	// typeid(pf).name() ptr; typeid推出类型是一个字符串，只能看不能用
//
//	auto pf1 = pf;
//
//	// decltype推出对象的类型，再定义变量，或者作为模板实参
//	// 单纯先定义一个变量出现
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

// const enum inline去替代宏
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
//	a1[15] = 1;  // 指针的解引用
//	a2[15] = 1;  // operator[]函数调用,内部检查
//
//	// 用这个也可以，显得array很鸡肋
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
//	// 以下的ptr、b、c、*p都是左值
//	int* ptr = new int(0);
//	int b = 1;
//	const int c = 2;
//	"xxxxx";
//	const char* p = "xxxxx";
//	p[2];
//
//	double x = 1.1, y = 2.2;
//	// 以下几个都是常见的右值
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

// 左值引用  右值引用
// 引用是取别名
// 左值引用:给左值取别名
// 右值引用:给右值取别名
//int main()
//{
//	double x = 1.1, y = 2.2;
//	// 左值引用:给左值取别名
//	int a = 0;
//	int& r1 = a;
//
//	// 左值引用能否给右值取别名？
//	// const左值引用可以
//	const int& r2 = 10;
//	const double& r3 = x + y;
//	
//	// 右值引用:给右值取别名
//	int&& r5 = 10;
//	double&& r6 = x + y;
//
//	// 右值引用能否给左值取别名？
//	// 右值引用可以引用move以后的左值
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

		// 拷贝构造
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- 深拷贝" << endl;

			//string tmp(s._str);
			//swap(tmp);
		}

		string(string&& s)
			:_str(nullptr)
		{
			cout << "string(string&& s) -- 移动拷贝" << endl;

			swap(s);
		}

		// 赋值重载
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- 深拷贝" << endl;
			string tmp(s);
			swap(tmp);

			return *this;
		}

		string& operator=(string&& s)
		{
			cout << "string& operator=(string && s) -- 移动拷贝" << endl;
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
		size_t _capacity; // 不包含最后做标识的\0
	};
}

// 左值引用的使用场景和价值是什么？
// 使用场景：1、做参数  2、做返回值  价值->减少拷贝
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
//	std::string copy2 = ret3; // 拷贝构造
//	std::string copy3 = move(ret3); // 移动构造
//
//	return 0;
//}

// 是否构成函数重载 -- 是
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
//	// 走更匹配的，有右值引用的重载，就会走右值引用版本
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

void Fun(int& x) { cout << "左值引用" << endl; }
void Fun(const int& x) { cout << "const 左值引用" << endl; }

void Fun(int&& x) { cout << "右值引用" << endl; }
void Fun(const int&& x) { cout << "const 右值引用" << endl; }

// 万能引用：既可以接收左值，又可以接收右值
// 实参左值，他就是左值引用（引用折叠）
// 实参右值，他就是右值引用
template<typename T>
void PerfectForward(T&& t)
{
	// 完美转发，t是左值引用，保持左值属性
	// 完美转发，t是右值引用，保持右值属性
	Fun(forward<T>(t));
}

//int main()
//{
//	PerfectForward(10);           // 右值
//
//	int a;
//	PerfectForward(a);            // 左值
//	PerfectForward(std::move(a)); // 右值
//
//	const int b = 8;
//	PerfectForward(b);		      // const 左值
//	PerfectForward(std::move(b)); // const 右值
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
//	PerfectForward(10);           // 右值
//
//	int a;
//	//PerfectForward(a);            // 左值
//	PerfectForward(std::move(a)); // 右值
//
//	const int b = 8;
//	//PerfectForward(b);		      // const 左值
//	//PerfectForward(std::move(b)); // const 右值
//
//	int& r = a;
//	int&& rr = move(a);
//	cout << &r << endl;
//	cout << &rr << endl;
//
//	// 右值不能取地址，右值也不能修改
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
	string _name;  // 名字
	double _price; // 价格
	int _evaluate; // 评价

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
//	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2, 3 }, { "菠萝", 1.5, 4 } };
//
//	//sort(v.begin(), v.end(), Compare1());  // 价格升序
//
//	//sort(v.begin(), v.end(), Compare2());  // 价格降序
//
//	//sort(v.begin(), v.end(), CompareEvaluateGreater());  // 评价的降序
//
//	sort(v.begin(), v.end(), Compare1()); 
//	sort(v.begin(), v.end(), Compare2());
//
//	return 0;
//}

//int main()
//{
//	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2, 3 }, { "菠萝", 1.5, 4 } };
//	sort(v.begin(), v.end(), Compare1());
//	sort(v.begin(), v.end(), Compare2());
//
//	// 局部的匿名函数对象
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
//	// mutable让捕捉的x和y可以改变了，
//	// 但是他们依旧是外面x和y的拷贝
//		int tmp = x;
//		x = y;
//		y = tmp;
//	};
//	swap1();
//
//	// 引用的方式捕捉
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
//	// 引用的方式捕捉所有对象，除了a
//	// a用传值的方式捕捉
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
//	// 函数对象
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
// 模板可变参数
//template <class ...Args>
//void ShowList(Args... args)
//{
//	cout << sizeof...(args) << endl;
//
//	// 不支持这样完
//	for (size_t i = 0; i < sizeof...(args); i++)
//	{
//		cout << args[i] << endl;
//	}
//}

//void _ShowList()
//{
//	// 结束条件的函数
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
////args代表0-N的参数包
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
////args代表0-N的参数包
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
		cout << "Date构造" << endl;
	}

	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		cout << "Date拷贝构造" << endl;
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
//	// emplace_back支持可变参数，拿到构建pair对象的参数后自己去创建对象
//	// 那么在这里我们可以看到除了用法上，和push_back没什么太大的区别
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
//	// 下面我们试一下带有拷贝构造和移动构造的bit::string，再试试呢
//	// 我们会发现其实差别也不到，emplace_back是直接构造了，push_back
//	// 是先构造，再移动构造，其实也还好。
//	std::list< std::pair<int, bit::string> > mylist;
//	mylist.emplace_back(10, "sort");
//	mylist.push_back(make_pair(30, "sort"));
//
//
//	std::list<Date> lt;
//	Date d(2023, 9, 27);
//	// 只能传日期类对象
//	lt.push_back(d);
//
//	// 传日期类对象
//	// 传日期类对象的参数包
//	// 参数包，一路往下传，直接去构造或者拷贝构造节点中日期类对象
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
// 包装器

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
//	// 函数指针
//	cout << useF(f, 11.11) << endl;
//
//	// 函数对象
//	cout << useF(Functor(), 11.11) << endl;
//
//	// lambda表达式
//	cout << useF([](double d)->double { return d / 4; }, 11.11) << endl;
//
//	return 0;
//}