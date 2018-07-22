#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
using namespace std;

typedef struct _Node {
	int elem;
	_Node *next;
}N;

N *head;

int n, list_size;

void add_back(int);
void remove();

int main() {

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		add_back(i);

	while (list_size) remove();

	return 0;
}


void add_back(int num) {
	N *new_node = (N*)malloc(sizeof(N));
	new_node->elem = num;

	if (head == NULL) {
		head = new_node;
		new_node->next = new_node;
	}
	else {
		new_node->next = head->next;
		head->next = new_node;
		head = new_node;
	}
	list_size++;
}

/*
1. head�� next�� ����Ű�� ������ �ϳ� ����.
2. �ش� �������� elem�� ���.
3. head->next = ������->next;
4. free ������
*/
void remove() {
	N *temp = head->next;
	if(list_size == 1)printf("%d\n", temp->elem);

	head->next = temp->next;
	head = temp->next;

	free(temp);
	list_size--;
}

/*
1�� ī�尡 ���� ��, N�� ī�尡 ���� �Ʒ�.

1. ���� ���� ī�带 �ٴڿ� ����.
2. �� ���� ���� ���� �ִ� ī�带 ���� �Ʒ��� �ִ� ī�� ������ �ű�.

ī�带 ������� ���.

Circular Queue ����.
*/