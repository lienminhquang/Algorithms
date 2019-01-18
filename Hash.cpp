#include <iostream>
#include <string>

#define Empty_Key -999999
const int m = 100;
struct Pair
{

	Pair()
	{
		key = Empty_Key;
	}

	int key;
	std::string value;
};

Pair hash_table[m];

int hash(int key)
{
	return key % m;
}

//su dung tham do tuyen tinh
void add(int key, std::string value, Pair* hash_table)
{
	int index = hash(key);
	if(hash_table[index].value == value && hash_table[index].key == key)
		return;
	
	while(hash_table[index].value != "")
	{

		if(hash_table[index].key == key)
		{
			hash_table[index].value = value;
			std::cout << "chen o vi tri trung " << index;
			return;
		}

		index++;
		if(index >= m)
		{
			std::cout << "Cannot add item into hash table";
			return;
		}
	}

	hash_table[index].value = value;
	hash_table[index].key = key;
}

std::string search(int key, Pair* hash_table)
{
	int index = hash(key);
	while(hash_table[index].key != Empty_Key && index < m)
	{
		if(hash_table[index].key == key)
		{
			
			return hash_table[index].value;
		}
		index++;
	}
// std:: cout << "index: " << index;
	return "__Empty__";
}

void delete_(int key, Pair* hash_table)
{
	int index = hash(key);
	while(hash_table[index].key != Empty_Key && index < m)
	{
		if(hash_table[index].key == key)
		{
			hash_table[index].key = Empty_Key;
			hash_table[index].value = "";

			
				std::cout << "rehash";
				//rehash
				Pair t[m];
				for(int i = 0; i < m; ++i)
				{
					if(hash_table[i].key != Empty_Key)
						add(hash_table[i].key, hash_table[i].value, t);
				}

				for(int i = 0; i < m; ++i)
				{
					hash_table[i].key = t[i].key;
					hash_table[i].value = t[i].value;
				}
			
			return;
		}
		index++;
	}
}

void printDebug(Pair* hash_table)
{
	for(int i = 0; i < m; i++)
	{
		std::cout << "\n" << i << " : Key: " << hash_table[i].key << " ----> value: " << hash_table[i].value;
	}
}


int main()
{

	printDebug(hash_table);
	add(100, "Lien", hash_table);
	add(101, "Minh", hash_table);
	add(102, "Quang", hash_table);
	add(200, "Nguyen", hash_table);

	std::cout << hash_table[0].value << hash_table[1].value << hash_table[2].value << hash_table[3].value;
	
	delete_(2000, hash_table);
	
	std::cout << " ---- " << hash_table[0].value << hash_table[1].value << hash_table[2].value << hash_table[3].value;
	printDebug(hash_table);
	return 0;
}