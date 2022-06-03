#include <cstdio>
#include <vector>
using namespace std;


const int maxn = 101;

struct Node{
	int id;
	vector<int> child;
}nodes[maxn];

int N,M;

//记录每一层的叶子结点的数量 
int level[maxn];


void DFS(int index,int depth){
	int size = nodes[index].child.size();
	//叶子结点 

	level[depth]++;

	for(int i = 0; i < size;i++){
		DFS(nodes[index].child[i],depth+1);
	}
	
}

int main(){
	scanf("%d%d",&N,&M);
	int id,child_num;
	for(int i = 0;i < M; i++){
		scanf("%d%d",&id,&child_num);
		int child_id;
		for(int j = 0; j < child_num; j++){
			scanf("%d",&child_id);
			nodes[id].child.push_back(child_id);
		}
	}
	DFS(1,1);
	int maxNum = -1;
	int maxIndex; 
	for(int i = 0; i < N; i++){
		if(level[i] > maxNum){
			maxNum = level[i];
			maxIndex = i; 
		} 
	}
	printf("%d %d\n",maxNum,maxIndex);
	return 0;
}
