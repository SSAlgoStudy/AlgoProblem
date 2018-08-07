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

	// 히프 가장 마지막 노드에 일단 추가.
	heap1.heap[idx] = item;

	// 루트 노드 보다 밑에 있을때만 상승이 가능하므로 첫 번째 조건 필수.
	// 부모 노드와 자신의 노드 비교, 부모 노드보다 자신이 크면 상승
	while ((idx != 1) && (heap1.heap[idx / 2] < heap1.heap[idx])) {
		Swap(&heap1.heap[idx / 2], &heap1.heap[idx]);
		
		// 인덱스 재설정.
		idx /= 2;
	}
}

int delete_max_heap() {
	int root_node = heap1.heap[1];
	heap1.heap[1] = heap1.heap[heap1.heap_size--];

	int parent = 1, child = 2;

	while (child <= heap1.heap_size) {
		// child가 히프의 마지막 노드가 될 수도 있으므로 첫 번째 조건 필수.
		// 왼쪽 자식노드와 오른쪽 자식노드 비교, 더 큰 노드를 타겟으로 잡음.
		if (child < heap1.heap_size && heap1.heap[child] < heap1.heap[child + 1]) child++;

		// 자식 노드 중 가장 큰 노드와 부모 노드 비교시, 부모노드가 크거나 같으면 종료
		if (heap1.heap[parent] >= heap1.heap[child]) break;

		// 부모 노드와 자식 노드 교체
		Swap(&heap1.heap[parent], &heap1.heap[child]);
		
		// 인덱스 재설정
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