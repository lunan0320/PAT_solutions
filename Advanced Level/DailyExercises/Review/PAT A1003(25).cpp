#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


const int maxn = 11;


struct Node{
	int id;
	int left;
	int right;
}nodes[maxn];

int N;

bool isRoot[maxn] = {false};

void postOrder(int root){
	if(root == -1){
		return;
	}
	postOrder(nodes[root].left);
	postOrder(nodes[root].right);
	swap(nodes[root].left,nodes[root].right);
}

int num2 = 0;
void inOrder(int root){
	if(root == -1){
		return;
	}
	inOrder(nodes[root].left);

	printf("%d",root);
	num2++;
	if(num2 < N){
		printf(" ");
	}else{
		printf("\n");
	}
	inOrder(nodes[root].right);
}
void BFS(int root){
	queue<int> q;
	q.push(root);
	int count = 0;
	while(!q.empty()){
		int front = q.front();
		q.pop();
		printf("%d",front);
		count++;
		if(count < N){
			printf(" ");
		}else{
			printf("\n");
		}
		if(nodes[front].left != -1 ){
			q.push(nodes[front].left);
		}
		if(nodes[front].right != -1){
			q.push(nodes[front].right);
		}
	}
}

int main(){
	scanf("%d",&N);
	string data;
	for(int i = 0; i < N; i++){
		nodes[i].id = i;
	}
	fill(isRoot,isRoot + N, true);
	for(int i = 0; i < N; i++){
		cin >> data;
		int temp_data;
		if(data == "-"){
			temp_data = -1;
		}else{
			temp_data = stoi(data);
			isRoot[temp_data] = false;
		}
		nodes[i].left = temp_data;
	//	printf("left:%d ",temp_data);
		getchar();
		cin >> data;
		if(data == "-"){
			temp_data = -1;
		}else{
			temp_data = stoi(data);
			isRoot[temp_data] = false;
		}
		nodes[i].right = temp_data;
	//	printf(" right:%d\n",temp_data);
	}
	
	int root ;
	for(int i = 0; i < N; i++){
		if(isRoot[i] == true){
			root = i;
			break;
		}
	}
	postOrder(root);
	BFS(root);
	inOrder(root);
	return 0;
}
