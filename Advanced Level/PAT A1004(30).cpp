#include <cstdio>
#include <vector>
#include <queue> 
using namespace std;

const int maxn = 110;

//N���ܵĽ������M�Ƿ�Ҷ�ӽ���� 
int N, M;
vector<int> family[maxn];

//��¼ÿһ��ķ�Ҷ�ӽ������ 
int hashTable[maxn] = {0} ;
int maxDepth = 0;
 
//��¼�������Ĳ�� 
int h[maxn];
 
 
//DFS�汾 
void DFS(int index,int level) {
	//�ڲ���� 
	if(family[index].size() == 0){
		hashTable[level]++;
		if(maxDepth < level){
			maxDepth = level;
		}
	}else{
		//ö�������ӽڵ㣬��������� 
		for(int i = 0; i < family[index].size(); i++){
			DFS(family[index][i],level + 1);
		}
	}
}



//BFS�汾
void BFS(int root,int level){
	queue<int>q;
	q.push(root);
	h[root] = level;
	while(!q.empty()){
		int front = q.front();
		q.pop();
		//���������� 
		maxDepth = max(h[front],maxDepth);
		if(family[front].size()){
			for(int i = 0; i < family[front].size(); i++){
				h[family[front][i]] = h[front] + 1;
				q.push(family[front][i]);
			}
		} else{
			//�����Ҷ�ӽ��,��ǰ��Ľ������1 
			hashTable[h[front]]++; 
		}
	}
}
 
int main(){
	scanf("%d %d",&N,&M);
	int id, k,child;
	//�������� 
	for(int i = 0; i < M; i++){
		scanf("%d%d",&id,&k);
		for(int j = 0; j < k; j++){
			scanf("%d",&child);
			family[id].push_back(child);
		}
	}
	//	DFS(1,0);
	
	//BFS�汾
	BFS(1,0); 
	for(int i = 0; i <= maxDepth;i++){
		if(i != maxDepth){
			printf("%d ",hashTable[i]);
		}else{
			printf("%d",hashTable[i]);
		}
	} 
	return 0;
}
