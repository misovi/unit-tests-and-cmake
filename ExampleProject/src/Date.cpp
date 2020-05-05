// File Date.cpp
// Implementation file for the Date class
// IEA February 1997
#include <iostream>
#include <cstdlib>
#include "Date.h"
// Constructor functions
Date::Date(int dd, int mm, int yy)
{
	day = dd;
	month = mm;
	year = yy;
}
Date::Date()
{
	day = 1;
	month = 1;
	year = 1900;
}
// Accessor functions
int Date::get_day()
{
	return day;
}
int Date::get_month()
{
	return month;
}
int Date::get_year()
{
	return year;
}
// Other functions
void Date::print()
{
	std::cout << day << " / " << month << " / "	<< year;
}
void Date::next_day()
{
	int days_in_month;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: days_in_month = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11: days_in_month = 30;
		break;
	case 2: if (leap_year())
		days_in_month = 29;
		  else days_in_month = 28;
		break;
	}
	day++;

	if (day > days_in_month)
	{
		day = 1;
		month++;
		if (month > 12)
		{
			month = 1;
			year++;
		}
	}
}

bool Date::equals(Date d)
{
	return get_day() == d.get_day() && get_month() == d.get_month() && get_year() == d.get_year();
}

int Date::days_between(Date d)
{
	int e_day, e_month, e_year, l_day, l_month, l_year;
	if(d.get_year() < get_year())
	{
		e_day = d.get_day();
		e_month = d.get_month();
		e_year = d.get_year();
		l_day = get_day();
		l_month = get_month();
		l_year = get_year();
	}
	else if(d.get_month() < get_month())
	{
		e_day = d.get_day();
		e_month = d.get_month();
		e_year = d.get_year();
		l_day = get_day();
		l_month = get_month();
		l_year = get_year();
	}
	else if(d.get_day() < get_day())
	{
		e_day = d.get_day();
		e_month = d.get_month();
		e_year = d.get_year();
		l_day = get_day();
		l_month = get_month();
		l_year = get_year();
	}
	else
	{
		e_day = get_day();
		e_month = get_month();
		e_year = get_year();
		l_day = d.get_day();
		l_month = d.get_month();
		l_year = d.get_year();
	}
	Date earlier_date(e_day,e_month,e_year);
	Date later_date(l_day,l_month,l_year);
	int i = 0;
	while(!earlier_date.equals(later_date))
	{
		earlier_date.next_day();
		i++;
	}
	return i;
}

int Date::days_since_newyear()
{
	Date newyear(1,1,get_year());
	return days_between(newyear);
}

// Private function
int Date::leap_year()
{
	if (year % 400 == 0)
		return 1;
	else if (year % 100 == 0)
		return 0;
	else if (year % 4 == 0)
		return 1;
	else return 0;
}
