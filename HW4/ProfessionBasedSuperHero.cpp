#include "ProfessionBasedSuperHero.h"
#include "ProfessionBasedSuperHero.h"



ProfessionBasedSuperHero::ProfessionBasedSuperHero() : SuperHero()
{
	_yearsExperience = 0;
	//_profession = _strdup("No Profession");
	_profession = new char[256];
	_profession = nullptr;
}


ProfessionBasedSuperHero::~ProfessionBasedSuperHero() { delete[] _profession;}

ProfessionBasedSuperHero::ProfessionBasedSuperHero(const char* name, double age, bool radioactive, const char* profession, int yearsExperience) : SuperHero(name, age, radioactive)
{
	_yearsExperience = yearsExperience;
	_profession = _strdup(profession);
}
ProfessionBasedSuperHero::ProfessionBasedSuperHero(const char* profession, int yearsExperience)
{
	_profession = _strdup(profession);
	_yearsExperience = yearsExperience;
}
ProfessionBasedSuperHero::ProfessionBasedSuperHero(const ProfessionBasedSuperHero& professionBasedSuperHero) 
	: SuperHero(professionBasedSuperHero.getName()
	, professionBasedSuperHero.getAge(), professionBasedSuperHero.getRadioactive())
{
	_profession = _strdup(professionBasedSuperHero.getProfession());
	_yearsExperience = professionBasedSuperHero.getYearsExperience();
}
void ProfessionBasedSuperHero::setProfession(const char* profession) { _profession = _strdup(profession); }
int ProfessionBasedSuperHero::getYearsExperience() const { return _yearsExperience; }
void ProfessionBasedSuperHero::setYearsExperience(int yearsExperience)
{
	if (yearsExperience < 0) return;
	else _yearsExperience = yearsExperience;
}

void ProfessionBasedSuperHero::load(ifstream& in_file)
{
	SuperHero::load(in_file);
	int size1;
	in_file.read((char*)&size1, sizeof(size1));
	in_file.read((char*)this->_profession, size1);
	in_file.read((char*)&this->_yearsExperience, sizeof(_yearsExperience));
}
void ProfessionBasedSuperHero::save(ofstream& out_file) const
{
	SuperHero::save(out_file);
	int size1 = strlen(_profession);
	out_file.write((char *)&size1, sizeof(size1));				
	out_file.write((char*)this->_profession, strlen(_profession));
	out_file.write((char*)&this->_yearsExperience, sizeof(_yearsExperience));
}

