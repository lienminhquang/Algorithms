#pragma once
#include "HashObject.h"


class HashTable
{
public:
	explicit HashTable(int size);
	~HashTable();

	void add(const std::string& key,const std::string& value);
	void remove(const std::string& key);
	std::string get(const std::string& key) const;
	bool exist(const std::string& key) const;

	int getSize() const;

private:
	HashObject* _table;
	int _size;

	int hash(const std::string& key) const;

};

