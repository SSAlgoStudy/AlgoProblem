#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int map[51][51];
bool visit[51][51];
int L, W;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int depth[51][51];
int max_value;
queue <int> qx;
queue <int> qy;

void bfs(int i, int j)
{
	visit[i][j] = true;
	qx.push(i);
	qy.push(j);

	int temp_x, temp_y;
	while (!qx.empty() && !qy.empty())
	{
		temp_x = qx.front(); qx.pop();
		temp_y = qy.front(); qy.pop();
		for (int i = 0; i < 4; i++)
		{
			int xx = temp_x + dx[i];
			int yy = temp_y + dy[i];
			if (map[xx][yy] == 1 && !visit[xx][yy])
			{
				visit[xx][yy] = true;
				qx.push(xx);
				qy.push(yy);

				depth[xx][yy] = depth[temp_x][temp_y] + 1;
				if (max_value < depth[xx][yy])
					max_value = depth[xx][yy]; //제일 큰값으로 갱신.
			}
		}
	}
}

int main()
{
	cin >> L >> W;
	char input_;
	for (int i = 1; i <= L; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			cin >> input_;
			if (input_ == 'W')
			{
				map[i][j] = 0;
			}
			else
			{
				map[i][j] = 1;
			}
		}
	}
	for (int i = 1; i <= L; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			if (map[i][j] == 1)
			{
				bfs(i, j);
				memset(visit, 0, sizeof(visit));        //육지인 정점에 대해서 bfs를 수행할 때마다
				memset(depth, 0, sizeof(depth));  // max_value를 구하기위한 초기화 작업.
			}
		}
	}
	cout << max_value << endl;

	return 0;

}