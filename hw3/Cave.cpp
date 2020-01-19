#include "Cave.h"
#include "Hazard.h"
#include "SealedRoom.h"
#include "RegularRoom.h"

using namespace std;

Cave::Cave(const int* const sealedRooms, int size)
{
	_roomsArr[0] = new RegularRoom(2, 18, 19);
	_roomsArr[1] = new RegularRoom(5, 17, 18);
	_roomsArr[2]= new RegularRoom(0, 4, 17);
	_roomsArr[3]= new RegularRoom(7, 16, 19);
	_roomsArr[4]= new RegularRoom(2, 6, 15);
	_roomsArr[5]= new RegularRoom(1, 9, 14);
	_roomsArr[6]= new RegularRoom(4, 8, 13);
	_roomsArr[7]= new RegularRoom(3, 11, 12);
	_roomsArr[8]= new RegularRoom(6, 10, 11);
	_roomsArr[9]= new RegularRoom(5, 10, 13);
	_roomsArr[10] = new RegularRoom(8, 9, 12);
	_roomsArr[11] = new RegularRoom(7, 8, 15);
	_roomsArr[12] = new RegularRoom(7, 10, 14);
	_roomsArr[13] = new RegularRoom(6, 9, 17);
	_roomsArr[14] = new RegularRoom(5, 12, 16);
	_roomsArr[15] = new RegularRoom(4, 11, 19);
	_roomsArr[16] = new RegularRoom(3, 14, 18);
	_roomsArr[17] = new RegularRoom(1, 2, 13);
	_roomsArr[18] = new RegularRoom(0, 1, 16);
	_roomsArr[19] = new RegularRoom(0, 3, 15);

	for (int i = 0; i < size; i++)
	{
		int t1 = this->_roomsArr[sealedRooms[i]]->getTunnel1();
		int t2 = this->_roomsArr[sealedRooms[i]]->getTunnel2();
		int t3 = this->_roomsArr[sealedRooms[i]]->getTunnel3();
		delete this->_roomsArr[sealedRooms[i]];
		this->_roomsArr[sealedRooms[i]] = new SealedRoom(t1, t2, t3);
	}

	this->_playeridx = -1;
	this->_gameOver = false;
}

Cave::~Cave()
{
	for (int i = 0; i < 20; i++)
		delete[] _roomsArr[i];
}

void Cave::plotHazard(int idx, const std::string& eventName)
{
	string str = eventName;
	if (str.compare("MushMush") != 0 &&
		str.compare("Bat") != 0 &&
		str.compare("Pit") != 0)
		throw "Invalid Hazard Exception";
	else if (idx < 0 || idx > 19 || this->_roomsArr[idx]->getHazard() != nullptr)
		throw "Invalid Index Exception";
	this->_roomsArr[idx]->setHazard(eventName);
}

void Cave::plotPlayerIdx(int idx)
{
	if (idx < 0 || idx > 19 || this->_roomsArr[idx]->getHazard() != nullptr)
		throw "Invalid Index Exception";

	this->_playeridx = idx;
}

int Cave::findMushMush(void) const
{
	string str = "MushMush";

	for (int i = 0; i < 20; i++)
	{
		if (str.compare(this->_roomsArr[i]->getHazardstr()) == 0)
			return i;
	}

	throw "MushMush Not Found Exception";
}

void Cave::movePlayer(int idx)
{
	if (this->_roomsArr[_playeridx]->getTunnel1() == idx ||
		this->_roomsArr[_playeridx]->getTunnel2() == idx ||
		this->_roomsArr[_playeridx]->getTunnel3() == idx)
		this->_playeridx = idx;
	else
		throw "Invalid Index Exception";
}

std::string Cave::playerAttack(int idx)
{
	//checks if the Index is valid
	if (this->_roomsArr[_playeridx]->getTunnel1() != idx &&
		this->_roomsArr[_playeridx]->getTunnel2() != idx &&
		this->_roomsArr[_playeridx]->getTunnel3() != idx)
		throw "Invalid Index Exception";

	string str;
	bool ifAttacked = this->_roomsArr[idx]->attackInRoom(str);

	//MushMush moves
	if (!ifAttacked)
	{
		int mushIdx = this->findMushMush();
		int t1 = _roomsArr[mushIdx]->getTunnel1();
		int t2 = _roomsArr[mushIdx]->getTunnel2();
		int t3 = _roomsArr[mushIdx]->getTunnel3();
		if (_roomsArr[t1]->roomIsEmpty())
		{
			//_roomsArr[mushIdx]->setHazard(nullptr);
			_roomsArr[mushIdx]->deleteHazard();
			_roomsArr[t1]->setHazard("MushMush");
		}
		else if (_roomsArr[t2]->roomIsEmpty())
		{
			_roomsArr[mushIdx]->setHazard(nullptr);
			_roomsArr[t2]->setHazard("MushMush");
		}
		else if (_roomsArr[t3]->roomIsEmpty())
		{
			_roomsArr[mushIdx]->setHazard(nullptr);
			_roomsArr[t3]->setHazard("MushMush");
		}
	}
	//Got MushMush
	else
	{
		if (str.compare("You got MushMush") == 0)
			this->_gameOver = true;
	}

	return str;
}

std::string Cave::playerClash(int idx)
{
	if (idx < 0 || idx > 19)
		throw "Invalid Index Exception";

	string str;
	bool backBool;

	backBool = _roomsArr[_playeridx]->clashInRoom(str);

	if (str.compare("A Bat will move you") == 0)
	{
		//_playeridx = idx++;
		/*if (idx > 19)
			idx -= 20;*/
		//this->_roomsArr[_playeridx]->setHazard(nullptr);
		this->_roomsArr[_playeridx]->deleteHazard();
		_playeridx = idx;
		idx++;
		if (idx > 19)
			idx -= 20;
		str = playerClash(idx);

		return str;
	}
	else if (str.compare("You fell into a Pit") == 0 ||
			 str.compare("MushMush got you") == 0)
	{
		_gameOver = true;
		return str;
	}

	return "";
}

bool Cave::gameOver() const
{
	return this->_gameOver;
}

void Cave::hazardNearPlayer(std::string* hazards) const
{
	int t1 = this->_roomsArr[_playeridx]->getTunnel1();
	int t2 = this->_roomsArr[_playeridx]->getTunnel2();
	int t3 = this->_roomsArr[_playeridx]->getTunnel3();

	hazards[0] = this->_roomsArr[t1]->roomHazard();
	hazards[1] = this->_roomsArr[t2]->roomHazard();
	hazards[2] = this->_roomsArr[t3]->roomHazard();
}

const Room* Cave::getRoomAtIndex(int index) const
{
	if (index < 0 || index > 19)
		throw "Invalid Index Exception";

	Room* p;

	p = this->_roomsArr[index];

	return p;
}