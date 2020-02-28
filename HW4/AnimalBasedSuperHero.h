#ifndef  ANIMAL_BASED_SUPERHERO__H_
#define ANIMAL_BASED_SUPERHERO__H_



#include "SuperHero.h"
class AnimalBasedSuperHero : virtual public SuperHero
{
public:	
	AnimalBasedSuperHero();																		// v
	AnimalBasedSuperHero(const char* name, double age,bool radioactive, const char* animal);    // v
	AnimalBasedSuperHero(const char* animal);													// v
	AnimalBasedSuperHero(const AnimalBasedSuperHero& animalBasedSuperHero);						// v
	virtual ~AnimalBasedSuperHero();															//

	void setAnimal(const char* animal);															// v
	const char* getAnimal() const;																// v

	virtual void load(ifstream& in_file);														// v
	virtual void save(ofstream& out_file) const;												// v

protected:
	char* _animal;
};

#endif // ! ANIMAL_BASED_SUPERHERO__H_