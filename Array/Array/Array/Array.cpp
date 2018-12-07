// Array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class Vector
{
public:
	Vector();
	~Vector();

	int getSize() const;
	bool isEmpty() const;
	int getCapacity() const;

	int at(int index);
	void push(int value);
	void printDebug() const;
	void insert(int value,int index);
	void prepend(int value);
	int pop() const;
	void deleteAt(int index);
	void remove(int value);
	int find(int value);

private:
	int* _data;
	int _size;
	int _capacity;

	void resize(int newCap);


};

Vector::Vector() :
	_size(0),
	_capacity(128)
	
{
	_data = new int[_capacity];
}

Vector::~Vector()
{
	delete _data;
}

int Vector::getSize() const
{
	return _size;
}

bool Vector::isEmpty() const
{
	return _size == 0;
}

int Vector::getCapacity() const
{
	return _capacity;
}

void Vector::resize(int newCap)
{
	int* newData = new int[newCap];
	std::memcpy(newData, _data, _size * sizeof(int));
	delete _data;
	_data = newData;
	_capacity = newCap;
}

int Vector::at(int index)
{
	if (index >= _size)
	{
		std::cerr << "\nError: Out of range.";
		exit(EXIT_FAILURE);
		return 0;
	}

	return *(_data + index);
}

void Vector::push(int value)
{
	if (_size == _capacity)
	{
		resize(_capacity * 2);
	}

	_data[_size] = value;
	_size++;
}

void Vector::insert(int value,  int index)
{
	if (index >= _size)
		return;

	if (_size == _capacity)
	{
		resize(_capacity * 2);
	}

	for (int i = _size - 1; i >= index; i--)
	{		
		_data[i + 1] = _data[i];
	}

	_data[index] = value;
	_size += 1;
}

void Vector::prepend(int value)
{
	insert(value, 0);
}

int Vector::pop() const 
{
	return _data[_size - 1];
}

void Vector::deleteAt(int index)
{
	if (index < 0 || index >= _size)
		return;

	for (int i = index; i < _size; ++i)
	{
		_data[i] = _data[i + 1];
	}
	_size -= 1;

	if (_size <= _capacity / 4)
	{
		resize(_capacity / 4);
	}
	
}

void Vector::remove(int value)
{
	int i = 0;
	while (i < _size)
	{
		if (_data[i] == value)
		{
			deleteAt(i);
		}
		else {
			i++;
		}
	}
}

int Vector::find(int value)
{
	int i = 0;
	while (i < _size)
	{
		if (_data[i] == value)
			return i;
		i++;
	}
	return -1;
}

void Vector::printDebug() const
{
	std::cout << "\n";
	for (int i = 0; i < _size; i++)
	{
		std::cout << _data[i] << " ";
	}
}


int main()
{

	Vector v;
	v.push(0);
	v.push(1);
	v.push(2);
	v.push(3);
	v.push(4);
	v.push(2);
	v.push(6);
	v.push(2);
	
	
	v.printDebug();
	std::cout << v.find(34);

	system("pause");
	return 0;
}

