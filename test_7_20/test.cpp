#define  _CRT_SECURE_NO_WARNINGS 1
#include"string.h"

//void Test1()
//{
	//mystring::string s1("hello world");
	/*cout << s1.c_str() << endl;
	cout << s1.size() << endl;
	cout << s1[0] << endl;
	s1.push_back('#');
	cout << s1.c_str() << endl;*/

	/*s1.append("###");
	cout << s1.c_str() << endl;*/

	/*s1.push_back('x');
	cout << s1.c_str() << endl;*/

	/*s1.append("hello bit");
	cout << s1.c_str()<< endl;*/
//}

//void Test2()
//{
//	mystring::string s1("hello world");
//	mystring::string s2("hello bit");
//
//	string s3("hello world");
//	string s4("hello");
//
//	s3 += s4;
//	cout << s3 << endl;
//	
//	s1.append("append");
//
//	s1 += "hello world";
//	s1 += 'x';
//
//	s1.insert(0, 3, 'c');
//
//	s1.insert(2, 2, 'v');
//
//	s1.insert(2, "hello");
//
//	cout << s1.c_str() << endl;
//
//
//}

//void Test3()
//{
//	mystring::string s1("hello world");
//	/*mystring::string::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		cout << *it << " ";
//		it++;
//	}*/
//	mystring::string s2("hellobit");
//
//	
//	cout << s2.find('h', 0) << endl;
//
//	cout << s1.find('lo', 0) << endl;
//	
//
//	/*for (auto ch : s2)
//	{
//		cout << ch << " ";
//	}
//
//	cout << endl;
//
//	s1.erase(2,3);
//
//	for (auto ch : s1)
//	{
//		cout << ch << " ";
//	}*/
//	cout << endl;
//
//	/*const mystring::string s2("hello");
//
//	s1
//
//	for (auto ch : s2)
//	{
//		cout << ch << " ";
//	}*/
//}


void test_string5()
{
	// 21£º18¼ÌÐø
	mystring::string url = "ftp://www.baidu.com/?tn=65081411_1_oem_dg";

	size_t pos1 = url.find("://");
	if (pos1 != mystring::string::npos)
	{
		mystring::string url = "ftp://www.baidu.com/?tn=65081411_1_oem_dg";
	
		
		mystring::string protocol = url.substr(0, pos1);
		cout << protocol.c_str() << endl;
	}

	size_t pos2 = url.find('/', pos1 + 3);
	if (pos2 != mystring::string::npos)
	{
		mystring::string domain = url.substr(pos1 + 3, pos2 - (pos1 + 3));
		mystring::string uri = url.substr(pos2 + 1);

		cout << domain.c_str() << endl;
		cout << uri.c_str() << endl;
	}
}

//void Test4()
//{
//	mystring::string s1("Test string");
//
//
//	mystring::string s2=s1.substr(0,2);
//
//	cout << s2.c_str() << endl;
//
//	
//}
int main()
{
	//Test1();
	//Test2();
	//Test3();
	 test_string5();
	//Test4();

}