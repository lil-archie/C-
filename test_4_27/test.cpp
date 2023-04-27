#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

struct A {

	long a1;

	short a2;

	int a3;

	int* a4;

};

int main()
{
	cout << sizeof(A) << endl;
	cout << sizeof(long) << endl;
	cout << sizeof(int*) << endl;

	return 0;
}
//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date(const Date& d)
//	{
//		cout << "Date(const Date& d)" << endl;
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	bool operator<(const Date& x)
//	{
//		if (_year < x._year)
//		{
//			return true;
//		}
//		else if (_year == x._year && _month < x._month)
//		{
//			return true;
//		}
//		else if (_year == x._year && _month == x._month && _day < x._day)
//		{
//			return true;
//		}
//
//		return false;
//	}
//
//	// d4 = d1
//	// d1 = d1
//	//Date& operator=(const Date& d)
//	//{
//	//	if (this != &d)
//	//	{
//	//		_year = d._year;
//	//		_month = d._month;
//	//		_day = d._day;
//	//	}
//
//	//	return *this;
//	//}
//
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//bool operator<(const Date& x1, const Date& x2)
//{
//	if (x1._year < x2._year)
//	{
//		return true;
//	}
//	else if (x1._year == x2._year && x1._month < x2._month)
//	{
//		return true;
//	}
//	else if (x1._year == x2._year && x1._month == x2._month && x1._day < x2._day)
//	{
//		return true;
//	}
//
//	return false;
//}


//int main()
//{
//	Date d1(2023, 4, 26);
//	Date d2(2023, 6, 21);
//
//	//d1 < d2; // ת����operator<(d1, d2);
//	//operator<(d1, d2);
//
//	d1 < d2; // ת����d1.operator<(d2);
//	d1.operator<(d2);
//
//	if (d1 < d2)
//	{
//
//	}
//
//	//d1 - d2;  // ������
//	//d1 + d2;  // û����
//	// �Ƿ�Ҫ���������������������������Ƿ�������
//
//	return 0;
//}


//int main()
//{
//	Date d1(2023, 4, 26);
//	Date d2(2023, 6, 21);
//	// �Ѿ����ڵ���������֮�临�ƿ���        -- ��������غ���
//	d1 = d2;
//
//	// ��һ���Ѿ����ڵĶ����ʼ����һ������  -- ���캯��
//	//Date d3(d1);
//
//	int i, j, k;
//	i = j = k = 0;
//
//	Date d5, d4;
//	d5 = d4 = d1;
//
//	d1 = d1;
//
//	return 0;
//}

#include"Date.h"

void TestDate1()
{
	Date d1(2023, 4, 26);
	d1 += 100;
	d1.Print();

	Date d2(2023, 4, 26);
	//Date d3(d2 + 100);
	Date d3 = d2 + 100;
	d2.Print();
	d3.Print();

	// ��һ���Ѿ����ڵĶ����ʼ����һ������  -- ���캯��
	Date d4 = d2;  // �ȼ��� Date d4(d2);

	//�Ѿ����ڵ���������֮�临�ƿ���        -- ��������غ���
	d4 = d1;

	//int i = 0, j = 1;
	//j += i += 10;
}

void TestDate2()
{
	Date d1(2023, 4, 26);
	// ��Ҫ++��ǰ��++����++�Ժ�Ķ��󣬺���++����++֮ǰ�Ķ���
	++d1; // d1.operator++()
	d1++; // d1.operator++(0)
}

int main()
{
	TestDate2();

	return 0;
}
#include "Date.h"

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

bool Date::operator<(const Date& x)
{
	if (_year < x._year)
	{
		return true;
	}
	else if (_year == x._year && _month < x._month)
	{
		return true;
	}
	else if (_year == x._year && _month == x._month && _day < x._day)
	{
		return true;
	}

	return false;
}

bool Date::operator==(const Date& x)
{
	return _year == x._year
		&& _month == x._month
		&& _day == x._day;
}

// ����
// d1 <= d2
bool Date::operator<=(const Date& x)
{
	return *this < x || *this == x;
}

bool Date::operator>(const Date& x)
{
	return !(*this <= x);
}

bool Date::operator>=(const Date& x)
{
	return !(*this < x);
}

bool Date::operator!=(const Date& x)
{
	return !(*this == x);
}

int Date::GetMonthDay(int year, int month)
{
	static int daysArr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	//if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && month == 2)
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		return 29;
	}
	else
	{
		return daysArr[month];
	}
}

Date& Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}

	return *this;
}

// d1 + 100
Date Date::operator+(int day)
{
	Date tmp(*this);
	tmp += day;
	return tmp;

	/*tmp._day += day;
	while (tmp._day > GetMonthDay(tmp._year, tmp._month))
	{
		tmp._day -= GetMonthDay(tmp._year, tmp._month);
		++tmp._month;
		if (tmp._month == 13)
		{
			++tmp._year;
			tmp._month = 1;
		}
	}
	return tmp;
	*/
}

// ǰ��++
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

// ����++
// �������int��������Ϊ�˽��վ����ֵ��������ռλ����ǰ��++��������
Date Date::operator++(int)
{
	Date tmp = *this;
	*this += 1;

	return tmp;
}
#pragma once
#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1);

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	Date(const Date& d)   // ����д�������뱨������������ݹ�
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	bool operator<(const Date& x);
	bool operator==(const Date& x);
	bool operator<=(const Date& x);
	bool operator>(const Date& x);
	bool operator>=(const Date& x);
	bool operator!=(const Date& x);

	int GetMonthDay(int year, int month);

	// d1 + 100
	Date& operator+=(int day);
	Date operator+(int day);

	Date& operator++();
	Date operator++(int);
private:
	int _year;
	int _month;
	int _day;
};
