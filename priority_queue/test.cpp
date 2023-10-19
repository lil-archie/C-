#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

#include"vector.h"

using namespace std;

int main()
{
	myvector::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);



	/*myvector::vector<int> iterator it
	
	
	while (it!= v1.end())
	{
		cout << *it << endl;

	}
	cout << endl;*/


	/*for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;*/


	myvector::vector<int>::iterator it = v1.begin();

	return 0;
}