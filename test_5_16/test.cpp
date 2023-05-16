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

// 原则：一定要匹配使用
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
			perror("malloc申请空间失败!!!");
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

	// 其他方法...

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
//		// 需要申请一个堆上的栈对象
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
//	// p1现在指向的只不过是与A对象相同大小的一段空间，还不能算是一个对象，因为构造函数没有执行
//	A* p1 = (A*)malloc(sizeof(A));
//	// 显示调用构造函数
//	new(p1)A(1);  // 注意：如果A类的构造函数有参数时，此处需要传参
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

// 模板
// 函数模板 + 类模板
//template<typename T>
//template<typename Tp>
//template<typename Ty>

// type
template<typename T>  // 模板参数 -- 类型
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
    friend class Date;   // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量

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
        // 直接访问时间类私有的成员变量
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
//    class B  // 内部类是外部类的天生友元
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
//    A aa(1);  // 有名对象 -- 生命周期在当前函数局部域
//    A(2);     // 匿名对象 -- 生命周期在当前行
//
//    Solution sl;
//    sl.Sum_Solution(10);
//
//    Solution().Sum_Solution(20);
//
//    //A& ra = A(1);  // 匿名对象具有常性
//    const A& ra = A(1); // const引用延长匿名对象的生命周期，生命周期在当前函数局部域
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
//    A ra1 = Func5(); // 拷贝构造+拷贝构造 ->优化为拷贝构造
//    cout << "==============" << endl;
//    A ra2;
//    ra2 = Func5();
//
//    //A aa1;
//    //Func1(aa1); // 不会优化
//
//    //Func1(A(1)); // 构造+拷贝构造 ->优化为构造
//    //Func1(1);    // 构造+拷贝构造 ->优化为构造
//
//    //A aa2 = 1;  // 构造+拷贝构造 ->优化为构造
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
//    // CPP 申请10个int的数组
//    int* p4 = new int[10];
//    delete[] p4;
//
//    // CPP 申请一个数组，初始化为10
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
    // 单纯开空间
    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    // 检查
    newnode->_next = NULL;
    newnode->_val = x;

    return newnode;
}

int main()
{
    struct ListNode* n1 = BuyListNode(1);
    struct ListNode* n2 = BuyListNode(2);
    struct ListNode* n3 = BuyListNode(3);

    // 开空间+调用构造函数初始化
    ListNode* nn1 = new ListNode(1);
    ListNode* nn2 = new ListNode(2);
    ListNode* nn3 = new ListNode(3);

    return 0;
}