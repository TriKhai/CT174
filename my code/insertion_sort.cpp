#include "stdio.h"

typedef struct {
	int key;
	float value;
} RecorType;

void swap(RecorType *x, RecorType *y) {
	RecorType tmp = *x;
	*x = *y;
	*y = tmp;
}

void printSort(RecorType arr[], int size) {
	for(int i=0; i<size; i++) {
		printf("%d %.2f\n", arr[i].key, arr[i].value);
	}
}
int count = 0;
void InsertionSort(RecorType arr[], int size) {
	for(int i=0; i<size; i++) {
		int j=i;
		while(j > 0 && arr[j].key < arr[j-1].key) {
			count++;
			swap(&arr[j], &arr[j-1]);
			j--;
		}
	}
}

int main() {
	freopen("data.txt", "r", stdin);
	RecorType arr[25];
	int size=0;
	while(2 == scanf("%d%f", &arr[size].key, &arr[size].value)) {
		size++;
	}
	printf("Truoc khi sap xep:\n");
	printSort(arr, size);
	printf("\nSau khi sap xep:\n");
	InsertionSort(arr, size);
	printSort(arr, size);
	printf("%d", count);
	return 0;
	
}
