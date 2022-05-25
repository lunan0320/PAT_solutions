/*
先找连通块
然后把连通块连接起来即可 

找连通块：图的遍历和并查集 
*/ 


// DFS遍历方式

#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;


const int maxn = 1010;

//当前要删除的结点 
int curQuery;

//N是结点数，M是边数，K是查询数 
int N, M, K; 


vector<int> G[maxn];
 
bool visit[maxn]; 

void DFS(int index){
	//当前遍历的结点是要删除的结点 
	if(index == curQuery){
		return;
	}
	visit[index] = true;
	for(int i = 0; i < G[index].size(); i++){
		if(visit[G[index][i]] == false){
			DFS(G[index][i]);
		}
	}
}

int main(){
	scanf("%d%d%d",&N,&M,&K);
	//一条边的起始和终点 
	int a,b;
	for(int i = 0; i < M; i++){
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int query = 0; query < K; query++){
		scanf("%d",&curQuery);
		//初始化连通块的数量 
		int block = 0;
		memset(visit,false,sizeof(visit));
		for(int i = 1; i <= N; i++){
			if(i != curQuery && !visit[i]){
				DFS(i);
				block++;
			}
		}
		printf("%d\n",block - 1);
	}
	return 0;
} 
