#include <cstdio>
#include <queue>


using namespace std;

struct node {
	int data;
	node *lchild;
	node *rchild;
};

const int maxn = 40;

int pre[maxn];
int in[maxn];
int post[maxn];
int n;



//已知前序和中序 重构树
node *rebuild1(int preL, int preR, int inL, int inR) {
	if (preL > preR) {
		return NULL;
	}
	int i = inL;
	node *root = new node;
	root->data = pre[preL];
	while (i <= inR) {
		if (in[i] == pre[preL]) {

			break;
		}
		i++;
	}
	int numLeft = i - inL;
	root->lchild = rebuild1(preL + 1, preL + numLeft, inL, i - 1);
	root->rchild = rebuild1(preL + numLeft + 1, preR, i + 1, inR);
	return root;
}

node *rebuild2(int postL, int postR, int inL, int inR) {
	if (postL > postR) {
		return NULL;
	}
	node *root = new node;
	root->data = post[postR];
	int i = inL;
	while (i <= inR) {
		if (in[i] == post[postR]) {
			break;
		}
		i++;
	}
	int numLeft = i - inL;
	root->lchild = rebuild2(postL, postL + numLeft - 1, inL, i - 1);
	root->rchild = rebuild2(postL + numLeft, postR - 1, i + 1, inR);
	return root;
}

void layer(node *root) {
	if (!root) {
		return;
	}
	queue<node * > que;
	que.push(root);
	while (!que.empty()) {
		node *temp = que.front();
		printf("%d ", temp->data);
		que.pop();
		if (temp->lchild) {
			que.push(temp->lchild);
		}
		if (temp->rchild) {
			que.push(temp->rchild);
		}
	}
}

int main() {
	printf("前序+中序，构建树\n");
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) {
		scanf("%d", &pre[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
	}
	node *root = new node;
	root = rebuild1(0, n - 1, 0, n - 1);
	layer(root);

	printf("\n后序+中序，构建树\n");
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) {
		scanf("%d", &post[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
	}
	root = new node;
	root = rebuild2(0, n - 1, 0, n - 1);
	layer(root);
	return 0;
}
/*
7
4 1 3 2 6 5 7
1 2 3 4 5 6 7

7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
*/