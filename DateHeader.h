//Nile Weadick

#include <iostream>
#include <string>
using namespace std;

#pragma once

class Date
{
public:

	Date(int = 1, int = 1, int = 1990); // Default Constuctor
	void print_date();
	void calc_military_date();
	void print_military_date();// 4-jun-2018
	void calc_dow();
	void get_dow();
	void print_full_date(); // Example Wednesday, March 13, 2019
	void yesterday();
	void tomorrow();

	~Date(void); // Destructor

private:

	int month, day, year;
	double dow;
	bool leapYear(int);
	string month_string, day_string;
};