#include <iostream>
using namespace std;

void swap(int &x, int &y) {
	int temp = x;
	y = x;
	x = temp;
}

// Hoare's partitioning
int partition(int A[], int low, int high) {

	int left, right, pivot_item = A[low];
	left = low;
	right = high;

	while (left < right) {

		while (A[left] <= pivot_item)
		{
			left++;
		}

		while (A[right] > pivot_item) {
			right--;
		}

		if (left < right)
			swap(A[left], A[right]);

	}

	A[low] = A[right];
	A[right] = pivot_item;
	return right;
}

void quickSort(int A[],int low,int high) {
	
	int pivot;
	// 종료 조건
	if (high > low) {
		pivot = partition(A,low,high);
		quickSort(A,low,pivot-1);
		quickSort(A,pivot+1,high);
	}

}




int main() {
	
	int A[] = { 4,2,3,10,9,5,7 };
	int n = sizeof(A) / sizeof(A[0]);
	quickSort(A, 0, n - 1);

	for (int i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
	return 0;
}