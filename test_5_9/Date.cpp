#define  _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"

Date:: Date(int year , int month , int day )  //缺省函数在声明中给缺省值即可,在定义中可以不给。
{
	_year = year;
	_month = month;
	_day = day;
}

bool Date::operator<(const Date& d) const
{
	if (_year < d._year)
		return true;
	else if (_year == d._year && _month < d._month)
		return true;
	else if (_year == d._year && _month == d._month && _day < d._day)
		return true;
	else
		return false;

}

bool Date::operator==(const Date& d)const
{
	return (_year == d._year
		&& _month == d._month
		&& _day == d._day);
}

bool Date::operator>(const Date& d) const
{
	if (_year > d._year)
		return true;
	else if (_year == d._year && _month > d._month)
		return true;
	else if (_year == d._year && _month == d._month && _day > d._day)
		return true;
	else
		return false;
}

bool Date::operator<=(const Date& d) const
{
	//return *this < d || *this == d;
	return !(*this > d);
}

bool Date::operator>=(const Date& d) const
{
	return !(*this < d);
}

int Date::GetMonthDay(int year, int month) const
{
	int MonthArr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		return 29;
	else
		return MonthArr[month];
}