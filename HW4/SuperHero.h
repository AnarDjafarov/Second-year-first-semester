#ifndef SUPERHERO__H_
#define SUPERHERO__H_
#include <iostream>
#include <fstream>
#include <string.h>
#include <typeinfo>

using namespace std;

class SuperHero
{
public:
	SuperHero();														// V
	SuperHero(const char* name, double age, bool radioactive = false);	// V
	SuperHero(const SuperHero& superHero);								// V
	virtual ~SuperHero();												// V

	const char* getName() const;										// V
	double getAge() const;												// V
	bool getRadioactive() const;										// V
	void setName(const char* name);										// V
	void setAge(double age);											// V
	void setRadioactive(bool radioactive);								// V

	virtual void load(ifstream& in_file);								// V
	virtual void save(ofstream& out_file) const;						// V


protected:
	char* _name;
	double _age;
	bool _radioactive;

};

#endif