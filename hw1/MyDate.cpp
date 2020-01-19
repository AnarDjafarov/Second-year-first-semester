#include <iostream>
#include <string.h>
#include "MyDate.h"

MyDate::MyDate()
{
    this->Day = 0;
    this->Month = 0;
    this->Year = 0;
}

MyDate::MyDate(int day, int month, int year)
{
    if((year >= 1900 && year <= 2100) && (month >= 1 && month <= 12) && (day >= 1 && day <= 30))
    {
        if((month != 2) || (month == 2 && day <= 28))
        {
            this->Day = day;
            this->Month = month;
            this->Year = year;
        }
    }
    else
    {
        this->Day = 0;
        this->Month = 0;
        this->Year = 0;
    }
}

// resets the date to 20.11.2019
void MyDate::init()
{
    this->Day = 20;
    this->Month = 11;
    this->Year = 2019;
}

// sets the date, returns 0 if succeed and if not -1
int MyDate::set(int day, int month, int year)
{
    if((year >= 1900 && year <= 2100) && (month >= 1 && month <= 12) && (day >= 1 && day <= 30))
    {
        if((month != 2) || (month == 2 && day <= 28))
        {
            this->Day = day;
            this->Month = month;
            this->Year = year;

            return 0;
        }
    }

    return -1;
}

// sets day, returns 0 if succeed and -1 if not
int MyDate::setDay(int day)
{
    if(this->set(day, this->Month, this->Year) == 0)
    {
        return 0;
    }

    return -1;
}

// sets month, returns 0 if succeed and -1 if not
int MyDate::setMonth(int month)
{
    if(this->set(this->Day, month, this->Year) == 0)
    {
        return 0;
    }

    return -1;
}

// sets year, returns 0 if succeed and -1 if not
int MyDate::setYear(int year)
{
    if(this->set(this->Day, this->Month, year) == 0)
    {
        return 0;
    }

    return -1;
}

// checks if the given date is before the class' date, returns true or false
bool MyDate::isBefore(const MyDate& newDate)
{
    if(this->Year < newDate.Year)
    {
        return true;
    }
    else if(this->Year > newDate.Year)
    {
        return false;
    }
    else
    {
        if(this->Month < newDate.Month)
        {
            return true;
        }
        else if(this->Month > newDate.Month)
        {
            return false;
        }
        else
        {
            if(this->Day < newDate.Day)
            {
                return true;
            }
            else
            {
                return false;
            }
            
        }
        
    }
    
}

// delays the date with the number we got, returns 0 if succeed and -1 if not
int MyDate::delay(int num)
{
    if(num < 365)
    {
        while(num >= 30)
        {
            if(this->Month == 2)
            {
                num -= 28;
                set(this->Day, this->Month + 1, this->Year);
            }
            else if(this->Month == 12)
            {
                num -= 30;
                set(this->Day, 1, this->Year + 1);
            }
            else
            {
                num -= 30;
                set(this->Day, this->Month + 1, this->Year);
            }
        }
        if(num > 0 && num < 30)
        {
            int temp = this->Day + num;
            if(temp > 30 && this->Month != 2 && this->Month != 12)
            {
                temp -= 30;
                set(temp, this->Month + 1, this->Year);
            }
            else if(temp > 30 && this->Month == 12)
            {
                temp -= 30;
                set(temp, 1, this->Year + 1);
            }
            else if(temp > 28 && this->Month == 2)
            {
                temp -= 28;
                set(temp, this->Month + 1, this->Year);
            }
            else
            {
                set(temp, this->Month, this->Year);
            }
        }

        return 0;
    }

    return -1;
}

// brings forward the date with the number we got, returns 0 if succeed and -1 if not
int MyDate::bringForward(int num)
{
    if(num < 365)
    {
        while(num >= 30)
        {
            if(this->Month == 3)
            {
                num -= 28;
                set(this->Day, this->Month - 1, this->Year);
            }
            else if(this->Month == 1)
            {
                num -= 30;
                set(this->Day, 12, this->Year - 1);
            }
            else
            {
                num -= 30;
                set(this->Day, this->Month - 1, this->Year);
            }
        }
        if(num > 0 && num < 30)
        {
            int temp = this->Day - num;
            if(temp < 0 && this->Month != 3 && this->Month != 1)
            {
                temp += 30;
                set(temp, this->Month - 1, this->Year);
            }
            else if(temp < 0 && this->Month == 1)
            {
                temp += 30;
                set(temp, 12, this->Year - 1);
            }
            else if(temp < 0 && this->Month == 3)
            {
                temp += 28;
                set(temp, this->Month - 1, this->Year);
            }
            else
            {
                set(temp, this->Month, this->Year);
            }
        }
        
        return 0;
    }

    return -1;
}

// prints the date, returns dynamic string
char* MyDate::print()
{
    char* str = new char[15];

    sprintf(str, "%d/%d/%d\n", this->Day, this->Month, this->Year);

    return str;
}

// returns the day
int MyDate::getDay()
{
    return this->Day;
}

// returns the month
int MyDate::getMonth()
{
    return this->Month;
}

// returns the year
int MyDate::getYear()
{
    return this->Year;
}

// deletes the date by setting the values to zero
void MyDate::myDelete()
{
    this->Day = 0;
    this->Month = 0;
    this->Year = 0;
}