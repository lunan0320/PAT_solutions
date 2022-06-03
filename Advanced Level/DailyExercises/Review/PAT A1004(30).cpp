#include <bits/stdc++.h>
using namespace std;

int N, M;

const int maxn = 101;

struct Node{
	int id;
	vector<int> child;
}nodes[maxn];

//每个结点的层号 
int level[maxn] = {0};

int maxLevel = 0;

int HashTable[maxn] = {0};

bool inque[maxn] = {false};

 
void BFS(int index){
	queue<int> q;
	q.push(index);
	inque[index] = true;
	level[index] = 1;
	while(!q.empty()){
		int front = q.front();
		q.pop();
		int size = nodes[front].child.size() ;
		maxLevel = max(level[front],maxLevel); 
		if(size){
			for(int i = 0; i< size; i++){
				if(!inque[nodes[front].child[i]]){
					inque[nodes[front].child[i]] = true;
					q.push(nodes[front].child[i]);
					level[nodes[front].child[i]] = level[front] + 1;
				}
			}			
		}else{
			HashTable[level[front]]++;
		}
	}
}


void DFS(int index,int lev){
	int size = nodes[index].child.size();
	maxLevel = max(level[index],maxLevel);
	if( size == 0){
		HashTable[level[index]]++;
	}else{
		for(int i = 0; i < size; i++){
			int id = nodes[index].child[i];
			level[id] = level[index] + 1;
			DFS(id,level[id]);
		}
	}
}

int main(){
	scanf("%d%d",&N,&M);
	int id;
	for(int i = 0; i < M; i++){
		scanf("%d",&id);
		int child_num;
		scanf("%d",&child_num);
		int child_id;
		for(int j = 0; j < child_num; j++){
			scanf("%d",&child_id);
			nodes[id].child.push_back(child_id);
		}
	} 
	
//	BFS(1);
	level[1] = 1;
	DFS(1,0);
	for(int i = 1; i <= maxLevel; i++){
		printf("%d",HashTable[i]);
		if(i < maxLevel){
			printf(" ");
		}
	}
	
	return 0;
}
