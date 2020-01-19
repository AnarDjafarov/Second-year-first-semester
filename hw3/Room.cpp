#include "Room.h"
#include "Hazard.h"
#include "MushMush.h"
#include "Bat.h"
#include "Pit.h"
#include <typeinfo>

using namespace std;

Room::Room(int tunnel1, int tunnel2, int tunnel3) : _hazard(nullptr)
{
	this->_tunnels[0] = tunnel1;
	this->_tunnels[1] = tunnel2;
	this->_tunnels[2] = tunnel3;
}

int Room::getTunnel1() const
{
	return this->_tunnels[0];
}

int Room::getTunnel2() const
{
	return this->_tunnels[1];
}

int Room::getTunnel3() const
{
	return this->_tunnels[2];
}

std::string Room::roomHazard() const
{
	if (this->_hazard == nullptr)
		return "";
	string str = this->_hazard->getMessage();
	if (str.compare("MushMush") == 0)
		return "MushMush is near";
	else if (str.compare("Bat") == 0)
		return "Bat is near";
	else
		return "Pit is near";
}

bool Room::roomIsEmpty() const
{
	if (this->_hazard == nullptr)
		return true;
	return false;
}

bool Room::attackInRoom(string& message) const
{
	if (this->_hazard == nullptr)
	{
		message = "";
		return false;
	}

	string str = this->_hazard->getMessage();
	//if (typeid(this[0]).name() == "SealedRoom")
	if(this->_ifSealed)
		message = "You just shot yourself";
	else if (str.compare("Bat") == 0)
		message = "Bat is laughing";
	else if (str.compare("Pit") == 0)
		message = "Pit is whistling";
	//else if( typeid(this[0]).name() == "SealedRoom")
	else if (str.compare("MushMush") == 0)
		message = "You got MushMush";

	return true;
}

bool Room::clashInRoom(std::string& msg) const
{
	if (this->_hazard == nullptr)
	{
		msg = "";
		return false;
	}
	string str = this->_hazard->getMessage();
	if (str.compare("MushMush") == 0)
		msg = "MushMush got you";
	else if (str.compare("Bat") == 0)
		msg = "A Bat will move you";
	else
		msg = "You fell into a Pit";

	return true;
}

bool Room::isMushMushHere() const
{
	if (this->_hazard->getMessage() == "MushMush")
		return true;
	return false;
}

const Hazard* Room::getHazard() const
{
	return this->_hazard;
}

void Room::setHazard(string str)
{
	this->_hazard = new Hazard;
	this->_hazard->mysetHazard(str);
}

void Room::deleteHazard()
{
	delete this->_hazard;
}

string Room::getHazardstr() const
{
	if (this->_hazard == nullptr)
		return "";
	return this->_hazard->getMessage();
}