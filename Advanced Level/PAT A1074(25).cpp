#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;

struct node{
	int addr;
	int data;
	int next;
	int order = maxn;
}nodes[maxn];

bool cmp(node A, node B){
	return A.order < B.order;
}
int main(){
	int begin,N,K;
	int address;
	//�������� 
	scanf("%d%d%d",&begin,&N,&K);
	for(int i = 0; i < N; i++){
		scanf("%d",&address);
		scanf("%d",&nodes[address].data);
		scanf("%d",&nodes[address].next);
		nodes[address].addr = address;
	}
	int p = begin,count = 0;
	while(p!=-1){
		nodes[p].order = count++;
		p = nodes[p].next;
	}
	sort(nodes,nodes+maxn,cmp);
	//���鴦��
	int group = count / K;
	 
	for(int i = 0;i<group;i++){
		int j = (i*K + K - 1);
		for(; j > i*K;j--){
			printf("%05d %d %05d\n",nodes[j].addr,nodes[j].data,nodes[j-1].addr);
		}
		//ÿ���е����һ��
		printf("%05d %d ",nodes[j].addr,nodes[j].data); 
		if(i < group -1){//�������һ�飬ָ����һ������һ����� 
			printf("%05d\n",nodes[(i+1)*K + K - 1].addr);
		}else{
			//�����һ����û�ж���� 
			if(count % K == 0){
				printf("-1\n"); 
			} else{
				//�����һ�飬�ж����
				int t = i * K + K;
				printf("%05d\n",nodes[t].addr);
				t = count / K * K;
				for(;t < N -1 ;t++){
					printf("%05d %d %05d\n",nodes[t].addr,nodes[t].data,nodes[t+1].addr);
				}
				if(t == N -1){
					printf("%05d %d -1\n",nodes[t].addr,nodes[t].data);
				}
			}
		}
	} 
	return 0;
}
/*
����������
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

Ԥ�������
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1 
*/
