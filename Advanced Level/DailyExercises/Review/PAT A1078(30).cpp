#include <cstdio>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>
#include <cstring> 
using namespace std;

int N,K;
string start;

const int maxn = 201;
const int INF = 10000000;

map<string,int> str2int;
map<int,string> int2str;

int weight[maxn];

int G[maxn][maxn];

int d[maxn];

bool visit[maxn] = {false};

//到达i的最短路径的数量 
int num[maxn] = {0};

//到达i的最大happiness 
int w[maxn] ;

//到达i的最短路径上结点数量 
int pt[maxn] = {0};

int pre[maxn];

void Dijkstra(int s){
	fill(d,d+maxn,INF);
	fill(visit,visit + maxn, false);
	memset(num,0,sizeof(num));
	memset(w,0,sizeof(w)); 
	for(int i = 0; i < N; i++){
		pre[i] = i;
	}
	d[s] = 0;
	num[s] = 1;
	w[s] = weight[s];
	pre[s] = -1;
	pt[s] = 1;
	 
	for(int i = 0; i < N; i++){
		int u = -1,min = INF;
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
				if(d[u] + G[u][j] < d[j]){
					d[j] = d[u] + G[u][j];
					pt[j] = pt[u] + 1;//路径上的结点数 
					num[j] = num[u]; //更新路径数量 
					pre[j] = u;
 					w[j] = w[u] + weight[j]; //更新最大的happiness 
				}else if(d[u] + G[u][j] == d[j]){
					pt[j] = pt[u]; 
					num[j] += num[u]; //更新路径数量 
					if(w[j] < w[u] + weight[j]){
						w[j] = w[u] + weight[j];
						pt[j] = pt[u] + 1; 
						pre[j] = u;
					}else if(w[j] == w[u] + weight[j]){
						double avg_u = 1.0 * (w[u] + weight[j])/(pt[u]+1);
						double avg_j = 1.0 * w[j]/pt[j];
						if(avg_u > avg_j){
							pt[j] = pt[u] + 1;
							pre[j] = u;
						}
						
					}
				}
			}
		}
	}
}

void printPath(int v){
	if(v == 0){
		cout << int2str[v];
		return;
	}
	printPath(pre[v]);
	cout << "->" <<int2str[v];
}

int main(){
	string s ;

	int temp_w; 
	cin >> N >> K >> start;
	str2int[start] = 0;
	int2str[0] = start;
	int start_id = 0;
	
	for(int i = 1; i < N; i++){
		cin >> s >> temp_w;
		str2int[s] = i;
		int2str[i] = s;
		weight[i] = temp_w;
	} 
	fill(G[0],G[0] + maxn * maxn,INF);
	
	string s1 ;
	string s2 ;
	int value;
	for(int i = 0; i < K; i++){
		cin >> s1 >> s2 >>value;
		int id1 = str2int[s1];
		int id2 = str2int[s2];
		G[id1][id2] = G[id2][id1] = value;
	}
	
	Dijkstra(0);
	int end_id = str2int["ROM"]; 
	cout << "ROM_ID:"<<end_id<<endl; 
	printf("%d %d %d %d\n",num[end_id],d[end_id],w[end_id],w[end_id] / (d[end_id] - 1));

	printPath(end_id);
	
	return 0;
} 
