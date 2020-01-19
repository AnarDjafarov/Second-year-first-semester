#include <iostream>
#include <string>
#include <sstream>
#include <cstring>

#include "Cave.h"
#include "SealedRoom.h"
static std::string expectedResults[] =
{
        "Bat is nearPit is nearMushMush is nearYou got MushMush1",
        "You just shot yourself",
        "MushMush got you",
        "A Bat will move you",
        "You fell into a Pit",
        "You got MushMush",
        "Bat is laughing",
        "Pit is whistling"
};

void test_all();

static std::string getStatusString(const Cave& c)
{
    std::string near_player[3];
    c.hazardNearPlayer(near_player);

    return near_player[0] + near_player[1] + near_player[2];
}

static std::string integerToString(int x)
{
    std::stringstream s;
    s << x;
    return s.str();
}

static bool test(void)
{

    Cave cave(NULL, 0);
    std::string status;
    cave.plotPlayerIdx(1);
    cave.plotHazard(9, "MushMush");
    cave.plotHazard(2, "Pit");
    cave.plotHazard(18, "Bat");

    status += getStatusString(cave);

    bool gotException = false;
    try
    {
        cave.movePlayer(6);
        status += getStatusString(cave);
        status += cave.playerClash(6);
    }
    catch (const char* p)
    {
        gotException = (0 == strcmp(p, "Invalid Index Exception"));
    }
    if (!gotException)
        std::cout << "Error: Incorrectly Handled Exception\n";
    cave.movePlayer(17);
    status += getStatusString(cave);

    cave.movePlayer(13);
    status += getStatusString(cave);

    status += cave.playerAttack(9);

    status += integerToString(cave.gameOver());

    return status == expectedResults[0];
}

static bool test_shoot_sealed_room(void) {
    int* sealed = new int[1];
    sealed[0] = 5;
    Cave cave(sealed, 1);

    std::string status;
    cave.plotPlayerIdx(1);
    cave.plotHazard(5, "MushMush");
    status += cave.playerAttack(5);
    return status == expectedResults[1];
}

static bool test_player_in_not_empty_room(void) {
    Cave cave(NULL, 0);
    bool gotException = false;
    std::string status;
    cave.plotHazard(5, "MushMush");
    try {
        cave.plotPlayerIdx(5);
        status = cave.playerAttack(5);
    }
    catch (const char* p) {
        gotException = (0 == strcmp(p, "Invalid Index Exception"));
    }
    return gotException;
}

static bool test_hazard_in_not_empty_room(void) {
    Cave cave(NULL, 0);
    bool gotException = false;
    std::string status;
    cave.plotHazard(5, "MushMush");
    try {
        cave.plotHazard(5, "Bat");
        status = cave.playerAttack(5);
    }
    catch (const char* p) {
        gotException = (0 == strcmp(p, "Invalid Index Exception"));
    }
    return gotException;
}

static bool test_invalid_hazard(void) {
    Cave cave(NULL, 0);
    bool gotException = false;
    std::string status;
    cave.plotHazard(5, "MushMush");
    try {
        cave.plotHazard(6, "Bit");
        status = cave.playerAttack(5);
    }
    catch (const char* p) {
        gotException = (0 == strcmp(p, "Invalid Hazard Exception"));
    }
    return gotException;
}

static bool test_not_mushmush(void) {
    Cave cave(NULL, 0);
    bool gotException = false;
    std::string status;
    try {
        status = cave.findMushMush();
        cave.plotHazard(6, "Bat");
    }
    catch (const char* p) {
        gotException = (0 == strcmp(p, "MushMush Not Found Exception"));
    }
    return gotException;
}

static bool test_mushmush_moved(void)
{
    int initialPos = 9;
    Cave cave(NULL, 0);
    std::string status;
    cave.plotPlayerIdx(1);
    cave.plotHazard(initialPos, "MushMush");
    cave.plotHazard(2, "Pit");
    cave.plotHazard(18, "Bat");

    bool gotException = false;
    try
    {
        cave.movePlayer(6);
        cave.playerClash(6);
    }
    catch (const char* p)
    {
        gotException = (0 == strcmp(p, "Invalid Index Exception"));
    }
    if (!gotException)
        std::cout << "Error: Incorrectly Handled Exception\n";
    cave.movePlayer(17);
    cave.movePlayer(13);
    cave.playerAttack(6);
    int mushmushPos = cave.findMushMush();
    return mushmushPos != initialPos;
}

static bool test_clash_in_room_mushmush() {
    Cave cave(NULL, 0);
    std::string status;
    cave.plotPlayerIdx(10);
    cave.plotHazard(9, "MushMush");
    cave.plotHazard(2, "Pit");
    cave.plotHazard(18, "Bat");
    cave.movePlayer(9);
    return expectedResults[2] == cave.playerClash(9);
}
static bool test_clash_in_room_bat() {
    Cave cave(NULL, 0);
    std::string status;
    cave.plotPlayerIdx(16);
    cave.plotHazard(9, "MushMush");
    cave.plotHazard(2, "Pit");
    cave.plotHazard(18, "Bat");
    cave.movePlayer(18);
    status += cave.playerClash(18);
    return expectedResults[3] == status;
}
static bool test_clash_in_room_pit() {
    Cave cave(NULL, 0);
    std::string status;
    cave.plotPlayerIdx(0);
    cave.plotHazard(9, "MushMush");
    cave.plotHazard(2, "Pit");
    cave.plotHazard(18, "Bat");
    cave.movePlayer(2);
    return expectedResults[4] == cave.playerClash(2);
}
static bool test_attack_in_room_mushmush() {
    Cave cave(NULL, 0);
    std::string status;
    cave.plotPlayerIdx(10);
    cave.plotHazard(9, "MushMush");
    cave.plotHazard(2, "Pit");
    cave.plotHazard(18, "Bat");
    return expectedResults[5] == cave.playerAttack(9);
}
static bool test_attack_in_room_bat() {
    Cave cave(NULL, 0);
    std::string status;
    cave.plotPlayerIdx(17);
    cave.plotHazard(9, "MushMush");
    cave.plotHazard(2, "Pit");
    cave.plotHazard(18, "Bat");
    return expectedResults[6] == cave.playerAttack(18);
}
static bool test_attack_in_room_pit() {
    Cave cave(NULL, 0);
    std::string status;
    cave.plotPlayerIdx(1);
    cave.plotHazard(9, "MushMush");
    cave.plotHazard(2, "Pit");
    cave.plotHazard(18, "Bat");
    return expectedResults[7] == cave.playerAttack(2);
}


void unit_tests() {
    if (!test_clash_in_room_mushmush()) std::cout << "Error in test_clash_in_room_mushmush()" << std::endl;
    if (!test_clash_in_room_bat()) std::cout << "Error in test_clash_in_room_bat()" << std::endl;
    if (!test_clash_in_room_pit()) std::cout << "Error in test_clash_in_room_pit()" << std::endl;
    if (!test_attack_in_room_mushmush()) std::cout << "Error in test_attack_in_room_mushmush()" << std::endl;
    if (!test_attack_in_room_bat()) std::cout << "Error in test_attack_in_room_bat()" << std::endl;
    if (!test_attack_in_room_pit()) std::cout << "Error in test_attack_in_room_pit()" << std::endl;
}

//int main()
//{
//    for (int i = 0; i < 10; i++)
//        test_all();
//    unit_tests();
//    Room* r = new SealedRoom(1, 2, 3);
//    delete r;
//    return 0;
//}

void test_all() {
    if (!test())
        std::cout << "Error: Game Logic Error 1\n";
    else if (!test_shoot_sealed_room())
        std::cout << "Error: Game Logic Error 2\n";
    else if (!test_player_in_not_empty_room())
        std::cout << "Error: Game Logic Error 3\n";
    else if (!test_hazard_in_not_empty_room())
        std::cout << "Error: Game Logic Error 4\n";
    else if (!test_invalid_hazard())
        std::cout << "Error: Game Logic Error 5\n";
    else if (!test_not_mushmush())
        std::cout << "Error: Game Logic Error 6\n";
    else if (!test_mushmush_moved())
        std::cout << "Error: Game Logic Error 7\n";
    else
        std::cout << "All good\n";
}
