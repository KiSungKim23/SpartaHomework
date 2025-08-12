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

        cout << name << "���� " << damage << "�� ���ظ� ������!" << endl;
        if (HP <= 0)
        {
            cout << player->getNickname() << "�� �¸�!" << endl;
            break;
        }
    }
}

void Monster::printMonsterStatus()
{
    cout << "------------------------------------" << endl;
    cout << "* ���� �ɷ�ġ" << endl;
    cout << "�г���: " << name << endl;
    cout << "HP: " << HP << endl;
    cout << "���ݷ�: " << power << endl;
    cout << "����: " << defence << endl;
    cout << "�ӵ�: " << speed << endl;
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

