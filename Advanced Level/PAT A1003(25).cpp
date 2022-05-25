#include <cstdio>
#include <cstring>
#include <algorithm> 


using namespace std;


const int maxn = 1000;


const int INF = 100000000;

//��¼��̾��� 
int d[maxn];

//��¼��Ȩ
int G[maxn][maxn];

//��¼��Ȩ
int  weight[maxn]; 

//��¼�Ƿ����
bool visit[maxn] = {false};

//��¼·�����������Ȩ����
int num[maxn],w[maxn];
 
int N, M, start,ed;

void Dijkstra(int s){
	fill(d,d+maxn,INF);
	memset(num,0,sizeof(num));
	memset(w,0,sizeof(num));
	//�����Լ��ľ���
	d[s] = 0;
	//����s�����Ȩ����weight[s] 
	w[s] = weight[s];
	//����s�����·������ 
	num[s] = 1;
	
	//ѭ��n��
	
	for(int i = 0; i < N; i++){
		//��δ���ʵļ������ҵ�����s��С��u 
		int u = -1,min = INF;
		for(int j = 0; j < N; j++){
			if(!visit[j] && d[j] < min){
				min = d[j];
				u = j;
			} 
		}
		//���û���ҵ�u
		if(u == -1){
			return;
		} 
		//�ҵ���С��u����ȥ���� 
		visit[u] = true;
		for(int j = 0; j < N;j++){
			//���jδ���ʣ����ܴ�u��j����uΪ�н����
			if(!visit[j] && G[u][j]!= INF ){
				if(d[u] + G[u][j] < d[j]){
					d[j] = d[u] + G[u][j];
					w[j] = w[u] + weight[j];
					num[j] = num[u];   //·���������� 
				}else if (d[u] + G[u][j] == d[j]){ //·����ͬ 
					if(w[u] + weight[j] > w[j]){  //Ȩ�͸��� 
						w[j] = w[u] + weight[j]; //����Ȩ�� 
					}
					num[j] += num[u]; //���·��������1 
				} 
			} 
		}
	} 
}



int main(){
	scanf("%d%d%d%d",&N,&M,&start,&ed);
	for(int i = 0; i < N; i++){
		scanf("%d",&weight[i]);
	}
	fill(G[0],G[0]+maxn*maxn,INF); 
	int a, b,c;
	for(int i = 0; i < M; i++){
		scanf("%d%d%d",&a,&b,&c);
		G[a][b] = G[b][a] = c;
	}
	Dijkstra(start);
	printf("%d %d\n",num[ed],w[ed]);
	return 0;
} 
