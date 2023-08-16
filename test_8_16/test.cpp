#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//class A
//{
//public:
//	int _a[128];
//};
//
// class B : public A
////class B : virtual public A
//{
//public:
//	int _b;
//};
//
//class C : public A
////class C : virtual public A
//{
//public:
//	int _c;
//};
//
//class D : public B, public C
//{
//public:
//	int _d;
//};
//
//
//
//int main()
//{
//	D d;
//	//d.B::_a = 1;
//	//d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//
//	cout << sizeof(D) << endl;
//
//	return 0;
//}

//class Base1 { public:  int _b1; };
//class Base2 { public:  int _b2; };
//class Derive : public Base2, public Base1 { public: int _d; };
//
//int main() {
//	Derive d;
//	Base1* p1 = &d;
//	Base2* p2 = &d;
//	Derive* p3 = &d;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class A {
//public:
//	A(const char* s) { cout << s << endl; }
//	~A() {}
//};
//
//class B :virtual public A
//{
//public:
//	B(const char* sa, const char* sb) :A(sa) { cout << sb << endl; }
//};
//
//class C :virtual public A
//{
//public:
//	C(const char* sa, const char* sb) :A(sa) { cout << sb << endl; }
//};
//
//class D :public B, public C
//{
//public:
//	D(const char* sa, const char* sb, const char* sc, const char* sd) 
//		:B(sa, sb), C(sa, sc), A(sa)
//	{
//		cout << sd << endl;
//	}
//};
//
//int main() {
//	D* p = new D("class A", "class B", "class C", "class D");
//	delete p;
//
//	B b("class A", "class B");
//
//	return 0;
//}

//class C
//{
//	//....
//};
//
//// 继承
//class D : public C
//{};
//
//// 组合
//class E
//{
//private:
//	C _cc;
//};

// 虚函数重写的一些细节：
// 重写的条件本来是虚函数+三同，但是有一些例外
// 1、派生类的重写虚函数可以不加virtual -- （建议大家都加上）
// 2、协变，返回的值可以不同，但是要求返回值必须是父子关系指针和引用

//class Person {
//public:
//	virtual	void BuyTicket() const { cout << "买票-全价" << endl; }
//};
//
//class Student : public Person {
//public:
//	void BuyTicket() const { cout << "买票-半价" << endl; }
//};

//class A
//{};
//
//class B : public A
//{};
//
//class Person {
//public:
//	virtual	A* BuyTicket() const { 
//		cout << "买票-全价" << endl;
//		return 0;
//	}
//};
//
//class Student : public Person {
//public:
//	virtual B* BuyTicket() const { 
//		cout << "买票-半价" << endl;
//		return 0;
//	}
//};
//
//// 多态条件
//// 1、调用函数是重写的虚函数
//// 2、基类指针或者引用
//
//// 多态，不同对象传递过去，调用不同函数
//// 多态调用看的指向的对象
//// 普通对象，看当前者类型
//void func(const Person* p)
//{
//	p->BuyTicket();
//}
//
//int main()
//{
//	Person pp;
//	func(&pp);
//
//	Student st;
//	func(&st);
//
//	return 0;
//}

///////////////////////////////////////////////////////////////////////////////////////
//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//
//	~Student() {
//		cout << "~Student()" << endl;
//		delete[] ptr;
//	}
//
//protected:
//	int* ptr = new int[10];
//};
//
//// 11:40继续
//// 析构函数可以是虚函数吗？为什么需要是虚函数？
//// 析构函数加virtual，是不是虚函数重写？
//// 是，因为类析构函数都被处理成destructor这个统一的名字
//// 为什么要这么处理呢？因为要让他们构成重写
//// 那为什么要让他们构成重写呢？
//// 因为下面的场景
//
//int main()
//{
//	//Person p;
//	//Student s;
//
//	Person* p = new Person;
//	p->BuyTicket();
//	delete p;
//
//	p = new Student;
//	p->BuyTicket();
//	delete p; // p->destructor() + operator delete(p)
//
//	// 这里我们期望p->destructor()是一个多态调用，而不是普通调用
//
//	return 0;
//}

//////////////////////////////////////////////////////////////////////////////////////////////
//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//
//class Benz :public Car
//{
//public:
//	void Drive(int i) { cout << "Benz-舒适" << endl; }
//};

//class Car {
//public:
//	 virtual void Drive() {}
//};
//
//// override 帮助派生检查是否完成重写，如果没有会报错
//class Benz :public Car {
//public:
//	virtual void Drive() override { cout << "Benz-舒适" << endl; }
//};

// 设计不想被继承类，如何设计？
// 方法1：基类构造函数私有   (C++98)
// 方法2：基类加一个final  （C++11）
//class A
//{
//public:
//	static A CreateObj()
//	{
//		return A();
//	}
//private:
//	A()
//	{}
//};
//
//class B : public A
//{};
//
//int main()
//{
//	// B bb;
//	A::CreateObj();
//
//	return 0;
//}

//class A
//{
//public:
//private:
//	~A()
//	{}
//};
//
//class B : public A
//{};
//
//int main()
//{
//	A* p = new A;
//
//	//B bb;
//
//	return 0;
//}


//class A final
//{
//public:
//private:
//};
//
//class B : public A
//{};
//
//int main()
//{
//	return 0;
//}
// 
// 这里常考一道笔试题：sizeof(Base)是多少？
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//
//	virtual void Func2()
//	{
//		cout << "Func1()" << endl;
//	}
//
//
//	void Func3()
//	{
//		cout << "Func1()" << endl;
//	}
//
//private:
//	char _b = 1;
//};
//
//int main()
//{
//	cout << sizeof(Base) << endl;
//
//	Base b1;
//
//	return 0;
//}

class Person {
public:
	virtual void BuyTicket() { cout << "买票-全价" << endl; }

	int _a = 1;
};

class Student : public Person {
public:
	virtual void BuyTicket() { cout << "买票-半价" << endl; }
	int _b = 1;
};

void Func(Person& p)
{
	// 符合多态，运行时到指向对象的虚函数表中找调用函数的地址
	p.BuyTicket();
}

int main()
{
	Person Mike;
	Func(Mike);

	Student Johnson;
	Func(Johnson);

	return 0;
}