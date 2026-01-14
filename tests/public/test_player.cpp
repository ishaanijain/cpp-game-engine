#include <catch_amalgamated.hpp>
#include "../../include/Player.h"
#include "Object.h"

class TestablePlayer : public Player {
    public:
    TestablePlayer(std::string name, int health, int weapon_strength, std::string weapon_type)
    : Object(name), Player(name, health, weapon_strength, weapon_type){}

    int getAttackvalue() const{
        return Player::getAttackValue();
    }

    void receiveDamage(int dmg) override{
        Player::receiveDamage(dmg);
    }

    std::string getCharacterType() const override{
        return Player::getCharacterType();
    }
};

namespace {
    using Catch::Matchers::ContainsSubstring;

    TEST_CASE("HW 5 Player Test 1", "[ConstructorPlayerTest]") {
        TestablePlayer hawkeye("Hawkeye", 80, 10, "Bow");
        CHECK_THAT(hawkeye.getCharacterInfo(), ContainsSubstring("Hawkeye"));
        CHECK_THAT(hawkeye.getWeaponInfo(), ContainsSubstring("Bow"));
        CHECK(hawkeye.getHealth()==160);
        CHECK(hawkeye.getAttackvalue()== 20);
    }

    TEST_CASE("HW5 Player Test 2", "[getAttackValueTest]") {
        TestablePlayer heracles("Heracles", 80, 10, "Club");
        TestablePlayer hawkeye("Hawkeye", 80, 10, "Bow");
        TestablePlayer arya_stark("Arya Stark", 80, 10, "Dagger");
        TestablePlayer gryffindor("Gryffindor", 80, 10, "Sword");
        int heracles_attack_value = 10;
        int hawkeye_attack_value = 20;
        int arya_stark_attack_value = 30;
        int gryffindor_attack_value = 10;
        CHECK(heracles.getAttackvalue() == heracles_attack_value);
        CHECK(hawkeye.getAttackvalue() == hawkeye_attack_value);
        CHECK(gryffindor.getAttackvalue() == gryffindor_attack_value);
        CHECK(arya_stark.getAttackvalue() == arya_stark_attack_value);
    }

    TEST_CASE("HW 5 Player Test 3", "[getCharacterTypeTest]") {
        TestablePlayer heracles("Heracles", 80, 10, "Club");
        TestablePlayer hawkeye("Hawkeye", 80, 10, "Bow");
        TestablePlayer arya_stark("Arya Stark", 80, 10, "Dagger");
        TestablePlayer gryffindor("Gryffindor", 80, 10, "Sword");

        std::string heracles_character_type = "Player";
        std::string hawkeye_character_type = "Player(Archer)";
        std::string arya_stark_character_type = "Player(Assassin)";
        std::string gryffindor_character_type = "Player(Warrior)";

        CHECK(heracles.getCharacterType() == heracles_character_type);        
        CHECK(hawkeye.getCharacterType() == hawkeye_character_type);        
        CHECK(arya_stark.getCharacterType() == arya_stark_character_type);        
        CHECK(gryffindor.getCharacterType() == gryffindor_character_type);               
    }

    TEST_CASE("HW 5 Weapon Test 4", "[getCharacterInfoTest]") {
        TestablePlayer heracles("Heracles", 80, 10, "Club");
        TestablePlayer hawkeye("Hawkeye", 80, 10, "Bow");
        TestablePlayer arya_stark("Arya Stark", 80, 10, "Dagger");
        TestablePlayer gryffindor("Gryffindor", 80, 10, "Sword");

        std::string heracles_character_info = "Name: Heracles, Character Type: Player, Health: 80.";
        std::string hawkeye_character_info = "Name: Hawkeye, Character Type: Player(Archer), Health: 160.";
        std::string arya_stark_character_info = "Name: Arya Stark, Character Type: Player(Assassin), Health: 80.";
        std::string gryffindor_character_info = "Name: Gryffindor, Character Type: Player(Warrior), Health: 240.";

        CHECK(heracles.getCharacterInfo() == heracles_character_info);
        CHECK(hawkeye.getCharacterInfo() == hawkeye_character_info);
        CHECK(arya_stark.getCharacterInfo() == arya_stark_character_info);
        CHECK(gryffindor.getCharacterInfo() == gryffindor_character_info);
    }

    TEST_CASE("HW 5 Weapon Test 5", "[getWeaponInfoTest]") {

        TestablePlayer heracles("Heracles", 80, 10, "Club");
        TestablePlayer hawkeye("Hawkeye", 80, 10, "Bow");
        TestablePlayer arya_stark("Arya Stark", 80, 10, "Dagger");
        TestablePlayer gryffindor("Gryffindor", 80, 10, "Sword");

        std::string heracles_weapon_info = "Name: Heracles, Weapon Type: Club, Weapon Strength: 10\nThe player has an attack multiplier of 1.";
        std::string hawkeye_weapon_info = "Name: Hawkeye, Weapon Type: Bow, Weapon Strength: 10\nThe player has an attack multiplier of 2.";
        std::string arya_stark_weapon_info = "Name: Arya Stark, Weapon Type: Dagger, Weapon Strength: 10\nThe player has an attack multiplier of 3.";
        std::string gryffindor_weapon_info = "Name: Gryffindor, Weapon Type: Sword, Weapon Strength: 10\nThe player has an attack multiplier of 1.";

        CHECK(heracles.getWeaponInfo() == heracles_weapon_info);
        CHECK(hawkeye.getWeaponInfo() == hawkeye_weapon_info);
        CHECK(arya_stark.getWeaponInfo() == arya_stark_weapon_info);
        CHECK(gryffindor.getWeaponInfo() == gryffindor_weapon_info);
    }

    TEST_CASE("HW 5 Player Test 6", "[describeTest]") {
        TestablePlayer hawkeye("Hawkeye", 80, 10, "Bow");

        std::string describe = "Type: Player(Archer), Name: Hawkeye, Health: 160, Weapon: Bow, Attack Value: 20.";
        CHECK(hawkeye.describe() == describe);
    }
    

    TEST_CASE("HW 5 Player Test 7", "[receiveDamageTest]") {
        TestablePlayer heracles("Heracles", 80, 10, "Club");
        CHECK(heracles.getHealth() == 80);
        heracles.receiveDamage(20);
        CHECK(heracles.getHealth() == 60);
    }
}