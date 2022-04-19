#include <cstrdio>
#include <vector>

using namespace std;

 
const int maxn = 1000;
const int INF = 100000000;

int G[maxn][maxn];
bool visit[maxn] = {false};//��ʾ������Ƿ񱻷��� 
int d[maxn] = {INF}//��ʾs��������Ƿ���ͨ
int n;  //������ 


/*

�ڽӾ��� 

*/
void Dijkstra(int s){
	d[s] = 0;
	for(int i = 0;i < n; i ++){ //����ÿ������ 
		int u = -1;
		int MIN = INF;
		for(int j = 0; j < n; j++){ //�ҵ�ʣ��δ���ʵ����С�ľ���
			if(!visit[j] && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1){  //���˵û�к�s��ͨ�ĵ㣬�Ǿͷ��� 
			return ;
		}
		//�������ǶԺ�δ���ʵĵ�Ĵ���
		visit[u] = true;
		for(int j = 0; j < n; j++){  //�ж�ʣ�µĵ����Ϣ���Ƿ����������������� 
			if(!visit[j] && G[u][j] && d[u] + G[u][j]< d[j] ){ //���jδ���ʣ��Һ�u�бߣ��Ҽ���u���̣���ô���� 
				d[j] = d[u] + G[u][j];
			}
		} 
	}
} 
 
 
 
 /*
 �ڽӱ� 
 */
 
 struct Node{
 	int v,dis;
 };
 
 vector<Node> Adj[maxn];
 
 void Dijkstra_vector(int s){
 	//��ʼ�������Լ����Լ�����̾�����0 
 	d[s] = 0;
 	for(int i = 0; i < n; i++){ //����Ѱ��n��������·�� 
 		int MIN = INF, u = -1;
		for(int j = 0; j < n; j++){ //��һ��δ���ʵ���̵ĵ�u 
			if(!visit[j] && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}	
		if(u == -1){
			return ; //��ʾû�е��u��ͨ�� 
		} 
		visit[u] = true;
		for(int j = 0; j < Adj[u].size(); j++){
			if(!visit[j] && Adj[u][j].dis + d[u] < d[j] ){
				d[j] = Adj[u][j].dis+ d[u];
			}
		}
	} 
 	
 }
