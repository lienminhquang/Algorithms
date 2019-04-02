/*
ID: minhqua3
TASK: transform
LANG: C++
*/

//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define N 10

void rotate90(char m[N][N], char out[N][N], int n)
{
	for (int h = 0; h < n; ++h)
	{
		for (int c = 0; c < n; ++c)
		{
			out[c][n - h - 1] = m[h][c];
		}
	}
}

void reflection(char m[N][N], char rs[N][N], int n)
{
	for (int h = 0; h < n; ++h)
	{
		for (int c = 0; c < n; ++c)
		{
			rs[h][n - c - 1] = m[h][c];
		}
	}
}

void print_matrix(char m[N][N], int n)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
		{
			cout << m[i][j];
		}
		cout << endl;
	}
}

bool equal_m(char a[N][N], char b[N][N], int n)
{
	for (int h = 0; h < n; ++h)
	{
		for (int c = 0; c < n; ++c)
		{
			if (a[h][c] != b[h][c]) return false;
		}
	}
	return true;
}

int main()
{
	ofstream fout("transform.out");
	ifstream fin("transform.in");
	
	char in[N][N];
	char out[N][N];
	int n = 0;
	fin >> n;
	for (int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
			fin >> in[i][j];
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			fin >> out[i][j];
	}
	
	

	char rs1[N][N];
	rotate90(in, rs1, n);
	if (equal_m(rs1, out, n))
	{
		fout << 1 << endl;
		return 0;
	}

	char rs2[N][N];
	rotate90(rs1, rs2, n);
	if (equal_m(rs2, out, n))
	{
		fout << 2 << endl;
		return 0;
	}

	rotate90(rs2, rs1, n);
	if (equal_m(rs1, out, n))
	{
		fout << 3 << endl;
		return 0;
	}

	reflection(in, rs1, n);
	if (equal_m(rs1, out, n))
	{
		fout << 4 << endl;
		return 0;
	}

	rotate90(rs1, rs2, n);
	if (equal_m(rs2, out, n))
	{
		fout << 5 << endl;
		return 0;
	}
	rotate90(rs2, rs1, n);
	if (equal_m(rs1, out, n))
	{
		fout << 5 << endl;
		return 0;
	}
	rotate90(rs1, rs2, n);
	if (equal_m(rs2, out, n))
	{
		fout << 5 << endl;
		return 0;
	}

	if (equal_m(in, out, n))
	{
		fout << 6 << endl;
		return 0;
	}

	fout << 7 << endl;


	

    return 0;
}

