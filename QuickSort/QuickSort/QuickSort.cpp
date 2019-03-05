// QuickSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

void swap(int& a, int& b) { int c = a; a = b; b = c; }

int Partition(int* arr, int l, int r)
{
	int pivot = arr[l];
	while (r > l)
	{
		while (arr[l] < pivot) l++;
		while (arr[r] > pivot) r--;
		if (l < r) 
		{
			swap(arr[l], arr[r]);
			if (arr[l] == arr[r])
			{
				l++;
				//r--;
			}
		}
		else
			return l;
		
	}
}

void QuickSort(int* arr, int l, int r)
{
	if (l < r - 1) 
	{
		int q = Partition(arr, l, r);
		QuickSort(arr, l, q);
		QuickSort(arr, q + 1, r);
	}
	else if (l = r - 1)
	{
		Partition(arr, l, r);
	}
}

void printArr(int* arr, int n)
{
	std::cout << "Array: ";
	for (int i = 0; i < n; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

void QuickSort2(int* arr, int L, int H)
{
	if (L >= H) return;
	int pivot = arr[L];
	int i = L, j = H;
	while (i < j)
	{
		while (arr[i] < pivot) i++;
		while (arr[j] > pivot) j--;

		if (i <= j)
		{
			if (i < j)
				swap(arr[i], arr[j]);
			i++;
			j--;
		}
		//printArr(arr, 11);
	}

	QuickSort2(arr, L, j);
	QuickSort2(arr, i, H);

}

int main()
{
	int arr[] = { 1,4,53,2,35,4,2,14,35,12,34 };
	
	printArr(arr, 11);
	QuickSort2(arr, 0, 10);
	printArr(arr, 11);

	system("pause");
    return 0;
}

