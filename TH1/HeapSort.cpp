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

//Heap Sort
void PushDown(RecordType arr[], int first, int last) {
	int r = first;
	while(r < (last-1)/2) {
		if(last == 2*r+1) { // chi co 1 con trai
			if(arr[r].key < arr[last].key) {
				swap(&arr[r], &arr[last]);
			}
			r = last;
		} else {
			if(arr[r].key < arr[2*r+1].key && arr[2*r+1].key >= arr[2*r+2].key) {
				swap(&arr[r], &arr[2*r+1]);
				r = 2*r+1;
			} else {
				if(arr[r].key < arr[2*r+2].key) {
					swap(&arr[r], &arr[2*r+2]);
					r = 2*r+2;
				} else {
					r = last;
				}
			}
		}
	}
}

// recurse
//void PushDown(RecordType arr[], int first, int last) {
//	int cur = first;
//	int L = cur*2+1;
//	int R = cur*2+2;
//	if(L < last && arr[L].key < arr[cur].key) {
//		cur = L;
//	} 
//	if(R < last && arr[R].key < arr[cur].key) {
//		cur = R;
//	} 
//	if(cur != first) {
//		swap(&arr[cur], &arr[first]); 
//		PushDown(arr, cur, last);
//	}
//}

void HeapSort(RecordType arr[], int size) {
	//1. tao heap
	for(int i = (size-2)/2; i>=0; i--) {
		PushDown(arr, i, size-1);
	}
	//2.
	for(int i=size-1; i>=2; i--) {
		swap(&arr[0], &arr[i]);
		PushDown(arr, 0, i-1);
	}
	swap(&arr[0], &arr[1]);
}

int main(){
	freopen("data.txt", "r", stdin);
	RecordType arr[25];
	int size = 0;
	while(2 == scanf("%d%f", &arr[size].key, &arr[size].value)) {
		size++;
	}
	printf("Thuat toan Heap Sort\n");
	printf("\nDu lieu truoc khi sap xep:\n");
	printSort(arr, size);
	printf("\nDu lieu sau khi sap xep:\n");
	HeapSort(arr, size);	
	printSort(arr, size);
	
	return 0;
}
