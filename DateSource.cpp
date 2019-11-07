#include "DateHeader.h"

Date::Date(int m, int d, int y) // we need to modify 
{
	switch(m)
	{
	case 1: case 3: case 5: case 7: 
	case 8: case 10: case 12: 

		if (d <= 31 && d > 0)
		{
			month = m;
			day = d;
			year = y;
			break;
		}

	case 4: case 6: case 9: case 11:

		if(d <= 30 && d > 0)
		{
			month = m;
			day = d;
			year = y;
			break;
		}

	case 2: // testing for leap year

		if((leapYear(y)) && (d <= 29 && d > 0))
		{
			month = m;
			day = d;
			year = y;
			break;
		}
		else if ((!(leapYear(y))) && (d <= 28 && d > 0))
		{
			month = m;
			day = d;
			year = y;
			break;

		}

		default:

		cout << "INVALID DATE!!!" << endl;
		month = m;
		day = d;
		year = y;
		print_date();
		// end switch
	}
}

void Date::print_date()
{
	cout << "The date is " << month << "-" << day << "-" << year;
}

void Date::calc_military_date()
{
	if(month == 1)
		month_string = "Jan";
	else if(month == 2)
		month_string = "Feb";
	else if(month == 3)
		month_string = "Mar";	
	else if(month == 4)
		month_string = "Apr";
	else if(month == 5)
		month_string = "May";
	else if(month == 6)
		month_string = "Jun";
	else if(month == 7)
		month_string = "Jul";
	else if(month == 8)
		month_string = "Aug";
	else if(month == 9)
		month_string = "Sep";
	else if(month == 10)
		month_string = "Oct";
	else if(month == 11)
		month_string = "Nov";
	else if(month == 12)
		month_string = "Dec";
	else 
		cerr << "Invalid Month" << endl;

}

void Date::print_military_date()
{
	calc_military_date();
	cout << "The military date is " << day << "-" << month << "-" << year << endl;
}

void Date::calc_dow()
{
	int m = month, d = day, y = year;
	dow = (d+=m<3?y--:y-2,23*m/9+d+4+y/4-y/100+y/400)%7;
}

void Date::get_dow()
{
	if(dow == 0)
	{
		day_string = "Sunday";
	}

	else if(dow == 1)
	{
		day_string = "Monday";
	}

	else if(dow == 2)
	{
		day_string = "Tuesday";
	}

	else if(dow == 3)
	{
		day_string = "Wednesday";
	}

	else if(dow == 4)
	{
		day_string = "Thursday";
	}

	else if(dow == 5)
	{
		day_string = "Friday";
	}

	else
	{
		day_string = "Saturday";
	}
}
void Date::print_full_date()
{
	calc_dow();
	get_dow();
	
	cout << "The full date is " << day_string << ", " << month_string << ", " << day << ", " << year;
}

void Date::yesterday()
{
	int prevDay, prevMonth, prevYear;
	switch(month)
	{
	case 2:case 4:case 6:case 8:case 9:case 11:
		if(day == 1)
		{
			prevMonth = month - 1;
			prevDay = 31;
			prevYear = year;
			break;
		}
		else
		{
			prevMonth = month;
			prevDay = day - 1;
			prevYear = year;
			break;
		}
	case 1:
		if(day == 1)
		{
			prevMonth = 12;
			prevDay = 31;
			prevYear =  year - 1;
			break;
		}
		else
		{
			prevMonth = month;
			prevDay = day - 1;
			prevYear = year;
			break;
		}
	case 3:
		if(day == 1)
		{
			prevMonth = month - 1;
			prevDay = 28;
			prevYear =  year;
			break;
		}
		else
		{
			prevMonth = month;
			prevDay = day - 1;
			prevYear = year;
			break;
		}
	case 5: case 7: case 10: case 12:
		if(day == 1)
		{
			prevMonth = month - 1;
			prevDay = 30;
			prevYear =  year;
			break;
		}
		else
		{
			prevMonth = month;
			prevDay = day - 1;
			prevYear = year;
			break;
		}

	}

	cout << "Yesterday's date was " << prevMonth << "-" << prevDay << "-" << prevYear;
}

void Date::tomorrow()
{
	int nextDay, nextMonth, nextYear;
	switch(month)
	{
	case 1:case 3: case 5: case 7: case 8: case 10:

		if(day == 31)
		{
			nextMonth - month + 1;
			nextDay = 1;
			nextYear = year;
			break;
		}

		else
		{
			nextMonth = month;
			nextDay = day + 1;
			nextYear = year;
			break;
		}

	case 12:
		if(day == 31)
		{
			nextMonth = 1;
			nextDay = 1;
			nextYear = year + 1;
			break;
		}
		else
		{
			nextMonth = month;
			nextDay = day + 1;
			nextYear = year;
			break;
		}

	case 2:
		if(day == 28)
		{
			nextMonth = month + 1;
			nextDay = 1;
			nextYear = year;
			break;
		}
		else
		{
			nextMonth = month;
			nextDay = day + 1;
			nextYear = year;
			break;
		}

	case 4: case 6: case 9: case 11:
		if(day == 30)
		{
			nextMonth = month + 1;
			nextDay = 1;
			nextYear = year;
			break;
		}
		else
		{
			nextMonth = month;
			nextDay = day + 1;
			nextYear = year;
			break;
		}

	}

	cout << "Tomorrow's date is " << nextMonth << "-" << nextDay << "-" << nextYear;

}
bool Date::leapYear(int y)
{
	if(y % 100 == 0)
		return (y % 400 == 0);

	else 
		return (y % 4 == 0);

}

Date::~Date(void)
{
}