#include <bits/stdc++.h>

using namespace std;

const int INF = 100000000;
const int maxn = 1000001;

struct Node{
	int addr;
	int data;
	int next;
	int order = INF ;
}nodes[maxn];


int start,N,M;


bool cmp(Node a,Node b){
	return a.order < b.order;
}
int main(){
	scanf("%05d%d%d",&start,&N,&M);
	int addr;
	for(int i = 0; i < N; i++){
		scanf("%d",&addr);
		scanf("%d%d",&nodes[addr].data,&nodes[addr].next);
		nodes[addr].addr = addr;
	}
	
	//排序 
	int p = start;
	int k = 0;
	while( p != -1){
		nodes[p].order = k++;
		p = nodes[p].next;
	}	
	
	sort(nodes,nodes+maxn,cmp);
	
	int group = N/M;
	
	for(int i = 0;i < group; i++){
		int j = i* M+M -1 ; //这个组中的最后一个 

		for(;j > i * M;j--){
			printf("%05d %d %05d\n",nodes[j].addr,nodes[j].data,nodes[j-1].addr);
		}		
		//每组的最后一个要单独处理	
		printf("%05d %d ",nodes[j].addr,nodes[j].data);	
		//不是最后一块 
		if(i < group - 1){
			printf("%05d\n",nodes[(i+1)*M + M - 1].addr);
		}else{
			if(N % M == 0){
				printf("-1\n");
			}else{
				int k = i * M + M;
				printf("%05d\n",nodes[k].addr);
				k = N / M * M; 
				for(;k < N -1 ;k++){
					printf("%05d %d %05d\n",nodes[k].addr,nodes[k].data,nodes[k+1].addr);
				}
				if(k == N -1){
					printf("%05d %d -1\n",nodes[k].addr,nodes[k].data);
				}					
			}
		}
	}
	
	return 0;
}
