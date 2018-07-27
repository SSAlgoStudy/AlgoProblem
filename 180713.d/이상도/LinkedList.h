#pragma once
#include<cstdio>

struct NODE {
	int value;
	NODE* next;

	NODE() {
		next = 0;
	}
}nodes[10000];

static struct MYAL {
	int len;
	const int MAX = 10000;

	MYAL() {
		len = 0;
	}
	void clear() {
		len = 0;
	}

	NODE* alloc() {
		if (len == MAX) return 0;

		return &nodes[len++];
	}
} my;

struct List {
	NODE* head, *tail, *cursor;

	List() {
		head = my.alloc();
		tail = my.alloc();
		head->next = tail;
	}

	void insert(int data) {
		NODE* nn = my.alloc();

		nn->next = head->next;
		nn->value = data;

		head->next = nn;
	}

	void setCursor() {
		cursor = head;
	}

	int next() {
		if (cursor->next == tail) return -1;
		
		cursor = cursor->next;
		return cursor->value;
	}

	void clear() {
		head->next = tail;
	}
};