#include <iostream>
#include <iostream>

enum Week {
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};

std::string day_of_week (const Week& w);

struct Date {
	int day;
	int month;
	int year;
};

void print (const Date& date, Week dw);

int main()
{
	Date today = {22, 02, 2024};
	Week weekDay = Thursday;
	print (today, weekDay);
}

std::string day_of_week (const Week& w)
{
	switch (w) {
		case Monday:
			return "Monday";
		case Tuesday:
			return "Tuesday";
		case Wednesday:
			return "Wednesday";
		case Thursday:
			return "Thursday";
		case Friday:
			return "Friday";
		case Saturday:
			return "Saturday";
		case Sunday:
			return "Sunday";
		default:
			return "Invalid week day";
	}
}

void print (const Date& date, Week dw)
{
	std::cout << "Date: " << date.day << "." << date.month << "." << date.year << std::endl;
	std::cout << "Week day: " << day_of_week (dw) << std::endl;
}


