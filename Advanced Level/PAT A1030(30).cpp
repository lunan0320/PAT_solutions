#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 501;
const int INF = 1000000;

int N,M,S,D;

//记录distance 
int G[maxn][maxn];

//记录路径cost
int cost[maxn][maxn];
 
//记录最短distance
int d[maxn];

//记录是否被访问过
bool visit[maxn] = {false};
 
vector<int> pre[maxn];
 
vector<int> temp;
 
 //判断最小值条件 
int minCost = INF;
vector<int> resPath;


void Dijkstra(int s){
	fill(d,d+maxn,INF);
	//初始化 
	d[s] = 0;
	for(int i = 0; i < N; i++){
		int u = -1, min = INF;
		for(int j = 0; j < N; j++){
			if(!visit[j] && d[j] < min){
				min = d[j];
				u = j;
			}	
		}
		//没有找到最小的u
		if(u == -1){
			return;
		} 
		//设置已访问
		visit[u] = true;
		for(int j = 0; j < N; j++){
			if(!visit[j] && G[u][j] != INF){
				if(d[u] + G[u][j] < d[j]){
					d[j] = G[u][j] + d[u];
					pre[j].clear();
					pre[j].push_back(u);
				}else if (d[u] + G[u][j] == d[j]){
					pre[j].push_back(u);
				}
			}
		} 
	} 
}

void DFS(int index){
	//递归到路径起点 
	if(index == S){
		int tempCost = 0;
		temp.push_back(index);
		//从后向前 
		for(int i = temp.size() -1 ;i >= 1;i--){
			int id = temp[i];
			int id_next = temp[i-1];
			tempCost += cost[id][id_next];
			
		}
		if(tempCost < minCost){
			minCost = tempCost;
			resPath = temp;
		} 
		temp.pop_back();
		return;
	}
	temp.push_back(index);
	for(int i = 0; i < pre[index].size();i++){
		DFS(pre[index][i]);
	}
	temp.pop_back();
}

int main(){
	scanf("%d%d%d%d",&N,&M,&S,&D);
	fill(G[0],G[0] + maxn * maxn, INF);
	fill(cost[0],cost[0] + maxn * maxn, INF);
	int a,b,c,t;
	for(int i = 0; i < M; i++){
		 scanf("%d%d%d%d",&a,&b,&c,&t);
		 G[a][b] = G[b][a] = c;
		 cost[a][b] = cost[b][a] = t;
	}
	
	Dijkstra(S);
	
	DFS(D);
	for(int i = resPath.size() - 1; i >= 0;i--){
		printf("%d ",resPath[i]);
	}
	printf("%d %d",d[D],minCost);
	
	
	return 0;
}
