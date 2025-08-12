#include "Magician.h"

Magician::Magician(string nickname) : Player(nickname)
{
	job_name = "������";
	speed = 1;
	accuracy = 1;
}

void Magician::attack(Monster* monster)
{
	cout << job_name << "�� �����̷� ������ ����ߴ�!" << endl;
	monster->attack(this);
}
