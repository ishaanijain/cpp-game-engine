#include <catch_amalgamated.hpp>
#include "Character.h"
#include "Object.h"

class TestableCharacter : public Character{
    public:
    TestableCharacter(std::string name, unsigned int health):Object(name), Character(name, health){}
    int getAttackValue() const override{
        return Character::getAttackValue();
    }
    
    void receiveDamage(int dmg) override{
      Character::receiveDamage(dmg);
    }
  };


namespace {
  TEST_CASE("HW 5 Character Test 1", "[isAliveTest]") {
   Character character("Hero", 100);
   CHECK(character.isAlive());
  }


  TEST_CASE("HW 5 Character Test 2", "[isAliveTest_false]") {
   Character character("Hero", 0);
   CHECK_FALSE(character.isAlive());
  }

  TEST_CASE("HW 5 Character Test 3", "[describeTest]") {
    Character character("Hero", 100);
    std::string describe("Type: Character, Name: Hero, Health: 100.");
    CHECK(character.describe() == describe);
  }


  TEST_CASE("HW 5 Character Test 4", "[getNameTest]") {
    Character character("Hero", 100);
    std::string name = "Hero";
    CHECK(character.getName() == name);
  }

  TEST_CASE("HW 5 Character Test 5", "[getAttackValueTest]") {
    TestableCharacter character("Hero", 100);
    CHECK(character.getAttackValue() == 0);
  }

  TEST_CASE("HW 5 Character Test 6", "[receiveDamageTest]") {
    TestableCharacter character("Hero", 100);
    character.receiveDamage(30);
    CHECK(character.getHealth() == 70);
  }

  TEST_CASE("HW 5 Character Test 7", "[receiveDamageIsAliveTest]"){
    TestableCharacter character("Hero", 50);
    character.receiveDamage(10);
    CHECK(character.isAlive());
    character.receiveDamage(40);
    CHECK_FALSE(character.isAlive());
  }

  TEST_CASE("HW 5 Character Test 8", "[getCharacterTypeTest]") {
    Character character("Hero", 100);
    std::string character_type = "Character";
    CHECK(character.getCharacterType() == character_type);
  }
}