#define  _CRT_SECURE_NO_WARNINGS 1

#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<array>
#include<map>
#include<string>

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
			//cout << "string(char* str)" << endl;

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

			string tmp(s._str);
			swap(tmp);
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
bit::string func()
{
	bit::string str("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
	//cin >> str;
	//....

	return str;
}

int main()
{
	//bit::string ret1 = func();

	bit::string ret2;
	//...
	ret2 = func();

	return 0;
}

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