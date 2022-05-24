#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


const int maxn = 110;


struct node{
	int weight;
	//�������� 
	vector<int>child;
};
//������� 
node Tree[maxn];

int N, M, S;

//��¼·�� 
int path[maxn];


//index�ǵ�ǰ�Ľ�㣬numNode�ǵ�ǰpath���ܹ��Ľ����
//sum�ǵ�ǰ��·���Ϻ� 
void DFS(int index,int numNode,int sum){
	if(sum > S){
		return;
	}
	if(sum == S){
		//�������Ҷ�ӽ�� 
		if(Tree[index].child.size()){
			return;
		}
		//��ӡ·������ 
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
	//ö��ÿһ���ӽڵ�
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
	//�������н���Ȩ�� 
	for(int i = 0; i < N; i++){
		scanf("%d",&Tree[i].weight);
	}
	//�����ڲ����
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

