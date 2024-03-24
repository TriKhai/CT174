#include "stdio.h"

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

//void pushDown(RecordType arr[], int first, int last) {
//	int r = first;
//	while(r<=(last-1)/2) {
//		if(last == 2*r+1) {//chi 1 con trai
//			if(arr[r].key < arr[last].key) {
//				swap(&arr[r], &arr[last]);
//			}
//			r = last;
//		} else if(arr[r].key < arr[2*r+1].key && arr[2*r+1].key>=arr[2*r+2].key) {
//			swap(&arr[r], &arr[2*r+1]);
//			r = 2*r+1;
//		} else if(arr[r].key < arr[2*r+2].key) {
//			swap(&arr[r], &arr[2*r+2]);
//			r = 2*r+2;
//		} else {
//			r = last;
//		}
//	}
//}

void pushDown(RecordType arr[], int first, int last) {
	int cur = first;
	int left = cur*2+1;
	int right = cur*2+2;
	if(left < last && arr[cur].key < arr[left].key) {
		cur = left;
	}
	if(right < last && arr[cur].key < arr[right].key) {
		cur= right;
	}
	if(cur != first) {
		swap(&arr[cur], &arr[first]);
		pushDown(arr, cur, last);
	}
}

void HeapSort(RecordType arr[], int n) {
	for(int i=(n-2)/2; i>=0; i--) {
		pushDown(arr, i, n-1);
	}
	for(int i=n-1; i>=2; i--) {
		swap(&arr[0], &arr[i]);
		pushDown(arr, 0, i-1);
	}
	swap(&arr[0], &arr[1]);
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
	HeapSort(arr, size);
	printSort(arr, size);
	
	
	return 0;
}
