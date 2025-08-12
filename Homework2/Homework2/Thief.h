#pragma once
#include "Player.h"
class Thief :
    public Player
{
public:
    Thief(string nickname);
    virtual void attack(Monster* monster);
};

