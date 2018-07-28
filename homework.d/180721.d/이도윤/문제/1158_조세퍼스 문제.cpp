#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct _Node {
	int data;
	_Node *next;
}N;

N *head;

int n, m, list_size;

void add(int);
void remove();

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		add(i);

	printf("<");
	while (list_size) remove();

	return 0;
}

void add(int num) {
	N *new_node = (N*)malloc(sizeof(N));
	new_node->data = num;

	if (head == NULL) {
		new_node->next = new_node;
		head = new_node;
	}
	else {
		new_node->next = head->next;
		head->next = new_node;
		head = new_node;
	}
	list_size++;
}

void remove() {
	int idx = 1;

	while (idx%m) {
		head = head->next;
		idx++;
	}
	if (list_size > 1) printf("%d, ", head->next->data);
	else printf("%d>\n", head->next->data);
	
	N *temp = head->next;
	head->next = temp->next;
	free(temp);
	list_size--;
}