#pragma once
#include "Hazard.h"

class Bat : public Hazard
{
private:
	std::string _name = "Bat";
public:
	std::string getMessage() const;
	void setHazard(std::string str);
};