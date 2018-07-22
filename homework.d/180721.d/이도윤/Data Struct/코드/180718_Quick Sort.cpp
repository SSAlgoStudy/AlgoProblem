#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 11

void Quick_Sort(int *, int, int);
void Swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {

	int arr[MAX_SIZE];

	for (int i = 0; i < MAX_SIZE; i++)
		scanf("%d", &arr[i]);

	Quick_Sort(arr, 0, MAX_SIZE-1);

	for (int i = 0; i < MAX_SIZE; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}

void Quick_Sort(int *arr, int left, int right) {
	// 인덱스 교차시 재귀에서 벗어남
	if (left >= right) return;

	// pivot은 배열 오른쪽 끝으로 설정.
	int pivot = right;

	// l은 left, r은 피봇 바로 왼쪽으로 설정.
	int l = left;
	int r = right - 1;

	while (l < r) {

		// left는 피봇보다 큰 놈이 나올 때까지 증가
		while (l < r && arr[pivot] > arr[l]) l++;
		
		// right는 피봇보다 작은 놈이 나올 때까지 감소
		while (l < r && arr[pivot] < arr[r]) r--;

		// 두 인덱스가 교차하지 않았는지 체크한 후, left와 right의 값 Swap
		if (l < r) Swap(&arr[l], &arr[r]);
	}

	// 위에서 정렬이 다 끝나면 pivot과 교차지점 Swap
	Swap(&arr[pivot], &arr[l]);

	// 재귀로 이분할
	Quick_Sort(arr, left, l - 1);
	Quick_Sort(arr, l + 1, right);
}