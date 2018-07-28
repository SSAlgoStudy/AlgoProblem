#include<stdio.h>

int arr[10];

int binary_search(int, int, int);

int main() {

	return 0;
}

int binary_search(int value, int left, int right) {

	int mid;

	// left <= right의 이유?
	// left < right로 할 경우, 원소가 하나 남았을 때는 value값과 비교하지 않고 종료할 수 있기 때문에 이를 방지.
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

	// Upper Bound는 값을 찾지 못해도 value보다 큰 가장 첫 번째 값을 반환하면 된다.
	// 그래서 기존 BS와는 다른점이 등호가 사라짐.
	while (left < right) {
		mid = (left + right) / 2;

		// 이 부분이 핵심. 찾고자 하는 key값과 배열의 값이 같아도 인덱스를 한 칸 밀어주는게 핵심.
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