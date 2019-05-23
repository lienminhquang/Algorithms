/*
ID: minhqua3
TASK: dualpal
LANG: C++
*/

//#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

//vi bai toan can tim so pal nen se xuat ra chuoi so base x nguoc so voi thuc ve de thuan tien
std::string toBase(int x, int base)
{
	std::string result = "";
	while (x > 0)
	{
		int nguyen = x / base;
		int du = x % base;
		x = nguyen;

		//chuyen sang ky tu
		du += '0';

		result += du;
	}


	
	return result;
}

bool isPal(const std::string& str)
{

	int size = str.size();
	for (int i = 0; i < size / 2; i++)
	{
		if (str[i] != str[size - 1 - i]) return false;
	}

	return true;
}


int main()
{
	std::ofstream fout("dualpal.out");
	std::ifstream fin("dualpal.in");

	int N, S;
	fin >> N >> S;

	//std::cout << N << "\n" << S << "\n";
	//std::cout << toBase(21, 2) << "\n";
	//std::cout << isPal(toBase(21, 2)) << "\n";

	int count = 0;
	int x = S + 1;
	while (count < N)
	{
		int tmp = 0;
		for (int i = 2; i <= 10; i++)
		{
			if (isPal(toBase(x, i)))
			{
				tmp++;
				if (tmp == 2) break;
			}
		}
		if (tmp == 2)
		{
			count++;
			fout << x << "\n";
		}

		x++;
	}

	fout.close();
	fin.close();

	//system("pause");
    return 0;
}

