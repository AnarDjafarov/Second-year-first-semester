#include "RegularRoom.h"

RegularRoom::RegularRoom(int t1, int t2, int t3) : Room(t1, t2, t3)
{
	this->_ifSealed = false;
}