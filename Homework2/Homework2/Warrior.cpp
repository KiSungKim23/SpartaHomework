#include "Warrior.h"

Warrior::Warrior(string nickname) : Player(nickname)
{
	job_name = "전사";
	speed = 1;
	accuracy = 1;
}

void Warrior::attack(Monster* monster)
{
	cout << job_name << "가 검을 휘둘러 공격했다!" << endl;
	monster->attack(this);
}
