#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<list>
#include<string>

using namespace std;


//��������
//void Swap(int& x1, int& x2)
//{
//	int tmp = x1;
//	x1 = x2;
//	x2 = tmp;
//
//}
//
//
//void Swap(double& x1, double& x2)
//{
//	double tmp = x1;
//	x1 = x2;
//	x2 = tmp;
//}
//
//
//int main()
//{
//	double x1 = 0.01, x2 = 0.03;
//	int a = 1, b = 2;
//
//	cout << x1 << " " << x2 << endl;
//	cout << a << " " << b << endl;
//	Swap(x1, x2);
//	Swap(a, b);
//	cout << a << " " << b << endl;
//	cout << x1 << " " << x2 << endl;
//
//
//
//	return 0;
//}

//class A
//{
//public :
//	template<typename T>
//	void Swap(T& x1, T& x2)
//	{
//		T tmp = x1;
//		x1 = x2;
//		x2 = tmp;
//	}
//private:
//};
//	
//
//template<typename T1>
//T1 Add( const T1& x, const T1& y)
//{
//	return x + y;
//}
//
//
//int main()
//
//{
//	/*A t;
//	int a = 1, b = 2;
//	cout << a << " " << b << endl;
//
//	t.Swap(a, b);
//	
//	cout << a << " " << b << endl;*/
//
//	int a = 1, b = 2;
//	double c = 0.01;
//
//	int ret = 0;
//
//	double d1 = 9.11;
//	int a1 = 2;
//
//	//ret = Add(a, c);//�����Ǳ��벻ͨ����
//
//
//	//int ret = Add(a, (int)c);
//
//	cout << Add(a,(int)c) << endl; //ǿ��ת��ʱ��Ҫ�γ�һ����ʱ��������ʱ�����Ǿ��г��Եģ��ڴ����õ�ʱ����Ҫ��const
//
//	/*int ret=Add<int>(d1, a1);*/
//
//
//	
//
//
//	return 0;
//}



//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.0, d2 = 20.0;
//	Add(a1, a2);
//	Add(d1, d2);
//
//	/*
//	����䲻��ͨ�����룬��Ϊ�ڱ����ڼ䣬��������������ʵ����ʱ����Ҫ������ʵ������
//	ͨ��ʵ��a1��T����Ϊint��ͨ��ʵ��d1��T����Ϊdouble���ͣ���ģ������б���ֻ��һ��T��
//	�������޷�ȷ���˴����׸ý�Tȷ��Ϊint ���� double���Ͷ�����
//	ע�⣺��ģ���У�������һ�㲻���������ת����������Ϊһ��ת�������⣬����������Ҫ���ڹ�
//	Add(a1, d1);
//	*/
//
//	// ��ʱ�����ִ���ʽ��1. �û��Լ���ǿ��ת�� 2. ʹ����ʽʵ����
//	//Add(a, (int)d);
//
//	Add<int>(a1,d2);//��ʾʵ����
//
//	return 0;
//
//
//}



//template<class T>
//class Vector
//{
//public:
//	Vector(size_t capacity = 10)
//		: _pData(new T[capacity])
//		, _size(0)
//		, _capacity(capacity)
//	{}
//
//	// ʹ������������ʾ�������������������ⶨ�塣
//	~Vector();
//
//	void PushBack(const T& data)��
//		void PopBack()��
//		// ...
//
//		size_t Size() { return _size; }
//
//	T& operator[](size_t pos)		
//	{
//	assert(pos < _size);
//	return _pData[pos];
//	}
//
//private:
//	T* _pData;
//	size_t _size;
//	size_t _capacity;
//};
//// ע�⣺��ģ���к�������������ж���ʱ����Ҫ��ģ������б�
//template <class T>
//Vector<T>::~Vector()
//{
//	if (_pData)
//		delete[] _pData;
//	_size = _capacity = 0;
//}


// ��ģ��
//template<class T>
//class Stack
//{
//public:
//	Stack(size_t capacity = 3);
//
//	void Push(const T& data);
//
//	// ��������...
//
//	void Print()
//	{
//		for (int i = 0; i < _size; i++)
//		{
//			cout << _array[i] << endl;
//		}
//
//		/*for (auto e : _array)
//		{
//			cout << e << endl;
//		}*/
//	}
//
//	~Stack()
//	{
//		if (_array)
//		{
//			delete(_array);
//			_array = NULL;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//
//	
//	
//
//private:
//	T* _array;
//	int _capacity;
//	int _size;
//};

//template<class T>
//void Stack<T>::Print() const
//{
//	
//		/*for (auto i : _array)
//		{
//			cout << _array[i] << endl;
//		}*/
//
//		for (int i = 0; i < size; i++)
//		{
//			cout << _array[i] << endl;
//		}
//	
//}

//template<class T>
//Stack<T>::Stack(size_t capacity)
//{
//	_array = new T[capacity];
//	_capacity = capacity;
//	_size = 0;
//
//}
//
//template<class T>
//void Stack<T>::Push(const T& data)
//{
//	_array[_size] = data;
//	_size++;
//}
//
//int main()
//{
//	/*Stack<int> s1;
//
//	Stack<double> s2(4);
//	s2.Push(2.222);s2.Print();s1.Push(1);*/
//
//	list<int> l;
//
//	l.push_back(1);
//	l.push_back(2);
//	l.push_back(3);
//	l.push_back(4);
//	l.push_back(5);
//	l.push_back(6);
//	l.push_back(7);
//
//	list<int>::iterator lt = l.begin();
//
//	for (; lt != l.end();lt++)
//	{
//		cout << *lt << endl;
//	}
//
//	
//}

int main()
{
	string s1("hello string");
	string s2("hello world");
	string name("zhangsan");

	string s0(10, '*');
	
	
	cout << s1 << endl;
	cout << s2 << endl;
	cout << name << endl;
	cout << s0 << endl;
}

