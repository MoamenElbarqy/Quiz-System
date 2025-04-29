#pragma once
#include "Date.h"
#include <ctime>
#include <string>
using namespace std;

string current_date()
{
	time_t t = time(nullptr); // Current Time
	tm now;
	localtime_s(&now, &t); // Changing Time To Structure Contains Day, Month, Year
	string Date = to_string(now.tm_mday) + "/" + to_string((now.tm_mon + 1)) + "/" + to_string(now.tm_year + 1900);
	return Date;
}
string current_time()
{
	time_t t = time(nullptr);
	tm now;
	localtime_s(&now, &t);
	if (now.tm_hour > 12)
		now.tm_hour -= 12;
	string Time = to_string(now.tm_hour) + ":" + to_string(now.tm_min) + ":" + to_string(now.tm_sec);
	return Time;
}