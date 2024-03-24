#include <stdio.h>

typedef int keyType;
typedef float otherType;
typedef struct {
	keyType key;
	otherType value;
} RecordType;

void swap(RecordType *x, RecordType *y) {
	RecordType tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void printData(RecordType arr[], int size) {
	for(int i=0; i<size; i++) {
		printf("%d %.2f\n", arr[i].key, arr[i].value);
	}
}

int count=0;
void SelectionSort(RecordType arr[], int size) {
	for(int i=0; i<size-1; i++) {
		int lowKey = arr[i].key;
		int lowIndex = i;
		for(int j=i+1; j<size; j++) {
			count++;
			if(arr[j].key < lowKey) {
				lowKey = arr[j].key;
				lowIndex = j;
			}
		} 
		if(lowIndex != i) {
			swap(&arr[i], &arr[lowIndex]);
		}
	}
}


int main() {
	freopen("data.txt", "r", stdin);
	RecordType arr[25];
	int n=0;
	while(2 == scanf("%d%f", &arr[n].key, &arr[n].value)) {
		n++;
	}
	printf("Truoc khi sap xep\n");
	printData(arr, n);
	SelectionSort(arr, n);
	printf("\nSau khi sap xep\n");
	printData(arr, n);
	printf("%d", count);
	return 0;
}
