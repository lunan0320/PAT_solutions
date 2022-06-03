#include <cstdio>
#include <map>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;


const int INF = 100000000;
const int maxn = 100001;


struct Node{
	int addr;
	int data;
	int next;
	int order = INF;
}nodes[maxn];


int start,N;

map<int,int> my_map;

vector<int>vec;

bool cmp(Node a,Node b){
	return a.order < b.order;
}


int main(){
	scanf("%d%d",&start,&N);
	int addr;
	for(int i = 0; i < N; i++){
		scanf("%d",&addr);
		scanf("%d%d",&nodes[addr].data,&nodes[addr].next);
		nodes[addr].addr = addr; 
	}
	
	int p = start;
	int k = 1;
	while(p != -1){
		nodes[p].order = k++;
		p = nodes[p].next;
	}
	sort(nodes,nodes+maxn,cmp);
	
	for(int i = 0; i < N; i++){
		//��ǰֵ��һ�γ��� 
		if(my_map.find(abs(nodes[i].data)) == my_map.end()){
			//map�ĵ�һ����¼ 
			if(!my_map.size()){
				printf("%05d %d ",nodes[i].addr,nodes[i].data) ;
			}else{
				//����map�ĵ�һ��
				int ad = my_map[abs(nodes[i].data)];
				printf("%05d\n%05d %d ",nodes[i].addr,nodes[i].addr,nodes[i].data) ;
			}
			my_map[abs(nodes[i].data)] = nodes[i].addr;
		}else{
			//���ǵ�һ�γ���
			vec.push_back(i);
		}
	}
	printf("-1\n");

	//��ӡɾ����Ԫ��
	int len = vec.size();
	for(int i = 0; i < len; i++){
		int index = vec[i];
		if(i!=0){
			printf("%05d\n%05d %d ",nodes[index].addr,nodes[index].addr,nodes[index].data);
		}else{
			printf("%05d %d ",nodes[index].addr,nodes[index].data);
		}
	} 
	if(len > 0){
		printf("-1\n");
	}
	
	return 0;
} 
