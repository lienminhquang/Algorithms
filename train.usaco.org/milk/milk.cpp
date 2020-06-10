/*
ID: minhqua3
TASK: milk
LANG: C++
*/

//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
//#include <vector>
#include <queue>


struct Farmer
{
	int _p;
	int _a;

	Farmer(int p, int a) :_p(p), _a(a) {}
};

struct cmp {
	bool operator()(const Farmer& a, const Farmer& b)
	{
		return a._p > b._p;
	}
};



int main()
{
	std::ifstream fin("milk.in");
	std::ofstream fout("milk.out");

	int N, M;
	fin >> N >> M;

	//std::vector<Farmer> list_farmer;
	std::priority_queue<Farmer, std::vector<Farmer> ,cmp> list_farmer;


	for (int i = 0; i < M; i++)
	{
		int p, a;
		fin >> p >> a;
		list_farmer.push(Farmer(p, a));
	}

	//std::cout << list_farmer.top()._p;

	int cost = 0;
	while (N > 0)
	{
		int price = list_farmer.top()._p;
		int amount = list_farmer.top()._a;
		if (N < amount)
		{
			cost += price * N;
			N = 0;
			break;
		}
		else
		{
			N -=  amount;
			cost += price * amount;
			list_farmer.pop();
		}

	}

	fout << cost << "\n";

	fin.close();
	fout.close();

	//system("pause");
    return 0;
}

