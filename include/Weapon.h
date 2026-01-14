#ifndef WEAPON_H
#define WEAPON_H

#include "Object.h"

class Weapon : public virtual Object{
    private:
    int weapon_strength;
    std::string weapon_type;

    public:
    static constexpr int max_weapon_strength = 300;
    Weapon(std::string name, int weapon_strength, std::string weapon_type);
    std::string getWeaponType() const;
    std::string describe() const override;

    protected:
    virtual int getWeaponStrength() const;
    
};

#endif
