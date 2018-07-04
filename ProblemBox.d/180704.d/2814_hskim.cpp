/*
Author : RaviKim
Version : 1.0.2
Date : 18.07.04
Description : Permutation
Problem No : 1215
*/

#include <iostream>
using namespace std;
int testCase = 10;

int main(void) {
	int findNum = 0;

	char Board[8][8];
	int Cnt = 0;
	int ff = 0;

	for (int tC = 0; tC < testCase; tC++) {	//	 10번 반복.
		cin >> findNum;	// 찾아야 하는 숫자.

						/* 펠린드롭 Board를 채움 */
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> Board[i][j];
			}
		}

		/*	스캔 부분	*/
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {

				/*	가로 스캔 부분.	*/
				if (findNum +i <= 8) {	//	찾는 숫자보다 넘지 않는 검증문.
					for (int a = i, b = findNum+i -1; a < i + findNum / 2; a++, b--) {
						if (Board[a][j] != Board[b][j]) ff++;
						else Cnt++;

					}
				}
				/*	세로 스캔 부분. */
				if (findNum + j <= 8) {	//	찾는 숫자보다 넘지 않는 검증문.
					for (int a = j, b = findNum+j -1; a < j + findNum / 2; a++, b--) {
						if (Board[i][a] != Board[i][b]) ff++;
						else Cnt++;
					}
				}
		}




		}
		/*	출력부	*/

		cout << "#" << tC + 1 << " ";
		cout << Cnt << endl;
	}



}
