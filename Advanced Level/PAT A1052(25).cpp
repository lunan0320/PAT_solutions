#include <cstdio>
#include <algorithm>
using namespace std;


const int maxn = 100010;

struct node{
	int addr;
	int key;
	int next;
	bool flag;
}nodes[maxn]; 

bool cmp(node A, node B){
	if(!A.flag || !B.flag){
		return A.flag > B.flag;
	}
	return A.key < B.key;
}


int main(){
	int N, addr_head;
	scanf("%d %d",&N,&addr_head);
	int addr;
	for(int i= 0; i < maxn ;i++){
		nodes[i].key = maxn;
	}
	for(int i = 0; i < N; i++){
		scanf("%d",&addr);
		scanf("%d",&nodes[addr].key);
		scanf("%d",&nodes[addr].next);
		nodes[addr].addr = addr;
	}
	int p = addr_head,count = 0;
	while(p!=-1){
		nodes[p].flag = true;
		p = nodes[p].next;
		count++;
	}
	if(count!= 0){
		sort(nodes,nodes+maxn,cmp);
		printf("%d %05d\n",N,nodes[0].addr);
		for(int i= 0; i < count; i++){
			if(i!=count-1){
				printf("%05d %d %05d\n",nodes[i].addr,nodes[i].key,nodes[i+1].addr);			
			}else{
				printf("%05d %d -1\n",nodes[i].addr,nodes[i].key);
			}
		} 		
	}else{
		printf("0 -1\n");
	}

	return 0;
}

/*
²âÊÔÑùÀý£º
5 00001
11111 100 -1
00001 0 22222
33333 100000 11111
12345 -1 33333
22222 1000 12345

Ô¤ÆÚÊä³ö£º
5 12345
12345 -1 00001
00001 0 11111
11111 100 22222
22222 1000 33333
33333 100000 -1

*/
