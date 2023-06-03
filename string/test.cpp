#define  _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<string>

using namespace std;



int main()
{
	/*string s1("hello world");

	string s2(10, '*');

	string s3(s1, 0, 2);

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;*/


	string s1("hello");

	for (int i = 0; i < 10; i++)
	{
		s1 += '*';
	}
	cout << s1 << endl;



	
	return 0;
}