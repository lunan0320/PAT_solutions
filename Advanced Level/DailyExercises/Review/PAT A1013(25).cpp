#include <bits/stdc++.h>
using namespace std;

const int maxn = 1001;

int N, M, K;

vector<int> G[maxn];


bool visit[maxn] = {false};

void DFS(int index){
	int size = G[index].size();
	for(int i = 0; i < size; i++){
		int id = G[index][i];
		if(!visit[id]){
			visit[id] = true;
			DFS(index);
		}
	}
}

int main(){
	scanf("%d%d%d",&N,&M,&K);
	int a,b;
	for(int i = 0;i < M; i++){
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	int query_id;
	for(int query = 0; query < K;query++){
		fill(visit,visit+maxn,false);
		int count_num = 0;
		scanf("%d",&query_id);
		//攻占相当于已经访问过
		visit[query_id] = true;
		for(int i = 1; i <= N; i++){
			if(!visit[i]){
				DFS(i);
				count_num ++;
			}
		}
		printf("%d\n",count_num - 1);
	} 
	return 0;
}
