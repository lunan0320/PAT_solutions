#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 21;

struct Node{
	int id;
	char c[11];
	Node* left;
	Node* right;
}nodes[maxn];


int N;
int root;
bool isRoot[maxn] = {false};

void DFS(Node* x){
	if(x == NULL){
		return ;
	}
	bool flag = false;
	if(x->left || x->right){
		flag = true; 
	}
	if(flag && root  != x->id){
		printf("("); 
	}
	DFS(x->left);
	printf("%s",x->c); 
	DFS(x->right);
	if(flag && root  != x->id){
		printf(")"); 
	}
}


int main(){
	scanf("%d",&N);
	fill(isRoot,isRoot+N,true);
	for(int i = 1;i <= N;i++){
		nodes[i].id = i;
	}
	for(int i = 1; i <= N; i++){
		int l,r;
		scanf("%s%d%d",nodes[i].c,&l,&r);
		if(l > 0){
			isRoot[l] = false;
			nodes[i].left = &nodes[l];
		}
		if(r > 0){
			isRoot[r] = false;
 			nodes[i].right = &nodes[r];
		}
	}
	
	for(int i = 1;i <= N; i++){
		if(isRoot[i]){
			root = i;
			break; 
		} 
	} 
	DFS(&nodes[root]);
	return 0;
}
