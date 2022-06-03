#include <bits/stdc++.h>

using namespace std;

const int maxn  = 10001;

int N;
int maxDepth = -1;
vector<int> Depth_vec; 
vector<int> G[maxn];

//��ͨ���� ���鼯 
int father[maxn];

bool visit[maxn] = {false};
bool isRoot[maxn] = {false};

int findFather(int x){
	int a = x;
	while(x != father[x]){
		x = father[x];
	}
	//·��ѹ��
	while(a != father[a]){
		int temp = a;
		a = father[a];
		father[temp]= x;
	} 
	return x;
}


void Union(int a,int b ){
	int aFather = findFather(a);
	int bFather = findFather(b);
	if(aFather != bFather){
		father[aFather] = bFather;
	}
}

void init(){
	for(int i = 1; i <= N; i++){
		father[i] = i;
		isRoot[i] = false;
	}
}

void DFS(int index,int depth){
    visit[index] = true;
	int size = G[index].size(); 
	//������ȸ��� 
	if(depth == maxDepth){
		Depth_vec.push_back(index);
	}else if(depth > maxDepth){
		//�ҵ������index 
		Depth_vec.clear(); 
		Depth_vec.push_back(index);
		maxDepth = depth;
	} 
	//����ÿ�������ı� 
	for(int i = 0; i < size; i ++){
		int id = G[index][i];
		//��ֹ�ظ����� 
		if(visit[id] == false){
			DFS(id,depth + 1);
		}
	}
	
}

int main(){
	scanf("%d",&N);
	int a,b;
	//��ʼ�����̣���ʼ�����鼯 
	init();
	for(int i = 0;i < N-1; i++){
		scanf("%d %d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
		//˵������������ͬһ����ͨ������
		Union(a,b); 
	} 
	int Root_count = 0;
	for(int i = 1; i <= N; i++){
		int f = findFather(i);
		if(isRoot[f] == false){
			isRoot[f] = true;
		}
	}
	for(int i = 1;i <= N;i ++){
		if(isRoot[i]){
			Root_count++;
		}
	}
	//ͨ�����鼯�ķ�ʽ�ж��Ƿ�����ͨ�� 
	if(Root_count != 1){
		printf("Error: %d components\n",Root_count);
	}else{

		//��ͨͼ�Ĵ���
		//�������һ�� 
		fill(visit,visit+maxn,false);
		DFS(1,1);
		vector<int> res = Depth_vec;
		Depth_vec.clear();
		fill(visit,visit+maxn,false);
		//�Ӽ�¼������ĵط���ʼ�ٱ���һ�� 
		DFS(res[0],1);
		for(int i = 0; i < Depth_vec.size();i++){
			res.push_back(Depth_vec[i]);
		} 
		sort(res.begin(),res.end());
		printf("%d\n",res[0]);
		for(int i = 1;i < res.size();i++){
			if(res[i] != res[i-1]){
				printf("%d\n",res[i]);
			}
		}
	}
	
	
	
	
	return 0;
}

