//https://www.acmicpc.net/problem/14226
//이모티콘
#pragma once
#include<cstdio>

int que[1000000][3], f, r;
bool visit[2001][2001];

int main() {
	int s, clip = 0;
	scanf("%d\n", &s);

	visit[1][0] = true;
	que[r][0] = 1;
	que[r][2] = 0;
	que[r++][1] = 0;

	int cnt = 0, t = 0;
	while (f != r) {
		int now[3] = { que[f][0], que[f][1], que[f++][2] };
		
		if (now[1] && now[0]+ now[1] == s) {
			t = now[2] + 1;
			break;
		}
		else if (now[1] && now[0] + now[1] < 2001) {
			if (!visit[now[0] + now[1]][now[1]]) {
				visit[now[0] + now[1]][now[1]] = true; 
				que[r][0] = now[0] + now[1];
				que[r][1] = now[1];
				que[r++][2] = now[2] + 1;
			}
		}

		if (now[0] > 0) {
			if (!visit[now[0] - 1][now[1]]) {
				visit[now[0] - 1][now[1]] = true;

				que[r][0] = now[0] - 1;
				que[r][1] = now[1];
				que[r++][2] = now[2] + 1;
			}
		}

		if (visit[now[0]][now[0]]) continue;
		visit[now[0]][now[0]] = true;

		que[r][0] = que[r][1] = now[0];
		que[r++][2] = now[2] + 1;
	}
	printf("%d\n", t);
	return 0;
}