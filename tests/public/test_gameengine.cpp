#include "GameEngine.h"
#include "NPC.h"
#include "Player.h"
#include <catch_amalgamated.hpp>
#include <sstream>
#include "test_utils.h"

namespace {
TEST_CASE("HW 5 Game Engine Test Initial State", "[engineTest_printState]") {
  Player hero{"Herakles", 50, 25, "Club"};
  NPC enemy{"Hydra", 75, 30, "Bite"};
  GameEngine engine{&hero, &enemy};

  std::stringstream ss;
  engine.printState(ss);

  CHECK(manual_eq(ss.str(), R"(=====
Turn: 1
Current Character: Herakles
Player: Type: Player, Name: Herakles, Health: 50, Weapon: Club, Attack Value: 25.
NPC: Type: NPC, Name: Hydra, Health: 75, Weapon: Bite, Attack Value: 30.
In Rage: No.
=====
)"));
}

TEST_CASE("HW 5 Game Engine Test Log action", "[engineTest_log]") {
  Player hero{"Herakles", 50, 25, "Club"};
  NPC enemy{"Hydra", 75, 30, "Bite"};
  GameEngine engine{&hero, &enemy};

  std::stringstream ss;
  engine.logAction(ss, "Zeus", 10);

  CHECK(manual_eq(ss.str(), R"(Zeus attacks for 10 damage.
)"));
}

class TestablePlayer: public Player {
    public:
    TestablePlayer(std::string name, int health, int attack_value, std::string weapon_type)
    :Object{name}, Player{name, health, attack_value, weapon_type} {}
    using Player::receiveDamage;
    int exposeAttackValue() const {return getAttackValue();}   
};

TEST_CASE("HW 5 Game Engine Test turnAction", "[engineTest_action]") {
  TestablePlayer hero{"Herakles", 50, 25, "Club"};
  NPC enemy{"Hydra", 75, 30, "Bite"};
  GameEngine engine{&hero, &enemy};

  std::stringstream expected;
  engine.logAction(expected, hero.getCharacterType(), hero.exposeAttackValue());

  std::stringstream actual;
  engine.turnAction(actual, &hero, &enemy);

  CHECK( manual_eq(actual.str(), expected.str()) );
  CHECK(enemy.getHealth() == 50);
}



TEST_CASE("HW 5 Game Engine Test Run engine", "[engineTest_run]") {
  Player hero{"Herakles", 50, 25, "Club"};
  NPC enemy{"Hydra", 75, 30, "Bite"};
  GameEngine engine{&hero, &enemy};

  std::stringstream ss;
  engine.run(ss);
  
  auto actual = ss.str();
  INFO("Output: " << actual);
  CHECK(manual_eq(actual, R"(=====
Turn: 1
Current Character: Herakles
Player: Type: Player, Name: Herakles, Health: 50, Weapon: Club, Attack Value: 25.
NPC: Type: NPC, Name: Hydra, Health: 75, Weapon: Bite, Attack Value: 30.
In Rage: No.
=====
Player attacks for 25 damage.
=====
Turn: 2
Current Character: Hydra
Player: Type: Player, Name: Herakles, Health: 50, Weapon: Club, Attack Value: 25.
NPC: Type: NPC, Name: Hydra, Health: 50, Weapon: Bite, Attack Value: 30.
In Rage: No.
=====
NPC attacks for 30 damage.
=====
Turn: 3
Current Character: Herakles
Player: Type: Player, Name: Herakles, Health: 20, Weapon: Club, Attack Value: 25.
NPC: Type: NPC, Name: Hydra, Health: 50, Weapon: Bite, Attack Value: 30.
In Rage: No.
=====
Player attacks for 25 damage.
=====
Turn: 4
Current Character: Hydra
Player: Type: Player, Name: Herakles, Health: 20, Weapon: Club, Attack Value: 25.
NPC: Type: NPC, Name: Hydra, Health: 25, Weapon: Bite, Attack Value: 30.
In Rage: Yes.
=====
NPC attacks for 30 damage.
NPC wins!
)"));
}

} // namespace