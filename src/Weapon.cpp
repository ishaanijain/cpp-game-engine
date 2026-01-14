#include "../include/Weapon.h" 
#include <algorithm>

Weapon::Weapon(std::string name, int weapon_strength, std::string weapon_type) 
    : Object(name), weapon_type(weapon_type) {

        this->weapon_strength = std::max(0, std::min(weapon_strength, max_weapon_strength));
}

std::string Weapon::getWeaponType() const {
    return weapon_type;
}

std::string Weapon::describe() const {
    return "Type: Weapon, Name: " + getName() + ", It is a " + weapon_type + 
           " with a weapon strength of " + std::to_string(weapon_strength) + ".";
}

int Weapon::getWeaponStrength() const {
    return weapon_strength;
}