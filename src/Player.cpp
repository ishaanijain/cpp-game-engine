#include "../include/Player.h"
#include <algorithm>

int Player::health_multiplier(const std::string& weapon_type) {
    if (weapon_type == "Sword") {
        return 3;
    } else if (weapon_type == "Bow") {
        return 2;
    } else if (weapon_type == "Dagger") {
        return 1;
    } else {
        return 1;
    }
}

int Player::attack_multiplier(const std::string& weapon_type) {
    if (weapon_type == "Sword") {
        return 1;
    } else if (weapon_type == "Bow") {
        return 2;
    } else if (weapon_type == "Dagger") {
        return 3;
    } else {
        return 1;
    }
}

Player::Player(std::string name, int health, int weapon_strength, std::string weapon_type)
    : Object(name),
      Character(name, std::min(health * health_multiplier(weapon_type), Character::max_health)),
      Weapon(name, weapon_strength, weapon_type) {
}

std::string Player::getCharacterInfo() const {
    return "Name: " + getName() + ", Character Type: " + getCharacterType() + 
           ", Health: " + std::to_string(getHealth()) + ".";
}

std::string Player::getWeaponInfo() const {
    return "Name: " + getName() + ", Weapon Type: " + getWeaponType() + 
           ", Weapon Strength: " + std::to_string(getWeaponStrength()) + 
           "\nThe player has an attack multiplier of " + 
           std::to_string(attack_multiplier(getWeaponType())) + ".";
}

std::string Player::getCharacterType() const {
    std::string wtype = getWeaponType();
    if (wtype == "Sword") {
        return "Player(Warrior)";
    } else if (wtype == "Bow") {
        return "Player(Archer)";
    } else if (wtype == "Dagger") {
        return "Player(Assassin)";
    } else {
        return "Player";
    }
}

std::string Player::describe() const {
    return "Type: " + getCharacterType() + ", Name: " + getName() + 
           ", Health: " + std::to_string(getHealth()) + 
           ", Weapon: " + getWeaponType() + 
           ", Attack Value: " + std::to_string(getAttackValue()) + ".";
}

int Player::getAttackValue() const {
    int attack = getWeaponStrength() * attack_multiplier(getWeaponType());
    return std::min(attack, Character::max_health);
}

void Player::receiveDamage(int dmg) {
    Character::receiveDamage(dmg);
}