#include <cstdio>
#include <iostream>

using namespace std;
/*
ʵ���˴󶥶ѵĻ�������
*/

const int maxn = 100;

int heap[maxn] = {0};
int n = 10;  //�����

//���϶��µ����󶥶�  low����Ҫ�����������±�
//high�Ƕ��е����һ��Ԫ��
void adjust_down(int low, int high) {
	//��ǰ���
	int cur = low;
	//����
	int lchild = 2 * low;
	//��Ҫswap�Ľ��
	int adjust_index = lchild;
	while (lchild <= high) {
		adjust_index = lchild;
		int rchild = lchild + 1;
		//�ҳ��������������ģ���Ϊ�����Ľ��
		if (rchild <= high && heap[lchild] < heap[rchild]) {
			adjust_index = rchild;
		}
		//����к��ӱȵ�ǰ����
		if (heap[adjust_index] > heap[cur]) {
			//����
			swap(heap[cur], heap[adjust_index]);
			//���µ�ǰ
			cur = adjust_index;
			lchild = 2 * cur;
		} else {
			break;
		}
	}
}

//�����󶥶�
void create_heap() {
	for (int i = n / 2; i >= 1; i--) {
		adjust_down(i, n);
	}
}

//�ڴ󶥶��в���Ԫ�أ���Ҫ��������
//low ��ʾ����high��ʾ��ǰλ�ã�ͨ��Ϊ���һ��λ��
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

//����Ԫ��
void insert_Elem(int x) {
	//�ȶ��ܽ������1�����޸�
	n = n + 1;
	heap[n] == x;
	printf("%d %d", x, heap[n]);
	printf("\n%d %d\n", heap[n], n);
	//�ӵ�ǰ���һ��λ�����ϵ���
	adjust_up(1, n);
}

//ɾ���Ѷ�Ԫ��
void delete_Elem() {
	//�Ƚ����Ѷ��Ͷѵ�
	heap[1] = heap[n];
	//ɾ���ѵ�
	n--;
	//���µ������ع��󶥶�
	adjust_down(1, n);
}

//���������
void print_heap() {
	printf("��������󶥶ѵĽ��Ϊ��");
	for (int i = 1; i <= n ; i++) {
		printf(" %d", heap[i]);
	}
	printf("\n");
}


void heap_sort() {
	printf("����ǰ:");
	print_heap();
	for (int i = n; i > 1; i--) {
		swap(heap[1], heap[i]);
		adjust_down(1, i - 1);
	}
	printf("�����:");
	print_heap();

}

int main() {
	//ע�⣬���� heap[1]�ǶѶ�������2*i��0��ʱ����0
	for (int i = 1; i <= n; i++) {
		scanf("%d", &heap[i]);
	}

	//�󶥶ѽ��ѹ���
	create_heap();
	print_heap();
	//����Ԫ��
	//insert_Elem(9);
	heap[++n] = 93;
	adjust_up(1, n);
	printf("����Ԫ��");
	print_heap();
	//ɾ��Ԫ��
	delete_Elem();
	printf("ɾ��Ԫ��");
	print_heap();
	//������
	heap_sort();

	return 0;
}

/*
85 55 82 57 68 92 99 98 66 56
*/