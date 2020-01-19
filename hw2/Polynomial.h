#pragma once

#include <iostream>
#include "Monomial.h"
#include <string.h>

class Polynomial
{
private:
	int _size;
	Monomial* _monoarr = new Monomial[1];

public:
	// Constructor's
	Polynomial();
	Polynomial(int newSize);
	Polynomial(const Polynomial& p);
	~Polynomial();

public:
	//Operators
	Polynomial& operator = (const Polynomial& p);           
	Polynomial& operator >> (const char* str);              
	Polynomial& operator += (const Polynomial& p);			
	Polynomial& operator += (const Monomial& m);			
	Polynomial& operator -= (const Polynomial& p);			
	Polynomial& operator -= (const Monomial& m);			
	Polynomial& operator *= (const Polynomial& p);			
	Polynomial& operator *= (const Monomial& m);
	int operator [] (const int exp) const;					
	Polynomial& negate();									
		
public:
	// Another functions 
	friend std::ostream& operator << (std::ostream& out, const Polynomial& p);
	int maxExp() const;
	void sort();
	char* getStringRepresentation() const;

public:
	// Global Operators 
	friend Polynomial operator+(const Polynomial& p1, const Polynomial& p2);   
	friend Polynomial operator+(const Polynomial& p,const Monomial& m);		   
	friend Polynomial operator+(const Monomial& m, const Polynomial& p);	   

	friend Polynomial operator-(const Polynomial& p1, const Polynomial& p2);   
	friend Polynomial operator-(const Polynomial& p, const Monomial& m);	   
	friend Polynomial operator-(const Monomial& m, const Polynomial& p);	   

	friend Polynomial operator*(const Polynomial& p1, const Polynomial& p2);   
	friend Polynomial operator*(const Polynomial& p, const Monomial& m);	   
	friend Polynomial operator*(const Monomial& m, const Polynomial& p);	   
};

// Global Operators 
std::ostream& operator << (std::ostream& out, const Polynomial& p);
