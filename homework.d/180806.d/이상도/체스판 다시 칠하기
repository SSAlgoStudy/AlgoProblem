#include <iostream>
using namespace std;

char arr[51][51];
int arr2[8][8];

void setarr2(int row,int col) {

	char pre;
	pre = (arr[row][col] == 'W') ? 'B' : 'W';

	for (int i = 0; i < 8; i++) {

		for (int j = 0; j < 8; j++) {

			if (pre != arr[row+i][col+j]) {
				arr2[i][j] = 1;
				pre = arr[row + i][col + j];
			}

			else {
				arr2[i][j] = 0;
				pre = (pre == 'W') ? 'B' : 'W';
			}

		}

		pre = (pre == 'W') ? 'B' : 'W';

	}
}

int main() {

	int N, M;
	char pre;
	cin >> N >> M;

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			cin >> arr[i][j];

	int min = 3000;
	int count = 0;

	for (int i = 0; i <= N - 8; i++) {

		for (int j = 0; j <= M - 8; j++) {
			
			setarr2(i, j);

			for (int row = 0; row < 8; row++) {

				for (int col = 0; col < 8; col++) {			

					if (arr2[row][col] == 0) {
						count++;
					}
				}

			}
			if (count > 32)
				count = 64 - count;
			min = (min > count) ? count : min;
			count = 0;
		}

	}

	cout << min;
	return 0;
}
