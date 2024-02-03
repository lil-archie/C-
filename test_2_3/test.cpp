#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>


using namespace std;


//class Person
//{
//public:
//	Person(const char* name = "Peter")
//		:_name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	Person(const Person& p)
//		:_name(p._name)
//	{
//		cout << "Person(const Person &p)" << endl;
//	}
//	Person& operator=(const Person& p)
//	{
//		if (this != &p)
//		{
//			_name = p._name;
//		}
//		return *this;
//	}
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name;
//
//};
//
//class Student :public Person
//{
//public:
//	Student(const char* name = "lisi", int num = 0)
//		:_num(num)
//		, Person(name)//语法规定，初始化派生类
//	{
//		cout << "student()" << endl;
//	}
//	Student(const Student& s)
//		:Person(s)//子类可以直接赋值给父类（剪切）p=s
//		, _num(s._num)
//	{
//		cout << "Student(const Student &s)" << endl;
//	}
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			Person::operator=(s);
//			_num = s._num;
//		}
//		return *this;
//	}
//	~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//
//protected:
//	int _num;
//	
//};
//
//int main()
//{
//	Person p("lisi");
//	Person p1(p);
//
//	Student s("张三",10);
//	Student s1(s);
//
//	Student s2("李四", 20);
//	
//	s1 = s2;
//
//}

//#include<iostream>
//using namespace std;

//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
////protected:
//	string _name = "peter"; // 姓名
//	int _age = 18;  // 年龄
//};
//
//// 继承后父类的Person的成员（成员函数+成员变量）都会变成子类的一部分。这里体现出了Student和Teacher复用了Person的成员。下面我们使用监视窗口查看Student和Teacher对象，可以看到变量的复用。调用Print可以看到成员函数的复用。
//class Student : public Person
//{
//protected:
//	int _stuid; // 学号
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // 工号
//};
//
//int main()
//{
//	Person p;
//	Student s;
//	p.Print();
//	s.Print();
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	// double d = i;
//	//double& d = i;
//	const double& d = i;
//
//	Person p;
//	Student s;
//
//	// 赋值兼容转换(切割，切片)
//	//p = s;
//	Person p1 = s;
//	Person& rp = s;
//	rp._name = "张三";
//
//	Person* ptrp = &s;
//	ptrp->_name = "李四";
//
//	//s = (Student)p;
//
//	return 0;
//}

//class Person
//{
//public:
//	void fun()
//	{
//		cout << "Person::func()" << endl;
//	}
//
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; 	   // 身份证号
//};
//
//// 隐藏/重定义：子类和父类有同名成员，子类的成员隐藏了父类的成员
//class Student : public Person
//{
//public:
//	void fun()
//	{
//		cout << "Student::func()" << endl;
//	}
//
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << _num << endl;
//		cout << Person::_num << endl;
//	}
//protected:
//	int _num = 999; // 学号
//};
//
//int main()
//{
//	Student s;
//	s.Print();
//	s.fun();
//	s.Person::fun();
//
//	return 0;
//}

// 两个fun构成什么关系？
// a、隐藏/重定义   b、重载   c、重写/覆盖  d、编译报错
// 答案：a  (父子类域中，成员函数名相同就构成隐藏)
//class Person
//{
//public:
//	void fun()
//	{
//		cout << "Person::func()" << endl;
//	}
//
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; 	   // 身份证号
//};
//
//// 隐藏/重定义：子类和父类有同名成员，子类的成员隐藏了父类的成员
//class Student : public Person
//{
//public:
//	void fun(int i)
//	{
//		cout << "Student::func()" << endl;
//	}
//
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << _num << endl;
//		cout << Person::_num << endl;
//	}
//protected:
//	int _num = 999; // 学号
//};
//
//int main()
//{
//	Student s;
//	s.Person::fun();
//	s.fun(1);
//
//	return 0;
//}

//class Person
//{
//public:
//	//Person(const char* name = "peter")
//	Person(const char* name)
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//		delete _pstr;
//	}
//protected:
//	string _name; // 姓名
//
//	string* _pstr = new string("111111111");
//};
//
//class Student : public Person
//{
//public:
//	// 先父后子
//	Student(const char* name = "张三", int id = 0)
//		:Person(name)
//		,_id(0)
//	{}
//
//	Student(const Student& s)
//		:Person(s)
//		,_id(s._id)
//	{}
//
//	// 10:45继续
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			Person::operator=(s);
//			_id = s._id;
//		}
//
//		return *this;
//	}
//
//	~Student()
//	{
//		// 由于后面多态的原因(具体后面讲)，析构函数的函数名被
//		// 特殊处理了，统一处理成destructor
//
//		// 显示调用父类析构，无法保证先子后父
//		// 所以子类析构函数完成就，自定调用父类析构，这样就保证了先子后父
//		//Person::~Person();
//
//		cout << *_pstr << endl;
//		delete _ptr;
//	}
//protected:
//	int _id;
//
//	int* _ptr = new int;
//};
//
//int main()
//{
//	Student s1;
//	Student s2(s1);
//
//	Student s3("李四", 1);
//	s1 = s3;
//
//	//Person p = s1;
//
//	return 0;
//}

//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // 姓名
//};
//
//class Student : public Person
//{
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum; // 学号
//};
//
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._stuNum << endl;
//}
//
//void main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//}

// 静态成员属于父类和派生类
// 在派生类中不会单独拷贝一份，继承的使用权
//class Person
//{
//public:
//	Person() { ++_count; }
////protected:
//	string _name; // 姓名
//public:
//	static int _count; // 统计人的个数。
//};
//
//int Person::_count = 0;
//
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // 研究科目
//};

//int main()
//{
//	Person p;
//	Student s1;
//	Student s2;
//
//	cout << Person::_count << endl;
//
//	/*cout << &p._name << endl;
//	cout << &s._name << endl;
//
//	cout << &p._count<< endl;
//	cout << &s._count << endl;
//
//	cout << &Person::_count << endl;
//	cout << &Student::_count << endl;*/
//
//	return 0;
//}

//class Person
//{
//public:
//	string _name; // 姓名
//	int _age;
//};
//
//class Student : virtual public Person
//{
//protected:
//	int _num; //学号
//};
//
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // 职工编号
//};
//
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//
//int main()
//{
//	Assistant as;
//	as.Student::_age = 18;
//	as.Teacher::_age = 30;
//	as._age = 19;
//
//	return 0;
//}
//

class A
{
public:
	int _a;
};

class B : virtual public A
{
public:
	int _b;
};

class C : virtual public A
{
public:
	int _c;
};

class D : public B, public C
{
public:
	int _d;
};

int main()
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;
	d._a = 0;

	D d1;

	return 0;
}

//int main()
//{
//	D d;
//	d._a = 1;
//
//	B b;
//	b._a = 2;
//	b._b = 3;
//
//	B* ptr = &b;
//	ptr->_a++;
//
//	ptr = &d;
//	ptr->_a++;
//
//	return 0;
//} 