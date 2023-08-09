#define  _CRT_SECURE_NO_WARNINGS 1

#include"vector.h"


//void Test1()
//{
//	/*myvector::vector<int> v1;
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//	v1.push_back(5);
//	v1.push_back(6);*/
//
//	//v1.insert(, 100);
//
//	myvector::vector<string> v1;
//	myvector::vector<string> v2;
//
//	v1.push_back("123");
//	v1.push_back("1111");
//	v1.push_back("3333");
//
//
//
//	v1.push_back("44444");
//	v1.push_back("55555");
//
//	
//
//	myvector::vector<string>::iterator it = v1.end()-1;
//	v1.erase(it);
//	v2 = v1;
//
//	for (auto e : v1)
//	{
//		cout << e << " ";
//	}
//
//	cout << endl;
//
//	for (auto e : v2)
//	{
//		cout << e << " ";
//	}
//
//	//cout << v1[1] << endl;
//
//	/*cout << endl;
//	cout << v1.capacity() << endl;*/
//
//	
//}

void Test2()
{
	myvector::vector<string> v1;
	v1.push_back("123");
	v1.push_back("1111");
	v1.push_back("3333");



	v1.push_back("44444");
	v1.push_back("55555");

	myvector::vector<string> v2(v1.begin(), v1.end());
	myvector::vector<string> v3(10, "2222");
	myvector::vector<int> v4(10, 1);

	myvector::vector<string> v5;

	v5 = v1;
	for (auto e : v2)
	{
		cout << e << " ";
	}
	
	cout << endl;

	for (auto e : v3)
	{
		cout << e << " ";
	}

	cout << endl;

	for (auto e : v4)
	{
		cout << e << " ";
	}
	cout << endl;

	for (auto e : v5)
	{
		cout << e << " ";
	}



}

int main()
{
	//Test1();
	Test2();
	return 0;
}