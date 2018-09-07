#pragma once
#include<cstdio>
#include<cstring>
int kevin[101][101], n, m, INF = 0x3f3f3f3f;
int adj[101][100], alen[101];
int MIN(int i1, int i2) { return i1 < i2 ? i1 : i2; }

int main() {
	scanf("%d %d\n", &n, &m);
	memset(kevin, 0x3f, sizeof(kevin));

	while (m--) {
		int from, to;
		scanf("%d %d\n", &from, &to);

		kevin[from][to] = 1;
		kevin[to][from] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				kevin[i][j] = MIN(kevin[i][k] + kevin[k][j], kevin[i][j]);
			}
		}
	}

	int res = 0, num = 1000;

	for (int i = 1; i <= n; i++) {
		int k = 0;
		for (int j = 1; j <= n; j++) {
			k += kevin[i][j];
		}
		k -= kevin[i][i];
		if (k < num) {
			res = i;
			num = k;
		}
	}
	printf("%d\n", res);
	return 0;
}