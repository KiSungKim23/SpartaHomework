#pragma once
#include <string>

using namespace std;

class Item
{
private:
	string name_;
	int price_;

public:

	Item(string name, int price);
	~Item();

	void PrintInfo() const;
	int GetPrice() const;

};

