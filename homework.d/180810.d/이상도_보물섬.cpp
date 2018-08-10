#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

struct Info
{
	char map[52][52];
	bool visit[52][52];

	typedef struct Cod { int r, c; } cod;
	const int dr[4] = { -1,1,0,0 };
	const int dc[4] = { 0,0,-1,1 };

	int n, m;
	int maxLength;
	void init()
	{
		cin >> n >> m;
		maxLength = 0;
		memset(map, 0, sizeof(map));
		for (int r = 1; r <= n; r++)
		{
			cin >> (char*)(map[r] + 1);
		}
	}

	int getLength(int r, int c)
	{
		cod now, next;
		now.r = r; now.c = c;
		queue<cod> que;
		que.push(now);

		memset(visit, false, sizeof(visit));

		int len = 0;
		int size = 1;
		while (que.size())
		{
			now = que.front();
			que.pop();

			for (int d = 0; d < 4; d++)
			{
				next.r = now.r + dr[d];
				next.c = now.c + dc[d];

				if (map[next.r][next.c] == 'L' && !visit[next.r][next.c])
				{
					visit[next.r][next.c] = true;
					que.push(next);
				}
			}

			size--;
			if (size == 0)
			{
				size = que.size();
				len++;
			}
		}

		return len;
	}

	int getTreasure()
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (map[i][j] == 'L')
				{
					int length;
					length = getLength(i, j);
					maxLength = maxLength < length ? length : maxLength;
				}
			}
		}

		return maxLength - 1;
	}
} info;

int main()
{
	info.init();
	cout << info.getTreasure() << '\n';
	return 0;
}