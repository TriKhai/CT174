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

void InsertionSort(RecordType arr[], int size) {
	for(int i=1; i<size; i++) {
		int pos = i;
		while(pos>0 && arr[pos].key < arr[pos-1].key) {
			swap(&arr[pos], &arr[pos-1]);
			pos--;
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
	
	printf("Thuat toan Insertion Sort\n");
	printf("Truoc khi sap xep:\n");
	printSort(arr, size);
	printf("\nSau khi sap xep:\n");
	InsertionSort(arr, size);	
	printSort(arr, size);
	
	return 0;
}
