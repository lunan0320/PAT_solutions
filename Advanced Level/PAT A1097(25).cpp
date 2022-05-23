#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

const int maxn = 100010;

int addr_head,N;

struct node{
	int addr;
	int key;
	int next;
	bool flag = false;
}nodes[maxn];

map<int,int> my_map;

int main(){
	scanf("%d%d",&addr_head,&N);
	int address,key;
	for(int i = 0; i < N; i++){
		scanf("%d",&address);
		scanf("%d",&key);
		scanf("%d",&nodes[address].next);
		nodes[address].addr = address;
		nodes[address].key = key;
	}
	
	int p = addr_head;
	while(p != -1){
		//第一次出现 
		if(my_map.find(abs(nodes[p].key)) == my_map.end()){
			if(p == addr_head){
				printf("%05d %d ",nodes[p].addr,nodes[p].key);
			}else{
				printf("%05d\n%05d %d ",nodes[p].addr,nodes[p].addr,nodes[p].key);
			}	
			my_map[abs(nodes[p].key)] = 1; 
			nodes[p].flag = true;
			p = nodes[p].next;
		}else{
			my_map[abs(nodes[p].key)]++; 
			p = nodes[p].next;
		}
	}
	if(p == -1){
		printf("-1\n");
	}
	p = addr_head;
	int count = 0;
	while(p!=-1){
		if(my_map[(abs(nodes[p].key))]!= 1 && !nodes[p].flag){
			if(count == 0){
				printf("%05d %d ",nodes[p].addr,nodes[p].key);
				count ++;
			}else{
				printf("%05d\n%05d %d ",nodes[p].addr,nodes[p].addr,nodes[p].key);
				count ++;
			}	
		}
		p = nodes[p].next;
	}
	if(count !=0 ){
		printf("-1\n");
	}
	return 0;
}

