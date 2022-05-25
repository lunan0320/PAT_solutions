#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 1010;

vector<int> G[maxn];

int N, M, K;



int father[maxn];

bool isRoot[maxn];


//���鼯����һ��cluster���� 
int findFather(int x){
	int a = x;
	while(x != father[x]){
		x = father[x];
	}
	//·��ѹ��
	while(a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	} 
	return x;
}

//�ϲ� 
void Union(int a ,int b){
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB){
		father[a] = faB; 
	}
} 


void init(){
	//��ʼ�����鼯���� 
	for(int i = 1; i < maxn; i++){
		father[i] = i;
		isRoot[i] = false;
	} 	
	
}

int main(){
	scanf("%d%d%d",&N,&M,&K);
	int a,b;
	for(int i = 0; i < M; i++){
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int query = 0; query < K; query++){
		int curQuery;
		scanf("%d",&curQuery);
		//��ʼ������ 
		init();
		//��������ͨ������ϲ� 
		for(int i = 1; i <= N; i++){
			if( i == curQuery){
				continue;
			}
			for(int j = 0; j < G[i].size(); j++){
				int u = i, v = G[i][j];
				if(u != curQuery && v != curQuery){
					Union(u,v); 
				}
			}
		}
		//�������н�㣬�ҵ���ͨ�� 
		int count = 0;
		for(int i = 1; i <= N; i++){
			if(i == curQuery){
				continue;
			}
			int temp = findFather(i);
			if(!isRoot[temp]){
				isRoot[temp] = true;
				count++;
			}
		} 
		printf("%d\n",count - 1); 
	}
	return 0; 
}
