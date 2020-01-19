#pragma once
#include <string>
using namespace std;
class Hazard;

#pragma pack(push, 1)
class Room
{
public:
    Room(int tunnel1, int tunnel2, int tunnel3);
    //~Room();
    //bool attackInRoom(std::string& message) const;
    virtual bool attackInRoom(std::string& message) const;
    int getTunnel1() const;
    int getTunnel2() const;
    int getTunnel3() const;
    std::string roomHazard() const;
    const Hazard* getHazard() const;

    bool roomIsEmpty() const;
    bool isMushMushHere() const;
    bool clashInRoom(std::string& msg) const;

    //mine
    void setHazard(std::string str);
    string getHazardstr() const;
    void deleteHazard();
protected:
    Hazard* _hazard;
    bool _ifSealed;
private:
    int _tunnels[3];
};
#pragma pack(pop)
