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
//		, Person(name)//�﷨�涨����ʼ��������
//	{
//		cout << "student()" << endl;
//	}
//	Student(const Student& s)
//		:Person(s)//�������ֱ�Ӹ�ֵ�����ࣨ���У�p=s
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
//	Student s("����",10);
//	Student s1(s);
//
//	Student s2("����", 20);
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
//	string _name = "peter"; // ����
//	int _age = 18;  // ����
//};
//
//// �̳к����Person�ĳ�Ա����Ա����+��Ա�����������������һ���֡��������ֳ���Student��Teacher������Person�ĳ�Ա����������ʹ�ü��Ӵ��ڲ鿴Student��Teacher���󣬿��Կ��������ĸ��á�����Print���Կ�����Ա�����ĸ��á�
//class Student : public Person
//{
//protected:
//	int _stuid; // ѧ��
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // ����
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
//	// ��ֵ����ת��(�и��Ƭ)
//	//p = s;
//	Person p1 = s;
//	Person& rp = s;
//	rp._name = "����";
//
//	Person* ptrp = &s;
//	ptrp->_name = "����";
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
//	string _name = "С����"; // ����
//	int _num = 111; 	   // ���֤��
//};
//
//// ����/�ض��壺����͸�����ͬ����Ա������ĳ�Ա�����˸���ĳ�Ա
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
//		cout << " ����:" << _name << endl;
//		cout << _num << endl;
//		cout << Person::_num << endl;
//	}
//protected:
//	int _num = 999; // ѧ��
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

// ����fun����ʲô��ϵ��
// a������/�ض���   b������   c����д/����  d�����뱨��
// �𰸣�a  (���������У���Ա��������ͬ�͹�������)
//class Person
//{
//public:
//	void fun()
//	{
//		cout << "Person::func()" << endl;
//	}
//
//protected:
//	string _name = "С����"; // ����
//	int _num = 111; 	   // ���֤��
//};
//
//// ����/�ض��壺����͸�����ͬ����Ա������ĳ�Ա�����˸���ĳ�Ա
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
//		cout << " ����:" << _name << endl;
//		cout << _num << endl;
//		cout << Person::_num << endl;
//	}
//protected:
//	int _num = 999; // ѧ��
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
//	string _name; // ����
//
//	string* _pstr = new string("111111111");
//};
//
//class Student : public Person
//{
//public:
//	// �ȸ�����
//	Student(const char* name = "����", int id = 0)
//		:Person(name)
//		,_id(0)
//	{}
//
//	Student(const Student& s)
//		:Person(s)
//		,_id(s._id)
//	{}
//
//	// 10:45����
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
//		// ���ں����̬��ԭ��(������潲)�����������ĺ�������
//		// ���⴦���ˣ�ͳһ�����destructor
//
//		// ��ʾ���ø����������޷���֤���Ӻ�
//		// ������������������ɾͣ��Զ����ø��������������ͱ�֤�����Ӻ�
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
//	Student s3("����", 1);
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
//	string _name; // ����
//};
//
//class Student : public Person
//{
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum; // ѧ��
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

// ��̬��Ա���ڸ����������
// ���������в��ᵥ������һ�ݣ��̳е�ʹ��Ȩ
//class Person
//{
//public:
//	Person() { ++_count; }
////protected:
//	string _name; // ����
//public:
//	static int _count; // ͳ���˵ĸ�����
//};
//
//int Person::_count = 0;
//
//class Student : public Person
//{
//protected:
//	int _stuNum; // ѧ��
//};
//
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // �о���Ŀ
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
//	string _name; // ����
//	int _age;
//};
//
//class Student : virtual public Person
//{
//protected:
//	int _num; //ѧ��
//};
//
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // ְ�����
//};
//
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
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