#include <iostream>
#include <string.h>
#include "MyDate.h"
#include "Calendar.h"

using namespace std;

int main() {
/*

    Calendar check
*/
/*
    Calendar c1;
    MyDate date(14, 12, 1995);
    MyDate oldest(27, 1, 1901);
    MyDate d1(17, 11, 2019);
    char* str;

    c1.setDate(date, 1);
    c1.setDate(date, 5);
    c1.insert(oldest);
    c1.insert(d1);
    c1.insert(d1);
    c1.insert(date);
    c1.insert(oldest);
    c1.insert(date);
    c1.insert(oldest);
    c1.insert(date);
    c1.insert(d1);
*/
	MyDate date5(16, 3, 1994);
	MyDate date2(16, 3, 2008);
	MyDate date3(16, 3, 2008);
	MyDate date4(16, 3, 2008);
	MyDate date1(16, 2, 2008);
	MyDate date6(15, 3, 2008);


	//MyDate datenull;
	//date1.delay(15);
	Calendar Cal1;
    char* str;

	Cal1.setDate(date1, 1);
	Cal1.setDate(date2, 2);
	Cal1.setDate(date3, 3);
	Cal1.setDate(date4, 4);
	Cal1.setDate(date5, 5);
	Cal1.setDate(date6, 6);

    cout << "--------------------------" << endl;
    //c1.sortDates();
    //c1.myPrint();
    str = Cal1.print();
    cout << str << endl;

    cout << "--------------------------" << endl;
    Cal1.sortDates();
    str = Cal1.print();
    cout << str << endl;
    
    delete[] str;

//-------------------------------
    /*

    MyDate check

    MyDate d;
    MyDate today(18, 11, 2019);
    char* str;

    //d.init();
    d.set(11, 11, 2011);

    d.myPrint();

    */

    return 0;
}