#define  _CRT_SECURE_NO_WARNINGS 1

#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>

using namespace std;

//class A
//{
//public:
//	//explicit A(int a)
//	A(int a)
//		:_a(a)
//	{}
//private:
//	int _a;
//};
//
//class B
//{
//public:
//	B(const A& a)
//	{}
//private:
//	//...
//};
//
//void insert(size_t pos, char ch)
//{
//	int end = 10;
//	while (end >= pos)
//	{
//		cout << end << endl;
//		//...
//		--end;
//	}
//}

//int main()
//{
//    int i = 1;
//    // ��ʽ����ת��
//    double d = i;
//    printf("%d, %.2f\n", i, d);
//
//    A aa1 = 1;
//    B bb1 = aa1;
//
//    int* p = &i;
//    // ��ʾ��ǿ������ת��
//    int address = (int)p;
//
//    printf("%p, %d\n", p, address);
//
//    //vector<int> v;
//    //string s;
//    //v = (vector<int>)s;
//
//    insert(3, 'x');
//    insert(0, 'x');
//
//
//    return 0;
//}

//int main()
//{
//	// volatile ���εı�����ÿ�ζ�Ҫȥ�ڴ�ȡ
//	volatile const int n = 10;
//	//n = 11;
//	// ת���а�ȫ������
//	int* p = (int*)&n;
//	(*p)++;
//
//	cout << n << endl;
//	cout << *p << endl;
//
//	cout << p << endl;
//
//	return 0;
//}

//int main()
//{
//	// �������/�������
//	double d = 12.34;
//	int a = static_cast<int>(d);
//	cout << a << endl;
//
//	// ���������
//	int* p1 = &a;
//	int address = reinterpret_cast<int>(p1);
//
//	// ȥ��const����
//	volatile const int n = 10;
//	int* p2 = const_cast<int*>(&n);
//
//	// 
//
//
//	return 0;
//}

//class A
//{
//public:
//	virtual void f() {}
//
//	int _x = 0;
//};
//
//class B : public A
//{
//public:
//	int _y = 0;
//};
//
//void fun(A* pa)
//{
//	// pa��ָ���������B�ģ�ת�����Գɹ����������ص�ַ
//	// pa��ָ�������A�ģ�ת��ʧ�ܣ����ؿ�ָ��
//	B* pb = dynamic_cast<B*>(pa);
//	if (pb)
//	{
//		cout << "ת���ɹ�" << endl;
//		pb->_x++;
//		pb->_y++;
//	}
//	else
//	{
//		cout << "ת��ʧ��" << endl;
//	}
//}

//int main()
//{
//	A aa;
//	fun(&aa);
//
//	B bb;
//	fun(&bb);
//
//	return 0;
//}

//int main()
//{
//	string str;
//	while (cin >> str) // operator>>(cin, str).operator bool()
//	{
//		cout << str << endl;
//	}
//
//	return 0;
//}

//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//
//	//explicit operator int()
//	operator int ()
//	{
//		return _a;
//	}
//
//	operator bool()
//	{
//		return _a;
//	}
//
//	int _a;
//};
//
//int main()
//{
//	//// �Զ�������<-��������
//	//A aa1 = 100;
//
//	//// ��������<-�Զ�������
//	//int i = aa1;
//	//cout << i << endl;
//
//	////double d = aa1;
//	////int* ptr = aa1;
//
//	//bool ret = aa1;
//	//cout << ret << endl;
//
//	int a, b;
//	while (cin>>a>>b)  // cin.operator>>(a).operator>>(b).operator bool()
//	{
//		cout << a << endl;
//		cout << b << endl;
//	}
//
//	return 0;
//}

class Date
{
	friend ostream& operator << (ostream& out, const Date& d);
	friend istream& operator >> (istream& in, Date& d);
public:
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	/*operator string()
	{
		string str;
		str += to_string(_year);
		str += ' ';
		str += to_string(_month);
		str += ' ';
		str += to_string(_day);
		return str;
	}*/

	operator bool()
	{
		// ����������д�ģ���������_yearΪ0�������
		if (_year == 0)
			return false;
		else
			return true;
	}
private:
	int _year;
	int _month;
	int _day;
};

istream& operator >> (istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}

ostream& operator << (ostream& out, const Date& d)
{
	out << d._year << " " << d._month << " " << d._day;
	return out;
}

#include<fstream>

//int main()
//{
//	Date d(2023, 10, 14);
//	//FILE* fin = fopen("file.txt", "w");
//	/*fwrite(&d, sizeof(Date), 1, fin);
//	fclose(fin);*/
//	//string str = d;
//	//fputs(str.c_str(), fin);
//
//	// 17:15����
//	//ofstream ofs("file.txt", ios_base::out | ios_base::binary);
//	ofstream ofs("file.txt");
//	// �����Ƶķ�ʽ
//	//ofs.write((const char*)&d, sizeof(d));
//	// 
//	// �ı��ķ�ʽ
//	ofs << d;
//
//	return 0;
//}

struct ServerInfo
{
	char _address[32];
	// �����ƶ�д������string vector�����Ķ��������
	// ����д��ȥ����һ��ָ�룬���̽�������Ұָ�룬��һ�������ٶ�����������
	//string _address;
	int _port;

	Date _date;
};

struct ConfigManager
{
public:
	ConfigManager(const char* filename = "file.txt")
		:_filename(filename)
	{}

	// �����ƶ�д -- �򵥸�Ч��ȱ�㣺д���ļ��е����ݿ�����
	void WriteBin(const ServerInfo& info)
	{
		ofstream ofs(_filename, ios_base::out | ios_base::binary);
		ofs.write((const char*)&info, sizeof(info));
	}

	void ReadBin(ServerInfo& info)
	{
		ifstream ifs(_filename, ios_base::in | ios_base::binary);
		ifs.read((char*)&info, sizeof(info));
	}

	void WriteText(const ServerInfo& info)
	{
		ofstream ofs(_filename);
		ofs << info._address << " " << info._port << " " << info._date;
	}

	void ReadText(ServerInfo& info)
	{
		ifstream ifs(_filename);
		ifs >> info._address >> info._port >> info._date;
	}
private:
	string _filename; // �����ļ�
};

//int main()
//{
//	ServerInfo winfo = { "192.0.0.1111111111111111111", 80, { 2022, 4, 10 } };
//	ConfigManager cm("test.bin");
//	cm.WriteBin(winfo);
//
//	return 0;
//}

//int main()
//{
//	ConfigManager cf_bin("test.bin");
//	ServerInfo rbinfo;
//	cf_bin.ReadBin(rbinfo);
//	cout << rbinfo._address << "  " << rbinfo._port << "  " << rbinfo._date << endl;
//
//	return 0;
//}
//
//int main()
//{
//	ServerInfo winfo = { "192.0.0.1111111111111111111", 80, { 2022, 4, 10 } };
//	ConfigManager cm("test.txt");
//	cm.WriteText(winfo);
//
//	return 0;
//}

//int main()
//{
//	ConfigManager cf_bin("test.txt");
//	ServerInfo rbinfo;
//	cf_bin.ReadText(rbinfo);
//	cout << rbinfo._address << "  " << rbinfo._port << "  " << rbinfo._date << endl;
//
//	return 0;
//}

int main()
{
	ifstream ifs("Test.cpp");
	char ch;
	while (ifs.get(ch))
	{
		cout << ch;
	}

	return 0;
}