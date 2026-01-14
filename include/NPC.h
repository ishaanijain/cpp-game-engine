#ifndef NPC_H
#define NPC_H

#include <string>
#include "Character.h"
#include "Weapon.h"

class GameEngine;

class NPC : public Character, private Weapon {
private:
    int original_health;
    bool in_rage;

public:
    NPC(std::string name, int health, int weapon_strength, std::string weapon_type);
    std::string getCharacterInfo() const;
    std::string getWeaponInfo() const;
    std::string getCharacterType() const override;
    std::string describe() const override;
    bool inRage() const;

protected:
    int getAttackValue() const override;
    void receiveDamage(int dmg) override;

friend void GameEngine::turnAction(std::ostream &, Character *attacker, Character *target);
};

#endif