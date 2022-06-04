#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 101;

struct Node{
	int id;
	int weight;
	vector<int> child;
}nodes[maxn];


//���·�� 
vector<int>temp_res;

//��������ڲ��������Ŀ��Ȩ�غ� 
int N, M, S;


bool cmp(int a, int b){
	return nodes[a].weight > nodes[b].weight;
}

void print_res(){
	int size = temp_res.size();
	for(int i = 0; i <size;i++){
		int id = temp_res[i];
		printf("%d",nodes[id].weight);
		if(i < size - 1){
			printf(" ");
		}else{
			printf("\n");
		}
	} 
}


void DFS(int index,int nowSum){
	if(!nodes[index].child.size() && nowSum == S){
		print_res();
		return;
	}
	//Ȩ�س��� 
	if(nowSum > S){
		return;
	}
	//��û�е�Ҷ�ӽ�� 
	if(nodes[index].child.size() && nowSum == S){
		return;
	}

	int size = nodes[index].child.size();
	for(int i = 0; i < size; i++){
		int id = nodes[index].child[i];
		//���μ�����˳�·�� 
		temp_res.push_back(id);
		DFS(id,nowSum + nodes[id].weight);
		temp_res.pop_back();
	}
}

int main(){
	scanf("%d%d%d",&N,&M,&S);
	int w;
	for(int i = 0; i < N; i++){
		scanf("%d",&w);
		nodes[i].weight = w;
		nodes[i].id = i;
	}
	int id,child_num;
	for(int i = 0; i < M; i++){
		scanf("%d%d",&id,&child_num);
		int child_id;
		for(int j = 0; j < child_num; j++){
			scanf("%d",&child_id);
			nodes[id].child.push_back(child_id);
		}	
		sort(nodes[id].child.begin(),nodes[id].child.end(),cmp);
	} 
	temp_res.push_back(0);
	DFS(0,nodes[0].weight);
	return 0;
}
