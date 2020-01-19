#pragma once
#include <string>

using namespace std;

class Hazard
{
protected:
	string _myhazard;
public:
//	void setHazard(string str);

	//virtual string getMessage() const= 0;
	string getMessage() const;
	//virtual string getName() { return this->_myhazard; }
	//virtual void mysetHazard(string str) = 0;
	void mysetHazard(string str);
};