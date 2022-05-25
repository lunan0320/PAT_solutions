#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 10010;

vector<int> G[maxn];

vector<int> temp;
vector<int> res; 


int N;

int father[maxn];

bool isRoot[maxn];



int findFather(int x){
	int a = x;
	while(x != father[x]){
		x = father[x];
	}
	
	//路径合并
	while( a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	} 
	return x;
}

void Union(int a,int b){
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB){
		father[faA] = faB;
	}
}



void init(){
	for(int i = 1; i < maxn; i++){
		father[i] = i;
		isRoot[i] = false;
	}
}

int maxHeight = -1;


void DFS(int index,int height,int pre){
	if(height > maxHeight){
		maxHeight = height;
		temp.clear();
		temp.push_back(index);
	}else if(height == maxHeight){
		temp.push_back(index);
	}
	for(int i = 0; i < G[index].size(); i++){
		if(pre != G[index][i]){
			DFS(G[index][i], height + 1, index);			
		}
	}
}

int main(){
	scanf("%d",&N);
	int a,b;
	
	init();
	
	for(int i = 1; i < N; i++){
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
		Union(a,b);
	}
	int block = 0;
	
	for(int i = 1; i <= N; i ++){
		int father = findFather(i);
		if(!isRoot[father]){
			isRoot[father] = true;
		} 
	}
	for(int i = 1; i <= N; i++){
		if(isRoot[i]){
			block++;
		}
	}
	if(block != 1){
		printf("Error: %d components\n",block);
	}else{
		//是一个连通图
		//刚开始随机遍历，从1开始，高度1，前面为-1 
		DFS(1,1,-1); 
		res = temp;
		DFS(res[0],1,-1);
		for(int i = 0; i < temp.size(); i++){
			res.push_back(temp[i]);
		}
		sort(res.begin(),res.end());
		printf("%d\n",res[0]);
		for(int i = 1; i < res.size(); i++){
			if(res[i] != res[i-1]){
				printf("%d\n",res[i]);
			}
		} 
	}
	
	
	return 0;
}
