#include<stdio.h>
#include<stdlib.h>

typedef struct _Heap{
	int heap[200], heap_size;
}H;

H heap1;

void Swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insert_max_heap(int item) {
	int idx = ++heap1.heap_size;

	// ���� ���� ������ ��忡 �ϴ� �߰�.
	heap1.heap[idx] = item;

	// ��Ʈ ��� ���� �ؿ� �������� ����� �����ϹǷ� ù ��° ���� �ʼ�.
	// �θ� ���� �ڽ��� ��� ��, �θ� ��庸�� �ڽ��� ũ�� ���
	while ((idx != 1) && (heap1.heap[idx / 2] < heap1.heap[idx])) {
		Swap(&heap1.heap[idx / 2], &heap1.heap[idx]);
		
		// �ε��� �缳��.
		idx /= 2;
	}
}

int delete_max_heap() {
	int root_node = heap1.heap[1];
	heap1.heap[1] = heap1.heap[heap1.heap_size--];

	int parent = 1, child = 2;

	while (child <= heap1.heap_size) {
		// child�� ������ ������ ��尡 �� ���� �����Ƿ� ù ��° ���� �ʼ�.
		// ���� �ڽĳ��� ������ �ڽĳ�� ��, �� ū ��带 Ÿ������ ����.
		if (child < heap1.heap_size && heap1.heap[child] < heap1.heap[child + 1]) child++;

		// �ڽ� ��� �� ���� ū ���� �θ� ��� �񱳽�, �θ��尡 ũ�ų� ������ ����
		if (heap1.heap[parent] >= heap1.heap[child]) break;

		// �θ� ���� �ڽ� ��� ��ü
		Swap(&heap1.heap[parent], &heap1.heap[child]);
		
		// �ε��� �缳��
		parent = child;
		child *= 2;
	}

	return root_node;
}

int main() {

	insert_max_heap(9);
	insert_max_heap(10);
	insert_max_heap(4);
	insert_max_heap(2);
	insert_max_heap(1);
	insert_max_heap(3);	
	insert_max_heap(6);
	insert_max_heap(11);
	insert_max_heap(22);	
	insert_max_heap(3);
	insert_max_heap(2);
	insert_max_heap(1);
	while (heap1.heap_size) printf("%d ", delete_max_heap());
	printf("\n");

	return 0;
}