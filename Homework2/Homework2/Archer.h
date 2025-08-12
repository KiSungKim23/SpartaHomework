#pragma once
#include "Player.h"
class Archer :
    public Player
{
public:
    Archer(string nickname);
    virtual void attack(Monster* monster);
};

