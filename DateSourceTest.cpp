#include "DateHeader.h"

int main()
{
	Date today(4,3,2019), testdate(3,14,2019); 

		today.print_date();
			cout << endl;

		today.print_military_date();
			cout << endl;

		today.print_full_date();
			cout << endl;
		
		today.yesterday();
			cout << endl;

		today.tomorrow();
			cout << endl;


	system ("PAUSE");

	return 0;
}