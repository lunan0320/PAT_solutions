#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

const int maxn = 100010;

vector<int> child[maxn];

int N;
double p,r;
//根节点的index 
int root;

int maxDepth = 0;
int num = 0; //最深层的结点数量 

void DFS(int index, int depth){
	if(child[index].size() == 0){
		if(depth > maxDepth){
			maxDepth = depth;
			num = 1; 
		}else if (depth == maxDepth){
			num++;
		}
		return;
	} 
	for(int i = 0; i < child[index].size(); i++){
		DFS(child[index][i],depth + 1);
	}
}

int main(){
	scanf("%d%lf%lf",&N,&p,&r);
	r /= 100;
	int father;
	//输入信息 
	for(int i = 0; i < N; i++){
		scanf("%d",&father);
		if(father != -1){
			child[father].push_back(i);
		}else{
			root = i;
		}
	}
	DFS(root,0); 
	printf("%.2f %d\n",p*pow(1+r,maxDepth),num); 
	return 0;
}
