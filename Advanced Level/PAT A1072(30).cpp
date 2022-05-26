#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 1050;
const int INF = 10000000000;

//N个居民房，M个站点，K条路，Ds限制条件 
int N,M,K,Ds;

//最终结果的最小距离和平均距离 、站点 


int G[maxn][maxn];

//d是从s到i的最短距离 
int d[maxn];

//是否访问过 
bool visit[maxn] = {false};

int change(char str[]){
	int i = 0,len = strlen(str),res = 0;
	while(i < len){
		if(str[i] != 'G'){
			res = res * 10 + (str[i] - '0');
		}
		i++;
	}
	//是一个居民房 
	if(str[0] == 'G'){
		return N + res; 
	}else{
		//是一个站点
		return res; 
	}
}

void Dijkstra(int s){
	
	memset(visit,false,sizeof(visit));
	fill(d,d+maxn,INF);
	//初始化 
	d[s] = 0;
	for(int i = 0; i < N+M;i++){
		int u = -1,min = INF;
		for(int j = 1; j <= N+ M;j++){
			if(visit[j] == false && d[j] < min){
				min = d[j];
				u = j;
			}
		}
		//没有找到
		if(u==-1){
			return;
		} 
		//找到合适的u
		visit[u] = true;
		for(int j = 1;j <= N+M;j++){
			if(!visit[j] && G[u][j] != INF){
				if(d[u] + G[u][j] < d[j]){
					d[j] = d[u] + G[u][j];
				}
			}
		} 
	} 
}


int main(){
	scanf("%d%d%d%d",&N,&M,&K,&Ds);
	char s1[5],s2[5];
	int id1,id2,t; 
	fill(G[0],G[0]+maxn*maxn,INF);
	for(int i = 0; i < K;i++){
		scanf("%s %s %d",s1,s2,&t);
		id1 = change(s1);
		id2 = change(s2);
		G[id1][id2] = G[id2][id1] = t;
	}
	double ansMin = -1,ansAvg = INF;
	int ansID = -1;
	//遍历候选的站点
	for(int i = N + 1; i <= M + N;i ++){
		//遍历这些找到的最小的点
		double MIN = INF;
		double avg = 0; 
		Dijkstra(i);

		//找到与居民房的最小距离 
		for(int j = 1; j <= N;j++){
			//超出范围 
			if(d[j] > Ds){
				MIN = -1;
				break;
			}
			//最小值 
			if(d[j] < MIN){
				MIN = d[j];
			}
			//计算平均距离
			avg += 1.0*d[j]/N ;
		} 
		//超出范围的情况 
		if(MIN == -1){
			continue;
		}
		if(MIN > ansMin){
			ansID = i;
			ansMin = MIN;
			ansAvg = avg;
		} else if (MIN == ansMin && ansAvg > avg){
			ansID = i; 
			ansAvg = avg;
		}
		
	} 
	if(ansID == -1){
		printf("No Solution\n");
	}else{
		printf("G%d\n",ansID-N);
		printf("%.1lf %.1lf\n",ansMin,ansAvg);
	}
	return 0;
}
