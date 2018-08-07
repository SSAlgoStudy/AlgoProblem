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
	// �ε��� ������ ��Ϳ��� ���
	if (left >= right) return;

	// pivot�� �迭 ������ ������ ����.
	int pivot = right;

	// l�� left, r�� �Ǻ� �ٷ� �������� ����.
	int l = left;
	int r = right - 1;

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
	Quick_Sort(arr, left, l - 1);
	Quick_Sort(arr, l + 1, right);
}