#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

// 泛型编程
// 函数模板
//template<class Tp>
//template<typename T>
//void Swap(T& x, T& y)
//{
//	T tmp = x;
//	x = y;
//	y = tmp;
//}
//
//template<typename T1, typename T2>
//T1 Func(const T1& x, const T2& y)
//{
//	cout << x << " " << y << endl;
//
//	return x;
//}
//
//// 函数模板实例化生成具体函数
//// 函数模板根据调用，自己推导模板参数的类型，实例化出对应的函数
//int main()
//{
//	int a = 0, b = 1;
//	Swap(a, b);
//
//	double c = 1.1, d = 2.2;
//	Swap(c, d);
//
//	Func(1, 2);
//	Func(1, 2.2);
//
//	return 0;
//}

//template<class T>
//T Add(const T& left, const T& right)
//{
//    return left + right;
//}
//
//template<class T>
//T* Alloc(int n)
//{
//    return new T[n];
//}
//
//int main()
//{
//    int a1 = 10, a2 = 20;
//    double d1 = 10.1, d2 = 20.2;
//    // 实参传递的类型，推演T的类型
//    cout << Add(a1, a2) << endl;
//    cout << Add(d1, d2) << endl;
//    cout << Add(a1, (int)d1) << endl;
//    cout << Add((double)a1, d1) << endl;
//
//    // 显示实例化，用指定类型实例化
//    cout << Add<int>(a1, d1) << endl;
//    cout << Add<double>(a1, d1) << endl;
//
//    // 有些函数无法自动推，只能显示实例化
//    double* p1 = Alloc<double>(10);
//
//    return 0;
//}

//typedef int DataType;
//class StackInt
//{
//public:
//	StackInt(size_t capacity = 3)
//	{
//		_array = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (NULL == _array)
//		{
//			perror("malloc申请空间失败!!!");
//			return;
//		}
//
//		_capacity = capacity;
//		_size = 0;
//	}
//
//	void Push(DataType data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//
//	// 其他方法...
//
//	~StackInt()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = NULL;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//
//private:
//	DataType* _array;
//	int _capacity;
//	int _size;
//};
//
//typedef double DataType;
//class StackDouble
//{
//public:
//	StackDouble(size_t capacity = 3)
//	{
//		_array = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (NULL == _array)
//		{
//			perror("malloc申请空间失败!!!");
//			return;
//		}
//
//		_capacity = capacity;
//		_size = 0;
//	}
//
//	void Push(DataType data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//
//	// 其他方法...
//
//	~StackDouble()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = NULL;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//
//private:
//	DataType* _array;
//	int _capacity;
//	int _size;
//};
//
//int main()
//{
//	StackInt s1; // int
//	StackDouble s2; // double
//
//	// char
//	// int*
//	// Date
//
//
//	return 0;
//}

// 类模板
template<class T>
class Stack
{
public:
	Stack(size_t capacity = 3);

	void Push(const T& data);

	// 其他方法...

	~Stack()
	{
		if (_array)
		{
			free(_array);
			_array = NULL;
			_capacity = 0;
			_size = 0;
		}
	}

private:
	T* _array;
	int _capacity;
	int _size;
};


template<class T>
Stack<T>::Stack(size_t capacity)
{
	/*_array = (T*)malloc(sizeof(T) * capacity);
	if (NULL == _array)
	{
		perror("malloc申请空间失败!!!");
		return;
	}*/
	_array = new T[capacity];

	_capacity = capacity;
	_size = 0;
}

template<class T>
void Stack<T>::Push(const T& data)
{
	// CheckCapacity();
	_array[_size] = data;
	_size++;
}

// 惠普实验室  STL -- 标准模板库，常见的数据结构和算法的库
// 普通类，类名和类型是一样
// 类模板，类名和类型不一样
// 类名：Stack
// 类型：Stack<T>

// 20:05继续
//int main()
//{
//	Stack<int> s1;    // int
//	Stack<double> s2; // double
//	Stack<char> s3;   // char
//
//	return 0;
//}

// c strxxx 系列库函数
// cpp  string 管理字符数组，增删查改+算法

//int main()
//{
//	string s1;
//	std::string s2;
//
//	std::string name("张三");
//	name = "张飞";
//
//	return 0;
//}

//int main()
//{
//	string s1;
//	string s2("张三");
//	string s3("hello world");
//	string s4(10, '*');
//	string s5(s2);
//
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s4 << endl;
//	cout << s5 << endl;
//
//	string s6(s3, 6, 5);
//	cout << s3 << endl;
//	cout << s6 << endl;
//
//	cout << (s1 == s2) << endl;
//	cout << (s1 > s2) << endl;
//
//	string s7(s3, 6);
//	cout << s7 << endl;
//
//	string s8(s3, 6, 100);
//	cout << s8 << endl;
//
//	// 休息21:26
//	//string url("https://cplusplus.com/reference/string/string/string/");
//	string url("https://en.cppreference.com/w/");
//	string sub1(url, 0, 5);
//	string sub2(url, 8, 13);
//	//string sub3(url, 22, url.size()-22);
//	string sub3(url, 22);
//	cout << sub1 << endl;
//	cout << sub2 << endl;
//	cout << sub3 << endl;
//
//	s1 = s2;
//	cout << s1 << endl;
//
//	s1 = "1111";
//	cout << s1 << endl;
//
//	s1 = '2';
//	cout << s1 << endl;
//
//	return 0;
//}

//class string
//{
// operator+=(char ch)
// operator+=(const char* str)
//private:
//	char* _str;
//	size_t _size;
//	size_t _capacity;
//};

int main()
{
	// 增
	string s1("hello");
	// 尾插入一个字符
	//s1.push_back(' ');
	//// 尾插一个字符串
	//s1.append("world");
	s1 += ' ';
	s1 += "world";
	cout << s1 << endl;

	size_t x = 0;
	cin >> x;

	// 要求x转成string对象
	string xstr;
	while (x)
	{
		size_t val = x % 10;
		xstr += ('0' + val);
		x /= 10;
	}

	// 逆置

	return 0;
}