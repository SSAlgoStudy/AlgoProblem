#pragma once
#include<cstdio>

struct NODE
{
	int value;
	NODE *next, *prev;

	NODE()
	{
		prev = next = 0;
	}
};

static struct MYMAL
{
	int idx;
	NODE nodes[5002];

	MYMAL()
	{
		idx = 0;
	}

	NODE* malloc()
	{
		return &nodes[idx++];
	}
} mymal;

struct LIST
{
	//환형 큐에는 head가 필요하지 않다.
	NODE *tail, *cursor;
	LIST()
	{
		tail = 0;
	}

	void insert(int i)
	{
		NODE* nn = mymal.malloc();
		nn->value = i;

		//노드가 이미 있다면 node를 tail의 다음(head)부분에 삽입한다.
		if (tail) {
			nn->next = tail->next;
			nn->next->prev = nn;
			nn->prev = tail;

			tail->next = nn;
		}

		//처음 들어오는 노드라면 tail이 새로운 노드를 가리키도록 한다.
		else {
			nn->next = nn;
			nn->prev = nn;
			tail = nn;
		}
	}

	void clear()
	{
		cursor = tail;
	}

	int next()
	{
		if (cursor == 0) return -1;
		cursor = cursor->next;
		return cursor->value;
	}

	void del()
	{
		if (cursor == tail)
		{
			//리스트의 사이즈가 0 또는 1
			if (tail->prev == tail) tail = 0;
			//그냥 끝에 부분일뿐
			else {
				tail = tail->prev;
			}
		}

		cursor->next->prev = cursor->prev;
		cursor->prev->next = cursor->next;
		
		//사이즈가 하나인 경우 cursor 는 0을 가리키도록한다. 아니라면, 커서는 이전 노드를 가리킨다.
		cursor = cursor->prev == cursor ? 0 : cursor->prev;
	}
};

int JocepusProblem()
{
	int n, m;
	scanf("%d %d\n", &n, &m);
	LIST li;
	for (int i = n; i >= 1; i--)
	{
		li.insert(i);
	}

	li.clear();
	printf("<");
	for (int i = 1; i < n; i++)
	{
		int out;
		for (int j = 0; j < m; j++) {
			out = li.next();
		}
		printf("%d, ", out);
		li.del();
	}

	printf("%d>\n", li.next());

	return 0;
}