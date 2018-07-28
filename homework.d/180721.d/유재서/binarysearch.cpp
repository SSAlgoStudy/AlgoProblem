#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int binarySearch (int arr[],int start,int end, int val) {
	
	if (start > end) 
		return -1;
	
	int mid = (start + end) / 2;

	if (arr[mid] == val) {
		return mid;
	}
	else if (arr[mid] > val) 
		return binarySearch(arr,start, mid - 1, val);

	else if (arr[mid] < val) 
		return binarySearch(arr,mid + 1, end, val);
	
}

int main() {

	int arr[] = { 3,7,4,10,11,9};
	// 3,4,7,9,10,11
	int n = sizeof(arr) / sizeof(arr[0]);

	sort(arr, arr + n);
	
	printf("%d", binarySearch(arr,0,n-1,9));
	return 0;
}