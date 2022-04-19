#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1000;
const int INF = 10000000;

//注意此处不要在初始的时候直接赋值INF，这是会失败的
//只有赋值0的时候才可d[maxn] = {0},其余需要用到fill函数 
int G[maxn][maxn] ;		//记录图 
int d[maxn]  ;    		//记录最短路径 
bool visit[maxn] = {false};

int n,m,s;  //顶点个数，边数，起点


void Dijkstra(int s){
	fill(d,d+maxn,INF); 
	d[s] = 0;  //设置自身到自身为0
	for(int i = 0; i < n; i ++){ //找每个点 
		int u = -1, MIN = INF;
		for(int j = 0; j < n; j++){			//在未访问区域找个最短的 
			if(!visit[j] && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		} 
		if(u == -1) return; //如果没有找到，说明没有和s连通的了
		visit[u] = true;  //设置该结点为访问
		//如果满足更新条件，就更新最短距离 
		for(int j = 0; j < n; j ++){
			if(!visit[j] && G[u][j] != INF && d[u] + G[u][j] < d[j]){
				d[j] = d[u] + G[u][j];
			}
		} 
	} 
}

int main(){
	scanf("%d%d%d",&n,&m,&s);
	int u,v,w;
	fill(G[0],G[0]+maxn*maxn,INF); 
	for(int i = 0; i < m; i++){  //输入m条边 
		scanf("%d%d%d", &u, &v, &w);
		G[u][v] = w;
	}
	
	Dijkstra(s);
	
	for(int i = 0; i < n; i++){
		printf("%d ",d[i]);
	} 
	return 0;
} 


/*
测试样例：
6 8 0
0 1 1
0 3 4
0 4 4
1 3 2
2 5 1
3 2 2
3 4 3
4 5 3


print
0 1 5 3 4 6 

*/
