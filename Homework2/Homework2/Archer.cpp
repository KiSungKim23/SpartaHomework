#include "Archer.h"

Archer::Archer(string nickname) : Player(nickname)
{
	speed = 3;
	accuracy = 3;
	job_name = "�ü�";
}

void Archer::attack(Monster* monster)
{
	cout << job_name << "�� Ȱ�� �� �����ߴ�!" << endl;
	monster->attack(this);
}
