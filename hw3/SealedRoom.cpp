#include "SealedRoom.h"

SealedRoom::SealedRoom(int t1, int t2, int t3) : Room(t1, t2, t3)
{
	this->_ifSealed = true;
}