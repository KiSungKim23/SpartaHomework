#include "Thief.h"

Thief::Thief(string nickname) : Player(nickname)
{
	job_name = "도적";

	speed = 5;
	accuracy = 5;
}

void Thief::attack(Monster* monster)
{
	cout << job_name << "이 단검을 던져 공격했다" << endl;
	monster->attack(this);
}
