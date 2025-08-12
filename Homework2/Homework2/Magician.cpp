#include "Magician.h"

Magician::Magician(string nickname) : Player(nickname)
{
	job_name = "마법사";
	speed = 1;
	accuracy = 1;
}

void Magician::attack(Monster* monster)
{
	cout << job_name << "가 지팡이로 마법을 사용했다!" << endl;
	monster->attack(this);
}
