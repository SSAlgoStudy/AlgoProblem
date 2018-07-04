/*
Author : RaviKim
Version : 1.0.1
Date : 18.07.04
Description : Find Vertex using By DFS Algo.

*/


#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

int n, m, maxVertex;
int T;

vector<int> graph[11];
void dfs(int h, int cnt, vector<int>& v);


int main() {
	
	scanf("%d", &T);
	/*	테스트케이스 입력부분.	*/
	for (int testCase = 1; testCase <= T; testCase++) {

		/*	테스트케이스 N, M두개 입력받음.	*/	
		scanf("%d %d", &n, &m);

		for (int i = 1; i <= n; i++) {
			graph[i].clear();	// Initial.
		}
		while (m--) {
			int u, v;
			/*	간선정보		*/
			scanf("%d%d", &u, &v);
	
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		int ret = 0;

		for (int i = 1; i <= n; i++) {
			maxVertex = 0;
			vector<int> v(n + 1);
			dfs(i, 1, v);
			ret = max(maxVertex, ret);
		}
		printf("#%d %d\n", testCase, ret);
	}
}


void dfs(int h, int cnt, vector<int>& v) {

	v[h] = 1;
	maxVertex = max(maxVertex, cnt);

	for (int i = 0; i < graph[h].size(); i++)
		if (!v[graph[h][i]]) dfs(graph[h][i], cnt + 1, v);

	v[h] = 0;
}
