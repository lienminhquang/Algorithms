// HashTable.cpp : Defines the entry point for the console application.
//
#include "HashTable.h"
#include <iostream>

int main()
{
	HashTable ht(1000);

	ht.add("a", "Lien Minh Quang");
	//ht.remove("a");
	ht.add("aa", "Lam Xung");
	ht.remove("a");
	ht.add("aa", "Vip");
	ht.add("a", "Minh Quang");
	std::string found = ht.get("aa");
	bool b = ht.exist("adfa");
	b = ht.exist("a");
	ht.add("bd", "bc");
    return 0;
}

