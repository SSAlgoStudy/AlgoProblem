#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 11

void Median_of_Three(int *, int, int, int);
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

	Quick_Sort(arr, 0, MAX_SIZE - 1);

	for (int i = 0; i < MAX_SIZE; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}

void Median_of_Three(int *arr, int left, int mid, int right) {
	int first, second, third;

	if (arr[left] > arr[mid]) {

	}
}

void Quick_Sort(int *arr, int left, int right) {
	// 인덱스 교차시 재귀에서 벗어남
	if (left >= right) return;

	// (left+right)/2로 해버리면 int형 범위 넘어갈 수 있으므로 이를 방지하는 mid 설정
	int mid_idx = left + (right - left) / 2;

	// 왼쪽, 가운데, 오른쪽 먼저 정렬. 그 이후 정렬은 3개 초과인 경우에만 진행.
	// 3개 이하인 경우에는 이 정렬만으로 해결 가능하기 때문.
	Median_of_Three(arr, left, mid_idx, right);


	if (right - left + 1 > 3) {
		// pivot은 배열 오른쪽 끝으로 설정.
		int pivot = right;

		// 시작 전에 정렬된 가운데 값을 pivot으로 설정한 후, 맨 오른쪽으로 옮김.
		Swap(&arr[pivot], &arr[right - 1]);

		// l은 left+1, r은 피봇 바로 왼쪽으로 설정.
		int l = left + 1;
		int r = right - 2;

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
		Quick_Sort(arr, left + 1, l - 1);
		Quick_Sort(arr, l + 1, right-1);
	}
}