#include<cstdio>
#include <cstring>
const int maxn = 100010;

struct node{
	int addr;
	char data;
	int next;
	bool flag = false;
}nodes[maxn];


int main(){
	int addr1,addr2,N;
	scanf("%d%d%d",&addr1,&addr2,&N);
	int address;
	for(int i = 0;i < N; i++){
		scanf("%d ",&address);
		scanf("%c ",&nodes[address].data);
		scanf("%d",&nodes[address].next);
		nodes[address].addr = address;
	}
	int p = addr1;
	while(p != -1){
		//flagΪ1��ʾ��list1�� 
		nodes[p].flag = true; 
		p = nodes[p].next;
	}
	p = addr2;
	while(p!=-1){
		if(nodes[p].flag){
			printf("%05d\n",p);
			break;
		}
		p = nodes[p].next;
	}
	if(p == -1){
		printf("-1\n");
	}
	return 0;
}
 
 
/*
����������
11111 22222 9
67890 i 00002
00010 a 12345
00003 g -1
12345 D 67890
00002 n 00003
22222 B 23456
11111 L 00001
23456 e 67890
00001 o 00010

Ԥ�������
67890

����������
00001 00002 4
00001 a 10001
10001 s -1
00002 a 10002
10002 t -1

Ԥ�������
-1 
*/
