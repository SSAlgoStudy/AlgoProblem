#pragma once
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
typedef pair<int, int> PII;
int n;
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
bool map[30][30];
double p[4];

double res = 0;

void getPath(int r, int c, int depth, double pro) 
{
	if (n == depth) {
		res += pro;
		return;
	}
	
	map[r][c] = true;

	for (int d = 0; d < 4; d++) {
		int next[2] = { r + dr[d], c + dc[d] };
		
		if (map[next[0]][next[1]]) continue;
		getPath(next[0], next[1], depth + 1, pro*p[d]);
	}
	
	map[r][c] = false;
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> p[0] >> p[1] >> p[2] >> p[3];

	for (int i = 0; i < 4; i++)
	{
		p[i] /= 100.;
	}
	
	getPath(15, 15, 0, 1);

	cout.setf(ios::fixed);
	cout.precision(9);

	cout << res << '\n';
	return 0;
}