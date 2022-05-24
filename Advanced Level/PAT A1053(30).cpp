#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


const int maxn = 110;


struct node{
	int weight;
	//孩子数组 
	vector<int>child;
};
//构造的树 
node Tree[maxn];

int N, M, S;

//记录路径 
int path[maxn];


//index是当前的结点，numNode是当前path上总共的结点数
//sum是当前的路径上和 
void DFS(int index,int numNode,int sum){
	if(sum > S){
		return;
	}
	if(sum == S){
		//如果不是叶子结点 
		if(Tree[index].child.size()){
			return;
		}
		//打印路径内容 
		for(int i = 0; i < numNode; i++){
			printf("%d",Tree[path[i]].weight);
			if(i < numNode - 1){
				printf(" ");
			}else{
				printf("\n");
			}
		} 
		return;
	}
	//枚举每一个子节点
	for(int i = 0; i < Tree[index].child.size();i++){
		int child = Tree[index].child[i]; 
		path[numNode] = child;
 		DFS(child,numNode + 1,sum + Tree[child].weight);
	} 
}

bool cmp(int A,int B){
	return Tree[A].weight > Tree[B].weight;
}

int main(){
	scanf("%d%d%d",&N,&M,&S);
	//输入所有结点和权重 
	for(int i = 0; i < N; i++){
		scanf("%d",&Tree[i].weight);
	}
	//输入内部结点
	int id, k, id_child; 
	for(int i = 0; i < M; i++){
		scanf("%d%d",&id,&k);
		for(int j = 0; j < k; j++){
			scanf("%d",&id_child);
			Tree[id].child.push_back(id_child); 
		} 
		sort(Tree[id].child.begin(),Tree[id].child.end(),cmp);
	}
	//
	path[0] = 0;
	DFS(0,1,Tree[0].weight);
	
	
	return 0;
}

