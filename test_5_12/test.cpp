#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Date
{
protected:
    friend ostream& operator<<(ostream& out, const Date& d);
public:
    Date(int year, int month, int day);
    Date operator+(int n);
    int GetMonthDay(int year, int month);
private:
    int _year;
    int _month;
    int _day;
};

Date::Date(int year, int month, int day)
{
    _day = day;
    _month = month;
    _year = year;
}
ostream& operator<<(ostream& out, const Date& d)
{
    if (d._month < 10 && d._day < 10)
        out << d._year << "-" << 0 << d._month << "-" << 0 << d._day;
    else if (d._month >= 10 && d._day < 10)
        out << d._year << "-" << d._month << "-" << 0 << d._day;
    else if (d._month < 10 && d._day >= 10)
        out << d._year << "-" << 0 << d._month << "-" << d._day;
    else
        out << d._year << "-" << d._month << "-" << d._day;
    return out;
}
Date Date::operator+(int n)
{
    int year = _year;
    int month = _month;
    int day = _day;
    int days = GetMonthDay(year, month);

    while (day + n > days)
    {
        month++;
        if (month > 12)
        {
            year++;
            month = 1;
        }
        n -= days;
        days = GetMonthDay(year, month);
    }
    day += n;
    return Date(year, month, day);
}

int Date::GetMonthDay(int year, int month)
{
    static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int day = days[month];
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
    {
        day += 1;
    }
    return day;
}

int main()
{

    int count = 0;
    int year = 0, month = 0, day = 0;
    int n = 0;
    cin >> count;
    for (int cur = 0; cur < count; cur++)
    {
        cin >> year >> month >> day >> n;
        Date d(year, month, day);
        Date d1 = d + n;
        cout << d1 << endl;
    }


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