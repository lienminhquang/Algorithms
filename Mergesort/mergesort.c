#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int l, int mid, int h)
{
	int* result =(int*)malloc(sizeof(int) * (h - l));
	int i = l, j = mid;
	int index = 0;
	while(1)
	{
		if(i < mid && j <= h && arr[i] < arr[j])
		{
			result[index] = arr[i];
			i++;
		}
		else if(i < mid && j <= h && arr[i] >= arr[j])
		{
			result[index] = arr[j];
			j++;
		}
		else if(i < mid)
		{
			result[index] = arr[i];
			i++;
		}
		else if(j <= h)
		{
			result[index] = arr[j];
			j++;
		}
		else{
			break;
		}
		++index;
	}

	for(int k = 0; k <= h - l; k++){
		arr[l + k] = result[k];
	}
	print_arr(arr);
	free(result);
}

void mergesort(int* arr, int l, int h)
{
	if(l >= h) return;

	int mid = (h + l) / 2;
	mergesort(arr, l, mid - 1);
	mergesort(arr, mid, h);
	merge(arr, l, mid, h);
}

void print_arr(int* arr, int size)
{
	printf("Arr: ");
	for(int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main(){
	int arr[] = {1, 34, 55, 23, 1, 43, 234, 55, 11};
	print_arr(arr, 9);
	mergesort(arr, 0, 8);
	print_arr(arr, 9);
	return 0;
}
