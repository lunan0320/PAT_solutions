//AVL平衡二叉搜索树

#include <cstdio>
#include <algorithm>
using namespace std;

struct node{
	int data;//权值
	int height;//高度 
	node* left;
	node* right;
}; 

int N,V;
node* root;


//给定权值，构造一个结点 
node* newNode(int v){
	node* temp_node = new node;
	temp_node->data = v;
	temp_node->height = 1; 
	temp_node->left = temp_node->right = NULL;
	return temp_node;
}

//获取结点的高度 
int height(node* root){
	if(root == NULL){
		return 0;
	}else{
		return root->height;
	}
} 

//更新高度 
void update(node* root){
	root->height = max(height(root->left),height(root->right)) + 1;
}

//求平衡因子 
int balanceFactor(node* root){
	return height(root->left) - height(root->right);
} 


//左旋 
void L_rotation(node* &root){
	node* temp = root->right;
	root->right = temp->left;
	temp->left = root;
	update(root);
	update(temp);
	root = temp;
}

//右旋 
void R_rotation(node* &root){
	node* temp = root->left;
	root->left = temp->right;
	temp->right = root;
	update(root);
	update(temp); 
	root = temp;
}

void insert(node* &root,int data){
	if(root == NULL){
		root = newNode(data);
		return;
	}
	//左半支插入 
	if(data < root->data){
		insert(root->left, data);
		//插入后更新
		update(root);
		int balance = balanceFactor(root);
		//LL型 
		if(balance == 2){
			if(balanceFactor(root->left) == 1){
				//对于LL型直接右旋 
				R_rotation(root); 
			} else if (balanceFactor(root->left) == -1){
				//LR型，先左旋左子树，再右旋右子树
				L_rotation(root->left);
				R_rotation(root); 
			}
		}
	}else{
		//右子树插入
		insert(root->right,data);
		update(root);
		int balance = balanceFactor(root);
		if(balance == -2){
			if(balanceFactor(root->right) == -1){
				//RR型，直接左旋
				L_rotation(root); 
			} else if(balanceFactor(root->right) == 1){
				//RL型，先右旋，转为RR型，再左旋 
				R_rotation(root->right);
				L_rotation(root);
			}
		}
	}
}

int main(){
	scanf("%d",&N);
	
	for(int i = 0; i < N; i++){
		scanf("%d",&V);
		insert(root,V);
	}
	printf("%d\n",root->data);
	return 0;
} 
