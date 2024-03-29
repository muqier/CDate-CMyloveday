// 1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
using namespace std;
class CMyDate
{
private:
	int year;
	int month;
	int day;
	int check();

public:
	CMyDate();
	CMyDate(int y, int m, int d);
	int setDate(int y, int m, int d);
	void displayDate();
	void addOneDay();
	int getYear();
	int getMonth();
	int getDay();
};
CMyDate::CMyDate()
{
	year = 2019;
	month = 1;
	day = 1;
}
CMyDate::CMyDate(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
	if (check() == 1 || check() == -1)
	{
		month = 1;
		day = 1;
		cout << "设置了错误日期，月日已置1" << endl;
	}

}
int CMyDate::setDate(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
	if (check() == 1 || check() == -1)
	{
		month = 1;
		day = 1;
		cout << "设置了错误日期，月日已置1" << endl;
		return -1;
	}
	return 0;

}
void CMyDate::displayDate()
{
	cout << year << "年" << month << "月" << day << "日" << endl;
}
int CMyDate::check()
{
	int flatYearDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapYearDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	if (month > 12 || month < 1)
		return -1;
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
	{
		if (leapYearDays[month - 1] < day || day < 1)
			return 1;
	}
	else
	{
		if (flatYearDays[month - 1] < day || day < 1)
			return 1;
	}
	return 0;
}
int CMyDate::getYear()
{
	return year;
}
int CMyDate::getMonth()
{
	return month;
}
int CMyDate::getDay()
{
	return day;
}
void CMyDate::addOneDay()
{
	int flatYearDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapYearDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	day++;

	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
	{
		if (leapYearDays[month - 1] < day)
		{
			day = 1;
			month++;
		}
	}
	else
	{
		if (flatYearDays[month - 1] < day)
		{
			day = 1;
			month++;
		}
	}
	if (month > 12)
	{
		month = 1;
		year++;
	}

}
class CMyloveday : public CMyDate 
{
public:
	int CMyDate()
	{
		year = 2019;
		month = 1;
		day = 1;
	}
	int CMyDate(int y, int m, int d) 
	{
		year = y;
		month = m;
		day = d;
		if (check() == 1 || check() == -1)
		{
			month = 1;
			day = 1;
			cout << "设置了错误日期，月日已置1" << endl;
		}
		
	}
	int setDate(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
		if (check() == 1 || check() == -1)
		{
			month = 1;
			day = 1;
			cout << "设置了错误日期，月日已置1" << endl;
			return -1;
		}
		return 0;
		
	}
	int check()
	{
		int flatYearDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		int leapYearDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
		if (month > 12 || month < 1)
			return -1;
		if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
		{
			if (leapYearDays[month - 1] < day || day < 1)
				return 1;
		}
		else
		{
			if (flatYearDays[month - 1] < day || day < 1)
				return 1;
		}
		return 0;
	}
	void displayDate()
	{
		cout << year << "年" << month << "月" << day << "日" << endl;
	}
	int getYear()
	{
		return year;
	}
	int getMonth()
	{
		return month;
	}
	int getDay()
	{
		return day;
	}
	void addOneDay()
	{
		int flatYearDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		int leapYearDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
		day++;

		if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
		{
			if (leapYearDays[month - 1] < day)
			{
				day = 1;
				month++;
			}
		}
		else
		{
			if (flatYearDays[month - 1] < day)
			{
				day = 1;
				month++;
			}
		}
		if (month > 12)
		{
			month = 1;
			year++;
		}

	}
private:
	int year;
	int month;
	int day;

};
int main()
{
	CMyloveday od;
	int i;
	int count = 1;
	od.setDate(2000, 1, 6);
	od.displayDate();
	while (!((od.getYear() == 2019) && (od.getMonth() == 6) && (od.getDay()) ==13))
	{
		od.addOneDay();
		count++;
	}
	cout << count << endl;
	return 0;
}