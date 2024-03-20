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

//Quick Sort
int FindPivot(RecordType arr[], int start, int end) {
	int pos = start+1;
	while(start <= end && arr[pos].key == arr[start].key) {
		pos++;
	}
	if(pos>end) return -1;
	return (arr[pos].key > arr[start].key)?pos:start;
}

int Partition(RecordType arr[], int start, int end, int pivot) {
	int L = start, R = end;
	while(L<=R) {
		while(arr[L].key < pivot) L++;
		while(arr[R].key >= pivot) R--;
		if(L < R) {
			swap(&arr[L], &arr[R]);
		}
	}
	return L;
}

void QuickSort(RecordType arr[], int start, int end) {
	int pivotIndex = FindPivot(arr, start, end);
	if(pivotIndex != -1) {
		int pivot = arr[pivotIndex].key;
		int pos = Partition(arr, start, end, pivot);
		QuickSort(arr, start, pos-1);
		QuickSort(arr, pos, end);
	}
}

int main(){
	freopen("data.txt", "r", stdin);
	RecordType arr[25];
	int size = 0;
	while(2 == scanf("%d%f", &arr[size].key, &arr[size].value)) {
		size++;
	}
	printf("Thuat toan Quick Sort\n");
	printf("\nDu lieu truoc khi sap xep:\n");
	printSort(arr, size);
	printf("\nDu lieu sau khi sap xep:\n");
	QuickSort(arr, 0, size-1);	
	printSort(arr, size);
	
	return 0;
}
