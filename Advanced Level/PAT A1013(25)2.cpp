#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 1010;

vector<int> G[maxn];

int N, M, K;



int father[maxn];

bool isRoot[maxn];


//并查集查找一个cluster的首 
int findFather(int x){
	int a = x;
	while(x != father[x]){
		x = father[x];
	}
	//路径压缩
	while(a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	} 
	return x;
}

//合并 
void Union(int a ,int b){
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB){
		father[a] = faB; 
	}
} 


void init(){
	//初始化并查集数组 
	for(int i = 1; i < maxn; i++){
		father[i] = i;
		isRoot[i] = false;
	} 	
	
}

int main(){
	scanf("%d%d%d",&N,&M,&K);
	int a,b;
	for(int i = 0; i < M; i++){
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int query = 0; query < K; query++){
		int curQuery;
		scanf("%d",&curQuery);
		//初始化操作 
		init();
		//将所有连通的情况合并 
		for(int i = 1; i <= N; i++){
			if( i == curQuery){
				continue;
			}
			for(int j = 0; j < G[i].size(); j++){
				int u = i, v = G[i][j];
				if(u != curQuery && v != curQuery){
					Union(u,v); 
				}
			}
		}
		//遍历所有结点，找到连通块 
		int count = 0;
		for(int i = 1; i <= N; i++){
			if(i == curQuery){
				continue;
			}
			int temp = findFather(i);
			if(!isRoot[temp]){
				isRoot[temp] = true;
				count++;
			}
		} 
		printf("%d\n",count - 1); 
	}
	return 0; 
}
