#include "../include/Character.h"
#include <algorithm>

Character::Character(std::string name, int health) : Object(name) {
   
    this->health = std::max(0, std::min(health, max_health));
}

bool Character::isAlive() const {
    return health > 0;
}

std::string Character::getCharacterType() const {
    return "Character";
}

std::string Character::describe() const {
    return "Type: " + getCharacterType() + ", Name: " + getName() + 
           ", Health: " + std::to_string(health) + ".";
}

int Character::getHealth() const {
    return health;
}
int Character::getAttackValue() const {
    return 0;
}

void Character::receiveDamage(int dmg) {
    health -= dmg;
    if (health < 0) {
        health = 0;
    }
}