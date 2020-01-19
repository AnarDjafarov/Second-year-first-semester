#include "Hazard.h"

using namespace std;

string Hazard::getMessage() const
{
	return this->_myhazard;
}

void Hazard::mysetHazard(string str)
{
	this->_myhazard = str;
}