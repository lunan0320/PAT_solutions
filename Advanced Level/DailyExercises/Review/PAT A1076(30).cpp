#include <cstdio>
#include <vector>
#include <queue>
 
using namespace std;


const int maxn = 1001;


struct Node{
	int id;
	vector<int> followers;	
	int level;
}nodes[maxn];


int N,L;

int main(){
	scanf("%d%d",&N,&L);
	int follow_num ;
	for(int i = 1;i <= N; i++){
		scanf("%d",&follow_num);
		int follow_id ;
		for(int j = 0; j < follow_num; j++){
			scanf("%d",&follow_id);
			nodes[follow_id].followers.push_back(i);
		}
	} 
	
	int query_num;
	scanf("%d",&query_num);
	for(int i = 0; i < query_num;i++){
		int query_id;
		scanf("%d",&query_id);
		int count = 0;
		bool isForward[maxn] = {false};
		queue<int> q;
		q.push(query_id);
		nodes[query_id].level = 0;
		while(!q.empty()){
			int front = q.front();
			q.pop();
		//	printf("front:%d\n",front);
			
			isForward[front] = true;
			if(nodes[front].level >= L){
			//	printf("level:%d\n",nodes[front].level);
				continue;
			}
			int user_len = nodes[front].followers.size();
		//	printf("len:%d\n",user_len);
			for(int j = 0; j < user_len;j++){
				int id = nodes[front].followers[j];
				
				//没有访问过 
				if(!isForward[id]){
				//	printf("id:%d\n",id);
					count++;
					isForward[id] = true;
					nodes[id].level = nodes[front].level + 1;
					q.push(id);
				}
			}	
		}
		printf("%d\n",count);
	}
	
	return 0;
}


/*
id  followers
1  4
2  1
3  1  4  5
4  1  5  6
5  3  7
6  3 
7  

*/
