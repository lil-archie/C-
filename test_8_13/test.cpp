#define  _CRT_SECURE_NO_WARNINGS 1
#include"list.h"

int main()
{
	mylist::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	mylist::list<int>::iterator it = lt.begin();

	while (it != lt.end())
	{
		cout << *it << " ";
		it++;
	}



	return 0;
}