#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100010;

struct Node {
	int address;
	int value;
	int next;
	bool flag; //有效结点为true
} node[maxn];

bool cmp(Node a, Node b) {
	if (a.flag == false || b.flag == false) {
		return a.flag > b.flag;
	}
	return a.value < b.value;
}

int main() {
	int N = 0;
	int  begin_addr = 0;
	//链表初始化
	for (int i = 0; i < maxn; i++) {
		node[i].flag = false;
	}
	//输入样例
	scanf("%d%d", &N, &begin_addr);
	int add, value, next_add;
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d", &add, &value, &next_add);
		node[add].address = add;
		node[add].value = value;
		node[add].next = next_add;
		node[add].flag = true;
	}
	//排序
	sort(node, node + maxn, cmp);
	int head_addr = node[0].address ;
	int addr = head_addr;
	int count = 0;
//	int p = begin_addr;
//	while (p != -1) {
//		node[p].flag = true;
//		count++;
//		p = node[p].next;
//	}
	printf("%d %d\n", N, head_addr);
	for (int i = 0; i < N; i++) {
		if (i != N - 1) {
			printf("%05d %d %05d\n", node[i].address, node[i].value, node[i + 1].address);
		} else {
			printf("%05d %d -1", node[i].address, node[i].value);
		}

	}

	return 0;
}
