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
	1. 첫 번째 원소를 뽑아냄.
	2. 왼쪽으로 한 칸 이동 시킴.
	3. 오른쪽으로 한 칸 이동시킴.

	circular doubly linked list를 구현하면 좋을까?

	head를 기준으로 양쪽으로 퍼져나가는 포인터 두 개를 만들어서 가장 먼저 찾아내는 놈을 최소로 둠.

	head자리 제거 시, 연결하는 메커니즘 적용.
*/