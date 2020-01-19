#pragma once
#include <iostream>
#define MAX_SIZE_OF_MONO 26

class Monomial
{
private:
	int _aCoeff;	
	int _nExp;

public:
	// Constractor
	Monomial(int coeff, int exp = 0);
	Monomial(const Monomial& m);
	Monomial();

	// Functions
	int getCoeff() const;
	int getExp() const;
	void setCoeff(int a);
	void setExp(int n);
	Monomial& negate();
	char* stringRepresentation() const;
	Monomial& polyToMono(const char* str);


	// Operators
	const Monomial& operator+=(const Monomial& m);
	const Monomial operator*(const Monomial& m);
	const Monomial& operator*=(const Monomial& m);
	const Monomial& operator-(const Monomial& m);
	bool operator==(const Monomial& m) const;

	// Global Operator
	friend std::ostream& operator << (std::ostream& out, const Monomial& m);


};
// Global Operator
std::ostream& operator << (std::ostream& out, const Monomial& m);