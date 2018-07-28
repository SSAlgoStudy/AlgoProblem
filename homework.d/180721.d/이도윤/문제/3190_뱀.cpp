#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

// 동쪽으로 이동. L시 반시계, D시 시계.
int map[101][101], N, K, L, xx[] = { 0,1,0,-1 }, yy[] = { 1,0,-1,0 };
char com[10001];
bool visit[101][101];

typedef struct _Node {
	int x, y;
	_Node *llink, *rlink;
}node;

node *head, *tail;

int go(int, int, int, int);

int main() {

	scanf("%d%d", &N,&K);

	node *snake_head = (node*)malloc(sizeof(node));
	snake_head->x = snake_head->y = 1;
	snake_head->rlink = snake_head->llink =  NULL;
	head = tail = snake_head;
	visit[1][1] = true;

	for (int i = 0; i < K; i++) {
		int cx, cy;
		scanf("%d %d", &cx, &cy);
		map[cx][cy] = 1;
	}
	scanf("%d", &L);

	for (int i = 0; i < L; i++) {
		int what_time;
		char ch;
		scanf("%d %c", &what_time, &ch);
		com[what_time] = ch;
	}

	printf("%d\n",go(1, 1, 0, 0));
	return 0;
}

int go(int x, int y, int dir, int time) {

	int ndir = dir;

	if (com[time] == 'L') {
		ndir--;
		ndir = ndir >= 0 ? ndir : 3;
	}
	else if (com[time] == 'D') ndir = (ndir + 1) % 4;

	int nx = x + xx[ndir], ny = y + yy[ndir];

	// 머리 들이 밀었을 때, 벽 이거나 자기 몸통이면 시간 반환 후 종료.
	if (nx > N || ny > N || nx < 1 || ny < 1 || visit[nx][ny]) return (time+1);

	else {
		node *new_node = (node*)malloc(sizeof(node));
		new_node->x = nx, new_node->y = ny;
		new_node->rlink = head;
		head->llink = new_node;
		head = new_node;
		visit[nx][ny] = true;

		if (map[nx][ny] == 1) map[nx][ny] = 0;	
		else {
			visit[tail->x][tail->y] = false;
			node *temp = tail;
			tail = temp->llink;
			free(temp);
		}
	}
	go(nx, ny, ndir, time + 1);
}

/*
	사과를 먹으면 뱀 길이가 늘어남.

	뱀이 기어다니다가 벽 또는 자기 자신과 부딪히면 게임이 끝남.

	NxN 정사각 보드 위에서 진행됨. 뱀은 (1,1)에서 시작함.

	뱀은 처음에 오른쪽을 향함.

	다음의 규칙을 따름.
		1) 머리를 먼저 다음칸에 위치시킴
			- 이동한 칸에 사과가 있다 : 사과 없어지고, 꼬리는 움직이지 않음.
			- 이동한 칸에 사과가 없다 : 몸 길이를 줄여서 꼬리 칸을 비워줌.
*/