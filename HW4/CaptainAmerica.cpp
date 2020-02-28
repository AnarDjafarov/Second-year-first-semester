#include "CaptainAmerica.h"


CaptainAmerica::CaptainAmerica() : ProfessionBasedSuperHero() { _ageIncludingFreezing = 0.0;}

CaptainAmerica::CaptainAmerica(const char* name, double age, bool radioactive, const char* profession, int yearsExperience, double ageIncludingFreezing)
	: SuperHero(name, age, radioactive), ProfessionBasedSuperHero(profession, yearsExperience)
{ _ageIncludingFreezing = 0.0; }

CaptainAmerica::CaptainAmerica(const char* profession, int yearsExperience, double ageIncludingFreezing) : ProfessionBasedSuperHero(profession, yearsExperience)
{ _ageIncludingFreezing = 0.0; }

CaptainAmerica::CaptainAmerica(double ageIncludingFreezing) { _ageIncludingFreezing = 0.0; }

CaptainAmerica::CaptainAmerica(const CaptainAmerica& captainAmerica) : ProfessionBasedSuperHero(captainAmerica.getName()
	, captainAmerica.getAge(), captainAmerica.getRadioactive(), captainAmerica.getProfession(), captainAmerica.getAgeIncludingFreezing())
{
	_ageIncludingFreezing = captainAmerica.getAgeIncludingFreezing();
}

CaptainAmerica:: ~CaptainAmerica() {}

double CaptainAmerica::getAgeIncludingFreezing() const { return _ageIncludingFreezing; }

void CaptainAmerica::setAgeIncludingFreezing(double ageIncludingFreezing) 
{ 
	if (_age >= _ageIncludingFreezing)
		return;
	else
		_ageIncludingFreezing = ageIncludingFreezing;
}


void CaptainAmerica::load(ifstream& in_file)
{
	ProfessionBasedSuperHero::load(in_file);
	in_file.read((char*)&this->_ageIncludingFreezing, sizeof(_ageIncludingFreezing));
}
void CaptainAmerica::save(ofstream& out_file) const
{
	ProfessionBasedSuperHero::save(out_file);
	out_file.write((char*)&this->_ageIncludingFreezing, sizeof(_ageIncludingFreezing));
}