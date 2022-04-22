#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const int maxn = 1000;
const int INF = 10000000;

vector<int> G[maxn];

//顶点数，边数 
int N, M;

//入度 
int inDegree[maxn];

//拓扑排序过程
bool topologicalSort(){
	queue<int> que;
	int num = 0; 
	for(int i = 0; i < N; i++){
		//先将所有入度为0的点加入队列 
		if(inDegree[i] == 0){
			que.push(i);
		}
	} 
	while(!que.empty()){
		int front = que.front();
		que.pop();
		//遍历这个点所在的零接表 
		for(int i = 0; i < G[front].size(); i++){
			int tmp = G[front][i];
			G[front][tmp] = INF; 
			//这个点所连接的点的入度都减1 
			inDegree[tmp]--;
			if(!inDegree[tmp]){
				que.push(tmp);
			}
		}
		//清空front所在的边
		G[u].clear(); 
		//记录入队的结点数 
		num++;
	}
	if(num == n){
		return true;
	}else{
		return false;
	}
} 

