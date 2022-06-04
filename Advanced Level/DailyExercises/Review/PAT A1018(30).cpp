#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;



const int maxn = 501;
const int INF = 100000;


int Cmax,N,Sp,M;

int now_station[maxn];

int G[maxn][maxn];


int d[maxn];

bool visit[maxn] ={false};


vector<int>pre[maxn];

vector<int>res;
vector<int>temp;

int minNeed = INF;
int minRemain = INF;

void Dijkstra(int s){
	fill(d,d+maxn,INF);
	d[s] = 0;

	for(int i = 0; i <= N; i++){
		int u = -1, min = INF;
		for(int j = 0; j <= N; j++){
			if(!visit[j] && d[j] < min){
				min = d[j];
				u = j;
			}
		}
		if(u == -1){
			return;
		}
		
		visit[u] = true;
		
		for(int j = 0; j <= N; j++){
			if(!visit[j] && G[u][j] != INF){
				if(d[u] + G[u][j] < d[j]){
					d[j] = d[u] + G[u][j];
					pre[j].clear();
					pre[j].push_back(u);
				}else if(d[u] + G[u][j] == d[j]){
					pre[j].push_back(u);
				}
			} 
		}
	}
}


void DFS(int index){
	//回到源点 
	if(index == 0){
		temp.push_back(index);
		int remain = 0, need = 0;
		for(int i = temp.size() - 1; i >= 0;i--){
			int id = temp[i];
			if(now_station[id] > 0){
				remain += now_station[id];
			}else{
				if(remain > abs(now_station[id])){
					remain -= abs(now_station[id]);
				}else if(remain <= abs(now_station[id])){
					need += (abs(now_station[id]) - remain);
					remain = 0;
				}
			}
		}
		if(need < minNeed){
			minNeed = need;
			minRemain = remain; 
			res = temp;
		}else if(need == minNeed && remain < minRemain){
			minRemain = remain;
			res = temp;
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
	scanf("%d%d%d%d",&Cmax,&N,&Sp,&M);
	int ac;
	for(int i = 1; i <= N; i++){
		scanf("%d",&ac);
		now_station[i] = ac - Cmax / 2;
	}
	fill(G[0],G[0]+maxn*maxn,INF);
	int a,b,t;
	for(int i = 0; i < M; i++){
		scanf("%d%d%d",&a,&b,&t);
		G[a][b] = G[b][a] = t;
	}
	
	Dijkstra(0);
	
	DFS(Sp);
	
	printf("%d ",minNeed);
	for(int i = res.size() - 1; i >= 0; i--){
		printf("%d",res[i]);
		if(i != 0){
			printf("->");
		}else{
			printf(" ");
		}
	}
	printf("%d\n",minRemain);
	return 0;
}
