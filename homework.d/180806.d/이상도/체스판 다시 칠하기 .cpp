#include<iostream>

using namespace std;

char PaintChess_map[50][50];

inline int PaintChess_min(int i1, int i2)
{
	return i1 < i2 ? i1 : i2;
}

int makeChess(int r, int c)
{
	bool check = true;
	int repair = 0;
	for (int i = r; i < r + 8; i++)
	{
		for (int j = c; j < c + 8; j++)
		{
			repair = check ^ (PaintChess_map[i][j] == 'W') ? ++repair : repair;
			check = !check;
		}
		check = !check;
	}
	return PaintChess_min(repair, 64 - repair);
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < m; c++)
		{
			cin >> PaintChess_map[r][c];
		}
	}
	int res = 65;
	for (int r = 0; r <= n - 8; r++)
	{
		for (int c = 0; c <= m - 8; c++)
		{
			res = PaintChess_min(res, makeChess(r, c));
		}
	}
	cout << res << '\n';
	return 0;
}