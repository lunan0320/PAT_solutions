#include <cstrdio>
#include <vector>

using namespace std;

 
const int maxn = 1000;
const int INF = 100000000;

int G[maxn][maxn];
bool visit[maxn] = {false};//表示这个点是否被访问 
int d[maxn] = {INF}//表示s到这个点是否连通
int n;  //顶点数 


/*

邻接矩阵 

*/
void Dijkstra(int s){
	d[s] = 0;
	for(int i = 0;i < n; i ++){ //遍历每个顶点 
		int u = -1;
		int MIN = INF;
		for(int j = 0; j < n; j++){ //找到剩下未访问点的最小的距离
			if(!visit[j] && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1){  //如果说没有和s连通的点，那就返回 
			return ;
		}
		//接下来是对和未访问的点的处理
		visit[u] = true;
		for(int j = 0; j < n; j++){  //判断剩下的点的信息，是否满足加上这个点会更短 
			if(!visit[j] && G[u][j] && d[u] + G[u][j]< d[j] ){ //如果j未放问，且和u有边，且加入u更短，那么更新 
				d[j] = d[u] + G[u][j];
			}
		} 
	}
} 
 
 
 
 /*
 邻接表法 
 */
 
 struct Node{
 	int v,dis;
 };
 
 vector<Node> Adj[maxn];
 
 void Dijkstra_vector(int s){
 	//初始条件设自己到自己的最短距离是0 
 	d[s] = 0;
 	for(int i = 0; i < n; i++){ //依次寻找n个点的最短路径 
 		int MIN = INF, u = -1;
		for(int j = 0; j < n; j++){ //找一个未访问的最短的点u 
			if(!visit[j] && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}	
		if(u == -1){
			return ; //表示没有点和u连通了 
		} 
		visit[u] = true;
		for(int j = 0; j < Adj[u].size(); j++){
			if(!visit[j] && Adj[u][j].dis + d[u] < d[j] ){
				d[j] = Adj[u][j].dis+ d[u];
			}
		}
	} 
 	
 }
