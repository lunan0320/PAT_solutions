#include <cstdio>
#include <algorithm>

using namespace std;
 
const int maxn = 1000;
const int INF = 1000000;

//�������ͱ��� 
int N, M;

//����S�Ǳ�ʾ�Ѿ����ʹ��Ľ�� 
int G[maxn][maxn];
int d[maxn]; //d[]��¼���Ƕ��㵽����S�е���С���� 
bool visit[maxn] = {false}; //��¼������Ƿ��ڼ���S�� 
int ans = 0;

int prim(){ //Ĭ�ϴ�0��ʼ 
	fill(d,d+maxn,INF);
	d[0] = 0;
	//�ж��ٸ������ִ�ж��ٴ� 
	for(int i = 0; i < N; i++){
		//��δ���ʵļ����У���һ�����뼯��S��������� 
		int u = -1, MIN = INF;
		for(int j = 0; j < N; j++){
			if(!visit[j] && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		//����Ҳ�������ʾ�����ʽ���
		if(u==-1){
			return -1;
		} 
		//����ҵ�֮�󣬾ͽ��ý�����S���Ż�����
		visit[u] = true;
		ans += d[u];
		for(int j = 0; j < N; j++){
			//��ʱu�Ѿ���S�У�ֻҪu��j�ľ����С���Ǿ�˵��j������S�ľ����С 
			if(!visit[j] && G[u][j] != INF && G[u][j] < d[j]){
				d[j] = G[u][j];
			}
		} 
	}
	return  ans;
	
}
 
int main(){
	
	fill(G[0],G[0] + maxn * maxn, INF);
	scanf("%d%d", &N, &M);
	int c1,c2,w;
	for(int i = 0; i < M; i++){
		scanf("%d%d%d",&c1, &c2, &w);
		G[c1][c2] = w;
		G[c2][c1] = w; 
	}
	int res = prim();
	printf("��С����������̷��ʾ��룺%d\n",res);
	
	return 0;
}
 /*
 �������� 
 6 10
0 1 4
0 4 1
0 5 2
1 2 6
1 5 3
2 3 6
2 5 5
3 4 4
3 5 5
4 5 3 
 */
