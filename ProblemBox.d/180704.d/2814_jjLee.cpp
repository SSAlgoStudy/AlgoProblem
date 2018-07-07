#include <stdio.h>
#include <memory.h>
int max = 0;//길이의 최대값
int map[11][11] = { { 0, }, };//무방향 그래프
int visit[11] = { 0, };//정점 방문 여부
int n, m;
void dfs(int sum, int current)//sum:이전에 방문한 정점까지의 길이, current:이번 호출에서 탐색할 정점
{	
	if (sum + 1 > max)//current 정점을 방문했을때의 길이가 이전에 기록한 max값보다 크면 max값 갱신
		max = sum + 1;

	visit[current] = 1;//현재 정점 방문 체크
	for (int i = 1; i <= n; i++)//1번 정점부터 n번 정점까지 모두 탐색
	{
		if (map[current][i] == 1 && visit[i] == 0)//current-i 정점이 서로 연결되어있고, i정점을 아직 방문 안한 경우
			dfs(sum + 1, i);//다음 i번째 정점 탐색
	}
	visit[current] = 0;//dfs함수에서 빠져나오기 전에 현재 정점 방문여부 해제
}
int main(void) {
	int T;
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++)
	{
		memset(map, 0, sizeof(map));//초기화
		memset(map, 0, sizeof(visit));//초기화
		
		scanf("%d%d", &n,&m);

		for (int i = 0; i < m; i++)
		{
			int x, y;
			scanf("%d%d", &x,&y);
			map[x][y] = 1;//무방향 그래프이므로 입력받은 양쪽을 다 연결되어있음으로 체크
			map[y][x] = 1;
		}

		max = 0;

		for (int i = 1; i <= n; i++)//시작 정점을 1번부터 n번까지 바꿔가며 dfs호출
			dfs(0, i);

		printf("#%d %d\n", test_case, max);
	}
	return 0;
}