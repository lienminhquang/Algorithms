// Heap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void print_array(int* A, int n)
{
	std::cout << "A: ";
	for (int i = 0; i < n; i++)
	{
		std::cout << A[i] << " ";
	}
	std::cout << "\n";
}

void max_heapify(int* A, int i, int size)
{
	if (2 * i >= size) return;
	if (A[2 * i] > A[i])
	{
		if (2 * i + 1 < size && A[2 * i] < A[2 * i + 1])
		{
			swap(A[2 * i + 1], A[i]);
			max_heapify(A, 2 * i + 1, size);
		}
		else
		{
			swap(A[2 * i], A[i]);
			max_heapify(A, 2 * i, size);
		}
	}
	else if(2 * i + 1 < size && A[2 * i + 1] > A[i])
	{
		swap(A[2 * i + 1], A[i]);
		max_heapify(A, 2 * i + 1, size);
	}
}

void build_max_heap(int* A, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		max_heapify(A, i, n);
		//print_array(A, n);
	}
}

int get_max(int* heap) { return heap[0]; }
int extract_max(int* heap, int size)
{
	int max = heap[0];
	swap(heap[0], heap[size - 1]);
	max_heapify(heap, 0, size - 1);
	heap[size - 1] = -999;
	return max;
}




int main()
{
	int size = 10;
	int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	build_max_heap(A, size);
	print_array(A, size);

	while (size > 0)
	{
		std::cout << extract_max(A, size) << " ";
		size--;
	}

	system("pause");
    return 0;
}

