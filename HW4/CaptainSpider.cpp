#include "CaptainSpider.h"

CaptainSpider::CaptainSpider() : CaptainAmerica(), Spiderman() {}

CaptainSpider::CaptainSpider(const char* name, double age, bool radioactive, const char* profession, int yearsExperience,
	double ageIncludingFreezing, const char* animal, double webSize)
	:SuperHero(name, age, radioactive), CaptainAmerica(profession, yearsExperience,ageIncludingFreezing),
	Spiderman(animal, webSize) {}

CaptainSpider::CaptainSpider(const char* profession, int yearsExperience, double ageIncludingFreezing, const char* animal, double webSize)
	: CaptainAmerica(profession, yearsExperience, ageIncludingFreezing), Spiderman(animal, webSize) {}

CaptainSpider::CaptainSpider(double ageIncludingFreezing, double webSize) : CaptainAmerica(ageIncludingFreezing), Spiderman(webSize){}

CaptainSpider::CaptainSpider(const CaptainSpider& captainSpider) :
	Spiderman(captainSpider.getName(), captainSpider.getAge(), 
		captainSpider.getRadioactive(), captainSpider.getAnimal(), captainSpider.getWebSize()) , 
		CaptainAmerica(captainSpider.getProfession(), captainSpider.getYearsExperience(), captainSpider.getAgeIncludingFreezing())
{ }
CaptainSpider::~CaptainSpider() {}

void CaptainSpider::load(ifstream& in_file)
{
	Spiderman::load(in_file);
	//CaptainAmerica::load(in_file);
	int size1;
	in_file.read((char*)&size1, sizeof(size1));
	in_file.read((char*)this->_profession, size1);
	in_file.read((char*)&this->_yearsExperience, sizeof(_yearsExperience));
	in_file.read((char*)&this->_ageIncludingFreezing, sizeof(_ageIncludingFreezing));
}
void CaptainSpider::save(ofstream& out_file) const
{
	Spiderman::save(out_file);
	//CaptainAmerica::save(out_file);
	int size1 = strlen(_profession);
	out_file.write((char *)&size1, sizeof(size1));
	out_file.write((char*)this->_profession, size1);
	out_file.write((char*)&this->_yearsExperience, sizeof(_yearsExperience));
	out_file.write((char*)&this->_ageIncludingFreezing, sizeof(_ageIncludingFreezing));
}
