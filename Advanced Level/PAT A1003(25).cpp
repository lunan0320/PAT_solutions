#include <cstdio>
#include <cstring>
#include <algorithm> 


using namespace std;


const int maxn = 1000;


const int INF = 100000000;

//记录最短距离 
int d[maxn];

//记录边权
int G[maxn][maxn];

//记录点权
int  weight[maxn]; 

//记录是否访问
bool visit[maxn] = {false};

//记录路径数，和最大权数和
int num[maxn],w[maxn];
 
int N, M, start,ed;

void Dijkstra(int s){
	fill(d,d+maxn,INF);
	memset(num,0,sizeof(num));
	memset(w,0,sizeof(num));
	//设置自己的距离
	d[s] = 0;
	//到达s的最大权和是weight[s] 
	w[s] = weight[s];
	//到达s的最大路径数量 
	num[s] = 1;
	
	//循环n次
	
	for(int i = 0; i < N; i++){
		//在未访问的集合中找到距离s最小的u 
		int u = -1,min = INF;
		for(int j = 0; j < N; j++){
			if(!visit[j] && d[j] < min){
				min = d[j];
				u = j;
			} 
		}
		//如果没有找到u
		if(u == -1){
			return;
		} 
		//找到最小的u，就去更新 
		visit[u] = true;
		for(int j = 0; j < N;j++){
			//如果j未访问，且能从u到j，且u为中介更优
			if(!visit[j] && G[u][j]!= INF ){
				if(d[u] + G[u][j] < d[j]){
					d[j] = d[u] + G[u][j];
					w[j] = w[u] + weight[j];
					num[j] = num[u];   //路径条数不变 
				}else if (d[u] + G[u][j] == d[j]){ //路径相同 
					if(w[u] + weight[j] > w[j]){  //权和更大 
						w[j] = w[u] + weight[j]; //更新权和 
					}
					num[j] += num[u]; //最短路径数量加1 
				} 
			} 
		}
	} 
}



int main(){
	scanf("%d%d%d%d",&N,&M,&start,&ed);
	for(int i = 0; i < N; i++){
		scanf("%d",&weight[i]);
	}
	fill(G[0],G[0]+maxn*maxn,INF); 
	int a, b,c;
	for(int i = 0; i < M; i++){
		scanf("%d%d%d",&a,&b,&c);
		G[a][b] = G[b][a] = c;
	}
	Dijkstra(start);
	printf("%d %d\n",num[ed],w[ed]);
	return 0;
} 
