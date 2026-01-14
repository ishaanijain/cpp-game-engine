#include "../include/GameEngine.h"
#include "../include/Character.h"
#include "../include/Player.h"
#include "../include/NPC.h"
#include <iostream>

GameEngine::GameEngine(Player* attacker, NPC* target)
    : turn_count(1), player(attacker), npc(target) {
    current = attacker;
    this->target = target;
}

void GameEngine::printState(std::ostream& output) const {
    output << "=====" << std::endl;
    output << "Turn: " << turn_count << std::endl;
    output << "Current Character: " << (current ? current->getName() : "None") << std::endl;
    output << "Player: " << (player ? player->describe() : "None") << std::endl;
    output << "NPC: " << (npc ? npc->describe() : "None") << std::endl;
    output << "=====" << std::endl;
}

void GameEngine::logAction(std::ostream& output, const std::string& ch_type, int attack) {
    output << ch_type << " attacks for " << attack << " damage." << std::endl;
}

void GameEngine::turnAction(std::ostream& output, Character* attacker, Character* target) {
    if (attacker && target) {
        int attack_value = attacker->getAttackValue();
        logAction(output, attacker->getCharacterType(), attack_value);
        target->receiveDamage(attack_value);
    }
}

void GameEngine::run(std::ostream& output) {
    // Check if any pointers are null
    if (!current || !target || !player || !npc) {
        return;
    }

    // Main game loop
    while (player->isAlive() && npc->isAlive()) {
        printState(output);
        turnAction(output, current, target);
        
        // Switch turns
        turn_count++;
        if (current == player) {
            current = npc;
            target = player;
        } else {
            current = player;
            target = npc;
        }
    }

    // Announce winner
    if (player->isAlive()) {
        output << "Player wins!" << std::endl;
    } else {
        output << "NPC wins!" << std::endl;
    }
}