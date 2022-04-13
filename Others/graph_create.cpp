#include <cstdio>
#include <vector>

using namespace std;

#define INF 100000000

const int maxn = 100;

//�ڽӾ���д��
int adj_matrix[maxn][maxn] = {INF};
int n;

bool visit_matrix[maxn] = {false};

//��ӡ�ڽӾ���
void print_matrix() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", adj_matrix[i][j]);
		}
		printf("\n");
	}
}

//����һ���ڽӾ���
void matrix_create() {
	printf("�ڽӾ��󶥵�����");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &adj_matrix[i][j]);
		}
	}
	print_matrix();
}

//�ڽӾ����DFS
void DFS(int index, int depth) {
	visit_matrix[index] = true;
	printf("%d ", index);
	for (int i = 0; i < n; i++) {
		if (!visit_matrix[i] && adj_matrix[index][i] != INF) {
			DFS(i, depth + 1);
		}
	}
}

void DFS_traverse() {
	for (int i = 0; i < n; i++) {
		printf("DFS��%d����㣺", i);
		if (!visit_matrix[i]) {
			DFS(i, 1);
		}

		printf("\n");
	}
}



/*

�ڽӱ��д��

*/
//�ڽӱ��д��
struct Node {
	int w;
	int v;
	Node(int x, int y) {
		w = x;
		v = y;
	}
};

vector<Node> Adj[maxn];

void print_list() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < Adj[i].size(); j++) {
			printf("%d ", Adj[i][j].v);
		}
		printf("\n");
	}
}

//�����ڽӱ�
void list_create() {
	printf("�ڽӾ��󶥵�����");
	scanf("%d", &n);
	int k;
	int weight, value;
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			scanf("%d%d", &weight, &value);
			Adj[i].push_back(Node(weight, value));
		}
	}
}

//�ڽӱ��DFS
bool visit_list[maxn] = {false};

void DFS_list(int index) {
	visit_list[index] = true;
	printf("%d ", index);
	for (int i = 0; i < Adj[index].size(); i++) {
		int temp = Adj[index][i].v;
		if (!visit_list[temp]) {
			DFS_list(temp);
		}
	}
}

void DFS_traverse_list() {
	for (int i = 0; i < n; i ++) {
		printf("DFS��%d����㣺", i);
		if (!visit_list[i]) {
			DFS_list(i);
		}
		printf("\n");
	}
}

int main() {
	//�ڽӾ���
//	matrix_create();
//	print_matrix();
//	DFS_traverse_matrix();
//	//�ڽӱ�
	list_create();
	print_list();
	DFS_traverse_list();

}

/*
//�ڽӾ���
5
0 2 0 0 1
2 0 2 0 2
0 2 0 1 0
0 0 1 0 1
1 2 0 1 0
//�ڽӱ�
2
2 1 1 4
3
2 0 2 2 2 4
2
2 1 1 3
2
1 2 1 4
3
1 0 2 1 1 3
*/