#ifndef CHARACTER_H
#define CHARACTER_H

#include "GameEngine.h"
#include "Object.h"

class Character : public virtual Object{
    private:
    int health;

    public:
    static constexpr int max_health = 300;
    Character(std::string name, int health);
    bool isAlive() const;
    virtual std::string getCharacterType() const;
    std::string describe() const override;
    int getHealth() const;

    protected:
    virtual int getAttackValue() const;
    virtual void receiveDamage(int dmg);

    friend void GameEngine::turnAction(std::ostream & output, Character *attacker, Character *target);
};  

#endif
