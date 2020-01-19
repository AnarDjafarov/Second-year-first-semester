#pragma once
#include <iostream>
#include <string.h>
#include "MyDate.h"


class Calendar
{
private:
	MyDate* dates[30];
public:
	Calendar();
	~Calendar();
public:
	int setDate(const MyDate& newDate, int num);
	bool isFree(int num);
	int firstFree();
	int insert(const MyDate& newDate);
	int oldest();
	int datesNum(const MyDate& newDate);
	void deleteAll();
	int deleteDate(int num);
	char* print();
	void sortDates();
};

