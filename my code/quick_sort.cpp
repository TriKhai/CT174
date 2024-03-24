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
	for(int i=0; i<size; i++) {
		printf("%d %.2f\n", arr[i].key, arr[i].value);
	}
}

int findPivot(RecordType arr[], int start, int end) {
	int pos = start+1;
	while(pos <= end && arr[pos].key == arr[start].key) {
		pos++;
//		printf("loop");
	}
	if(pos > end) return -1;
	return (arr[pos].key > arr[start].key)?start:pos;//find lester element
}

int partition(RecordType arr[], int start, int end, int pivot) {
	int L = start;
	int R = end;
	while(L<=R) {
		while(arr[L].key<=pivot) L++;//> pivot
		while(arr[R].key>pivot) R--;//=pivot
		if(L<R) swap(&arr[L], &arr[R]);
	}
	return L;
}

void QuickSort(RecordType arr[], int start, int end) {
	int pivotIndex = findPivot(arr, start, end);
	int pivot;
	if(pivotIndex != -1) {
		pivot = arr[pivotIndex].key;
		int pos = partition(arr, start, end, pivot);
		QuickSort(arr, start, pos-1);
		QuickSort(arr, pos, end);
	}
}
int main() {
	freopen("data.txt", "r", stdin);
	RecordType arr[25];
	int size=0;
	while(2==scanf("%d%f", &arr[size].key, &arr[size].value)) {
		size++;
	}
	printf("Truoc khi sap xep:\n");
	printSort(arr, size);
	printf("\nSau khi sap xep:\n");
	QuickSort(arr, 0, size-1);
	printSort(arr, size);
	
	
	return 0;
}
