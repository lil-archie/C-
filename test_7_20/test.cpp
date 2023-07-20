#define  _CRT_SECURE_NO_WARNINGS 1
#include"string.h"

void Test1()
{
	mystring::string s1("hello world");
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
}

void Test2()
{
	mystring::string s1("hello world");
	mystring::string s2("hello bit");

	string s3("hello world");
	string s4("hello");

	s3 += s4;
	cout << s3 << endl;
	
	s1.append("append");

	s1 += "hello world";
	s1 += 'x';

	cout << s1.c_str() << endl;


}

int main()
{
	//Test1();
	Test2();
}