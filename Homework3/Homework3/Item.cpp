#include "Item.h"
#include <iostream>

Item::Item(string name, int price)
{
    name_ = name;
    price_ = price;
    cout << name_ << "������" << endl;
}

Item::~Item()
{
    cout << name_ << "������" << endl;
}

void Item::PrintInfo() const
{
    cout << "[�̸�: " << name_ << ", ����: " << price_ << "G]" << endl;
}

int Item::GetPrice() const
{
    return price_;
}
