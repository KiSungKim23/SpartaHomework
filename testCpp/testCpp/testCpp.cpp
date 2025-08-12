// testCpp.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum class Status
{
    HP = 0,
    MP = 1,
    ATK = 2,
    DEF = 3,
};

class Player
{
public:
    Player();
    bool InitStatus(Status s, int value);
    void SetPotion(int count, int* p_HPPotion, int* p_MPPotion);

    void PlayGame(int option);

    void UsingHPPotion();
    void UsingMPPotion();
    void EnhanceHP();
    void EnhanceMP();
    void Attack();
    void SpecialAttack();

private:
    int status[4]{};
    int _hpPotion = 0;
    int _mpPotion = 0;
};

bool Player::InitStatus(Status s, int value)
{
    switch (s)
    {
    case Status::HP:
    case Status::MP: 
        if (value <= 50)
        {
            cout<<"HP나 MP의 값이 너무 작습니다. 다시 입력해주세요."<<'\n';
            return  false;
        }
        status[static_cast<size_t>(s)] = value;
        break;
    case Status::ATK:
    case Status::DEF:
        if (value <= 0)
        {
            cout<<"공격력이나 방어력의 값이 너무 작습니다. 다시 입력해주세요."<<'\n';
            return  false;
        }
        break;
    }
    status[static_cast<size_t>(s)] = value;

    return  true;
}

void Player::SetPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
    *p_HPPotion = count;
    *p_MPPotion = count;
}

void Player::PlayGame(int option)
{
    switch (option)
    {
    case 1:
        UsingHPPotion();
        break;
    case 2:
        UsingMPPotion();
        break;
    case 3:
        EnhanceHP();
        break;
    case 4:
        EnhanceMP();
        break;
    case 5:
        Attack();
        break;
    case 6:
        SpecialAttack();
        break;
    default: ;
    }
}

void Player::UsingHPPotion()
{
    if (_hpPotion <= 0)
    {
        cout<< "포션이 부족합니다." << '\n';
        return;
    }

    _hpPotion--;
    status[static_cast<size_t>(Status::HP)] += 20;
    
    cout<< "* HP가 20 회복되었습니다. 포션이 1개 차감됩니다."<< '\n';
    cout<< "현재 HP : "<< status[static_cast<size_t>(Status::HP)]<< '\n';
    cout<< "남은 포션 수 : " << _hpPotion << '\n';
}

void Player::UsingMPPotion()
{
    if (_mpPotion <= 0)
    {
        cout<< "포션이 부족합니다." << '\n';
        return;
    }

    _mpPotion--;
    status[static_cast<size_t>(Status::MP)] += 20;

    cout<< "* MP가 20 회복되었습니다. 포션이 1개 차감됩니다."<< '\n';
    cout<< "현재 MP : "<< status[static_cast<size_t>(Status::MP)]<< '\n';
    cout<< "남은 포션 수 : " << _mpPotion << '\n';
    
}

void Player::EnhanceHP()
{
    status[static_cast<size_t>(Status::HP)] += status[static_cast<size_t>(Status::HP)];
    cout<< "* HP가 2배로 증가되었습니다."<< '\n';
    cout<< "현재 HP : "<< status[static_cast<size_t>(Status::HP)]<< '\n';
}

void Player::EnhanceMP()
{
    status[static_cast<size_t>(Status::MP)] += status[static_cast<size_t>(Status::MP)];
    cout<< "* MP가 2배로 증가되었습니다."<< '\n';
    cout<< "현재 MP : "<< status[static_cast<size_t>(Status::MP)]<< '\n';
}

void Player::Attack()
{
    if (status[static_cast<size_t>(Status::MP)] <= 50)
    {
        cout<< "스킬 사용이 불가합니다." << '\n';
        return;
    }

    status[static_cast<size_t>(Status::MP)] -= 50;
    cout<<"* 스킬을 사용하여 MP가 50 소모되었습니다."<< '\n';
    cout<< "현재 MP : "<< status[static_cast<size_t>(Status::MP)]<< '\n';
}

void Player::SpecialAttack()
{
    status[static_cast<size_t>(Status::MP)] -= (int)(status[static_cast<size_t>(Status::MP)] * 0.5);
    cout<<"* 스킬을 사용하여 MP가 50% 소모되었습니다."<< '\n';
    cout<< "현재 MP : "<< status[static_cast<size_t>(Status::MP)]<< '\n';
}


Player::Player()
{
    int initA = 0;
    int initB = 0;
    
    while (true)
    {
        cout << "HP와 MP를 입력해주세요: ";
        cin >> initA >> initB;

        if (InitStatus(Status::HP, initA) && InitStatus(Status::MP, initB))
            break;
    }
    
    while (true)
    {
        cout << "공격력과 방어력을 입력해주세요: ";
        cin >> initA >> initB;

        if (InitStatus(Status::ATK, initA) && InitStatus(Status::DEF, initB))
            break;
    }
    SetPotion(5, &_hpPotion, &_mpPotion);
    cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)" << '\n';
}



int main()
{
    Player* player = new Player();

    cout << "=============================================" << '\n';
    cout << "1. HP 회복" << '\n';
    cout << "2. MP 회복" << '\n';
    cout << "3. HP 강화" << '\n';
    cout << "4. MP 강화" << '\n';
    cout << "5. 공격 스킬 사용" << '\n';
    cout << "7. 게임 종료" << '\n';

    int option = 0;
    
    while (true)
    {
        cout << "번호를 선택해주세요: ";
        cin >> option;

        player->PlayGame(option);

        if (option == 7)
            break;
    }
    
    delete player;
}
