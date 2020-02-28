#ifndef PROFESSION_BASED_SUPERHERO__H_
#define PROFESSION_BASED_SUPERHERO__H_
#include "SuperHero.h"
class ProfessionBasedSuperHero : virtual public SuperHero
{
public:
	ProfessionBasedSuperHero();
	ProfessionBasedSuperHero(const char* name, double age, bool radioactive, const char* profession, int yearsExperience);	// v
	ProfessionBasedSuperHero(const char* profession, int yearsExperience);													// v
	ProfessionBasedSuperHero(const ProfessionBasedSuperHero& professionBasedSuperHero);										// v
	virtual ~ProfessionBasedSuperHero();																					//
		
	void setProfession(const char* profession);																				// v
	const char* getProfession() const { return _profession; }																// v
	void setYearsExperience(int yearsExperience);																			// v
	int getYearsExperience() const;																							// v

	virtual void load(ifstream& in_file);																					// v
	virtual void save(ofstream& out_file) const;																			// v

protected:
	int _yearsExperience;
	char* _profession;
};

#endif