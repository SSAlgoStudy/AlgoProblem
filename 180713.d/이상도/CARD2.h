#pragma once
#include<cstdio>

struct NODE
{
	int value;
	NODE* prev;
	NODE* next;

	NODE()
	{
		prev = next = 0;
	}
};

//malloc을 쓰기 싫었음.
static struct MYMAL
{
	NODE nodes[2000000];
	int idx;
	MYMAL()
	{
		idx = 0;
	}
	void clear()
	{
		idx = 0;
	}
	NODE* malloc()
	{
		return &nodes[idx++];
	}


} MYMAL;

struct LIST
{
	NODE *head, *tail;
	NODE *cursor[2];

	LIST()
	{
		head = MYMAL.malloc();
		tail = MYMAL.malloc();
		head->next = tail;
		tail->prev = head;
	}

	void insert_front(int i)
	{
		NODE *nn = MYMAL.malloc();
		nn->value = i;
		nn->next = head->next;
		nn->prev = head;

		head->next->prev = nn;
		head->next = nn;
	}

	void insert_back(int i)
	{
		NODE* nn = MYMAL.malloc();
		nn->value = i;
		nn->next = tail;
		nn->prev = tail->prev;

		tail->prev->next = nn;
		tail->prev = nn;
	}

	void clear_front()
	{
		cursor[0] = head;
	}
	void clear_back()
	{
		cursor[1] = tail;
	}

	int next()
	{
		if (cursor[0]->next != tail) cursor[0] = cursor[0]->next;

		return cursor[0]->value;
	}

	int prev()
	{
		if (cursor[1]->prev != head) cursor[1] = cursor[1]->prev;
		return cursor[1]->value;
	}

	void del_front()
	{
		if (cursor[0] != head)
		{
			cursor[0]->prev->next = cursor[0]->next;
			cursor[0]->next->prev = cursor[0]->prev;
			cursor[0] = cursor[0]->prev;
		}
	}

	void del_back()
	{
		if (cursor[1] != tail)
		{
			cursor[1]->prev->next = cursor[1]->next;
			cursor[1]->next->prev = cursor[1]->prev;
			cursor[1] = cursor[1]->next;
		}
	}
};

int CARD2()
{
	int n;
	scanf("%d\n", &n);
	LIST li;

	for (int i = 1; i <= n; i++)
	{
		li.insert_back(i);
	}

	li.clear_back();
	li.clear_front();

	for (int i = 1; i < n; i++) {
		int out = li.next();
		li.del_front();

		out = li.next();
		li.del_front();
		li.insert_back(out);
	}
	printf("%d\n", li.next());

	return 0;
}