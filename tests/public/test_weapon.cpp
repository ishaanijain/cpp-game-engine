#include <catch_amalgamated.hpp>
#include "../../include/Weapon.h"

class TestableWeapon : public Weapon{
  public:
  TestableWeapon(std::string name, int weapon_strength, std::string weapon_type)
  :Object(name), Weapon(name, weapon_strength, weapon_type){}

  int getWeaponStrength() const{
    return Weapon::getWeaponStrength();
  }
};

namespace {
  TEST_CASE("HW 5 Weapon Test 1", "[getNameTest]") {
   TestableWeapon weapon("Sword of Gryffindor",10,"Sword");
   std::string name = "Sword of Gryffindor";
   CHECK(weapon.getName() == name);
  }

  TEST_CASE("HW 5 Weapon Test 2", "[describeTest]") {
   Weapon weapon("Axe of Perun",15,"Axe");
   std::string description = "Type: Weapon, Name: Axe of Perun, It is a Axe with a weapon strength of 15.";
   CHECK(weapon.describe() == description);
  }

  TEST_CASE("HW5 Weapon Test 3", "[getWeaponStrengthTest]"){
    TestableWeapon weapon("Bow of Artemis",20,"Bow");
    int weapon_strength = 20;
    CHECK(weapon.getWeaponStrength() == weapon_strength);
  }

  TEST_CASE("HW5 Weapon test 4", "[getWeaponTypeTest]"){
    Weapon weapon("Dagger of Loki",5,"Dagger");
    std::string weapon_type = "Dagger";
    CHECK(weapon.getWeaponType() == weapon_type);
  }
}