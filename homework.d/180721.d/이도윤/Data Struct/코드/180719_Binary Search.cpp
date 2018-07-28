#include<stdio.h>

int arr[10];

int binary_search(int, int, int);

int main() {

	return 0;
}

int binary_search(int value, int left, int right) {

	int mid;

	// left <= right�� ����?
	// left < right�� �� ���, ���Ұ� �ϳ� ������ ���� value���� ������ �ʰ� ������ �� �ֱ� ������ �̸� ����.
	while (left <= right) {
		mid = (left + right) / 2;
		if (value == arr[mid]) return mid;
		else if (value > arr[mid]) left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}

int binary_search_Upper_Bound(int value, int left, int right) {

	int mid;

	// Upper Bound�� ���� ã�� ���ص� value���� ū ���� ù ��° ���� ��ȯ�ϸ� �ȴ�.
	// �׷��� ���� BS�ʹ� �ٸ����� ��ȣ�� �����.
	while (left < right) {
		mid = (left + right) / 2;

		// �� �κ��� �ٽ�. ã���� �ϴ� key���� �迭�� ���� ���Ƶ� �ε����� �� ĭ �о��ִ°� �ٽ�.
		if (arr[mid] <= value) left = mid + 1;
		else right = mid;
	}
	return right;
}

int binary_search_Lower_Bound(int value, int left, int right) {

	int mid;

	while (left < right) {
		mid = (left + right) / 2;

		if (arr[mid] < value) left = mid + 1;
		else right = mid;
	}
	return right;
}