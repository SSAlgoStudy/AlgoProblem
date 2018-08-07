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
	// �ε��� ������ ��Ϳ��� ���
	if (left >= right) return;

	// (left+right)/2�� �ع����� int�� ���� �Ѿ �� �����Ƿ� �̸� �����ϴ� mid ����
	int mid_idx = left + (right - left) / 2;

	// ����, ���, ������ ���� ����. �� ���� ������ 3�� �ʰ��� ��쿡�� ����.
	// 3�� ������ ��쿡�� �� ���ĸ����� �ذ� �����ϱ� ����.
	Median_of_Three(arr, left, mid_idx, right);


	if (right - left + 1 > 3) {
		// pivot�� �迭 ������ ������ ����.
		int pivot = right;

		// ���� ���� ���ĵ� ��� ���� pivot���� ������ ��, �� ���������� �ű�.
		Swap(&arr[pivot], &arr[right - 1]);

		// l�� left+1, r�� �Ǻ� �ٷ� �������� ����.
		int l = left + 1;
		int r = right - 2;

		while (l < r) {

			// left�� �Ǻ����� ū ���� ���� ������ ����
			while (l < r && arr[pivot] > arr[l]) l++;

			// right�� �Ǻ����� ���� ���� ���� ������ ����
			while (l < r && arr[pivot] < arr[r]) r--;

			// �� �ε����� �������� �ʾҴ��� üũ�� ��, left�� right�� �� Swap
			if (l < r) Swap(&arr[l], &arr[r]);
		}

		// ������ ������ �� ������ pivot�� �������� Swap
		Swap(&arr[pivot], &arr[l]);

		// ��ͷ� �̺���
		Quick_Sort(arr, left + 1, l - 1);
		Quick_Sort(arr, l + 1, right-1);
	}
}