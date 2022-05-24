#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 100010;

vector<int>child[maxn];

int N;
double p,r;

//最低层数的叶子结点的数量 
int num;
int minLevel = maxn; 

void DFS(int index,int level){
	if(child[index].size() == 0){
		if(level < minLevel){
			minLevel = level;
			num = 1;
		}else if (level == minLevel){
			num++;
		}
	}else{
		for(int i = 0; i < child[index].size(); i++){
			DFS(child[index][i], level + 1);
		}
	}
} 

int main(){
	scanf("%d%lf%lf",&N,&p,&r);
	r /= 100;
	int k, member;
	//输入 
	for(int i = 0; i < N; i++){
		scanf("%d",&k);
		for(int j = 0; j < k; j++){
			scanf("%d",&member);
			child[i].push_back(member);
		}
	}
	DFS(0,0);
	printf("%.4lf %d",p*pow(1+r,minLevel),num);
	
	return 0;
}
