#include <stdio.h>
#include <stdlib.h>

//k[0..n-1], 0 <= k[i] < m
//m[0..m-1]
void counting_sort(int* k, int n, int m)
{
	int* v = malloc(sizeof(int)*m);
	for(int i = 0; i < m; ++i) v[i] = 0;

	for(int i = 0; i < n; ++i) v[k[i]]++;

	v[0]--;
	for(int i = 1; i < m; ++i) v[i] += v[i-1];

	int* x = malloc(sizeof(int)*n);
	for(int i = n-1; i >= 0; --i)
	{
		x[v[k[i]]] = k[i];
		v[k[i]]--;
	}

	for(int i = 0; i < n; ++i) k[i] = x[i];

	free(x);
	free(v);
}

void print_arr(int* arr, int n)
{
	printf("Arr: ");
	for(int i = 0; i < n; ++i) printf("%d ", arr[i]);
	printf("\n");
}


const int N = 10;
const int M = 7;

void main()
{
	int arr[] = {3,1,4,6,2,1,2,3,3,4};
	print_arr(arr, N);
	counting_sort(arr, N, M);
	print_arr(arr, N);
}
