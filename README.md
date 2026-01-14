# cpp-game-engine

A minimal turn-based RPG combat engine built in C++ to explore object-oriented design patterns including inheritance hierarchies, virtual functions, polymorphism, and friend classes.

## Features

- **Inheritance hierarchy** — Abstract base class (`Object`) with derived `Character` and `Weapon` classes
- **Diamond inheritance** — Resolved using virtual inheritance
- **Polymorphism** — Runtime behavior via virtual functions and overriding
- **Friend functions** — Controlled access for game engine coordination
- **Turn-based combat loop** — Player vs NPC with health, damage, and rage mechanics

## Class Structure
```
Object (abstract base)
├── Character
│   ├── Player (also inherits Weapon)
│   └── NPC (also inherits Weapon)
└── Weapon
```

## Example
```cpp
Player hero{"Herakles", 50, 25, "Sword"};
NPC enemy{"Hydra", 75, 30, "Bite"};
GameEngine game(&hero, &enemy);
game.run();
```

Output:
```
=====
Turn: 1
Current Character: Herakles
Player: Type: Player(Warrior), Name: Herakles, Health: 150, Weapon: Sword, Attack Value: 25.
NPC: Type: NPC, Name: Hydra, Health: 75, Weapon: Bite, Attack Value: 30.
=====
Player attacks for 25 damage.
...
Player wins!
```

## Mechanics

- **Player weapon bonuses:**
  | Weapon | Health Multiplier | Attack Multiplier |
  |--------|-------------------|-------------------|
  | Sword  | 3x | 1x |
  | Bow    | 2x | 2x |
  | Dagger | 1x | 3x |

- **NPC rage mode:** When health drops below 50%, damage received is halved

## Building
```bash
cmake -B build
cmake --build build
./build/bin/game
```

## License

MIT
