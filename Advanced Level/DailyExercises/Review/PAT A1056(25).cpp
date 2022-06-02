
#include <bits/stdc++.h>
using namespace std;

const int maxn = 10001;

int N,N_g;

struct Mouse{
	int weight;
	int rank;
}mouse[maxn];


int main(){
	scanf("%d%d",&N,&N_g);
	for(int i = 0; i < N; i++){
		scanf("%d",&mouse[i].weight); 
	} 
	queue<int> q;
	int order;
	for(int i = 0; i < N;i++){
		scanf("%d",&order);
		q.push(order);
	}
	int temp = N; //当前的老鼠数量 
	int group = 0; //组数 
	while(q.size() != 1){
		//每次组内比较结束后 重新分组 
		if(temp % N_g == 0){
			group = temp / N_g;
		}else{
			group = temp / N_g +  1;
		}
		//所有分组 
		for(int i = 0; i < group;i++){
	
			int max = q.front();
			 //每个组 
			for(int j = 0;j < N_g;j++){
				//最后一个组超过 
				if(i * N_g + j >= temp){
					break;
				}
				int front = q.front();
				max = mouse[front].weight > mouse[max].weight ? front : max;
				//设置排名
				mouse[front].rank = group + 1; 
				q.pop();
			}

			//组内选拔结束 
			q.push(max);
		}
		temp = group;
	}
	int front = q.front();
	mouse[front].rank = 1; 
	for(int i = 0; i < N; i++){
		printf("%d",mouse[i].rank);
		if(i < N - 1){
			printf(" ");
		}else{
			printf("\n");
		}
	}
	return 0;
}
