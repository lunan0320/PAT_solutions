/*
������ͨ��
Ȼ�����ͨ�������������� 

����ͨ�飺ͼ�ı����Ͳ��鼯 
*/ 


// DFS������ʽ

#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;


const int maxn = 1010;

//��ǰҪɾ���Ľ�� 
int curQuery;

//N�ǽ������M�Ǳ�����K�ǲ�ѯ�� 
int N, M, K; 


vector<int> G[maxn];
 
bool visit[maxn]; 

void DFS(int index){
	//��ǰ�����Ľ����Ҫɾ���Ľ�� 
	if(index == curQuery){
		return;
	}
	visit[index] = true;
	for(int i = 0; i < G[index].size(); i++){
		if(visit[G[index][i]] == false){
			DFS(G[index][i]);
		}
	}
}

int main(){
	scanf("%d%d%d",&N,&M,&K);
	//һ���ߵ���ʼ���յ� 
	int a,b;
	for(int i = 0; i < M; i++){
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int query = 0; query < K; query++){
		scanf("%d",&curQuery);
		//��ʼ����ͨ������� 
		int block = 0;
		memset(visit,false,sizeof(visit));
		for(int i = 1; i <= N; i++){
			if(i != curQuery && !visit[i]){
				DFS(i);
				block++;
			}
		}
		printf("%d\n",block - 1);
	}
	return 0;
} 
