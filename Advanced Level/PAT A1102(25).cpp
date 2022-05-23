#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int N;
const int maxn = 50;

bool notRoot[maxn] = {false}; //��ʼΪ����root 

struct node{
	char left;
	char right;
}Node[maxn];

int str2Num(char c){
	if(c == '-'){
		return -1;
	} else{
		notRoot[c-'0'] = true;
		return c-'0';
	}
}

int findRoot(){
	for(int i = 0; i < maxn; i++){
		if(notRoot[i] == false){
			return i;
		}
	}
}
void postTravel(int root){
	if(root == -1){
		return ;
	}
	postTravel(Node[root].left);
	postTravel(Node[root].right);
	//ͨ���������ʱ�򽻻���ʵ��invert 
	swap(Node[root].left,Node[root].right);
}

//������� 
int num = 0;
void BFS(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int front = q.front();
		q.pop();
		if(num != N - 1){
			printf("%d ",front);
		}else{
			printf("%d\n",front);
		}
		num ++;
		if(Node[front].left != -1){
			q.push(Node[front].left);
		} 
		if(Node[front].right != -1){
			q.push(Node[front].right);
		}
	}
}
//������� 
int num2 = 0;
void inTravel(int root){
	if(root == -1){
		return ;
	}
	inTravel(Node[root].left);
	if(num2 != N - 1){
		printf("%d ",root);
	}else{
		printf("%d",root);
	}
	num2 ++; 
	inTravel(Node[root].right);
}
int main(){
	scanf("%d",&N);
	char lchild, rchild;
	for(int i = 0; i < N; i++){
		getchar(); //���ն����ַ� 
		scanf("%c %c",&lchild,&rchild);
		Node[i].left = str2Num(lchild);
		Node[i].right = str2Num(rchild);
	}
	int root = findRoot();
	postTravel(root);
	BFS(root);
	num = 0;
	inTravel(root); 
	return 0;
}
