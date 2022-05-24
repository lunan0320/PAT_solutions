//AVLƽ�����������

#include <cstdio>
#include <algorithm>
using namespace std;

struct node{
	int data;//Ȩֵ
	int height;//�߶� 
	node* left;
	node* right;
}; 

int N,V;
node* root;


//����Ȩֵ������һ����� 
node* newNode(int v){
	node* temp_node = new node;
	temp_node->data = v;
	temp_node->height = 1; 
	temp_node->left = temp_node->right = NULL;
	return temp_node;
}

//��ȡ���ĸ߶� 
int height(node* root){
	if(root == NULL){
		return 0;
	}else{
		return root->height;
	}
} 

//���¸߶� 
void update(node* root){
	root->height = max(height(root->left),height(root->right)) + 1;
}

//��ƽ������ 
int balanceFactor(node* root){
	return height(root->left) - height(root->right);
} 


//���� 
void L_rotation(node* &root){
	node* temp = root->right;
	root->right = temp->left;
	temp->left = root;
	update(root);
	update(temp);
	root = temp;
}

//���� 
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
	//���֧���� 
	if(data < root->data){
		insert(root->left, data);
		//��������
		update(root);
		int balance = balanceFactor(root);
		//LL�� 
		if(balance == 2){
			if(balanceFactor(root->left) == 1){
				//����LL��ֱ������ 
				R_rotation(root); 
			} else if (balanceFactor(root->left) == -1){
				//LR�ͣ���������������������������
				L_rotation(root->left);
				R_rotation(root); 
			}
		}
	}else{
		//����������
		insert(root->right,data);
		update(root);
		int balance = balanceFactor(root);
		if(balance == -2){
			if(balanceFactor(root->right) == -1){
				//RR�ͣ�ֱ������
				L_rotation(root); 
			} else if(balanceFactor(root->right) == 1){
				//RL�ͣ���������תΪRR�ͣ������� 
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
