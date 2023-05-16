#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class A
{
public:
	//A(int a = 0)
	A(int a = 0, int b = 0)
		: _a(a)
	{
		cout << "A():" << this << endl;
	}

	A(const A& aa)
		: _a(aa._a)
	{
		cout << "A(const A& aa):" << this << endl;
	}

	~A()
	{
		cout << "~A():" << this << endl;
	}

private:
	int _a;
};

// ԭ��һ��Ҫƥ��ʹ��
//int main()
//{
//	int* p3 = (int*)malloc(sizeof(int)); // C
//	int* p4 = new int;
//	free(p3);
//	delete p4;
//
//	A* p1 = (A*)malloc(sizeof(A));
//	A* p2 = new A(1,1);
//	free(p1);
//	delete p2;
//
//	A* p5 = (A*)malloc(sizeof(A) * 10);
//	//A* p6 = new A[4]{ A(1,1),A(2,2),A(3,3) };
//	A* p6 = new A[4]{ A(1,1),A(2,2),A(3,3),A(4,4) };
//	free(p5);
//	delete[] p6;
//
//	return 0;
//}


//int main()
//{
//	int* p3 = (int*)operator new(sizeof(int)); // CPP
//	int* p4 = new int;
//	operator delete(p3);
//	delete p4;
//
//	A* p1 = (A*)operator new(sizeof(A));
//	A* p2 = new A(1,1);
//	operator delete(p1);
//	delete p2;
//}

//int main()
//{
//	int* p1 = nullptr;
//	try
//	{
//		do
//		{
//			//p1 = (int*)malloc(1024 * 1024);
//			p1 = new int[1024 * 1024];
//			cout << p1 << endl;
//		} while (p1);
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}


typedef int DataType;
class Stack
{
public:
	Stack(size_t capacity = 3)
	{
		cout << "Stack(size_t capacity = 3)" << endl;

		_array = (DataType*)malloc(sizeof(DataType) * capacity);
		if (NULL == _array)
		{
			perror("malloc����ռ�ʧ��!!!");
			return;
		}

		_capacity = capacity;
		_size = 0;
	}

	void Push(DataType data)
	{
		// CheckCapacity();
		_array[_size] = data;
		_size++;
	}

	// ��������...

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
	DataType* _array;
	int       _capacity;
	int       _size;
};

//int main()
//{
//	try
//	{
//		// ��Ҫ����һ�����ϵ�ջ����
//		Stack* p1 = new Stack;
//		delete p1;
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}

//int main()
//{
//	// p1����ָ���ֻ��������A������ͬ��С��һ�οռ䣬����������һ��������Ϊ���캯��û��ִ��
//	A* p1 = (A*)malloc(sizeof(A));
//	// ��ʾ���ù��캯��
//	new(p1)A(1);  // ע�⣺���A��Ĺ��캯���в���ʱ���˴���Ҫ����
//
//	p1->~A();
//	free(p1);
//
//	return 0;
//}

//int main()
//{
//	char* p1 = new char[1024 * 1024 * 1024]{'b','i','t','\0'};
//	cout << (void*)p1 << endl;
//
//	return 0;
//}
//
//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//
//void Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//
//void Swap(char& left, char& right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}

// ģ��
// ����ģ�� + ��ģ��
//template<typename T>
//template<typename Tp>
//template<typename Ty>

// type
template<typename T>  // ģ����� -- ����
void Swap(T& x1, T& x2)
{
	T tmp = x1;
	x1 = x2;
	x2 = tmp;
}

int main()
{
	int a = 0, b = 1;
	double c = 1.1, d = 2.2;
	//Swap(a, b);
	//Swap(c, d);
	swap(a, b);
	swap(c, d);

	int* p1 = &a, * p2 = &b;
	swap(p1, p2);



	//Date d1(2023,5,12), d2(2023, 1, 1);

	return 0;
}


#include<iostream>
#include<string>
using namespace std;

class Time
{
    friend class Date;   // ����������Ϊʱ�������Ԫ�࣬�����������о�ֱ�ӷ���Time���е�˽�г�Ա����

public:
    Time(int hour = 0, int minute = 0, int second = 0)
        : _hour(hour)
        , _minute(minute)
        , _second(second)
    {}

private:
    int _hour;
    int _minute;
    int _second;
};

class Date
{
public:
    Date(int year = 1900, int month = 1, int day = 1)
        : _year(year)
        , _month(month)
        , _day(day)
    {}

    void SetTimeOfDate(int hour, int minute, int second)
    {
        // ֱ�ӷ���ʱ����˽�еĳ�Ա����
        _t._hour = hour;
        _t._minute = minute;
        _t._second = second;
    }

private:
    int _year;
    int _month;
    int _day;
    Time _t;
};


//class A
//{
//private:
//    static int k;
//    int h;
////public:
//    class B
//    {
//    public:
//        void foo()
//        {
//
//        }
//    private:
//        int b;
//    };
//};
//
//int A::k = 1;
//
//int main()
//{
//    cout << sizeof(A) << endl;
//
//    A aa;
//    A::B bb;
//
//	return 0;
//}

//class A
//{
//private:
//    static int k;
//    int h;
//
//    class B  // �ڲ������ⲿ���������Ԫ
//    {
//    public:
//        void foo(const A& a)
//        {
//            cout << k << endl;//OK
//            cout << a.h << endl;//OK
//        }
//    private:
//        int b;
//    };
//};
//
//int A::k = 1;
//
//int main()
//{
//    cout << sizeof(A) << endl;
//
//    A aa;
//
//    return 0;
//}
//
//class A
//{
//public:
//    A(int a = 0)
//        :_a(a)
//    {
//        cout << "A(int a)" << endl;
//    }
//
//    ~A()
//    {
//        cout << "~A()" << endl;
//    }
//private:
//    int _a;
//};
//
//class Solution {
//public:
//    int Sum_Solution(int n) {
//        cout << "Sum_Solution" << endl;
//        //...
//        return n;
//    }
//};


void push_back(const string& s)
{
    cout << "push_back:" << s << endl;
}

//int main()
//{
//    A aa(1);  // �������� -- ���������ڵ�ǰ�����ֲ���
//    A(2);     // �������� -- ���������ڵ�ǰ��
//
//    Solution sl;
//    sl.Sum_Solution(10);
//
//    Solution().Sum_Solution(20);
//
//    //A& ra = A(1);  // ����������г���
//    const A& ra = A(1); // const�����ӳ�����������������ڣ����������ڵ�ǰ�����ֲ���
//    A(10);
//
//    Solution().Sum_Solution(20);
//
//    string str("11111");
//    push_back(str);
//
//    push_back(string("222222"));
//
//    push_back("222222");
//
//    return 0;
//}

class A
{
public:
    A(int a = 0)
        :_a(a)
    {
        cout << "A(int a)" << endl;
    }

    A(const A& aa)
        :_a(aa._a)
    {
        cout << "A(const A& aa)" << endl;
    }

    A& operator=(const A& aa)
    {
        cout << "A& operator=(const A& aa)" << endl;

        if (this != &aa)
        {
            _a = aa._a;
        }

        return *this;
    }

    ~A()
    {
        cout << "~A()" << endl;
    }
private:
    int _a;
};

//void Func1(A aa)
//{
//
//}
//
//void Func2(const A& aa)
//{
//
//}
//
//A Func3()
//{
//    A aa;
//    return aa;
//}
//
//A& Func4()
//{
//    static A aa;
//    return aa;
//}
//
//int main()
//{
//   /* A a1;
//    Func1(a1);
//    Func2(a1);*/
//
//    //Func3();
//    Func4();
//
//
//    return 0;
//}

void Func1(A aa)
{}

A Func5()
{
    A aa;
    return aa;
}

// 20:25
//int main()
//{
//    A ra1 = Func5(); // ��������+�������� ->�Ż�Ϊ��������
//    cout << "==============" << endl;
//    A ra2;
//    ra2 = Func5();
//
//    //A aa1;
//    //Func1(aa1); // �����Ż�
//
//    //Func1(A(1)); // ����+�������� ->�Ż�Ϊ����
//    //Func1(1);    // ����+�������� ->�Ż�Ϊ����
//
//    //A aa2 = 1;  // ����+�������� ->�Ż�Ϊ����
//
//
//    return 0;
//}

//int main()
//{
//    int a = 1;
//    const int b = 2;
//    cout << &a << endl;
//    cout << &b << endl;
//
//
//    return 0;
//}

//int main()
//{
//    // C
//    int* p1 = (int*)malloc(sizeof(int));
//    free(p1);
//
//    // CPP
//    int* p2 = new int;
//    delete p2;
//
//    // C
//    int* p3 = (int*)malloc(sizeof(int)*10);
//    free(p3);
//
//    // CPP ����10��int������
//    int* p4 = new int[10];
//    delete[] p4;
//
//    // CPP ����һ�����飬��ʼ��Ϊ10
//    int* p5 = new int(10);
//    delete p5;
//
//    int* p6 = new int[10]{1,2,3};
//    delete[] p6;
//
//    return 0;
//}

struct ListNode
{
    int _val;
    struct ListNode* _next;

    ListNode(int x)
        :_val(x)
        , _next(NULL)
    {}
};

struct ListNode* BuyListNode(int x)
{
    // �������ռ�
    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    // ���
    newnode->_next = NULL;
    newnode->_val = x;

    return newnode;
}

int main()
{
    struct ListNode* n1 = BuyListNode(1);
    struct ListNode* n2 = BuyListNode(2);
    struct ListNode* n3 = BuyListNode(3);

    // ���ռ�+���ù��캯����ʼ��
    ListNode* nn1 = new ListNode(1);
    ListNode* nn2 = new ListNode(2);
    ListNode* nn3 = new ListNode(3);

    return 0;
}