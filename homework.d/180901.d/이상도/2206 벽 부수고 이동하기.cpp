#pragma once
#include<iostream>
#include<cstring>
struct INFO {
	int r, c, cnt;
	bool key;
};
using namespace std;
bool map[1002][1002];
bool visit[2][1001][1001];
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
int n, m;

INFO que[3000000];

bool outBound(int r, int c)
{
	return r <= 0 || r > n || c <= 0 || c > m;
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	char in;
	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= m; j++) 
		{
			cin >> in;

			map[i][j] = in - '0';
		}
	}
		
	int res = -1;
	int f, r;
	f = r = 0;
	INFO info = { 1,1,1, true};
	que[r++] = info;
	
	while (f != r)
	{
		INFO now = que[f++];
		
		if (now.r == n && now.c == m)
		{
			res = now.cnt;
			break;
		}

		for (int d = 0; d < 4; d++)
		{
			INFO next;
			next.r = now.r + dr[d];
			next.c = now.c + dc[d];
			next.cnt = now.cnt + 1;
			if (outBound(next.r, next.c)) continue;

			if (map[next.r][next.c]) {
				if (now.key) {
					if (visit[false][next.r][next.c]) continue;
					visit[false][next.r][next.c] = true;
					next.key = false;
					que[r++] = next;
				}
			}
			else {
				next.key = now.key;
				if (visit[next.key][next.r][next.c]) continue;
				visit[next.key][next.r][next.c] = true;

				que[r++] = next;
			}
		}
	}

	cout << res << '\n';

	return 0;
}