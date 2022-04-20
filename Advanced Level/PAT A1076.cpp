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
	//构造函数 
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
	//初始化结点 
	Node user = Node(u,0);
	que.push(user);
	//设置入队了 
	inque[u] = true;
	while(!que.empty()){
		Node topNode = que.front();
		que.pop();
		//处理该用户的Followers 
		for(int i = 0; i < Adj[topNode.id].size();i++){
			Node next = Adj[topNode.id][i];
			next.layer = topNode.layer+1;
			//判断入队的条件 
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
	//依次输入每个用户 
	//注意此处的i是从1开始，因为题目给出的都是大于等于1的id 
	for(int i = 1; i <= N; i++){
		scanf("%d", &numFollows);
		user.id = i;
		user.layer = 0;
		int idFollowed;
		//输入关注的几个id 
		for(int j = 0; j < numFollows; j++){
			scanf("%d", &idFollowed);
			//在被关注者的边中加入当前的结点i的id 
			Adj[idFollowed].push_back(user);
		}
	}
	int numQuery,s;
	scanf("%d", &numQuery);
	//处理每个要查询的用户 
	for(int i = 0; i < numQuery; i++){
		scanf("%d", &s);
		//每次初始化inque数组为false 
		memset(inque,false,sizeof(inque));
		//BFS找到最大的forward数量 
		int maxForward = BFS(s);
		printf("%d\n", maxForward);
	} 
	return 0;
}
