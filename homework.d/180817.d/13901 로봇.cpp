//https://www.acmicpc.net/problem/13901
//·Îº¿
#pragma once
#include<cstdio>

bool map[1002][1002];
int dr[5] = { 0,-1,1,0,0 };
int dc[5] = { 0,0,0,-1,1 };

int main() {
	int r, c, k;
	scanf("%d %d\n", &r, &c);
	scanf("%d \n", &k);
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			map[i][j] = true;
		}
	}
		
	while (k--) {
		int tr, tc;
		scanf("%d %d\n", &tr, &tc);
		map[++tr][++tc] = false;
	}
	
	int sr, sc;
	scanf("%d %d\n", &sr, &sc);

	int d[4], cnt = 0;
	scanf("%d %d %d %d\n", &d[0], &d[1], &d[2], &d[3]);

	sr++; sc++;

	bool cont = true;
	while (cont) {
		int nnr, nnc;
		
		cont = false;

		for (int i = 0; i < 4; i++) {
			nnr = sr + dr[d[(cnt+i)%4]]; nnc = sc + dc[d[(cnt+ i)%4]];

			if (map[nnr][nnc]) {
				cnt = (cnt + i) % 4;
				map[sr][sc] = false;
				sr = nnr; sc = nnc;
				cont = true;
				break;
			}
		}
	}

	printf("%d %d\n", --sr, --sc);
	return 0;
}