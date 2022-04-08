#include <cstdio>
#include <vector>

using namespace std;


struct node {
	int data;
	node *left, *right;
	node() {

	}
	node(int x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

void insertBST(node *&root, int x) {
	if (root == NULL) {
		root = new node(x);
		return ;
	}
	if (root->data > x) {
		insertBST(root->left, x);
	} else {
		insertBST(root->right, x);
	}
}

int n, data;

vector<int> input_data;
vector<int> pre, preM, post, postM;

void preOrder(node *root) {
	if (!root) {
		return;
	}
	pre.push_back(root->data);
	preOrder(root->left);
	preOrder(root->right);
}

void preMirror(node *root) {
	if (!root) {
		return;
	}
	preM.push_back(root->data);
	preMirror(root->right);
	preMirror(root->left);
}

void postOrder(node *root) {
	if (!root) {
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	post.push_back(root->data);
}

void postMirror(node *root) {
	if (!root) {
		return;
	}
	postMirror(root->right);
	postMirror(root->left);
	postM.push_back(root->data);
}

int main() {
	scanf("%d", &n);
	node *root = NULL;
	for (int i = 0; i < n; i++) {
		scanf("%d", &data);
		input_data.push_back(data);
		insertBST(root, data);
	}
	preOrder(root);
	preMirror(root);
	if (input_data == pre) {
		printf("YES\n");
		postOrder(root);
		for (int i = 0; i < post.size(); i++) {
			printf("%d", post[i]);
			if (i < post.size() - 1) {
				printf(" ");
			}
		}
	} else if (input_data == preM) {
		printf("YES\n");
		postMirror(root);
		for (int i = 0; i < postM.size(); i++) {
			printf("%d", postM[i]);
			if (i < postM.size() - 1) {
				printf(" ");
			}
		}
	} else {
		printf("NO");
	}
	return 0;
}
/*

7
8 6 5 7 10 8 11

*/