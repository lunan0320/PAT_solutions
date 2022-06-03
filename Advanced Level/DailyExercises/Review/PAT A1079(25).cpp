#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 100001;

struct Node{
	int data;
	vector<int>child;
}nodes[maxn];

int N;
double P,r;

double res = 0;

void DFS(int index,int depth){
	int size = nodes[index].child.size();
	if(size == 0){
		res += nodes[index].data * pow((1+r),depth);
	}else{
		for(int i = 0; i < size;i ++){
			DFS(nodes[index].child[i],depth+1);
		}
	}
}

int main(){
	scanf("%d%lf%lf",&N,&P,&r);
	r /= 100;
	int child_num;
	for(int i = 0; i < N;i++){
		scanf("%d",&child_num);
		if(child_num == 0){
			
		}
		int id;
		for(int j = 0; j < child_num;j++){
			scanf("%d",&id);
			nodes[i].child.push_back(id);
		}
		if(child_num == 0){
		x
		}
	}
	
	DFS(0,0);
	printf("%.1f\n",res);
	return 0;
}
