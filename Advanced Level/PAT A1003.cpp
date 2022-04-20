#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 1000000;
const int maxn = 1000;

int G[maxn][maxn];
int num[maxn] ;  //代表最短路径的数量
int weight[maxn]; //代表点权
int d[maxn]; //代表从起始点到v的最短距离 
int w[maxn]  ; //代表到达点v的最大点权 
bool visit[maxn] = {false};

int N, M, C1, C2;

void Dijkstra(int s){
	memset(w,0,sizeof(w));
	memset(num,0,sizeof(num));
	fill(d,d+maxn,INF);
	//此处要记录自己到自己的最短距离 
	d[s] = 0;
	//此处要记录自己到自己的最短路径 
	num[s] = 1;
	//此处要记录自己到自己的最大权重 
	w[s] = weight[s]; 
	for(int i = 0; i < N; i++){
		int u = -1, MIN = INF;
		//找出一个未访问的最短的 
		for(int j = 0; j < N; j++){
			if(!visit[j] && d[j] < MIN ){
				u = j;
				MIN = d[j];
			}			
		}
		//如果找不到最短的，说明没有和s连通的 
		if(u == -1){
			return;
		}
		//处理有连通的情况
		visit[u] = true;
		for(int j = 0 ; j < N; j++){
			if(!visit[j] && G[u][j] != INF &&d[u] + G[u][j] < d[j]){
				//更新点权和最短路径 
				num[j] = num[u];
				d[j] = d[u] +G[u][j]; 
				w[j] = w[u] + weight[j];
			}else if(!visit[j] && G[u][j] != INF && d[u] + G[u][j] == d[j]){
				num[j] += num[u];
				w[j] = w[u] + weight[j]; //更新点权 
			}
		} 
		
	}
} 

int main(){
	scanf("%d%d%d%d", &N, &M, &C1, &C2);
	//输入N个城市的救援队伍 
	for(int i = 0; i < N;i++){
		scanf("%d", &weight[i]);
	}
	//输入公路和权重
	fill(G[0],G[0]+maxn*maxn,INF);
	int c1,c2,W;
	for(int i = 0; i < M; i++){
		scanf("%d%d%d",&c1,&c2,&weight);
		G[c1][c2] = W;
		G[c2][c1] = W;
	} 
	//输入算法的source 
	Dijkstra(C1);
	//用终点来输出 
	printf("%d %d",num[C2],w[C2]); 
	return 0;
} 


/*

5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
*/
