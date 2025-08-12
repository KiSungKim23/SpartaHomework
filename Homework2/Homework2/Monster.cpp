#include "Monster.h"
#include "Player.h"

Monster::Monster(string name)
{
    setName(name);

    HP = 50;
    defence = 2;
    power = 4;
    speed = 3;
}

void Monster::attack(Player* player)
{
    auto damage = (int)((player->getPower() - defence) / player->getAccuracy());
    damage = damage <= 0 ? 1 : damage;
    
    for (int i = 0; i < player->getSpeed(); i++)
    {
        setHP(HP - damage);

        cout << name << "에게 " << damage << "의 피해를 입혔다!" << endl;
        if (HP <= 0)
        {
            cout << player->getNickname() << "의 승리!" << endl;
            break;
        }
    }
}

void Monster::printMonsterStatus()
{
    cout << "------------------------------------" << endl;
    cout << "* 현재 능력치" << endl;
    cout << "닉네임: " << name << endl;
    cout << "HP: " << HP << endl;
    cout << "공격력: " << power << endl;
    cout << "방어력: " << defence << endl;
    cout << "속도: " << speed << endl;
    cout << "------------------------------------" << endl;
}


string Monster::getName()
{
	return name;
}

int Monster::getHP()
{
	return HP;
}

int Monster::getPower()
{
    return power;
}

int Monster::getDefence()
{
	return defence;
}

int Monster::getSpeed()
{
	return speed;
}

void Monster::setName(string name)
{
	this->name = name;
}

bool Monster::setHP(int HP)
{
    this->HP = HP;

    return this->HP > 0;
}

void Monster::setPower(int power)
{
    this->power = power;
}

void Monster::setDefence(int defence)
{
    this->defence = defence;
}

void Monster::setSpeed(int speed)
{
    this->speed = speed;
}

