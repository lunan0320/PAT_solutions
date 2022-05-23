#include <cstdio>
#include <queue>

using namespace std;

int N;
const int maxn = 31;

int post[maxn];
int in[maxn];


struct node{
	int data;
	node* left;
	node* right;
};

//后序和先序来创建树 
node* create(int postL, int postR, int inL, int inR){
	if(postL > postR){
		return NULL;
	}	
	int k = inL;
	for(; k <= inR; k++){
		if(in[k] == post[postR]){
			break;
		}
	}
	node* root = new node;
	root->data = post[postR];
	int numleft = k - inL;
	//注意后序的递归边界 
	root->left = create(postL,postL + numleft - 1, inL, k - 1);
	root->right = create(postL + numleft, postR - 1, k + 1,inR);
	return root;
}

void BFS(node* root){
    queue<node*>q;
	q.push(root);
	int cnt = 0;
	while(!q.empty()){
		node* front = q.front();
		q.pop();
		printf("%d",front->data);
		if(cnt != N-1){
			printf(" ");
		}
		cnt++;
		if(front->left != NULL){
			q.push(front->left);
		}
		if(front->right != NULL){
			q.push(front->right);
		}
	}
}
int main(){
	scanf("%d",&N);
	for(int i = 0; i < N; i++){
		scanf("%d",&post[i]); 
	}
	for(int i = 0; i < N; i++){
		scanf("%d",&in[i]);
	}
	node* root = create(0,N-1,0,N-1);
	BFS(root);	
	return 0;
}
