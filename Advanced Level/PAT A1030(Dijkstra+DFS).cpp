#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;


const int maxn = 1000;
const int INF = 10000000;

vector<int> pre[maxn]; 
vector<int> res_path;
vector<int> tempPath;
int Mincost = INF;

struct Node{
	int dist;
	int cost;
};

Node G[maxn][maxn];
int d[maxn];
bool visit[maxn] = {false};


int N, M, S, D;

void Dijkstra(int s){
	fill(d,d+maxn,INF);
	d[s] = 0;
	for(int i = 0; i< N; i++){
		//找一个连通的最短的 
		int u = -1, MIN = INF;
		for(int j = 0; j < N; j++){
			if(!visit[j] &&  d[j] < MIN){
				u = j;
				MIN = d[u];
			} 
		}
		if(u==-1){
			return ;
		}
		//访问该结点 
		visit[u] = true;
		//处理过程 
		for(int j = 0; j < N; j++){
			//前提是结点存在，且未访问 
			if(!visit[j] && G[u][j].dist != INF){
				//长度更短，那就替换 
				if(d[u] + G[u][j].dist < d[j]){
					d[j] = d[u] + G[u][j].dist;
					pre[j].clear();
					pre[j].push_back(u);
				//相同长度则直接放入pre 
				}else if(d[u] + G[u][j].dist == d[j]){
					pre[j].push_back(u);
				}
			}
		}	
	}
}
bool tag = false;
void DFS(int v){
	if(v == S){
		tempPath.push_back(v);
		int tempCost = 0;
		for(int  i =  tempPath.size() -1;i > 0; i --){
			int nextID = tempPath[i-1]; 
			int id = tempPath[i];
			tempCost += G[id][nextID].cost;
		} 
		if(tempCost < Mincost){
			Mincost = tempCost;
			res_path = tempPath;
		}
		//此处也要pop一次，此处是if语句中的pop 一次push对应一次pop 
		tempPath.pop_back();
		return; 
	}
	//依次pushback到tempPath中的是一条最短路径 
	tempPath.push_back(v);
	for(int i = 0; i < pre[v].size(); i++){
		DFS(pre[v][i]);
	}
	tempPath.pop_back();
}

int main(){
	scanf("%d%d%d%d", &N, &M, &S, &D);
	//初始化图 
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			G[i][j].dist = INF;
			G[i][j].cost = INF;
		}
	}
	//输入图的距离和花费 
	int C1, C2, dist, cost;
	for(int i = 0; i < M; i++){
		scanf("%d%d%d%d", &C1, &C2, &dist, &cost);
		G[C1][C2].dist = dist;
		G[C1][C2].cost = cost;
		G[C2][C1].dist = dist;
		G[C2][C1].cost = cost;
	}

	//找到最短路径，所有的最短路径对应放在pre[v]中 
	Dijkstra(S);
	//DFS找最短路径下对应的最小的cost 
	DFS(D); 
	for(int i = res_path.size()-1 ; i >= 0 ;i--){
		printf("%d ",res_path[i]);
	}
	printf("%d %d",d[D],Mincost);
	 
	return 0;
} 

/*

4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20

*/

