// BinarySearch.cpp : Defines the entry point for the console application.
//


#include <iostream>

int BinarySearch(int* arr, int min, int max, int x)
{
	int mid = 0;
	while(min <= max)
	{
		mid = min + (max - min) / 2;

		if (arr[mid] < x)
			min = mid + 1;
		else if (arr[mid] > x)
			max = mid - 1;
		else
			return mid;	
	}
	return -1;
}

int BinarySearch_Recursive(int* arr, int min, int max, int x)
{
	if (min > max) return -1;
	int mid = min + (max - min) / 2;
	if (arr[mid] < x) {
		min = mid + 1;
		BinarySearch_Recursive(arr, min, max, x);
	}
	else if (arr[mid] > x)
	{
		max = mid - 1;
		BinarySearch_Recursive(arr, min, max, x);
	}
	else
		return mid;
}

int main()
{
	int arr[] = {0, 5, 13, 19, 22, 41, 55, 68, 72, 81, 98};
	std::cout << BinarySearch_Recursive(arr, 0, 10, 81);

	system("pause");
    return 0;
}

