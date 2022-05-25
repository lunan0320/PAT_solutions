#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct node{
	int id;
	int layer;
};

const int maxn = 1100;
//邻接表 
vector<node> G[maxn];

bool inque[maxn] = {false};

int N, L;



//从s开始BFS 
int BFS(int s){
	int numForward  = 0;
	queue<node> q;
	node start;
	start.id = s;
	start.layer = 0;
	q.push(start);
	inque[start.id] = true;
	while(!q.empty()){
		node front = q.front();
		q.pop();
		
		int temp = front.id;
		for(int i = 0; i < G[temp].size();i++){
			node next = G[temp][i];
			next.layer = front.layer + 1;
			
			if(inque[next.id] == false && next.layer <= L){
				q.push(next);
				inque[next.id] = true;
				numForward++;
			}
		}
	}
	return numForward;
}



int main(){
	scanf("%d%d",&N,&L);
	int k;
	node user;
	int next;
	for(int i = 1; i <= N; i++){
		user.id = i;
		scanf("%d",&k);
		//k是用户i follow的人数 
		for(int j = 0; j < k; j++){
			scanf("%d",&next);
			G[next].push_back(user);
		}
	}
	
	int numQuery,s;
	
	scanf("%d",&numQuery);
	for(int i = 0; i < numQuery;i++){
		memset(inque,false,sizeof(inque));
		scanf("%d",&s);
		int numForward = BFS(s);
		printf("%d\n",numForward); 
	} 
	return 0;
}
