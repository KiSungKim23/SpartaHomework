#include "Thief.h"

Thief::Thief(string nickname) : Player(nickname)
{
	job_name = "����";

	speed = 5;
	accuracy = 5;
}

void Thief::attack(Monster* monster)
{
	cout << job_name << "�� �ܰ��� ���� �����ߴ�" << endl;
	monster->attack(this);
}
