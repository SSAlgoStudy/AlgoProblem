#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct _Node {
	int data;
	_Node *before, *next;
}node;

node *head, *left, *right;

int list_size, n, m, res;

void add_back(int);
void find(int);

int main() {

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		add_back(i);

	head = head->next;

	left = right = head;

	int start = head->data;

	
	for (int i = 0; i < m; i++) {
		int idx;
		scanf("%d", &idx);
		find(idx);
	}

	printf("%d\n", res);
	return 0;
}

void add_back(int num) {
	node *new_node = (node *)malloc(sizeof(node));
	new_node->data = num;

	if (head == NULL) {
		new_node->before = new_node->next = new_node;
		head = new_node;
	}
	else {
		new_node->next = head->next;
		new_node->before = head;

		head->next->before = new_node;
		head->next = new_node;
		
		head = new_node;
	}
	list_size++;
}

void find(int num) {

	if (head->data != num) {
		left = right = head;
		while (1) {
			left = left->before;
			right = right->next;
			res++;
			if (left->data == num) {
				head = left;
				break;
			}
			else if (right->data == num) {
				head = right;
				break;
			}
		}
	}

	node *temp = head;
	head = head->next;
	temp->before->next = temp->next;
	temp->next->before = temp->before;
	free(temp);
	list_size--;
}
/*
	1. ù ��° ���Ҹ� �̾Ƴ�.
	2. �������� �� ĭ �̵� ��Ŵ.
	3. ���������� �� ĭ �̵���Ŵ.

	circular doubly linked list�� �����ϸ� ������?

	head�� �������� �������� ���������� ������ �� ���� ���� ���� ���� ã�Ƴ��� ���� �ּҷ� ��.

	head�ڸ� ���� ��, �����ϴ� ��Ŀ���� ����.
*/