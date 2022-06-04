#include <cstdio>
#include <algorithm>

using namespace std;
 

const int INF = 1000000;
const int maxn = 501;

int G[maxn][maxn];

int N, M, C1, C2;

int weight[maxn];

//��¼���·�� 
int d[maxn];

//��¼�Ƿ���ʹ�
bool visit[maxn] = {false};

//��¼·���������Լ����ĵ�Ȩ�� 
int num[maxn], w[maxn]; 

 
void Dijkstra(int s){
	fill(num,num+maxn,0);
	fill(w,w+maxn,0);
	fill(d,d+maxn,INF);
	
	d[s] = 0;
	w[s] = weight[s];
	num[s] = 1;
	
	
	 
	for(int i = 0; i < N;i++){
		//�� V-S���� 
		int u = -1,min = INF;
		for(int j = 0; j < N;j++){
			if(!visit[j] && d[j] < min){
				min = d[j];
				u = j;
			} 
		}
		//����Ҳ��������ĵ�
		if(u == -1){
			return ;
		} 
		//����u
		visit[u] = true; 
		//�ҵ��󣬸���
		for(int j = 0; j < N; j++){
			//���û�÷������бߴ��� 
			if(!visit[j] && G[u][j] != INF){
				if(d[u] + G[u][j] < d[j]){
					//�ҵ����̵�·����ʱ�� 
					d[j] = d[u] + G[u][j];
					//��Ȩ��  
					w[j] = weight[j] + w[u];
					//·������
					num[j] = num[u]; 
				}else if(d[u] + G[u][j] == d[j]){
					//·�����ʱ�� 
					if(w[u] + weight[j] > w[j]){
						w[j] = w[u] + weight[j];	
					}
					//·������
					num[j] = num[j] + num[u]; 
				}
			}

		} 
		
		
	}
}

int main(){
	scanf("%d%d%d%d",&N,&M,&C1,&C2);
	for(int i = 0; i < N;i++){
		scanf("%d",&weight[i]);
	}
	//��ʼ��G
	fill(G[0],G[0] + maxn * maxn, INF);
	int a,b,l;
	for(int i = 0; i < M; i++){
		scanf("%d%d%d",&a,&b,&l);
		G[a][b] = l;
		G[b][a] = l;
	}
	//��C1��ʼ�ĵ�Դ���·�� 
	Dijkstra(C1); 
	printf("%d %d\n",num[C2],w[C2]);
	return 0;
} 
