#include "Warrior.h"

Warrior::Warrior(string nickname) : Player(nickname)
{
	job_name = "����";
	speed = 1;
	accuracy = 1;
}

void Warrior::attack(Monster* monster)
{
	cout << job_name << "�� ���� �ֵѷ� �����ߴ�!" << endl;
	monster->attack(this);
}
