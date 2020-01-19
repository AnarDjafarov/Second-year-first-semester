#pragma once
#include "Hazard.h"
using namespace std;
class MushMush : public Hazard
{
private:
	std::string _name = "MushMush";
public:
	std::string getMessage() const;
	void setHazard(std::string str);
};