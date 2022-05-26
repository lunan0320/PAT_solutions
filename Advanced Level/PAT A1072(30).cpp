#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 1050;
const int INF = 10000000000;

//N�����񷿣�M��վ�㣬K��·��Ds�������� 
int N,M,K,Ds;

//���ս������С�����ƽ������ ��վ�� 


int G[maxn][maxn];

//d�Ǵ�s��i����̾��� 
int d[maxn];

//�Ƿ���ʹ� 
bool visit[maxn] = {false};

int change(char str[]){
	int i = 0,len = strlen(str),res = 0;
	while(i < len){
		if(str[i] != 'G'){
			res = res * 10 + (str[i] - '0');
		}
		i++;
	}
	//��һ������ 
	if(str[0] == 'G'){
		return N + res; 
	}else{
		//��һ��վ��
		return res; 
	}
}

void Dijkstra(int s){
	
	memset(visit,false,sizeof(visit));
	fill(d,d+maxn,INF);
	//��ʼ�� 
	d[s] = 0;
	for(int i = 0; i < N+M;i++){
		int u = -1,min = INF;
		for(int j = 1; j <= N+ M;j++){
			if(visit[j] == false && d[j] < min){
				min = d[j];
				u = j;
			}
		}
		//û���ҵ�
		if(u==-1){
			return;
		} 
		//�ҵ����ʵ�u
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
	//������ѡ��վ��
	for(int i = N + 1; i <= M + N;i ++){
		//������Щ�ҵ�����С�ĵ�
		double MIN = INF;
		double avg = 0; 
		Dijkstra(i);

		//�ҵ�����񷿵���С���� 
		for(int j = 1; j <= N;j++){
			//������Χ 
			if(d[j] > Ds){
				MIN = -1;
				break;
			}
			//��Сֵ 
			if(d[j] < MIN){
				MIN = d[j];
			}
			//����ƽ������
			avg += 1.0*d[j]/N ;
		} 
		//������Χ����� 
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
