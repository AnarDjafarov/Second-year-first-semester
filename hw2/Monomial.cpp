#include "Monomial.h"
#include <iostream>
#include <string.h>

//----------------------------------------------------------------------------
// Constractor's
Monomial::Monomial()
{ // Defualt
	this->_aCoeff = 0;
	this->_nExp = 0;
}

Monomial::Monomial(int coeff, int exp) :_aCoeff(coeff), _nExp(exp) {}

Monomial::Monomial(const Monomial& m)
{// Copy Constractor
	this->_aCoeff = m._aCoeff;
	this->_nExp = m._nExp;
}

//----------------------------------------------------------------------------
// Functions

//returns the coefficient
int Monomial::getCoeff() const
{
	return this->_aCoeff;
}

//returns the exponent
int Monomial::getExp() const
{
	return this->_nExp;
}

//Returns a string representing the monomial
char* Monomial::stringRepresentation() const
{
	char* str = new char[MAX_SIZE_OF_MONO];

	if (this->_aCoeff == 0)                                  //0*x
		sprintf(str, "%d", 0);
	else if (this->_nExp == 0)                               //ax^0
		sprintf(str, "%d", this->_aCoeff);
	else if (this->_aCoeff == 1 && this->_nExp == 1)         //1x^1
		sprintf(str, "x");
	else if (this->_aCoeff == 1)                             //1x^n
		sprintf(str, "x^%d", this->_nExp);
	else if (this->_aCoeff == -1)                            //-1x^n
	{
		if (this->_nExp == 1)
			sprintf(str, "-x");
		else
			sprintf(str, "-x^%d", this->_nExp);
	}
	else if (this->_nExp == 1)                               //ax^1
		sprintf(str, "%dx", this->_aCoeff);
	else
		sprintf(str, "%dx^%d", this->_aCoeff, this->_nExp);

	return str;
}

//gets char* and returns monomial
Monomial& Monomial::polyToMono(const char *str)
{
	Monomial newM;
	char* temp = new char[strlen(str) + 1];
	strcpy(temp, str);
	int i = 0, a = 0, n = 0;
	char firstC = 0;

	if (temp[i] == '-' || temp[i] == '+')
	{
		firstC = temp[i++];
	}
	if (temp[i] == 'x' || temp[i] == 'X')
	{
		a = 1;
	}

	while (temp[i] >= 48 && temp[i] <= 57)
	{
		a *= 10;
		a += temp[i++] - 48;
	}

	if (temp[i] == '\0')
	{
		newM._nExp = 0;
	}
	else if (temp[i] == 'x' || temp[i] == 'X')
	{
		if (temp[++i] == '^')
		{
			i++;
			while (temp[i] >= 48 && temp[i] <= 57)
			{
				n *= 10;
				n += temp[i] - 48;
				i++;
			}
		}
		else
			n = 1;

		newM._nExp = n;
	}

	if (firstC == '-')
		newM._aCoeff = a * -1;
	else
		newM._aCoeff = a;

	this->_aCoeff = newM._aCoeff;
	this->_nExp = newM._nExp;

	delete[] temp;

	return *this;
}

//sets the coefficient
void Monomial::setCoeff(int a)
{
	this->_aCoeff = a;
}

//returns the exponent
void Monomial::setExp(int n)
{
	this->_nExp = n;
}

//returns the negative monomial
Monomial& Monomial::negate()	// -M
{
	this->_aCoeff *= -1;

	return *this;
}

//----------------------------------------------------------------------------
// Operators
 
const Monomial& Monomial::operator+=(const Monomial &m)		//	M += M
{
	if (this->_nExp == m._nExp)
		this->_aCoeff += m._aCoeff;

	return *this;
}

const Monomial Monomial::operator*(const Monomial &m)		//	M = M * M
{
	Monomial mNew(this->_aCoeff*m._aCoeff, this->_nExp + m._nExp);

	return mNew;
}

const Monomial& Monomial::operator*=(const Monomial &m)		//	M *= M
{
	*this = *this * m;

	return *this;
}

bool Monomial::operator==(const Monomial &m) const			//	M == M
{
	if (this->_aCoeff == m._aCoeff && this->_nExp == m._nExp)
		return true;

	return false;
}

const Monomial& Monomial::operator-(const Monomial &m)   //	M = M - M
{
	Monomial *myMono = new Monomial;

	if (this->_nExp == m._nExp)
	{
		myMono->_nExp = this->_nExp;
		myMono->_aCoeff = this->_aCoeff - m._aCoeff;
	}

	return *myMono;
}

//Allows printing the monomial
std::ostream& operator << (std::ostream& out, const Monomial& m)
{
	out << m.stringRepresentation();

	return out;
}

