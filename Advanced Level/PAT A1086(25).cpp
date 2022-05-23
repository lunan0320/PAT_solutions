#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

int N;
const int maxn = 50;
int pre[maxn],in[maxn];


struct node{
	int data;
	node* left;
	node* right;
};

node* create(int preL,int preR,int inL,int inR){
	if(preL > preR){
		return NULL;
	}
	int k = inL;
	node* root = new node;
	root->data = pre[preL];
	for(; k <= inR; k++){
		if(in[k] == pre[preL]){
			break;
		}
	}
	int numleft = k - inL;
	//注意前序的边界 
	root->left = create(preL + 1,preL + numleft, inL,k-1);
	root->right = create(preL + numleft + 1, preR, k + 1,inR);
	return root; 
}

int count = 0;
void postTravel(node* root){
	if(!root){
		return;
	}
	postTravel(root->left);
	postTravel(root->right);
	
	
	if(count != N-1){
		printf("%d ",root->data); 
	}else{
		printf("%d",root->data);
	}
	count++;
} 



int main(){
	scanf("%d",&N);
	char str[5];
	//push 是pre数组，pop是in数组 
	int preindex = 0;
	int inindex = 0;
	
	stack<int> st;
	
	for(int i = 0; i < 2 * N; i++){
		scanf("%s",&str);
		int temp; 
		if(strcmp(str,"Push") == 0){
			scanf("%d",&temp);
			pre[preindex++] = temp; 
			st.push(temp);
		}else{
			in[inindex++] = st.top();
			st.pop();
		}
	}
	node * root = create(0,N-1,0,N-1);
	postTravel(root);
	return 0;
}
