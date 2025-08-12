#include "Archer.h"

Archer::Archer(string nickname) : Player(nickname)
{
	speed = 3;
	accuracy = 3;
	job_name = "±Ã¼ö";
}

void Archer::attack(Monster* monster)
{
	cout << job_name << "°¡ È°À» ½÷ °ø°ÝÇß´Ù!" << endl;
	monster->attack(this);
}
