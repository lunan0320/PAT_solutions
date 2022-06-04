#include <cstdio>
#include <string>
#include <iostream>
#include <cctype>
using namespace std;


const int maxn = 1001;
const int INF = 1000000;

int N, M, K, Ds;

int G[maxn][maxn];

int d[maxn];

bool visit[maxn] = {false};

int res_index ;
double res_dist = -1, res_avg = 0;
double temp_dist = -1,temp_avg = 0;

void Dijkstra(int s){
	fill(d,d+maxn,INF);
	fill(visit,visit+maxn,false);
	
	d[s] = 0;
	
	for(int i = 0; i < N + M; i++){
		int u = -1,min = INF;
		for(int j = 1; j <= N+ M; j++){
			if(!visit[j] && d[j] < min){
				min = d[j];
				u = j;
			}
		}
		if(u == -1){
			return;
		}
		visit[u] = true;
		for(int j = 1; j <= N + M; j++){
			if(!visit[j] && G[u][j] != INF){
				if(d[j] > d[u] + G[u][j]){
					d[j] = d[u] + G[u][j];
				}
			}
		}
	}
	
}

int main(){
	scanf("%d%d%d%d",&N,&M,&K,&Ds);
	//1-N表示N个居民房   N+1 ~ N + M 表示加油站 
	string a,b;
	int a1,b1;
	int value;
	fill(G[0],G[0] + maxn * maxn,INF);
	for(int i = 0; i < K; i++){
		 cin >> a >> b >> value;
		 if(a[0] == 'G'){
		 	a1 = (a[1] - '0') + N;
		 }else{
		 	a1 = stoi(a);
		 }
		 if(b[0] == 'G'){
		 	b1 = (b[1] - '0') + N;
		 }else{
		 	b1 = stoi(b);
		 }
		 //cout << a1 <<" "<< b1 << " "<< value <<endl;
		 G[a1][b1] = G[b1][a1] = value;
	}
	
	for(int i = N+1; i <= N + M; i++){
		temp_avg = 0;
		temp_dist = INF;
		Dijkstra(i);
		for(int j =1 ; j <= N; j++){
			if(d[j] > Ds){
				temp_dist = -1;
				break;
			}
			if(d[j] < temp_dist){
				temp_dist = d[j];
			}
			temp_avg += 1.0* d[j]/N;
		}
		if(temp_dist == -1){
			continue;
		}
		if(temp_dist > res_dist){
			res_index = i - N;
			res_dist = temp_dist;
			res_avg = temp_avg;
		}else if(temp_dist == res_dist && temp_avg < res_avg){
			res_index = i - N;
			res_avg = temp_avg;
		}
	}
	if(res_dist == -1){
		printf("No Solution\n");
	}else{
		printf("G%d\n",res_index);
		printf("%.1f %.1f\n",res_dist,res_avg);
	}
	return 0;
}
