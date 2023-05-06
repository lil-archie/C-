#define  _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

class Date
{
	// ��Ԫ��������
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	Date(int year = 1, int month = 1, int day = 1);

	void Print() const
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	Date(const Date& d)   // ����д�������뱨������������ݹ�
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	bool operator<(const Date& x) const;
	bool operator==(const Date& x) const;
	bool operator<=(const Date& x) const;
	bool operator>(const Date& x) const;
	bool operator>=(const Date& x) const;
	bool operator!=(const Date& x) const;

	int GetMonthDay(int year, int month);

	// d1 + 100
	Date& operator+=(int day);
	Date operator+(int day) const;

	Date& operator-=(int day);
	Date operator-(int day) const;

	Date& operator++();
	Date operator++(int);

	Date& operator--();
	Date operator--(int);

	int operator-(const Date& d) const;

	// �����벻��д�ɳ�Ա����?
	// ��ΪDate����Ĭ��ռ�õ�һ�����������������������
	// д������һ�������������ӣ�������ʹ��ϰ��
	//d1 << cout; // d1.operator<<(cout); 
	//void operator<<(ostream& out);

	/*int GetYear()
	{
		return _year;
	}*/
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& out, const Date& d);
istream& operator>>(istream& in, Date& d);


