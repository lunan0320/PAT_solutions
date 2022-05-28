#include <cstdio>
#include <iostream>
#include <map>
#include <cstring>
using namespace std;

const int maxn = 201;
const int INF = 10000000;

map<string,int>str2int;
map<int,string>int2str;

string start;
int start_id;

int d[maxn],G[maxn][maxn],happys[maxn];

//记录路径上的数目 
int pt[maxn];
//记录前一个结点 
int pre[maxn];
int N, K, st;

bool visit[maxn] = {false};

//最大点权    最短路径条数 
int w[maxn],num[maxn];


void Dijkstra(int s){
	fill(d,d+maxn,INF);
	memset(w,0,sizeof(w));
	memset(num,0,sizeof(num));
	for(int i = 0; i < N;i++){
		pre[i] = i;
	}
	d[s] = 0;
	num[s] = 1;
	w[s] = happys[s];
	
	for(int i = 0;i < N;i++){
		int u = -1,min = INF;
		for(int j = 0; j < N;j++){
			if(!visit[j] && d[j] < min){
				min = d[j];
				u = j;
			}
		}
		if(u==-1){
			return;
		}
		visit[u] = true;
		for(int j = 0; j < N; j++){
			if(!visit[j] && G[u][j] != INF){
				if(d[u] + G[u][j] < d[j]){
					d[j] = d[u] + G[u][j];
					num[j] = num[u];
					w[j] = w[u] + happys[j];
					pt[j] = pt[u] +1;
					pre[j] = u;
				}else if (d[u] + G[u][j] == d[j]){
					num[j] += num[u];
					if(w[j] < w[u] + happys[j]){
						w[j] = w[u] + happys[j];
						pre[j] = u;
						pt[j] = pt[u] + 1;
					} else if(w[j] == w[u] + happys[j]){
						double avg_j = 1.0 * w[j] / pt[j];
						double avg_u = 1.0 * (w[u] + happys[j]) / (pt[u] +1);
						if(avg_u > avg_j){
							pre[j] = u;
							pt[j] = pt[u] + 1;
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
	cin >> N >> K >> start;
	str2int[start] = 0;
	int2str[0] = start; 
	
	string c;
	int happy;
	for(int i = 1; i < N; i++){
		cin >> c >> happy;
		str2int[c] = i;
		happys[i] = happy;
		int2str[i] = c;
	}
	fill(G[0],G[0]+maxn*maxn,INF);
	string c1,c2;
	int id1,id2,len;
	for(int i = 0; i < K;i++){
		cin >> c1 >> c2 >> len;
		id1 = str2int[c1];
		id2 = str2int[c2];
		G[id1][id2] = len;
		G[id2][id1] = len;
	}
	
	Dijkstra(0);
	int dst = str2int["ROM"];
	printf("%d %d %d %d\n",num[dst],d[dst],w[dst],(int)w[dst]/pt[dst]);
	printPath(dst); 
	return 0;
}
