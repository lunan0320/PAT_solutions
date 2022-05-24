#include <cstdio>
#include <vector>
#include <queue> 
using namespace std;

const int maxn = 110;

//N是总的结点数，M是非叶子结点数 
int N, M;
vector<int> family[maxn];

//记录每一层的非叶子结点数量 
int hashTable[maxn] = {0} ;
int maxDepth = 0;
 
//记录各个结点的层号 
int h[maxn];
 
 
//DFS版本 
void DFS(int index,int level) {
	//内部结点 
	if(family[index].size() == 0){
		hashTable[level]++;
		if(maxDepth < level){
			maxDepth = level;
		}
	}else{
		//枚举所有子节点，再深度搜索 
		for(int i = 0; i < family[index].size(); i++){
			DFS(family[index][i],level + 1);
		}
	}
}



//BFS版本
void BFS(int root,int level){
	queue<int>q;
	q.push(root);
	h[root] = level;
	while(!q.empty()){
		int front = q.front();
		q.pop();
		//更新最大深度 
		maxDepth = max(h[front],maxDepth);
		if(family[front].size()){
			for(int i = 0; i < family[front].size(); i++){
				h[family[front][i]] = h[front] + 1;
				q.push(family[front][i]);
			}
		} else{
			//如果是叶子结点,当前层的结点数加1 
			hashTable[h[front]]++; 
		}
	}
}
 
int main(){
	scanf("%d %d",&N,&M);
	int id, k,child;
	//输入序列 
	for(int i = 0; i < M; i++){
		scanf("%d%d",&id,&k);
		for(int j = 0; j < k; j++){
			scanf("%d",&child);
			family[id].push_back(child);
		}
	}
	//	DFS(1,0);
	
	//BFS版本
	BFS(1,0); 
	for(int i = 0; i <= maxDepth;i++){
		if(i != maxDepth){
			printf("%d ",hashTable[i]);
		}else{
			printf("%d",hashTable[i]);
		}
	} 
	return 0;
}
