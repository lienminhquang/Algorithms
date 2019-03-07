#include <stdio.h>

void swap(int* a, int* b){ int c = *a; *a = *b; *b = c; }

void heapify(int* arr, int n, int index)
{
	if(index >= n/2) return;
	int left_child = index * 2 + 1;
	int right_child = index * 2 + 2;
	int has_left = left_child < n;
	int has_right = right_child < n;
	int swap_index = index;
	if(has_left && has_right)
		if(arr[left_child] > arr[right_child]) swap_index = left_child;
		else swap_index = right_child;
	else if(has_left)
		swap_index = left_child;
	else if(has_right)
		swap_index = right_child;

	if(arr[index] < arr[swap_index])
	{
		swap(&arr[index], &arr[swap_index]);
		heapify(arr, n ,swap_index);
	}
}

void build_max_heap(int* arr, int n)
{
	for(int i = n / 2 - 1; i >= 0; --i)
	{
		heapify(arr, n, i);
	}
}

int extract_max(int* arr, int *n)
{
	int max = arr[0];
	arr[0] = arr[*n-1];
	*n--;
	heapify(arr, *n, 0);
	return max;
}

void heap_sort(int* arr, int n)
{
	build_max_heap(arr, n);
	for(int i = n-1; i > 0; --i)
	{
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}

void print_arr(int* arr, int n)
{
	printf("Array: ");
	for(int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int n = 11;
	int arr[11] = {1, 4, 5, 3, 7, 2, 5, 1, 3, 9, 10};
	//build_max_heap(arr, n);
	//printf("Max: %d\n", extract_max(arr, &n));

	print_arr(arr, n);
	heap_sort(arr, n);
	print_arr(arr, n);

	//extract_max(arr, &n);
	return 0;
}
