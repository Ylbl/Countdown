#include <string>
#include <time.h>
bool isLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}
int getDays(int year, int month, int day)
{
	int m[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (isLeapYear(year))
		m[2]++;
	int result = 0;
	for (int i = 1; i < year; i++)
	{
		result += 365;
		if (isLeapYear(i))
			result++;
	}
	for (int i = 1; i < month; i++)
	{
		result += m[i];
	}
	result += day;

	return result;
}
int dayDis(int year1, int month1, int day1, int year2, int month2, int day2)
{
	return abs(getDays(year2, month2, day2) - getDays(year1, month1, day1));
}
/// <summary>
/// 获得剩余时间
/// </summary>
/// <returns>剩余时间</returns>
std::string getRestTime() {
	time_t time_seconds = time(0);
	static struct tm now_time;
	localtime_s(&now_time, &time_seconds);


	int now_hour = now_time.tm_hour;
	int now_min = now_time.tm_min;
	int now_sec = now_time.tm_sec;
	int now_year = now_time.tm_year + 1900;
	int now_mon = now_time.tm_mon + 1;
	int now_day = now_time.tm_mday;

	static int rest_hour = 0;
	static int rest_min = 0;
	static int rest_sec = 0;

	if (now_min != 0) {
		rest_hour = 23 - now_hour;
	}
	else {
		rest_hour = 24 - now_hour;
	}

	if (now_sec != 0) {
		rest_min = 59 - now_min;
	}
	else {
		rest_min = 60 - now_min;
	}

	rest_sec = 60 - now_sec;

	std::string endTime = std::to_string(dayDis(2024, 6, 14, now_year, now_mon, now_day)) + "天" + std::to_string(rest_hour) + "小时" + std::to_string(rest_min) + "分" + std::to_string(rest_sec) + "秒";
	return endTime;
}