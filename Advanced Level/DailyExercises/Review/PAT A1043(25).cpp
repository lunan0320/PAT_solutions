#include <cstdio>


const int maxn = 10001;

struct Node{
	int data;
	Node* left;
	Node* right;
	Node(){
		left = NULL;
		right = NULL;
	}
};	

Node* root = NULL;
int N;
int preOrder[maxn];

int m = 0, n = 0;
int treePre[maxn];
int treePost[maxn];

int m2 = 0, n2 = 0;
int mirrorPre[maxn];
int mirrorPost[maxn];


void insert(Node*& root,int v){
	if(root == NULL){
		root = new Node;
		root->data = v;
	}else if(root->data > v){
		insert(root->left,v);
	}else{
		insert(root->right,v);
	}
}


void dfs(Node*& root){
	if(root == NULL){
		return;
	}
	treePre[m++] = root->data;
	dfs(root->left);
	dfs(root->right);
	treePost[n++] = root->data;
}

void mirror(Node*& root){
	if(root == NULL){
		return;
	}
	mirrorPre[m2++] = root->data;
	mirror(root->right);
	mirror(root->left);
	mirrorPost[n2++] = root->data;
}

bool cmp(int a[], int b[]){
	for(int i = 0; i < N; i++){
		if(a[i] != b[i]){
			return false;
		}
	}
	return true;
}

void print(int a[]){
	for(int i = 0; i < N; i++){
		printf("%d",a[i]);
		if(i < N - 1){
			printf(" ");
		}else{
			printf("\n");
		}
	}
}
int main(){
	scanf("%d",&N);

	
	for(int i = 0,v; i < N; i++){
		scanf("%d",&v);
		preOrder[i] = v;
		insert(root,v);
	}


	dfs(root);
	mirror(root);
	
	if(cmp(treePre,preOrder)){
		printf("YES\n");
		print(treePost);
	}else if(cmp(mirrorPre,preOrder)){
		printf("YES\n");
		print(mirrorPost);
	}else{
		printf("NO\n");
	}
	
	return 0;
}
