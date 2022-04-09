/*
《算法笔记》
page 332

*/


#include <cstdio>

const int maxn = 101;

int father[maxn];

int n, m;


void init() {
	for (int i = 0; i < n; i++) {
		father[i] = i;
	}
}

//并查集
int findFather(int x) {
	int a = x;
	//找父结点
	while (x != father[x]) {
		x = father[x];
	}

	//路径压缩算法
	while (a != father[a]) {
		int temp = father[a];
		father[a] = x;
		a = temp;
	}
}

//集合合并（此处为数据合并）
void union_set(int a, int b) {
	//找到各自的根节点
	int father_a = findFather(a);
	int father_b = findFather(b);
	//判断如果不是一个集合，那就对根节点合并
	if (father_a != father_b) {
		father[father_a] = father_b;
	}
}


int main() {
	scanf("%d%d", &n, &m);
	init();
	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		union_set(a, b);
	}
	//判断集合的个数
	int count = 0;
	for (int i = 0; i < n; i ++) {
		if (i == father[i]) {
			count++;
		}
	}
	printf("%d", count);
	return 0;
}