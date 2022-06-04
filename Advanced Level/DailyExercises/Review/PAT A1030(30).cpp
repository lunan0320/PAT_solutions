#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;


const int INF = 1000000;
const int maxn = 501;


int N,M,S,D;

int G[maxn][maxn];
int cost[maxn][maxn];

int d[maxn];
bool visit[maxn] = {false};

int total_cost[maxn];

int pre[maxn];

vector<int> res;
vector<int> temp;
vector<int> pre_vec[maxn];

int min_cost = INF;

void Dijkstra(int s){
	fill(d,d+maxn,INF);
	fill(total_cost,total_cost+maxn,0);
	for(int i = 0; i < N; i++){
		pre[i] = i;
	}
	
	d[s] = 0;
	total_cost[s] = 0;
	pre[s] = -1;
	
	for(int i = 0; i < N; i++){
		int u = -1, min = INF;
		for(int j = 0; j < N; j++){
			if(!visit[j] && d[j] < min){
				min = d[j];
				u = j;
			}
		}
		if(u == -1){
			return;
		}
		visit[u] = true;
		for(int j = 0; j < N; j++){
			if(!visit[j] && G[u][j] != INF){
				//找到更小的 
				if(d[u] + G[u][j] < d[j]){
					d[j] = d[u] + G[u][j];
					total_cost[j] = total_cost[u] + cost[u][j];
					pre[j] = u;
					pre_vec[j].clear();
					pre_vec[j].push_back(u);
  				}else if(d[u] + G[u][j] == d[j]){
  					pre_vec[j].push_back(u);
 					if(total_cost[j] > total_cost[u] + cost[u][j]){
 					
						total_cost[j] = total_cost[u] + cost[u][j];
					 	pre[j] = u;
					 }
				 }
			}
		}
	}
}



void DFS(int index){
	if(index == S){
		temp.push_back(index);
		int temp_cost = 0;
		for(int i = temp.size() - 1; i >= 1; i--){
			int id = temp[i];
			int id_next = temp[i-1];
			temp_cost += cost[id][id_next];
		}
		if(temp_cost < min_cost){
			min_cost = temp_cost;
			res = temp;
		}
		temp.pop_back();
		return;
	}
	temp.push_back(index);
	for(int i = 0; i <pre_vec[index].size(); i++){
		DFS(pre_vec[index][i]);
	}
	temp.pop_back();
}

void print(int a){
	stack<int>st;
	do{
		st.push(a);
		a = pre[a];
	}while(a != -1 );
	while(!st.empty()){
		int top = st.top();
		printf("%d ",top);
		st.pop();
	}

}

void print2(int v){
	if(v == S){
		printf("%d ",v);
		return;
	} 
	print2(pre[v]);
	printf("%d ",v);
}

int main(){
	scanf("%d%d%d%d",&N,&M,&S,&D);
	int c1,c2,dist,Cost;
	fill(G[0],G[0]+maxn*maxn,INF);
	fill(cost[0],cost[0]+maxn*maxn,INF);
	for(int i = 0; i < M;i++){
		scanf("%d%d%d%d",&c1,&c2,&dist,&Cost);
		G[c1][c2] = G[c2][c1] = dist;
		cost[c1][c2] = cost[c2][c1] = Cost; 
	}
	Dijkstra(S); 
//	DFS(D);
//	for(int i = res.size() -1; i >= 0;i--){
//		printf("%d ",res[i]);
//	}
//	printf("%d %d\n",d[D],min_cost);
	print(D);
	printf("%d %d\n",d[D],total_cost[D]);
	return 0;
}
