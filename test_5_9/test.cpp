#define  _CRT_SECURE_NO_WARNINGS 1


#include"Date.h"

void Test1()
{
	Date d1(2023,12,12);
	//d1.Print();
	Date d2(2023, 12, 12);

	cout << (d2 < d1 )<< endl;

	cout << (d2 == d1) << endl;

	cout << (d2 <= d1) << endl;



}


int main()
{
	Test1();
	return 0;
}