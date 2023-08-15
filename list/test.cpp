#define  _CRT_SECURE_NO_WARNINGS 1


#include"list.h"
void Test1()
{
	mylist::list<int> lt1;
	lt1.push_back(1);
	lt1.push_back(2);
	lt1.push_back(3);
	lt1.push_back(4);

	mylist::list<int> lt2(lt1);

	for (auto e : lt2)
	{
		cout << e << " ";
	}

	cout << endl;


	

	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

	cout << lt1.size() << endl;
}
//struct A
//{
//	A(int a1=0, int a2=0)
//		:_a1(a1)
//		, _a2(a2)
//	{}
//
//	int _a1;
//	int _a2;
//};

//void test_list2()
//{
//	mylist::list<A> lt;
//	lt.push_back(A(1, 1));
//	lt.push_back(A(2, 2));
//	lt.push_back(A(3, 3));
//	lt.push_back(A(4, 4));
//
//	mylist::list<A>::iterator it = lt.begin();
//	while (it != lt.end())
//	{
//		//cout << (*it)._a1 << " " << (*it)._a2 << endl;
//		cout << it->_a1 << " " << it->_a2 << endl;
//
//		++it;
//	}
//	cout << endl;
//
//	/*mylist::list<A> lt1(lt);
//
//	for (auto& e : lt)
//	{
//	
//	}*/
//}


int main()
{
	Test1();
	//test_list2();
	return 0;
}