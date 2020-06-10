// friday.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"


#include <iostream>
#include <fstream>
#include <string>

/*
ID: minhqua3
TASK: friday
LANG: C++
*/


//moi nam co 12 thang => co 12 ngay 13
//mang sau chua ngay 13 trong thang la ngay thu bao nhieu trong nam nhuan
const int Nhuan[12] = { 13, 44, 73, 104, 134, 165, 195, 226, 257, 287, 318, 348 };

//mang sau chua ngay 13 trong thang la ngay thu bao nhieu trong nam ko nhuan
const int Ko_Nhuan[12] =  {13, 44, 72, 103, 133, 164, 194, 225, 256, 286, 317, 347};

//void pre_compute();



bool la_nhuan(int year)
{
	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	
}



//thu_bat_dau = [1,2,..,7]
void tinh_so_ngay13(int nam, int thu_bat_dau, int* _SoNgay13)
{
	bool nhuan = la_nhuan(nam);
	int count = 0;

	for (int i = 0; i < 12; ++i)
	{
		count++;
		if (nhuan)
		{
			int thu_cua_ngay_13 = (Nhuan[i] % 7 + thu_bat_dau) % 7;
			_SoNgay13[thu_cua_ngay_13]++;
		}
		else
		{
			int thu_cua_ngay_13 = (Ko_Nhuan[i] % 7 + thu_bat_dau) % 7;
			_SoNgay13[thu_cua_ngay_13]++;
		}

		
	}
	
}

int SoNgay13[7] = { 0 };

int main()
{
	std::ofstream fout("friday.out");
	std::ifstream fin("friday.in");

	int N = 0;
	fin >> N;

	
	

	//pre_compute();
	int thu_bat_dau = 1;
	for (int i = 0; i < N; ++i)
	{
		
		int nam = 1900 + i;
		tinh_so_ngay13(nam, thu_bat_dau, SoNgay13);
		if (la_nhuan(nam))
		{
			thu_bat_dau += 366 % 7;
		}
		else {
			thu_bat_dau += 365 % 7;
		}
		thu_bat_dau %= 7;
	}

	for (int i = 0; i < 7 - 1; ++i)
		fout << SoNgay13[i] << " ";
	fout << SoNgay13[6] << std::endl; 

	fin.close();
	fout.close();

    return 0;
}



//void pre_compute()
//{
//	int tong_so_ngay = 0;
//	//tinh mang ngay thu 13 ko nhuan
//	for (int i = 1; i < 13; ++i)
//	{
//		
//		int so_ngay = 0;
//		switch (i)
//		{
//		case 2:
//			so_ngay = 28;
//			break;
//		case 9:
//		case 4:
//		case 6:
//		case 11:
//			so_ngay = 30;
//			break;
//		default:
//			so_ngay = 31;
//			break;
//		}
//
//		Ko_Nhuan[i - 1] = tong_so_ngay + 13;
//		tong_so_ngay += so_ngay;
//
//	}
//
//	tong_so_ngay = 0;
//	//tinh mang ngay thu 13 nhuan
//	for (int i = 1; i < 13; ++i)
//	{
//		
//		int so_ngay = 0;
//		switch (i)
//		{
//		case 2:
//			so_ngay = 29;
//			break;
//		case 9:
//		case 4:
//		case 6:
//		case 11:
//			so_ngay = 30;
//			break;
//		default:
//			so_ngay = 31;
//			break;
//		}
//
//		Nhuan[i - 1] = tong_so_ngay + 13;
//		tong_so_ngay += so_ngay;
//
//	}
//}