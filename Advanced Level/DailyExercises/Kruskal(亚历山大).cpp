#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1000;
const int INF = 1000000;

struct edge{
	int u,v;
	int cost;
}Edge[maxn]; 

//�������ͱ��� 
int N, M; 
int ans = 0; //��С�������ı�Ȩ֮�� 

//���鼯���� 
int father[maxn]; 

//��д�ȽϺ��� ���������� 
bool cmp(edge a, edge b){
	return a.cost < b.cost;
}

//���鼯����
int findFather(int x){
	int a = x;
	//�˴��ҵ��˸��ڵ�x 
	while(x != father[x]){
		x = father[x];
	}
	//�˴���·��ѹ���Ĺ��� 
	//��·���ϵĵ�ĸ��ڵ㶼����Ϊx����������ѯ 
	while(a != father[a]){
		  int z = a;
		  a = father[a];
		  father[z] = x;
	}
	return x;
} 

int kruskal(){
	//�Ա�Ȩ��С�������� 
	sort(Edge,Edge+M,cmp);
	//���鼯�ĳ�ʼ�� 
	for(int i = 0; i < maxn; i++){
		father[i] = i;
	}
	int num = 0; //num��ʾ��ʱ����С�������еıߵ����� 
	for(int i = 0; i < M; i++){
		int faU = findFather(Edge[i].u);
		int faV = findFather(Edge[i].v);
		int cost = Edge[i].cost;
		//�������������ͬһ����ͨ�飬����ͨ 
		if(faU != faV){
			//�ϲ��������� 
			father[faU] = faV;
			//�˱߼��뵽��С�������� 
			ans += Edge[i].cost;
			num++;
			if(num ==N-1){
				return ans;
			} 
		}
	}
	//��ʾû�й�����ͨ��  ���������㶥����-1 
	if(num != N-1){
		return -1;
	}
	return ans; 
}

int main(){
	scanf("%d%d",&N, &M);
	int c1,c2,w;
	for(int i = 0; i < M; i++){
		scanf("%d%d%d",&c1, &c2, &w);
		Edge[i].u = c1;
		Edge[i].v = c2;
		Edge[i].cost = w;
	}
	int res = kruskal();
	printf("��С�������ı�ȨΪ��%d\n", res); 
	
	return 0;
} 


 /*
 �������� 
 6 10
0 1 4
0 4 1
0 5 2
1 2 6
1 5 3
2 3 6
2 5 5
3 4 4
3 5 5
4 5 3 
 */
