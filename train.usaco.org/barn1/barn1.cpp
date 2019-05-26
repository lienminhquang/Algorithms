/*
ID: minhqua3
TASK: barn1
LANG: C++
*/

//#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>



std::vector<int> occupied;


int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

int main()
{
	std::ifstream fin("barn1.in");
	std::ofstream fout("barn1.out");

	int M, S, C;
	fin >> M >> S >> C;
	
	if (M >= C)
	{
		fout << C << "\n";
	}
	else
	{

		for (int i = 0; i < C; i++)
		{
			int tmp;
			fin >> tmp;
			occupied.push_back(tmp);
		}

		qsort(&occupied[0], occupied.size(), sizeof(occupied[0]), compare);

		std::priority_queue<int> m_queue;

		for (int i = 1; i < occupied.size(); i++)
		{
			m_queue.push(occupied[i] - occupied[i - 1]);
		}


		int min_stall = M;
		for (int i = 1; i < M; i++)
		{
			m_queue.pop();
		}

		while (!m_queue.empty())
		{
			min_stall += m_queue.top();
			m_queue.pop();
		}

		fout << min_stall << "\n";
	}
	//system("pause");

	fin.close();
	fout.close();

    return 0;
}

