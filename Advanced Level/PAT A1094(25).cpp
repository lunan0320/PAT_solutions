#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 101;

vector<int> family[maxn];

int N,M;

//记录每一层的结点数量 
int hashTable[maxn] = {0};
 
void DFS(int index, int level){
	hashTable[level]++;
	//到达叶子结点 
	if(family[index].size() == 0){
		return;
	}else{
		for(int i = 0; i < family[index].size(); i++){
			DFS(family[index][i], level + 1);
		}
	} 
} 



int main(){
	scanf("%d%d",&N,&M);
	int id, k,child;
	//输入信息 
	for(int i = 0; i < M; i++){
		scanf("%d%d",&id,&k);
		for(int j = 0; j < k; j++){
			scanf("%d",&child);
			family[id].push_back(child);
		}
	} 
	//root为1level 
	DFS(1,1);
	int maxNum = 0, maxLevel = 0;
	for(int i = 0; i < maxn; i++){
		if(hashTable[i] > maxNum){
			maxNum = hashTable[i];
			maxLevel = i;
		}
	}
	printf("%d %d",maxNum,maxLevel);
	return 0;
} 
