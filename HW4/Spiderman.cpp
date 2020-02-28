#include "Spiderman.h"




Spiderman::Spiderman() : AnimalBasedSuperHero() { _webSize = 0.0; }

Spiderman::Spiderman(const char* name, double age, bool radioactive, const char* animal, double webSize) :SuperHero(name, age, radioactive),
	AnimalBasedSuperHero( animal) { _webSize = webSize; }

Spiderman::Spiderman(const char* animal, double webSize) : AnimalBasedSuperHero(animal) { _webSize = webSize; }

Spiderman::Spiderman(double webSize) { _webSize = webSize; }

Spiderman::Spiderman(const Spiderman& spiderman) : AnimalBasedSuperHero(spiderman.getName(), spiderman.getAge(),
	spiderman.getRadioactive(), spiderman.getAnimal())
{ 
	_webSize = spiderman.getWebSize();
}

Spiderman::~Spiderman() {}

double Spiderman::getWebSize() const { return _webSize; }

void Spiderman::setWebSize(double webSize)
{
	if (webSize < 0) return;
		else  _webSize = webSize;
}

void Spiderman::load(ifstream& in_file)
{
	AnimalBasedSuperHero::load(in_file);
	in_file.read((char*)&this->_webSize, sizeof(_webSize));
}
void Spiderman::save(ofstream& out_file) const
{
	AnimalBasedSuperHero::save(out_file);
	out_file.write((char*)&this->_webSize, sizeof(_webSize));
}