#include "Avengers.h"

Avengers::Avengers()
{
	_numSuperHeros = 1;
	_superHeros = new SuperHero*[_numSuperHeros];
}
Avengers::~Avengers()
{
	//for (int i = 0; i < _numSuperHeros; i++)
		//delete _superHeros[i];
	delete[] _superHeros;
}

void Avengers::saveType(ofstream& out, const SuperHero* hero) const
{
	char* temp = new char[3];
	if      (typeid(*hero) == typeid(SuperHero))				temp = _strdup("SH");
	else if (typeid(*hero) == typeid(ProfessionBasedSuperHero)) temp = _strdup("PB");
	else if (typeid(*hero) == typeid(AnimalBasedSuperHero))		temp = _strdup("AB");
	else if (typeid(*hero) == typeid(Spiderman))				temp = _strdup("SP");
	else if (typeid(*hero) == typeid(CaptainAmerica))			temp = _strdup("CA");
	else														temp = _strdup("CS");
	out.write((char*)temp, strlen(temp));
	delete[] temp;
}

int Count_SuperHeros(ifstream& in)
{
	int num_SuperHeros = 0;
	in.seekg(0, in.end);
	int size = (int)in.tellg();
	in.seekg(0, in.beg);

	char* block = new char[size + 1];
	char* temp = new char[2];

	in.read((char*)block, size);

	for (int i = 0; i < size - 1; i++, block++)
	{
		memcpy(temp, block, 2);
		if (strcmp(temp, "SH") == 0)
			num_SuperHeros++;
		else if (strcmp(temp, "AB") == 0)
			num_SuperHeros++;
		else if (strcmp(temp, "PB") == 0)
			num_SuperHeros++;
		else if (strcmp(temp, "SP") == 0)
			num_SuperHeros++;
		else if (strcmp(temp, "CA") == 0)
			num_SuperHeros++;
		else if (strcmp(temp, "CS") == 0)
			num_SuperHeros++;
	}
	return num_SuperHeros;
}

SuperHero* Build_Team(ifstream& in)
{
	SuperHero* TempHero = nullptr;
	char temp[3];
	in.read((char*)temp, 2);
	temp[2] = '\0';
	if (strcmp(temp, "SH") == 0)
		TempHero = new SuperHero();
	else if (strcmp(temp, "AB") == 0)
		TempHero = new AnimalBasedSuperHero();
	else if (strcmp(temp, "PB") == 0)
		TempHero = new ProfessionBasedSuperHero();
	else if (strcmp(temp, "SP") == 0)
		TempHero = new Spiderman();
	else if (strcmp(temp, "CA") == 0)
		TempHero = new CaptainAmerica();
	else if (strcmp(temp, "CS") == 0)
		TempHero = new CaptainSpider();
	return TempHero;
}



void Avengers::load(ifstream& in_file)
{
	_numSuperHeros = Count_SuperHeros(in_file);
	delete[] _superHeros;
	_superHeros = new SuperHero*[_numSuperHeros];

	SuperHero* temp = Build_Team(in_file);
	for (int i = 0; i < _numSuperHeros; i++)
	{
		_superHeros[i] = temp;
		_superHeros[i]->load(in_file);
	}
}
void Avengers::save(ofstream& out_file) const
{
	for (int i = 0; i < _numSuperHeros; i++)
	{
		saveType(out_file,_superHeros[i]);
		_superHeros[i]->save(out_file);
	}
}
void Avengers::setSuperHeros(SuperHero** superHeros, int size)
{
	delete[] _superHeros;
	_superHeros = new SuperHero*[size];
	//memcpy(_superHeros, superHeros, size * sizeof(superHeros));
	for (int i = 0; i < size; i++)
		_superHeros[i] = superHeros[i];
	_numSuperHeros = size;
}
SuperHero** Avengers::getSuperHeros() const { return _superHeros; }


