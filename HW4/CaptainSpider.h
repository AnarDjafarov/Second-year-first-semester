
#ifndef CAPTAINSPIDER__H_
#define CAPTAINSPIDER__H_


#include "Spiderman.h"
#include "CaptainAmerica.h"
#include "AnimalBasedSuperHero.h"
#include "ProfessionBasedSuperHero.h"
#include "SuperHero.h"

class CaptainSpider : public Spiderman, public CaptainAmerica
{
public:
	CaptainSpider();																											// V		
	CaptainSpider(const char* name, double age, bool radioactive, const char* profession, int yearsExperience,					// V
		double ageIncludingFreezing, const char* animal, double webSize);														// V
	CaptainSpider(const char* profession, int yearsExperience, double ageIncludingFreezing, const char* animal, double webSize);// V
	CaptainSpider(double ageIncludingFreezing, double webSize);																	// V
	CaptainSpider(const CaptainSpider& captainSpider);																			// V
	~CaptainSpider();																											// V

	virtual void load(ifstream& in_file);																					    // V
	virtual void save(ofstream& out_file) const;																				// V
};

#endif