#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 510;
const int INF = 10000000;

//��¼����ǰ����ҪЯ����
int need[maxn];
//��¼����ǰ����Ҫ�����
int remain[maxn]; 

//��¼��Ȩ 
int G[maxn][maxn];
//��¼��Ȩ
int weight[maxn];
//��¼·������
int num[maxn];
//��¼�Ƿ񱻷���
bool visit[maxn] = {false}; 
//��¼��̾���
int d[maxn];
 
vector<int> pre[maxn];
vector<int>tempPath,resPath;
int Cmax, N,Sp,M;

void Dijkstra(int s){
	fill(d,d+maxn,INF);
	fill(num,num+maxn,0);
	
	d[s] = 0;
	num[s] = 1;
	
	for(int i = 0; i <= N;i++){
		int u = -1,min = INF;
		for(int j = 0; j <= N; j++){
			if(!visit[j] && d[j] < min){
				min = d[j];
				u = j;
			}
		}
		//û���ҵ� 
		if(u == -1){
			return;
		}
		visit[u] = true;
		for(int j = 0; j <= N; j++){
			if(!visit[j] && G[u][j] != INF){
				if(d[u] + G[u][j] < d[j]){
					d[j] = d[u] + G[u][j];
					num[j] = num[u];
					pre[j].clear();
					pre[j].push_back(u);
				}else if(d[u] + G[u][j] == d[j]){
					num[j] += num[u];
					pre[j].push_back(u);
				}
			}
		}
	}
}

int minNeed = INF;
int minRemain = INF;

void DFS(int v){
	if(v == 0){
		tempPath.push_back(v);
		int need = 0,remain = 0;
		for(int i = tempPath.size() - 1; i >= 0; i--){
			int id = tempPath[i];
			if(weight[id] > 0){
				remain += weight[id];
			}else{
				if(remain > abs(weight[id])){
					remain -= abs(weight[id]);
				}else{
					need += abs(weight[id]) - remain;
					remain = 0;
				}
			}
		}
		if(need < minNeed){
			minNeed = need;
			minRemain = remain;
			resPath = tempPath;
		}else if(need == minNeed && remain < minRemain){
			minRemain = remain;
			resPath = tempPath;
		}
		tempPath.pop_back();
		return; 
	}
	tempPath.push_back(v);
	for(int i = 0; i < pre[v].size();i++){
		DFS(pre[v][i]);
	} 
	tempPath.pop_back();
}


int main(){
	scanf("%d%d%d%d",&Cmax,&N,&Sp,&M);
	for(int i = 1; i <= N; i++){
		scanf("%d",&weight[i]);
		weight[i] -= Cmax/2;
	}
	int a,b ,c;
	fill(G[0],G[0] + maxn * maxn, INF);
	for(int i = 0; i < M; i++){
		scanf("%d%d%d",&a,&b,&c);
		G[a][b] = c;
		G[b][a] = c;
	}
	Dijkstra(0);
	DFS(Sp);
	printf("%d ",minNeed);
	for(int i = resPath.size() -1; i>=0; i--){
		printf("%d",resPath[i]);
		if(i > 0){
			printf("->");
		}
	}
	printf(" %d",minRemain);
	printf("%d",num[Sp]);
	return 0;
} 
