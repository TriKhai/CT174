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

void BubleSort(RecordType arr[], int size) {
	for(int i=0; i<size-1; i++) {
		for(int j=size-1; j>=i+1; j--) {
			if(arr[j].key < arr[j-1].key) {
				swap(&arr[j], &arr[j-1]);
			}
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
	printf("Thuat toan Buble Sort\n");
	printf("\nDu lieu truoc khi sap xep:\n");
	printSort(arr, size);
	printf("\nDu lieu sau khi sap xep:\n");
	BubleSort(arr, size);	
	printSort(arr, size);
	
	return 0;
}
