#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>


using namespace std;


struct Node{
	int v;
	int dist;
	Node(int _v, int _dist):v(_v),dist(_dist){
	}
}; 

const int maxn = 1000;
const int INF = 0x3fffffff;

vector<Node> Adj[maxn];
int d[maxn];

//w用来统计最大点权之和，num用来统计最短路径的数量 
int w[maxn],num[maxn];
//set中记录前驱 
set<int> pre[maxn];

int N, M, S, D,weight[maxn];


void Bellman(int s){
	fill(d,d+maxn,INF);
	memset(w,0,sizeof(w));
	memset(num,0,sizeof(num));
	//初始化！！！！（——又忘记！！！ 
	d[s] = 0;
	num[s] = 1;
	w[s] = weight[s];
	
	//执行n-1轮操作 
	for(int i = 0; i < N-1; i++){
		//每轮操作遍历所有的边 
		for(int u = 0; u < N; u++){
			for(int j = 0; j < Adj[u].size();j++){
				int v = Adj[u][j].v;
				int dist = Adj[u][j].dist;
				//加入u中介对v最短路径有效果 
				if(d[u] + dist < d[v]){
					//更改路径，最小点权和， 最短路径的数量 
					d[v] = d[u] + dist;
					w[v] = w[u] + weight[v];
					num[v] = num[u];
					pre[v].clear(); 
					pre[v].insert(v);
				} else if(d[u] +dist == d[v]){
					if(w[u] + weight[v] > w[v]){
						w[v] = w[u] + weight[v];
					}
					pre[v].insert(u);
					num[v] = 0;
					set<int>::iterator it;
					for( it = pre[v].begin();it!=pre[v].end();it++){
						num[v] += num[*it];
					}
				} 
				
			}
		}
	}
}


int main(){

	scanf("%d%d%d%d", &N, &M, &S, &D);
	for(int i = 0; i < N ;i++){
		scanf("%d", &weight[i]);
	}
	int c1, c2, dist;
	for(int i = 0; i < M; i++){
		scanf("%d%d%d",&c1,&c2,&dist);
		Adj[c1].push_back(Node(c2,dist));
		Adj[c2].push_back(Node(c1,dist));
	} 
	Bellman(S);
	printf("%d %d",num[D],w[D]);
	for(int i =0; i < N; i++){
		printf("%d ",num[i]);
	}
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
