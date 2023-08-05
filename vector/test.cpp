#define  _CRT_SECURE_NO_WARNINGS 1

#include"vector.h"


void Test1()
{
	myvector::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);

	//v1.insert(, 100);
	for (auto e : v1)
	{
		cout << e << " ";
	}

	//cout << v1[1] << endl;

	/*cout << endl;
	cout << v1.capacity() << endl;*/
}

int main()
{
	Test1();
	return 0;
}