#include <cstdio>
#include <queue>

using namespace std;

const int maxn = 31;
int N;

struct Node{
	int data;
	Node* left;
	Node* right;
}; 

int postOrder[maxn];	
int inOrder[maxn];


Node* create(int postL, int postR,int inL,int inR){
	if(postL > postR || inL > inR){
		return NULL;
	}
	Node* res = new Node;
	res->data = postOrder[postR];
	int k ;  //分割点 
	for(int i = inL; i <= inR;i++){
		if(inOrder[i] == postOrder[postR]){
			k = i;
			break;
		}
	}
	int size = k - inL;
	res->left = create(postL,postL + size - 1,inL,k-1);
	res->right = create(postL + size ,postR-1,k+1,inR );
}


void BFS(Node* root){
	if(!root){
		return ;
	}
	int cnt  = 0;
	queue<Node*>q;
	q.push(root);
	while(!q.empty()){
		Node* front = q.front();
		q.pop();
		printf("%d",front->data);
		cnt++;
		if(cnt <= N-1){
			printf(" ");
		}
		if(front->left){
			q.push(front->left);
		}
		if(front->right){
			q.push(front->right);
		}
	}
}

int main(){
	scanf("%d",&N);
	for(int i = 0; i < N; i++){
		scanf("%d",&postOrder[i]);
	}
	for(int i = 0; i < N; i++){
		scanf("%d",&inOrder[i]);
	}
	//通过后序和中序构造一棵树 
	Node* root = create(0,N-1,0,N-1);
	//层序遍历
	BFS(root);
	 
	return 0;
}
