#include <bits/stdc++.h>

using namespace std;

const int maxn  = 10001;

int N;
int maxDepth = -1;
vector<int> Depth_vec; 
vector<int> G[maxn];

//连通分量 并查集 
int father[maxn];

bool visit[maxn] = {false};
bool isRoot[maxn] = {false};

int findFather(int x){
	int a = x;
	while(x != father[x]){
		x = father[x];
	}
	//路径压缩
	while(a != father[a]){
		int temp = a;
		a = father[a];
		father[temp]= x;
	} 
	return x;
}


void Union(int a,int b ){
	int aFather = findFather(a);
	int bFather = findFather(b);
	if(aFather != bFather){
		father[aFather] = bFather;
	}
}

void init(){
	for(int i = 1; i <= N; i++){
		father[i] = i;
		isRoot[i] = false;
	}
}

void DFS(int index,int depth){
    visit[index] = true;
	int size = G[index].size(); 
	//最深深度更新 
	if(depth == maxDepth){
		Depth_vec.push_back(index);
	}else if(depth > maxDepth){
		//找到更深的index 
		Depth_vec.clear(); 
		Depth_vec.push_back(index);
		maxDepth = depth;
	} 
	//遍历每个相连的边 
	for(int i = 0; i < size; i ++){
		int id = G[index][i];
		//防止重复加入 
		if(visit[id] == false){
			DFS(id,depth + 1);
		}
	}
	
}

int main(){
	scanf("%d",&N);
	int a,b;
	//初始化过程，初始化并查集 
	init();
	for(int i = 0;i < N-1; i++){
		scanf("%d %d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
		//说明这两个点在同一个连通分量中
		Union(a,b); 
	} 
	int Root_count = 0;
	for(int i = 1; i <= N; i++){
		int f = findFather(i);
		if(isRoot[f] == false){
			isRoot[f] = true;
		}
	}
	for(int i = 1;i <= N;i ++){
		if(isRoot[i]){
			Root_count++;
		}
	}
	//通过并查集的方式判断是否是连通的 
	if(Root_count != 1){
		printf("Error: %d components\n",Root_count);
	}else{

		//连通图的处理
		//随机遍历一次 
		fill(visit,visit+maxn,false);
		DFS(1,1);
		vector<int> res = Depth_vec;
		Depth_vec.clear();
		fill(visit,visit+maxn,false);
		//从记录的最深的地方开始再遍历一次 
		DFS(res[0],1);
		for(int i = 0; i < Depth_vec.size();i++){
			res.push_back(Depth_vec[i]);
		} 
		sort(res.begin(),res.end());
		printf("%d\n",res[0]);
		for(int i = 1;i < res.size();i++){
			if(res[i] != res[i-1]){
				printf("%d\n",res[i]);
			}
		}
	}
	
	
	
	
	return 0;
}

