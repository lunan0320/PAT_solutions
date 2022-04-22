#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const int maxn = 1000;
const int INF = 10000000;

vector<int> G[maxn];

//������������ 
int N, M;

//��� 
int inDegree[maxn];

//�����������
bool topologicalSort(){
	queue<int> que;
	int num = 0; 
	for(int i = 0; i < N; i++){
		//�Ƚ��������Ϊ0�ĵ������� 
		if(inDegree[i] == 0){
			que.push(i);
		}
	} 
	while(!que.empty()){
		int front = que.front();
		que.pop();
		//������������ڵ���ӱ� 
		for(int i = 0; i < G[front].size(); i++){
			int tmp = G[front][i];
			G[front][tmp] = INF; 
			//����������ӵĵ����ȶ���1 
			inDegree[tmp]--;
			if(!inDegree[tmp]){
				que.push(tmp);
			}
		}
		//���front���ڵı�
		G[u].clear(); 
		//��¼��ӵĽ���� 
		num++;
	}
	if(num == n){
		return true;
	}else{
		return false;
	}
} 

