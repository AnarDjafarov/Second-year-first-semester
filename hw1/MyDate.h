#pragma once
#include <iostream>
#include <string.h>

using namespace std;

class MyDate
{
private:
	int Day;
	int Month;
	int Year;
public:
	MyDate();
	MyDate(int day, int month, int year);
public:
	void init();
	int set(int day, int month, int year);
	int setDay(int day);
	int setMonth(int month);
	int setYear(int year);
	bool isBefore(const MyDate& newDate);
	int delay(int num);
	int bringForward(int num);
	char* print();
public:
	int getDay();
	int getMonth();
	int getYear();
	void myDelete();

	~MyDate() {};
};

