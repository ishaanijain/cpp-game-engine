#include <catch_amalgamated.hpp>
#include "NPC.h"
#include "Object.h"

class TestableNPC: public NPC {
    public:
    TestableNPC(std::string name, int health, int attack_value, std::string weapon_type)
    : Object(name), NPC(name, health, attack_value, weapon_type) {}
    using NPC::receiveDamage;
    int exposeAttackValue() const {return getAttackValue();}   
};

namespace {
    using Catch::Matchers::ContainsSubstring;
    TEST_CASE("HW 5 NPC Test 1", "[ConstructorNPCTest]") {
        TestableNPC npc("Cyclops", 70, 50, "Club");
        CHECK_THAT(npc.getCharacterInfo(), ContainsSubstring("Cyclops"));
        CHECK_THAT(npc.getWeaponInfo(), ContainsSubstring("Club"));
        CHECK(npc.exposeAttackValue()==50);
        CHECK_FALSE(npc.inRage());
    }
    TEST_CASE("HW 5 NPC Test 2", "[getCharacterTypeNPCTest]") {
        TestableNPC warlock("Warlock", 100, 35, "Wand");
        TestableNPC witch("Witch", 80, 22, "Broom");
        TestableNPC warrior("Aragorn", 25, 25, "Sword");
        TestableNPC archer("Legolas", 90, 10, "Bow");
        TestableNPC assasin("Assassin", 50, 50, "Dagger");

        CHECK(warlock.getCharacterType() == "NPC");
        CHECK(witch.getCharacterType()=="NPC");
        CHECK(warrior.getCharacterType()=="NPC(Warrior)");
        CHECK(archer.getCharacterType()=="NPC(Archer)");
        CHECK(assasin.getCharacterType()=="NPC(Assassin)");
    }
    TEST_CASE("HW 5 NPC Test 3", "[receiveDamageNPCTest]") {
        TestableNPC npc("Vampire", 30, 10, "Dagger");
        npc.receiveDamage(10);
        CHECK_THAT(npc.getCharacterInfo(), ContainsSubstring("Health: 20"));
        CHECK_FALSE(npc.inRage());

        npc.receiveDamage(5); // health is less than or equal to half
        CHECK(npc.inRage());
        CHECK_THAT(npc.getCharacterInfo(), ContainsSubstring("Health: 15")); 
    }
    TEST_CASE("HW 5 NPC Test 4", "[edgeCaseNPCTest]") {
        TestableNPC npc("Mummy", 50, 10, "Sword");
        npc.receiveDamage(100); //more than health
        CHECK_FALSE(npc.isAlive());
        CHECK_THAT(npc.getCharacterInfo(), ContainsSubstring("Health: 0"));
    }
    TEST_CASE("HW 5 NPC Test 5", "[edgeCaseNPCTest]") {
        TestableNPC npc("Siren", 100, 15, "Sword");
        npc.receiveDamage(60);
        CHECK(npc.inRage()); //gets mad

        npc.receiveDamage(20); //scale damage by half so 20/2 (10 actually taken)
        CHECK_THAT(npc.getCharacterInfo(), ContainsSubstring("Health: 30"));
    }
    TEST_CASE("HW 5 NPC Test 6", "[edgeCaseNPCTest]") {
        TestableNPC npc("Goblin", 100, 15, "Sword");
        npc.receiveDamage(120); //instant kill
        CHECK_FALSE(npc.inRage());
        CHECK_FALSE(npc.isAlive());
    }
    TEST_CASE("HW 5 NPC Test 7", "[edgeCaseNPCTest]") {
        TestableNPC npc("Evil Chihuahua", 100, 15, "Dagger");
        npc.receiveDamage(60); //rage triggered
        std::string description = npc.describe();
        CHECK_THAT(description, ContainsSubstring("In Rage: Yes"));

    }
}