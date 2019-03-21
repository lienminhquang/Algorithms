/*
ID: minhqua3
TASK: test
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ofstream fout ("test.out");
	std::ifstream fin ("test.in");
	int a,b;
	fin >> a >> b;
	fout << a + b << std::endl;
	
	return 0;
}