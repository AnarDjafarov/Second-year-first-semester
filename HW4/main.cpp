//#include "Avengers.h"
//
//
//
//int main()
//{
//
//		SuperHero* superArr[6];
//		superArr[0] = new SuperHero("Clark Kent", 25);
//		superArr[1] = new ProfessionBasedSuperHero("IronMan", 38, false, "entrepreneur", 18);
//		superArr[2] = new AnimalBasedSuperHero("Scott Lang", 30, false, "Ant");
//		superArr[3] = new Spiderman("Peter Parker", 17, true, "spider", 2.3);
//		superArr[4] = new CaptainAmerica("Steve Rogers", 22, true, "soldier", 75, 89);
//		superArr[5] = new CaptainSpider("Peter Rogers", 20, true, "soldier", 3, 53, "spider", 3.4);
//
//
//		Avengers team;
//		ofstream out_file("avengers.bin", ios::binary | ios::out);
//		team.setSuperHeros(superArr, 6);
//		team.save(out_file);
//		out_file.close();
//
//
//		ifstream in_file("avengers.bin",  ios::in);
//		team.load(in_file);
//		in_file.close();
//
//
//	return 0;
//}

#include "Avengers.h"


void test_superhero(SuperHero** s, int id, const char* name, double age, bool radioactive = false, const char* profession = nullptr,
	int yearsExperience = -1000, double ageIncludingFreezing = -1000, const char* animal = nullptr, double webSize = -1000)
{
	if (const Spiderman* sp = dynamic_cast<const Spiderman*>(s[id])) {
		if (sp->getWebSize() != webSize)
			std::cout << "Websize of " << id << " is wrong" << endl;
	}
	if (const CaptainAmerica* ca = dynamic_cast<const CaptainAmerica*>(s[id])) {
		if (ca->getAgeIncludingFreezing() != ageIncludingFreezing)
			std::cout << "AgeIncludingFreezing of " << id << " is wrong" << endl;
	}
	if (const AnimalBasedSuperHero* ab = dynamic_cast<const AnimalBasedSuperHero*>(s[id])) {
		if (!(!ab->getAnimal() && !animal) && strcmp(ab->getAnimal(), animal))
			std::cout << "Animal of " << id << " is wrong" << endl;
	}
	if (const ProfessionBasedSuperHero* pb = dynamic_cast<const ProfessionBasedSuperHero*>(s[id])) {
		if (pb->getYearsExperience() != yearsExperience)
			std::cout << "YearsExperience of " << id << " is wrong" << endl;
		if (!(!pb->getProfession() && !profession) && strcmp(pb->getProfession(), profession) != 0)
			std::cout << "Profession of " << id << " is wrong" << endl;
	}
	if (!(!s[id]->getName() && !name) && strcmp(s[id]->getName(), name) != 0)
		std::cout << "Name of " << id << " is wrong (" << s[id]->getName() << ", " << name << ")" << endl;
	if (s[id]->getAge() != age)
		std::cout << "Age of " << id << " is wrong" << endl;
}


void test_default_val() {
	SuperHero* superArr[6];
	superArr[0] = new SuperHero();
	superArr[1] = new ProfessionBasedSuperHero();
	superArr[2] = new AnimalBasedSuperHero();
	superArr[3] = new CaptainAmerica();
	superArr[4] = new Spiderman();
	superArr[5] = new CaptainSpider();
	test_superhero(superArr, 0, nullptr, 0);
	test_superhero(superArr, 1, nullptr, 0, false, nullptr, 0);
	test_superhero(superArr, 2, nullptr, 0, false, nullptr, 0, 0, nullptr);
	test_superhero(superArr, 3, nullptr, 0, false, nullptr, 0, 0);
	test_superhero(superArr, 4, nullptr, 0, false, nullptr, 0, 0, nullptr, 0);
	test_superhero(superArr, 5, nullptr, 0, false, nullptr, 0, 0, nullptr, 0);
}

void test_no_change_values() {
	SuperHero* superArr[6];
	int ages[] = { 25, 38, 30, 22, 17, 20 };
	superArr[0] = new SuperHero("Clark Kent", ages[0]);
	superArr[1] = new ProfessionBasedSuperHero("IronMan", ages[1], false, "entrepreneur", 18);
	superArr[2] = new AnimalBasedSuperHero("Scott Lang", ages[2], false, "Ant");
	superArr[3] = new CaptainAmerica("Steve Rogers", ages[3], true, "soldier", 75, 89);
	superArr[4] = new Spiderman("Peter Parker", ages[4], true, "spider", 2.3);
	superArr[5] = new CaptainSpider("Peter Rogers", ages[5], true, "soldier", 3, 53, "spider", 3.4);
	for (int i = 0; i < 6; i++) {
		superArr[i]->setAge(10);
		if (superArr[i]->getAge() != ages[i]) cout << "Age should not accept ages lower than 15";
		superArr[i]->setAge(50);
		if (superArr[i]->getAge() != ages[i]) cout << "Age should not accept ages bigger than 40";
	}
}
void test_special_cases() {
	CaptainAmerica* ca = new CaptainAmerica("Steve Rogers", 22, true, "soldier", 75, 89);
	ca->setAgeIncludingFreezing(20);
	if (ca->getAgeIncludingFreezing() != 89) cout << "Age including freezing should be bigger than age";

	ProfessionBasedSuperHero* pb = new ProfessionBasedSuperHero("IronMan", 38, false, "entrepreneur", 18);
	pb->setYearsExperience(-10);
	if (pb->getYearsExperience() != 18) cout << "years of experience does not change on values < 0";
	pb->setYearsExperience(0);
	if (pb->getYearsExperience() != 0) cout << "years of experience can be 0";

	Spiderman* sp = new Spiderman("Peter Parker", 17, true, "spider", 2.3);
	sp->setWebSize(-10);
	if (sp->getWebSize() != 2.3) cout << "websize does not change on values < 0";
	sp->setWebSize(0);
	if (sp->getWebSize() != 0) cout << "websize can be 0";

}
int main() {

	/*test_default_val();
	test_no_change_values();
	test_special_cases();*/
	SuperHero* superArr[6];
	superArr[0] = new SuperHero("Clark Kent", 25);
	superArr[1] = new ProfessionBasedSuperHero("IronMan", 38, false, "entrepreneur", 18);
	superArr[2] = new AnimalBasedSuperHero("Scott Lang", 30, false, "Ant");
	superArr[3] = new CaptainAmerica("Steve Rogers", 22, true, "soldier", 75, 89);
	superArr[4] = new Spiderman("Peter Parker", 17, true, "spider", 2.3);
	superArr[5] = new CaptainSpider("Peter Rogers", 20, true, "soldier", 3, 53, "spider", 3.4);

	//test_superhero(superArr, 0, "Clark Kent", 25);
	//test_superhero(superArr, 1, "IronMan", 38, false, "entrepreneur", 18);
	//test_superhero(superArr, 2, "Scott Lang", 30, false, NULL, -1000, -1000, "Ant");
	//test_superhero(superArr, 3, "Steve Rogers", 22, true, "soldier", 75, 89);
	//test_superhero(superArr, 4, "Peter Parker", 17, true, NULL, -1000, -1000, "spider", 2.3);
	//test_superhero(superArr, 5, "Peter Rogers", 20, true, "soldier", 3, 53, "spider", 3.4);



	Avengers team;
	ofstream out_file("avengers.bin", ios::binary | ios::out);
	team.setSuperHeros(superArr, 6);


	team.save(out_file);

	out_file.close();

	Avengers team2;
	ifstream in_file("avengers.bin", ios::binary | ios::in);

	team2.load(in_file);

	//test_superhero(team2.getSuperHeros(), 0, "Clark Kent", 25);
	//test_superhero(team2.getSuperHeros(), 1, "IronMan", 38, false, "entrepreneur", 18);
	//test_superhero(team2.getSuperHeros(), 2, "Scott Lang", 30, false, NULL, -1000, -1000, "Ant");
	//test_superhero(team2.getSuperHeros(), 3, "Steve Rogers", 22, true, "soldier", 75, 89);
	//test_superhero(team2.getSuperHeros(), 4, "Peter Parker", 17, true, NULL, -1000, -1000, "spider", 2.3);
	//test_superhero(team2.getSuperHeros(), 5, "Peter Rogers", 20, true, "soldier", 3, 53, "spider", 3.4);


	in_file.close();

	for (int i = 0; i < 6; i++) {
		delete superArr[i];
	}

	return 0;
}
