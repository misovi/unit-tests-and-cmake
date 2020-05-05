#pragma once
class Date
{
public:
	// Constructors
	// initialise to 1/1/1900
	Date();
	// initialise to dd/mm/yy
	Date(int dd, int mm, int yy);
	// member functions
	void print(); // prints date
	void next_day(); // sets date to next day
	int days_between(Date d);
	int days_since_newyear();
	// Accessor functions
	int get_day(); // returns day
	int get_month(); // returns month
	int get_year(); // returns year
private:
	int day;
	int month;
	int year;
	int leap_year(); // returns true if year is a leap
	// year. Required in next_day()
	int return_number_of_days(int month);
	bool equals(Date d);
};
