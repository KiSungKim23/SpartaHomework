#pragma once
#include "Player.h"
class Warrior :
    public Player
{
public:
    Warrior(string nickname);
    virtual void attack(Monster* monster);
};

