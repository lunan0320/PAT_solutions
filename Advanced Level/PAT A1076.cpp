#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 101;

int N, L;

bool inque[maxn] = {false};


struct Node{
	int id;
	int layer;
	//���캯�� 
	Node(){
	}
	Node(int para1,int para2){
		id = para1;
		layer = para2;
	}
}; 

vector<Node> Adj[maxn];

int BFS(int u){
	int numForward = 0;
	queue<Node> que;
	//��ʼ����� 
	Node user = Node(u,0);
	que.push(user);
	//��������� 
	inque[u] = true;
	while(!que.empty()){
		Node topNode = que.front();
		que.pop();
		//������û���Followers 
		for(int i = 0; i < Adj[topNode.id].size();i++){
			Node next = Adj[topNode.id][i];
			next.layer = topNode.layer+1;
			//�ж���ӵ����� 
			if(!inque[next.id] && next.layer <= L){
				inque[next.id] = true; 
				numForward++;
				que.push(next);
			} 
		}
	}
	return numForward; 

}

int main(){
	scanf("%d%d", &N, &L);
	Node user;
	int numFollows;
	//��������ÿ���û� 
	//ע��˴���i�Ǵ�1��ʼ����Ϊ��Ŀ�����Ķ��Ǵ��ڵ���1��id 
	for(int i = 1; i <= N; i++){
		scanf("%d", &numFollows);
		user.id = i;
		user.layer = 0;
		int idFollowed;
		//�����ע�ļ���id 
		for(int j = 0; j < numFollows; j++){
			scanf("%d", &idFollowed);
			//�ڱ���ע�ߵı��м��뵱ǰ�Ľ��i��id 
			Adj[idFollowed].push_back(user);
		}
	}
	int numQuery,s;
	scanf("%d", &numQuery);
	//����ÿ��Ҫ��ѯ���û� 
	for(int i = 0; i < numQuery; i++){
		scanf("%d", &s);
		//ÿ�γ�ʼ��inque����Ϊfalse 
		memset(inque,false,sizeof(inque));
		//BFS�ҵ�����forward���� 
		int maxForward = BFS(s);
		printf("%d\n", maxForward);
	} 
	return 0;
}
