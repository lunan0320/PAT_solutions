#include <cstdio>
#include <iostream>

using namespace std;
/*
实现了大顶堆的基本操作
*/

const int maxn = 100;

int heap[maxn] = {0};
int n = 10;  //结点数

//自上而下调整大顶堆  low是想要调整的数组下标
//high是堆中的最后一个元素
void adjust_down(int low, int high) {
	//当前结点
	int cur = low;
	//左孩子
	int lchild = 2 * low;
	//需要swap的结点
	int adjust_index = lchild;
	while (lchild <= high) {
		adjust_index = lchild;
		int rchild = lchild + 1;
		//找出两个孩子中最大的，最为交换的结点
		if (rchild <= high && heap[lchild] < heap[rchild]) {
			adjust_index = rchild;
		}
		//如果有孩子比当前结点大
		if (heap[adjust_index] > heap[cur]) {
			//交换
			swap(heap[cur], heap[adjust_index]);
			//更新当前
			cur = adjust_index;
			lchild = 2 * cur;
		} else {
			break;
		}
	}
}

//创建大顶堆
void create_heap() {
	for (int i = n / 2; i >= 1; i--) {
		adjust_down(i, n);
	}
}

//在大顶堆中插入元素，需要不断向上
//low 表示根，high表示当前位置，通常为最后一个位置
void adjust_up(int low, int high) {
	int cur = high;
	int father = high / 2;
	while (father >= low) {
		if (heap[cur] > heap[father]) {
			swap(heap[cur], heap[father]);
			cur = father;
			father = cur / 2;
		} else {
			break;
		}
	}
}

//插入元素
void insert_Elem(int x) {
	//先对总结点数加1，再修改
	n = n + 1;
	heap[n] == x;
	printf("%d %d", x, heap[n]);
	printf("\n%d %d\n", heap[n], n);
	//从当前最后一个位置向上调整
	adjust_up(1, n);
}

//删除堆顶元素
void delete_Elem() {
	//先交换堆顶和堆底
	heap[1] = heap[n];
	//删除堆底
	n--;
	//向下调整，重构大顶堆
	adjust_down(1, n);
}

//层序遍历堆
void print_heap() {
	printf("层序遍历大顶堆的结果为：");
	for (int i = 1; i <= n ; i++) {
		printf(" %d", heap[i]);
	}
	printf("\n");
}


void heap_sort() {
	printf("排序前:");
	print_heap();
	for (int i = n; i > 1; i--) {
		swap(heap[1], heap[i]);
		adjust_down(1, i - 1);
	}
	printf("排序后:");
	print_heap();

}

int main() {
	//注意，这里 heap[1]是堆顶，否则2*i在0的时候还是0
	for (int i = 1; i <= n; i++) {
		scanf("%d", &heap[i]);
	}

	//大顶堆建堆过程
	create_heap();
	print_heap();
	//插入元素
	//insert_Elem(9);
	heap[++n] = 93;
	adjust_up(1, n);
	printf("插入元素");
	print_heap();
	//删除元素
	delete_Elem();
	printf("删除元素");
	print_heap();
	//堆排序
	heap_sort();

	return 0;
}

/*
85 55 82 57 68 92 99 98 66 56
*/