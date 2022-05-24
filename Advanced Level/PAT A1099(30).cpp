#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int N;

struct node{
	int data;
	int left,right;
};

const int maxn = 110;

node Tree[maxn];
int number[maxn];
int res[maxn];
int index = 0;


void inOrder(int root){
	if(root == -1){
		return;
	}
	inOrder(Tree[root].left);
	Tree[root].data = number[index++];
	inOrder(Tree[root].right);
} 

//��¼����ĸ���
int cnt = 0; 
void BFS(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		int front = q.front();
		q.pop();
		printf("%d",Tree[front].data);
		if(cnt < N - 1){
			printf(" ");
		} 
		cnt++;
		if(Tree[front].left != -1){
			q.push(Tree[front].left);
		}
		if(Tree[front].right != -1){
			q.push(Tree[front].right);
		}
	}
}

int main(){
	scanf("%d",&N);
	int left,right;
	//������ 
	for(int i = 0; i < N; i++){
		scanf("%d%d",&left,&right);
		Tree[i].left = left;
		Tree[i].right = right;
	}
	for(int i = 0; i < N; i++){
		scanf("%d",&number[i]);
	}
	//������������������η������������ 
	sort(number,number+ N);
	//���������ʱ�򣬾Ͷ� 
	inOrder(0);
	BFS(0);
	return 0;
} 


