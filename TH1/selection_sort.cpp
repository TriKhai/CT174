#include <stdio.h>

typedef struct {
	int key;
	float value;
} RecordType;

void swap(RecordType *x, RecordType *y) {
	RecordType tmp = *x;
	*x = *y;
	*y = tmp;
}

void printSort(RecordType arr[], int size) {
	int i;
	for(i=0; i<size; i++) {
		printf("%d %.2f\n", arr[i].key, arr[i].value);
	}
}

void SelectionSort(RecordType arr[], int size) {
	for(int i=0; i<size-1; i++) {
		int lowKey = arr[i].key;
		int lowIndex = i;
		for(int j=i+1; j<size; j++) {
			if(lowKey > arr[j].key) {
				lowIndex = j;
				lowKey = arr[j].key;
			}
		}
		if(lowIndex != i) {
			swap(&arr[lowIndex], &arr[i]);
		}
	}
}

int main(){
	freopen("data.txt", "r", stdin);
	RecordType arr[25];
	int size = 0;
	while(2 == scanf("%d%f", &arr[size].key, &arr[size].value)) {
		size++;
	}
	printf("Thuat toan Selection Sort\n");
	printf("Truoc khi sap xep:\n");
	printSort(arr, size);
	printf("\nSau khi sap xep:\n");
	SelectionSort(arr, size);	
	printSort(arr, size);
	
	return 0;
}
