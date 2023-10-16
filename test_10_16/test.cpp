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
//    // 隐式类型转换
//    double d = i;
//    printf("%d, %.2f\n", i, d);
//
//    A aa1 = 1;
//    B bb1 = aa1;
//
//    int* p = &i;
//    // 显示的强制类型转换
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
//	// volatile 修饰的变量，每次都要去内存取
//	volatile const int n = 10;
//	//n = 11;
//	// 转换有安全隐患的
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
//	// 相关类型/相近类型
//	double d = 12.34;
//	int a = static_cast<int>(d);
//	cout << a << endl;
//
//	// 不相关类型
//	int* p1 = &a;
//	int address = reinterpret_cast<int>(p1);
//
//	// 去掉const属性
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
//	// pa是指向子类对象B的，转换可以成功，正常返回地址
//	// pa是指向父类对象A的，转换失败，返回空指针
//	B* pb = dynamic_cast<B*>(pa);
//	if (pb)
//	{
//		cout << "转换成功" << endl;
//		pb->_x++;
//		pb->_y++;
//	}
//	else
//	{
//		cout << "转换失败" << endl;
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
//	//// 自定义类型<-内置类型
//	//A aa1 = 100;
//
//	//// 内置类型<-自定义类型
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
		// 这里是随意写的，假设输入_year为0，则结束
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
//	// 17:15继续
//	//ofstream ofs("file.txt", ios_base::out | ios_base::binary);
//	ofstream ofs("file.txt");
//	// 二进制的方式
//	//ofs.write((const char*)&d, sizeof(d));
//	// 
//	// 文本的方式
//	ofs << d;
//
//	return 0;
//}

struct ServerInfo
{
	char _address[32];
	// 二进制读写不能用string vector这样的对象存数据
	// 否则写出去就是一个指针，进程结束就是野指针，另一个进程再读进来进坑了
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

	// 二进制读写 -- 简单高效，缺点：写到文件中的内容看不懂
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
	string _filename; // 配置文件
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

//int main()
//{
//	ifstream ifs("Test.cpp");
//	char ch;
//	while (ifs.get(ch))
//	{
//		cout << ch;
//	}
//
//	return 0;
//}

#include<sstream>

//int main()
//{
//	//int x;
//	//cin >> x;
//	//char buff[128];
//	//sprintf(buff, "int:%d", x);
//
//	// 简单序列化和反序列化
//	//Date d(2023, 10, 16);
//	//ostringstream oss;
//	//oss << d;
//	//string str = oss.str();
//	//cout << str << endl;
//
//	// 整形    补码存储
//	// 浮点型  整形和浮点数部分
//	// 布尔    真 假
//	// enum    整形常量
//	// 字符串
//	// 联合
//	// 结构
//	// 类
//
//	//string str("2023 10 16");
//	//istringstream iss(str);
//	//Date d;
//	//iss >> d;
//
//
//	return 0;
//}

//struct ChatInfo
//{
//	string _name; // 名字
//	int _id;      // id
//	Date _date;   // 时间
//	string _msg;  // 聊天信息
//};

//int main()
//{
//	ChatInfo winfo = { "张三", 135246, { 2023, 10, 16 }, "晚上一起看电影吧" };
//	stringstream oss;
//	oss << winfo._name << " " << winfo._id << " " << winfo._date << " " << winfo._msg;
//	string str = oss.str();
//
//	//send(str);
//	cout << str << endl;
//
//	// json xml 
//	ChatInfo rInfo;
//	stringstream iss(str);
//	iss >> rInfo._name >> rInfo._id >> rInfo._date >> rInfo._msg;
//	cout << "-------------------------------------------------------" << endl;
//	cout << "姓名：" << rInfo._name << "(" << rInfo._id << ") ";
//	cout << rInfo._date << endl;
//	cout << rInfo._name << ":>" << rInfo._msg << endl;
//	cout << "-------------------------------------------------------" << endl;
//	return 0;
//}

int main()
{

	return 0;
}