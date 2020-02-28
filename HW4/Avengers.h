
#ifndef AVENGERS__H_
#define AVENGERS__H_

#include "CaptainSpider.h"
#include "SuperHero.h"
#include "Spiderman.h"
#include "AnimalBasedSuperHero.h"
#include "ProfessionBasedSuperHero.h"
#include "CaptainAmerica.h"

class Avengers
{
public:
	Avengers();													// V
	~Avengers();												// V

	void saveType(ofstream& out, const SuperHero* hero) const;  //
	void save(ofstream& out) const;								// V
	void load(ifstream& in);									// V

	void setSuperHeros(SuperHero** superHeros, int size);		// V
	SuperHero** getSuperHeros() const;							// V

private:
	SuperHero** _superHeros;
	int _numSuperHeros;
};

#endif