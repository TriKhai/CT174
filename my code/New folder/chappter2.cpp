#include "stdio.h"


typedef int keytType;
typedef float otherType;
typedef struct {
	keytType key;
	otherType value;
} recordType;

void swap(recordType *x, recordType *y) {
	recordType tmp = *x;
	*x = *y;
	*y = tmp;
}

//cac thuat toan sap xep don gian:seletion sort, insertion sort, buble sort
void SeletionSort(recordType arr[], int size) {
	printf("Select Sort\n");
	int lowIndex;
	keytType lowKey;
	for(int i=0; i<size-1; i++) {
		lowIndex = i;
		lowKey = arr[i].key;
		for(int j=i; j<size; j++) {
			if(lowKey > arr[j].key) {
				lowIndex = j;
				lowKey = arr[j].key;
			}
		}
		if(i != lowIndex) {
			swap(&arr[i], &arr[lowIndex]);
		}
	}
} 

void InsertionSort(recordType arr[], int size) {
	printf("Insertion Sort\n");
	for(int i=1; i<size; i++) {
		int j=i;
		while(j>0 && arr[j].key < arr[j-1].key) {
			swap(&arr[j], &arr[j-1]);
			j--;
		}
	}
}

void BubleSort(recordType arr[], int size) {
	printf("Buble Sort\n");
	for(int i=0; i<size-1; i++) {
		for(int j=size-1; j>i; j--) {
			if(arr[j].key < arr[j-1].key) {
				swap(&arr[j], &arr[j-1]);
			}
		}
	}
}


//cac thuat toan sap xep phut tap
 

int main() {
	freopen("data.txt", "r", stdin);
	recordType arr[50];
	int size = 0;
	while(2 == scanf("%d%f", &arr[size].key, &arr[size].value)) {
		size++;
	}
//	SeletionSort(arr, size);
//	InsertionSort(arr, size);
	BubleSort(arr, size);
	for(int i=0; i<size; i++) {
		printf("%d %.2f\n", arr[i].key, arr[i].value);
	}
	return 0;
}
