#pragma once
#include "Hazard.h"

class Pit : public Hazard
{
private:
	std::string _name = "Pit";
public:
	std::string getMessage() const;
	void setHazard(std::string str);
};