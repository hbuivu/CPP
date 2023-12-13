#include <iostream>
#include <chrono>
#include <ctime>

int main()
{
	time_t	t = time(nullptr);
	struct tm *tm = localtime(&t);

	int day = tm ->tm_mday;
	int	month = tm->tm_mon + 1;
	int	year = tm->tm_year + 1900;
	int hour = tm->tm_hour;
	int	minutes = tm->tm_min;
	int seconds = tm->tm_sec;
	std::cout << "day:" << day << "month:" << month << "year:" << year << std::endl;
	std::cout << "hour:" << hour << "minutes:" << minutes << "seconds:" << seconds << std::endl; 
}