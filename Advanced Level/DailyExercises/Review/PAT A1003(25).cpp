#include <cstdio>
#include <algorithm>

using namespace std;
 

const int INF = 1000000;
const int maxn = 501;

int G[maxn][maxn];

int N, M, C1, C2;

int weight[maxn];

//记录最短路径 
int d[maxn];

//记录是否访问过
bool visit[maxn] = {false};

//记录路径的数量以及最大的点权和 
int num[maxn], w[maxn]; 

 
void Dijkstra(int s){
	fill(num,num+maxn,0);
	fill(w,w+maxn,0);
	fill(d,d+maxn,INF);
	
	d[s] = 0;
	w[s] = weight[s];
	num[s] = 1;
	
	
	 
	for(int i = 0; i < N;i++){
		//从 V-S中找 
		int u = -1,min = INF;
		for(int j = 0; j < N;j++){
			if(!visit[j] && d[j] < min){
				min = d[j];
				u = j;
			} 
		}
		//如果找不到这样的点
		if(u == -1){
			return ;
		} 
		//访问u
		visit[u] = true; 
		//找到后，更新
		for(int j = 0; j < N; j++){
			//如果没用访问且有边存在 
			if(!visit[j] && G[u][j] != INF){
				if(d[u] + G[u][j] < d[j]){
					//找到更短的路径的时候 
					d[j] = d[u] + G[u][j];
					//点权和  
					w[j] = weight[j] + w[u];
					//路径数量
					num[j] = num[u]; 
				}else if(d[u] + G[u][j] == d[j]){
					//路径相等时候 
					if(w[u] + weight[j] > w[j]){
						w[j] = w[u] + weight[j];	
					}
					//路径条数
					num[j] = num[j] + num[u]; 
				}
			}

		} 
		
		
	}
}

int main(){
	scanf("%d%d%d%d",&N,&M,&C1,&C2);
	for(int i = 0; i < N;i++){
		scanf("%d",&weight[i]);
	}
	//初始化G
	fill(G[0],G[0] + maxn * maxn, INF);
	int a,b,l;
	for(int i = 0; i < M; i++){
		scanf("%d%d%d",&a,&b,&l);
		G[a][b] = l;
		G[b][a] = l;
	}
	//从C1开始的单源最短路径 
	Dijkstra(C1); 
	printf("%d %d\n",num[C2],w[C2]);
	return 0;
} 
