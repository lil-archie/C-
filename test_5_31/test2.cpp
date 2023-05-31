#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;


template<typename T>
void Swap(T& x, T& y)
{
	T tmp = x;
	x= y;
	y= tmp;
}

int main()

{
	int a = 1, b = 2;
	double c = 1.12, d = 2.22;
	cout << a << endl;
	cout << b << endl;



	Swap(a, b);
	Swap(c, d);

	cout << a << endl;
	cout << b<< endl;

	cout << c << endl;
	cout << d << endl;



	return 0;
}