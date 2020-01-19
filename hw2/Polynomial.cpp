#include <iostream>
#include "Polynomial.h"
#include "Monomial.h"
#include <string.h>

//-------------------------------------------------------------------
// Constructors
Polynomial::Polynomial()
{// Default Constractor
	this->_size = 0;
	this->_monoarr = nullptr;
}

Polynomial::Polynomial(int newSize)
{//  Constractor
	this->_size = newSize;
	this->_monoarr = new Monomial[this->_size];
}

Polynomial::~Polynomial()
{// Distractor
	delete[] this->_monoarr;
}

Polynomial::Polynomial(const Polynomial& p)
{// Copy Constractor
	this->_size = p._size;
	this->_monoarr = new Monomial[this->_size];
	for (int i = 0; i < this->_size; i++)
		this->_monoarr[i] = p._monoarr[i];
}

//-------------------------------------------------------------------
// Operators

//Allows placement of a Polynomial type object
Polynomial& Polynomial::operator=(const Polynomial& p)
{ 
	Polynomial newP(p);
	if (&p != this)
	{
		delete[] this->_monoarr;
		this->_size = newP._size;
		this->_monoarr = new Monomial[this->_size];
		for (int i = 0; i < this->_size; i++)
			this->_monoarr[i] = newP._monoarr[i];
	}
	return *this;
}

//Enables the creation of a polynomial through textual representation
Polynomial& Polynomial::operator>>(const char* str) {
	char *word = NULL;
	char *word2 = NULL;
	int index = 0, i = 0;
	char *temp = strdup(str);
	char *temp2 = strdup(str);
	//char *temp = _strdup(str);
	//char *temp2 = _strdup(str);
	Monomial NewMono;
	this->_size = index;

	word = strtok(temp, "+-\0");

	while (word != nullptr)
	{
		index++;
		word = strtok(NULL, "+-\0");
	}

	Polynomial newPoly(index);
	int index2 = 0;
	int j = 0;
	word2 = new char[MAX_SIZE_OF_MONO];
	while (index2 != index)
	{
		if (*temp2 == '-' || *temp2 == '+' || *temp2 == '\0')
		{
			if (i != 0)
			{
				NewMono.polyToMono(word2);
				newPoly._monoarr[index2].setCoeff(NewMono.getCoeff());
				newPoly._monoarr[index2].setExp(NewMono.getExp());
				index2++;

				delete word2;
				word2 = new char[MAX_SIZE_OF_MONO];
				j = 0;
			}
			if (*temp2 == '\0')
				break;
		}
		word2[j] = *temp2;
		j++;
		i++;
		temp2++;

	}
	*this = newPoly;
	return *this;
}


Polynomial& Polynomial::operator+=(const Monomial &m)	// P += M
{
	int index = -1;
	for (int i = 0; i < _size; i++)
	{
		if (m.getExp() == _monoarr[i].getExp())
		{
			index = i;
			_monoarr[i] += m;
		}
	}
	if (index == -1)
	{
		Polynomial temp(_size + 1);
		for (int i = 0; i < _size; i++)
			temp._monoarr[i] = _monoarr[i];
		temp._monoarr[_size] = m;
		*this = temp;
	}

	Monomial mono;
	int count_zero = 0;
	for (int i = 0; i < _size; i++)
	{
		if (mono == _monoarr[i])
			count_zero++;
	}

	Polynomial temp(_size - count_zero);
	int j = 0;
	for (int i = 0; i < _size; i++)
	{
		if (mono == _monoarr[i])
		{
			continue;
		}
		else
		{
			temp._monoarr[j] = this->_monoarr[i];
			j++;
		}
	}

	return *this;
}

Polynomial& Polynomial::operator+=(const Polynomial& p) // P += P
{
	for (int i = 0; i < p._size; i++)
		*this += (p._monoarr[i]);

	sort();
	return *this;
}




Polynomial& Polynomial::operator -= (const Monomial& m) // P -= M
{
	Monomial newM(m);
	int i;

	for (i = 0; i < this->_size; i++)
	{
		if (this->_monoarr[i].getExp() == newM.getExp())
		{
			newM.negate();
			this->_monoarr[i].setCoeff(this->_monoarr[i].getCoeff() + newM.getCoeff());
			return *this;
		}
	}

	Polynomial newP(this->_size + 1);
	for (i = 0; i < this->_size; i++)
	{
		newP._monoarr[i] = this->_monoarr[i];
	}

	newP._monoarr[i] = newM;
	*this = newP;

	return *this;
}

Polynomial& Polynomial::operator -= (const Polynomial& p) // P -= P
{
	int sizefor = p._size;
	Polynomial newP(p);
	newP.negate();

	for (int i = 0; i < sizefor; i++)
	{
		*this += newP._monoarr[i];
	}

	this->sort();

	return *this;
}



Polynomial& Polynomial::operator *= (const Monomial& m) // P *= M
{
	for (int i = 0; i < _size; i++)
	{
			_monoarr[i] *= m;
	}
		return *this;
}


Polynomial& Polynomial::operator *= (const Polynomial& p) // P *= P
{
	Polynomial newP1(_size);
	newP1 = *this;
	Polynomial newP2(p._size);
	Polynomial newP3(p._size);

	for (int i = 0; i < newP1._size; i++)
	{
		newP2 = p;
		newP2 *= newP1._monoarr[i];
		newP3 += newP2;
	}
	*this = newP3;
	return *this;
}

//returns the exp rank, returns the coefficient of the exponent
int Polynomial::operator [] (const int exp) const 
{
	for (int i = 0; i < this->_size; i++)
	{
		if (this->_monoarr[i].getExp() == exp)
			return this->_monoarr[i].getCoeff();
	}

	return 0;
}

//------------------------------------------------------------------------------------
// Global operator 

//Allows printing of the polynomial
std::ostream& operator<<(std::ostream& out, const Polynomial& p)
{
	out << p.getStringRepresentation();
	return out;
}



//------------------------------------------------------------------------------------
//Functios

//Returns a string representing the polynomial
char* Polynomial::getStringRepresentation() const
{
	int size = MAX_SIZE_OF_MONO * this->_size;
	char* str = new char[size];
	//check this for throw
	if (this->_monoarr == NULL)
		return 0;
	else
	{
		for (int i = 0; i < this->_size; i++)
		{
			if (i == 0)
			{
				strcpy(str, this->_monoarr[i].stringRepresentation());
			}
			else
			{
				Monomial mono;
				if (mono == _monoarr[i])
					continue;
				if (this->_monoarr[i].getCoeff() > 0)
					strcat(str, "+");
				strcat(str, this->_monoarr[i].stringRepresentation());
			}
		}
	}
	return str;
}

//sorts the polynomial
void Polynomial::sort()
{
	Monomial temp;

	for (int i = 0; i < this->_size; i++)
	{
		for (int j = 0; j < this->_size; j++)
		{
			if (this->_monoarr[i].getExp() > this->_monoarr[j].getExp())
			{
				temp = this->_monoarr[j];
				this->_monoarr[j] = this->_monoarr[i];
				this->_monoarr[i] = temp;
			}

		}
	}
}

//returns the negative polynomial
Polynomial& Polynomial::negate()
{
	for (int i = 0; i < this->_size; i++)
	{
		this->_monoarr[i].negate();
	}

	return *this;
}

//returns the max exponent
int Polynomial::maxExp() const
{
	int num = 0;
	for (int i = 0; i < this->_size; i++)
	{
		if (this->_monoarr[i].getExp() > num)
			num = this->_monoarr[i].getExp();
	}

	return num;
}


//----------------------------------------------------------------------------
Polynomial operator+(const Polynomial& p1, const Polynomial& p2)	 // P = P + P
{
	Polynomial temp; 
	temp += p1;
	temp += p2;
    return temp; 
}

Polynomial operator+(const Polynomial& p, const Monomial& m)	    // P = P + M
{
	Polynomial temp;
	temp += p;
	temp += m;
	return temp;
}

Polynomial operator+(const Monomial& m, const Polynomial& p)		// P = M + P
{
	Polynomial temp;
	temp = p + m;
	return temp;
}

Polynomial operator-(const Polynomial& p1, const Polynomial& p2)	// P = P - P
{
	Polynomial temp;
	temp = p1;
	temp -= p2;
	return temp;
}

Polynomial operator-(const Polynomial& p, const Monomial& m)		// P = P - M
{
	Polynomial temp;
	temp = p;
	temp -= m;
	return temp;
}

Polynomial operator-(const Monomial& m, const Polynomial& p)		// P = M - P
{
	Polynomial temp;
	temp = p - m;
	temp.negate();
	return temp;
}
Polynomial operator*(const Polynomial& p1, const Polynomial& p2)    // P = P * P
{
	Polynomial temp;
	temp = p1;
	temp *= p2;
	return temp;
}

Polynomial operator*(const Polynomial& p, const Monomial& m)		// P = P * M
{
	Polynomial temp;
	temp = p;
	temp *= m;
	return temp;
}

Polynomial operator*(const Monomial& m, const Polynomial& p)		// P = M * P
{
	Polynomial temp;
	temp = p * m;
	return temp;
}