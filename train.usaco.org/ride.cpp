/*
ID: minhqua3
TASK: gift1
LANG: C++
*/

#include <iostream>
#include <string>
#include <fstream>

struct Friend {
	int money;
	std::string name;

	Friend* next;

	Friend(const std::string& name)
		:money(0)
		, name(name)
		, next(nullptr) {}
};

Friend* head = nullptr;
Friend* tail = nullptr;

void add(Friend* f)
{
	if (head == nullptr)
		head = tail = f;
	else {
		tail->next = f;
		tail = f;
	}
}

Friend* find(const std::string& name)
{
	Friend* rs = head;
	while (rs != nullptr)
	{
		if (rs->name == name)
			return rs;
		rs = rs->next;
	}
}

void delete_list()
{
	Friend* f = head;
	Friend* next;
	while (f != nullptr)
	{
		next = f->next;
		delete f;
		f = next;
	}
}

int main()
{
	std::ofstream fout("gift1.out");
	std::ifstream fin("gift1.in");

	int NP = 0;
	fin >> NP;

	for (int i = 0; i < NP; ++i)
	{
		std::string s;
		fin >> s;
		Friend* f = new Friend(s);
		add(f);
	}
	for (int i = 0; i < NP; ++i)
	{
		std::string name;
		int m = 0, NG = 0;
		fin >> name >> m >> NG;

		if (m == 0 || NG == 0) continue;

		Friend* giver = find(name);

		

		for (int j = 0; j < NG; ++j)
		{
			std::string reci_name;
			fin >> reci_name;
			Friend* reci = find(reci_name);

			reci->money += (int)(m / NG);

		}

		giver->money -= m;
		giver->money += m % NG;

	}

	Friend* f = head;
	while (f != nullptr)
	{
		fout << f->name << " " << f->money << std::endl;
		f = f->next;
	}

	delete_list();

	return 0;
}