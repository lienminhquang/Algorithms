#include "stdafx.h"
#include "HashTable.h"


HashTable::HashTable(int size):
	_size(size),
	_table(new HashObject[size])
{
}


HashTable::~HashTable()
{
	delete[] _table;
}

void HashTable::add(const std::string & key, const std::string & value)
{
	int index = hash(key);
	bool found = false;
	int dummy_index = -1;

	while (index < _size) 
	{
		if (_table[index].getKey() == HashObject::getNullKey() || _table[index].getKey() == key)
		{
			found = _table[index].getKey() == key;
			break;
		}
		if (dummy_index == -1 && _table[index].getKey() == HashObject::getDummyKey())
			dummy_index = index;

		index++;
	}

	if (found == false && dummy_index != -1)
	{
		_table[dummy_index].setKey(key);
		_table[dummy_index].setValue(value);
		return;
	}

	if (index < _size)
	{
		_table[index].setKey(key);
		_table[index].setValue(value);
		return;
	}
	

}

void HashTable::remove(const std::string & key)
{
	int index = hash(key);

	while (index < _size && _table[index].getKey() != HashObject::getNullKey())
	{
		if (_table[index].getKey() == key)
		{
			_table[index].setKey(HashObject::getDummyKey());
			_table[index].setValue("");
			return;
		}
		index++;
	}
}

std::string HashTable::get(const std::string & key) const
{
	int index = hash(key);

	while (index < _size && _table[index].getKey() != HashObject::getNullKey())
	{
		if (_table[index].getKey() == key)
		{
			return _table[index].getValue();
		}
		index++;
	}

	return "NOT_FOUND";
}

bool HashTable::exist(const std::string & key) const
{
	return get(key) != "NOT_FOUND";
}

int HashTable::getSize() const
{
	return _size;
}

int HashTable::hash(const std::string & key) const
{
	//debug
	//if (key == "a" || key == "aa")
	//	return 7;

	int index = 0;
	int base = 31;

	for (size_t i = 0; i < key.length(); ++i)
	{
		index = (index * base + key[i]);
	}


	return index % _size;
}
