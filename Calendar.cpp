#include <iostream>
#include <string.h>
#include "Calendar.h"
#include "MyDate.h"

#define MAXDATE 30

// creates new dynamic array
Calendar::Calendar()
{
    for(int i=0; i<MAXDATE; i++)
    {
        dates[i] = new MyDate();
    }
}

//sets the date, returns 0 if valid and returns -1 if not
int Calendar::setDate(const MyDate& newDate, int num)
{
    MyDate temp = newDate;
    if(num > 30 || num < 1)
    {
        return -1;
    }
    else
    {
        if(dates[num-1]->getDay() != 0)
        {
            return -1;
        }
        else
        {
            dates[num-1]->set(temp.getDay(), temp.getMonth(), temp.getYear());
            return 0;
        }
    }
}

//checks if there free space, returns 0 if valid and -1 if not
bool Calendar::isFree(int num)
{
    if(num < 0 || num > 30 || this->dates[num-1]->getDay() != 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// checks which index is free first, returns the number of the index and -1 if there no free index
int Calendar::firstFree()
{
    for(int i=0; i<MAXDATE; i++)
    {
        if(dates[i]->getDay() == 0)
        {
            return i+1;
        }
    }

    return -1;
}

// Insert date to the first free index, returns the first number of the index and -1 if not
int Calendar::insert(const MyDate& newDate)
{
    MyDate temp = newDate;
    int firstPlace = this->firstFree();

    if(firstPlace != -1)
    {
        dates[firstPlace-1]->set(temp.getDay(), temp.getMonth(), temp.getYear());

        return firstPlace;
    }
    else
    {
        return -1;
    }   
}

// returns the number of the index of the oldest date, and -1 if empty
int Calendar::oldest()
{
    MyDate temp(30, 12, 2100);
    int indexMin = -1;

    for(int i = 0; i < MAXDATE; i++)
    {
        if(dates[i]->isBefore(temp) && dates[i]->getDay() != 0)
        {
            temp.set(dates[i]->getDay(), dates[i]->getMonth(), dates[i]->getYear());
            indexMin = i + 1;
        }
    }

    return indexMin;
}


// returns the number of the dates there is in the array with the users date
int Calendar::datesNum(const MyDate& newDate)
{
    MyDate temp = newDate;
    int sum = 0;

    for(int i=0; i<MAXDATE; i++)
    {
        if(dates[i]->getDay() == temp.getDay() &&
            dates[i]->getMonth() == temp.getMonth() &&
            dates[i]->getYear() == temp.getYear())
        {
            sum++;
        }
    }

    return sum;
}

// deletes all the dates
void Calendar::deleteAll()
{
    for(int i=0; i < MAXDATE; i++)
    {
        this->dates[i]->myDelete();
    }
}

// deletes a date int the num's index, returns 0 if succeeded and -1 if not
int Calendar::deleteDate(int num)
{
    if(num > 30 || num < 1)
    {
        return -1;
    }

    dates[num-1]->myDelete();

    return 0;
}

// returns dynamic string with all the dates
char* Calendar::print()
{
    char* token;
    char* bigStr = new char[460];
    char* backStr = new char[15];
    int i, j = 0;

    for(i = 0; i < MAXDATE; i++)
    {
        j++;
        backStr = dates[i]->print();
        token = strtok(backStr, "\n");
        strcat(backStr, " ");
        strcat(bigStr, backStr);
    }

    if(i == MAXDATE && j == 0)
    {
        strcat(bigStr, "Empty Calendar\n");
    }

    delete[] backStr;

    return bigStr;
}

// sorts the array from the oldest date to the newest
void Calendar::sortDates()
{
    MyDate temp, comp;
    int i, j;

    for(i = 0; i < MAXDATE; i++)
    {
        if(dates[i]->getDay() != 0)
        {
            for(j = i; j < MAXDATE; j++)
            {
                comp.set(dates[j]->getDay(), dates[j]->getMonth(), dates[j]->getYear());
                if(!dates[i]->isBefore(comp) && dates[j]->getDay() != 0)
                {
                    temp.set(dates[i]->getDay(), dates[i]->getMonth(), dates[i]->getYear());
                    dates[i]->set(dates[j]->getDay(), dates[j]->getMonth(), dates[j]->getYear());
                    dates[j]->set(temp.getDay(), temp.getMonth(), temp.getYear());
                }
            }
        }
    }
}

// frees all the dynamics dates
Calendar::~Calendar()
{
    for(int i=0; i<MAXDATE; i++)
    {
        delete dates[i];
    }
}