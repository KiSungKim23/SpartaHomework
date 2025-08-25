#include "Item.h"
#include <iostream>

Item::Item(string name, int price)
{
    name_ = name;
    price_ = price;
    cout << name_ << "»ý¼ºµÊ" << endl;
}

Item::~Item()
{
    cout << name_ << "»èÁ¦µÊ" << endl;
}

void Item::PrintInfo() const
{
    cout << "[ÀÌ¸§: " << name_ << ", °¡°Ý: " << price_ << "G]" << endl;
}

int Item::GetPrice() const
{
    return price_;
}
