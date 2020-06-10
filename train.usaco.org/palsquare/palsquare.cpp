/*
ID: minhqua3
TASK: palsquare
LANG: C++
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


void reverseStr(string& str)
{
	int n = str.length();

	// Swap character starting from two 
	// corners 
	for (int i = 0; i < n / 2; i++)
		swap(str[i], str[n - i - 1]);
}

//chuyen tu co so 10 sang co so base
string chuyencoso(int x, int base)
{

	string rs = "";


	while (x > 0)
	{
		int tmp = x % base;
		if (tmp <= 9) rs += ('0' + tmp);
		else rs += ('A' + (tmp - 10));


		x /= base;
	}

	reverseStr(rs);
	//cout << rs;
	return rs;
}

bool isPal(const string& num)
{
	int size = num.size();
	int mid = num.size() / 2 ;
	for (int i = 0; i < mid; ++i)
		if (num[i] != num[size - 1 - i]) return false;
	return true;
}


int main()
{
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");

	int base = 0;
	fin >> base;

	for (int i = 1; i <= 300; i++)
	{
		int square = i * i;
		string rs = chuyencoso(square, base);
		if (isPal(rs))
			fout << chuyencoso(i, base) << " " << rs << "\n";
	}
    return 0;
}

