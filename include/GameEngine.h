#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H
#include <iosfwd>
#include <string>

class Character;
class Player;
class NPC;

class GameEngine {
private:
    unsigned int turn_count;
    Character* current;
    Character* target;
    Player*    player;
    NPC*       npc;

public:
    GameEngine(Player* attacker, NPC* target);

    void printState(std::ostream & output) const;
    void logAction(std::ostream & output, const std::string& ch_type, int attack);
    void turnAction(std::ostream & output, Character *attacker, Character *target);
    void run(std::ostream &output);
};

#endif