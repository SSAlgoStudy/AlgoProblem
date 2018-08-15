#include<iostream>
#include<algorithm>
#include<cstring>
#define MAX 1000

using namespace std;
int map[MAX + 3][MAX + 3];
int dp[MAX + 3][MAX + 3];
int ans = 0;

int main() {

	int N, M;	//N:가로, M:세로

	cin >> M >> N;

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == 1 || j == 1) {
				if (map[i][j] == 0)
					dp[i][j] = 1;
				else
					dp[i][j] = 0;
			}
			else if (i >= 2 && j >= 2) {
				if (map[i][j] == 0) {
					dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;
				}
				else {
					dp[i][j] = 0;
				}
			}
			ans = max(dp[i][j], ans);
		}
	}

	cout << ans;

	return 0;
}