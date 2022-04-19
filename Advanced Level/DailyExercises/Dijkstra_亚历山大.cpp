#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1000;
const int INF = 10000000;

//ע��˴���Ҫ�ڳ�ʼ��ʱ��ֱ�Ӹ�ֵINF�����ǻ�ʧ�ܵ�
//ֻ�и�ֵ0��ʱ��ſ�d[maxn] = {0},������Ҫ�õ�fill���� 
int G[maxn][maxn] ;		//��¼ͼ 
int d[maxn]  ;    		//��¼���·�� 
bool visit[maxn] = {false};

int n,m,s;  //������������������


void Dijkstra(int s){
	fill(d,d+maxn,INF); 
	d[s] = 0;  //������������Ϊ0
	for(int i = 0; i < n; i ++){ //��ÿ���� 
		int u = -1, MIN = INF;
		for(int j = 0; j < n; j++){			//��δ���������Ҹ���̵� 
			if(!visit[j] && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		} 
		if(u == -1) return; //���û���ҵ���˵��û�к�s��ͨ����
		visit[u] = true;  //���øý��Ϊ����
		//�����������������͸�����̾��� 
		for(int j = 0; j < n; j ++){
			if(!visit[j] && G[u][j] != INF && d[u] + G[u][j] < d[j]){
				d[j] = d[u] + G[u][j];
			}
		} 
	} 
}

int main(){
	scanf("%d%d%d",&n,&m,&s);
	int u,v,w;
	fill(G[0],G[0]+maxn*maxn,INF); 
	for(int i = 0; i < m; i++){  //����m���� 
		scanf("%d%d%d", &u, &v, &w);
		G[u][v] = w;
	}
	
	Dijkstra(s);
	
	for(int i = 0; i < n; i++){
		printf("%d ",d[i]);
	} 
	return 0;
} 


/*
����������
6 8 0
0 1 1
0 3 4
0 4 4
1 3 2
2 5 1
3 2 2
3 4 3
4 5 3


print
0 1 5 3 4 6 

*/
