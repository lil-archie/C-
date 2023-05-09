#pragma once
#include<iostream>

using namespace std;

class Date
{
public :
	Date(int year = 1998, int month = 11, int day = 18) ;

	void Print()const //const Date *this
	{
		cout << _year << " " << _month << " " << _day << endl;
	}

	bool operator < (const Date& d) const; //�Ƚ�������Ĵ�С��С��
	
	bool operator>(const Date& d) const;//����

	bool operator==(const Date& d) const;

	bool operator<=(const Date& d) const; 

	bool operator>=(const Date& d) const;

	int GetMonthDay(int year, int month) const;








private:
	int _year;
	int _month;
	int _day;
};