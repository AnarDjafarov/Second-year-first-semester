#include "AnimalBasedSuperHero.h"

AnimalBasedSuperHero::AnimalBasedSuperHero() : SuperHero(){_animal = nullptr;}

AnimalBasedSuperHero::AnimalBasedSuperHero(const char* name, double age, bool radioactive, const char* animal)
	: SuperHero(name, age, radioactive) {_animal = _strdup(animal);}

AnimalBasedSuperHero::AnimalBasedSuperHero(const char* animal) { _animal = _strdup(animal); }
AnimalBasedSuperHero::AnimalBasedSuperHero(const AnimalBasedSuperHero& animalBasedSuperHero) : SuperHero(animalBasedSuperHero.getName()
, animalBasedSuperHero.getAge(), animalBasedSuperHero.getRadioactive())
{ 
	_animal = _strdup(getAnimal());
}
AnimalBasedSuperHero::~AnimalBasedSuperHero() { delete[] _animal; }

void AnimalBasedSuperHero::setAnimal(const char* animal) { _animal = _strdup(animal); }
const char* AnimalBasedSuperHero::getAnimal() const { return _animal; }

void AnimalBasedSuperHero::load(ifstream& in_file)
{
	SuperHero::load(in_file);
	int size1;
	in_file.read((char*)&size1, sizeof(size1));
	in_file.read((char*)this->_animal, size1);
}

void AnimalBasedSuperHero::save(ofstream& out_file) const
{
	SuperHero::save(out_file);
	int size1 = strlen(_animal);
	out_file.write((char*)this->_animal, size1);
}

