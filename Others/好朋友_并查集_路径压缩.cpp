/*
���㷨�ʼǡ�
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

//���鼯
int findFather(int x) {
	int a = x;
	//�Ҹ����
	while (x != father[x]) {
		x = father[x];
	}

	//·��ѹ���㷨
	while (a != father[a]) {
		int temp = father[a];
		father[a] = x;
		a = temp;
	}
}

//���Ϻϲ����˴�Ϊ���ݺϲ���
void union_set(int a, int b) {
	//�ҵ����Եĸ��ڵ�
	int father_a = findFather(a);
	int father_b = findFather(b);
	//�ж��������һ�����ϣ��ǾͶԸ��ڵ�ϲ�
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
	//�жϼ��ϵĸ���
	int count = 0;
	for (int i = 0; i < n; i ++) {
		if (i == father[i]) {
			count++;
		}
	}
	printf("%d", count);
	return 0;
}