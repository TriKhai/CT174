#include <stdio.h>

typedef struct {
	int key;
	float value;
} RecortType;

void swap(RecortType *x, RecortType *y) {
	RecortType tmp = *x;
	*x = *y;
	*y = tmp;
}

void printSort(RecortType arr[], int size) {
	for(int i=0; i<size; i++) {
		printf("%d %.2f\n", arr[i].key, arr[i].value);
	}
}

int count = 0;
void bubleSort(RecortType arr[], int size) {
	for(int i=0; i<size-1; i++) {
		for(int j=size-1; j>=i+1; j--) {
			count++;
			if(arr[j].key < arr[j-1].key) {
				swap(&arr[j], &arr[j-1]);
			}
		}
	}
}

int main() {
	freopen("data.txt", "r", stdin);
	RecortType arr[25];
	int size=0;
	while(2==scanf("%d%f", &arr[size].key, &arr[size].value)) {
		size++;
	}
	printf("Truoc khi sap xep:\n");
	printSort(arr, size);
	printf("\nSau khi sap xep:\n");
	bubleSort(arr, size);
	printSort(arr, size);
	printf("%d", count);
	return 0;
}
