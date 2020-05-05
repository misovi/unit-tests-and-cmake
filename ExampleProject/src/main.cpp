#include <iostream>
#include "Date.h"
int main()
{
	using namespace std;
	Date d1, d2(21, 8, 34);
	int d, m, y;
	// check initialisation is correct
	cout << "First date is ";
	d1.print();
	cout << endl;
	cout << "Second date is ";
	d2.print();
	cout << endl;
	// check accessor functions
	d = d2.get_day();
	m = d2.get_month();
	y = d2.get_year();
	cout << endl << d << " "
		<< m << " "
		<< y << endl;
	// check next day is correct
	d2.next_day();
	cout << "Next day is ";
	d2.print();
	cout << endl;
	// check setting date by assignment
	// and another check on next day.
	d1 = Date(31, 12, 1999);
	d1.next_day();
	cout << "Day after 31/12/1999 is ";
	d1.print();
	cout << endl;
	return 0;
}
