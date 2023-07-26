#define  _CRT_SECURE_NO_WARNINGS 1
#include"string.h"

int main()
{
	mystring::string s1("hello");
	mystring::string s2;

	s1 += "\0";
	s1 += "xxxx";

	s2 = s1;

	cout << s2 << endl;

	return 0;
}
