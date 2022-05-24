#include <cstdio>
#include <vector>

using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

int N;
void insert(node*& root,int data){
	if(root == NULL){
		root = new node;
		root->data = data;
		root->left = NULL;
		root->right = NULL;
		return;
	}
	if(data < root->data){
		insert(root->left,data);
	}else{
		insert(root->right,data);
	}
}

void preTravel(node* root, vector<int>& pre){
	if(root == NULL){
		return;
	}
	pre.push_back(root->data);
	preTravel(root->left,pre);
	preTravel(root->right,pre);
}
void postTravel(node* root,vector<int>&post){
	if(root == NULL){
		return;
	}
	postTravel(root->left,post);
	postTravel(root->right,post);
	post.push_back(root->data);
}

void preMTravel(node* root,vector<int>& preM){
	if(root == NULL){
		return;
	}
	preM.push_back(root->data);
	preMTravel(root->right,preM);
	preMTravel(root->left,preM);
} 

void postMTravel(node* root,vector<int>& postM){
	if(root == NULL){
		return;
	}
	postMTravel(root->right,postM);
	postMTravel(root->left,postM);
	postM.push_back(root->data);
}


vector<int> orign,pre,post,preM,postM;
int main(){
	scanf("%d",&N);
	int data;
	node* root = NULL;
	for(int i = 0; i < N;i++){
		scanf("%d",&data);
		orign.push_back(data);
		insert(root,data);
	}
	preTravel(root,pre);
	preMTravel(root,preM);
	postTravel(root,post);
	postMTravel(root,postM);
	if(orign == pre){
		printf("YES\n");
		//给出的是pre，则返回post
		for(int i = 0; i < post.size();i++){
			printf("%d",post[i]);
			if(i != post.size() - 1){
				printf(" ");
			}
		} 
	}else if (orign == preM){
		printf("YES\n");
		//给出的是mirror 的pre，返回mirror 的post
		for(int i = 0; i < postM.size();i++){
			printf("%d",postM[i]);
			if(i != postM.size()){
				printf(" ");
			}
		} 
	}else{
		printf("NO\n");
	}
	return 0;
}


















