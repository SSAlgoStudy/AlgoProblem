//https://www.acmicpc.net/problem/14925
//목장 건설하기
#pragma once
#include<cstdio>
int map[1001][1001];

int min(int i1, int i2, int i3) {
	int res = i1 < i2 ? i1 : i2;
	res = res < i3 ? res : i3;
	return res;
}

int main() {
	int m, n;
	scanf("%d %d\n", &m, &n);
	int M = 0;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			int in;
			scanf("%d \n", &in);
			if (in == 0) {
				map[i][j] = 1;

				map[i][j] = min(map[i - 1][j - 1], map[i - 1][j], map[i][j - 1]) + 1;
				M = M > map[i][j] ? M : map[i][j];
			}

		}
	}
	printf("%d\n", M);

	return 0;
}