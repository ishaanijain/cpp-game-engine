#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Character.h"
#include "Weapon.h"

class GameEngine;

class Player : public Character, private Weapon {
private:
    static int health_multiplier(const std::string& weapon_type);
    static int attack_multiplier(const std::string& weapon_type);
    
public:
    Player(std::string name, int health, int weapon_strength, std::string weapon_type);
    std::string getCharacterInfo() const;
    std::string getWeaponInfo() const;
    std::string getCharacterType() const override;
    std::string describe() const override;

protected:
    int getAttackValue() const override;
    void receiveDamage(int dmg) override;

friend void GameEngine::turnAction(std::ostream &output, Character *attacker, Character *target);
};


#endif