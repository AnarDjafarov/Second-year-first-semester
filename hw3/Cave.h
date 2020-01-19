#pragma once

#include <string>
//mine
#include "Room.h"

class Room;
class Cave
{
public:
    Cave(const int* const sealedRooms, int size);
    ~Cave();
    const Room* getRoomAtIndex(int index) const;
    void plotHazard(int idx, const std::string& eventName);
    void plotPlayerIdx(int idx);
    int findMushMush(void) const;
    void movePlayer(int idx);
    std::string playerAttack(int idx);
    std::string playerClash(int idx);
    bool gameOver() const;

    void hazardNearPlayer(std::string* hazards) const;
private:
    Room* _roomsArr[20];
    int _playeridx;
    bool _gameOver;
};
