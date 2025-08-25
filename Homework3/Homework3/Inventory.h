#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
class Inventory
{
private:
	T** _pItems = nullptr;

	int _size = 0;
	int _capacity = 0;

public:
	Inventory(int capacity = 10);
	Inventory(const Inventory<T>& other);
	~Inventory();

	Inventory<T>* AddItem(T* item);
	void RemoveLastItem();
	void PrintAllItems() const;
	void EndMove();
	void Resize(int newCapacity);
	void SortItems();

	int GetSize() const { return _size; }
	int GetCapacity() const { return _capacity; }
	T* GetItem(int index) const;

};

template<typename T>
inline Inventory<T>::Inventory(int capacity)
{
	_capacity = capacity <= 0 ? 1 : capacity;
	_pItems = new T*[_capacity] {};
	_size = 0;
}

template<typename T>
inline Inventory<T>::Inventory(const Inventory<T>& other)
{
	_capacity = other.GetCapacity() * 2;
	_size = other.GetSize();
	_pItems = new T * [_capacity] {};
	for (int i = 0; i < _size; ++i) {
		_pItems[i] = other.GetItem(i);
	}
	cout << "인벤토리 확장 완료   크기 : "<< _capacity << endl;
}

template<typename T>
inline Inventory<T>::~Inventory()
{
	if (_pItems != nullptr)
	{
		for (int i = 0; i < _size; i++)
		{
			if (_pItems[i] != nullptr)
				delete _pItems[i];
		}

		delete[] _pItems;
		_pItems = nullptr;
	}
}

template<typename T>
inline Inventory<T>* Inventory<T>::AddItem(T* item)
{
	if (_size >= _capacity)
	{
		auto ret = new Inventory<T>(*this);
		ret->AddItem(item);
		EndMove();
		return ret;
	}

	_pItems[_size++] = item;
	return this;
}

template<typename T>
inline void Inventory<T>::RemoveLastItem()
{
	if (_size <= 0)
	{
		cout << "(비어있음)" << endl;
		return;
	}

	delete _pItems[--_size];
}

template<typename T>
inline void Inventory<T>::PrintAllItems() const
{
	if (_size <= 0)
	{
		cout << "(비어있음)" << endl;
	}

	try
	{
		for (int i = 0; i < _size; i++)
		{
			_pItems[i]->PrintInfo();
		}
	}
	catch (exception e)
	{
		cout << "Item이 아닌 데이터로 인벤토리가 만들어졌습니다." << endl;
	}
}

template<typename T>
inline void Inventory<T>::EndMove()
{
	_size = 0;
}

template<typename T>
inline void Inventory<T>::Resize(int newCapacity)
{
	if (newCapacity < _size)
		return;

	auto temp = new T*[newCapacity];
	for (int i = 0; i < _size; i++)
	{
		temp[i] = _pItems[i];
	}
	delete _pItems;

	cout << "크기 재조정 : " << newCapacity << endl;
	_pItems = temp;
	_capacity = newCapacity;
}

template<typename T>
inline void Inventory<T>::SortItems()
{
	cout << "인벤토리 정리" << endl;
	try
	{
		sort(_pItems, _pItems + _size, [](const T* a, const T* b)
			{
				if (a == nullptr) return false;
				if (b == nullptr) return true;
				return a->GetPrice() < b->GetPrice();
			});
	}
	catch (exception e)
	{
		cout << "Item이 아닌 데이터로 인벤토리가 만들어졌습니다." << endl;
	}
}

template<typename T>
inline T* Inventory<T>::GetItem(int index) const
{
	if (index >= _size)
	{
		return nullptr;
	}

	return _pItems[index];
}

