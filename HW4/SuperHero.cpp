#include "SuperHero.h"
#include <string.h>

SuperHero::SuperHero()
{
	_name = new char[256];
	_name = nullptr;
	_age = 0.0;
	_radioactive = false;
}
SuperHero::~SuperHero() { delete[] _name; }
SuperHero::SuperHero(const SuperHero& superHero)
{
	_name = _strdup(superHero.getName());
	_age = superHero.getAge();
	_radioactive = superHero.getRadioactive();
}
SuperHero::SuperHero(const char* name, double age, bool radioactive)
{
	_name = _strdup(name);
	_radioactive = radioactive;
	_age = age;
}
const char* SuperHero::getName() const { return _name;}
double SuperHero::getAge() const { return _age;}
bool SuperHero::getRadioactive() const { return _radioactive;}

void SuperHero::setName(const char* name)
{
	if ((name == nullptr) || (strcmp(name, _name) == 0) || (_name == nullptr))
		return;
	else
		_name = _strdup(name);
}

void SuperHero::setAge(double age)
{
	if ((age < 15 || age > 40))
		return;
	else
		_age = age;
}
void SuperHero::setRadioactive(bool radioactive) { this->_radioactive = radioactive; }
void SuperHero::load(ifstream& in_file)
{
	char* temp = new char[3];
	in_file.read((char*)temp ,3);
	int size1;
	in_file.read((char*)&size1, sizeof(size1));
	in_file.read((char*)this->_name, size1);
	in_file.read((char*)&this->_age, sizeof(_age));
	in_file.read((char*)&this->_radioactive, sizeof(_radioactive));
	delete[] temp;
}
void SuperHero::save(ofstream& out_file) const
{
	int size1 = strlen(_name);									 
	out_file.write((char *)&size1, sizeof(size1));				// 1 value - size name
	out_file.write((char*)this->_name, size1);					// 2 value - name
	out_file.write((char *)&_age, sizeof(_age));				// 3 value - age
	out_file.write((char *)&_radioactive, sizeof(_radioactive));// 4 value - radioactive

	//out_file << _name;
	//out_file << _age;
	//out_file << _radioactive;
}