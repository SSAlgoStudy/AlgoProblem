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
	1. head의 next를 가리키는 포인터 하나 생성.
	2. 해당 포인터의 elem을 출력.
	3. head->next = 포인터->next;
	4. free 포인터
*/
void remove() {
	N *temp = head->next;
	printf("%d ", temp->elem);

	head->next = temp->next;
	head = temp->next;

	free(temp);
	list_size--;
}

/*
	1번 카드가 제일 위, N번 카드가 제일 아래.

	1. 제일 위의 카드를 바닥에 버림.
	2. 그 다음 제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮김.

	카드를 순서대로 출력.

	Circular Queue 구현.
*/