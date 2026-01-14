#include "../include/NPC.h"

NPC::NPC(std::string name, int health, int weapon_strength, std::string weapon_type)
    : Object(name),
      Character(name, health),
      Weapon(name, weapon_strength, weapon_type),
      original_health(getHealth()),
      in_rage(false) {
}

std::string NPC::getCharacterInfo() const {
    return "NPC Name: " + getName() + ", NPC Type: " + getCharacterType() + 
           ", Health: " + std::to_string(getHealth()) + ".";
}

std::string NPC::getWeaponInfo() const {
    return "Weapon Name: " + getName() + ", Weapon Type: " + getWeaponType() + 
           ", Attack Bonus: " + std::to_string(getWeaponStrength()) + 
           "\nThe player has an attack bonus of " + std::to_string(1) + ".";
}

std::string NPC::getCharacterType() const {
    std::string wtype = getWeaponType();
    if (wtype == "Sword") {
        return "NPC(Warrior)";
    } else if (wtype == "Bow") {
        return "NPC(Archer)";
    } else if (wtype == "Dagger") {
        return "NPC(Assassin)";
    } else {
        return "NPC";
    }
}

std::string NPC::describe() const {
    std::string rage_status = (isAlive() && in_rage) ? "Yes" : "No";
    return "Type: " + getCharacterType() + ", Name: " + getName() + 
           ", Health: " + std::to_string(getHealth()) + 
           ", Weapon: " + getWeaponType() + 
           ", Attack Value: " + std::to_string(getAttackValue()) + ".\n" +
           "In Rage: " + rage_status + ".";
}

bool NPC::inRage() const {
    return isAlive() && in_rage;
}

int NPC::getAttackValue() const {
    return getWeaponStrength();
}

void NPC::receiveDamage(int dmg) {
    // If already in rage, take reduced damage
    if (in_rage) {
        Character::receiveDamage(dmg / 2);
    } else {
        // Take full damage
        Character::receiveDamage(dmg);
        // Check if NPC entered rage state after taking damage
        if (getHealth() <= original_health / 2) {
            in_rage = true;
        }
    }
}