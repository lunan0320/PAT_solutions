
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
	int temp = N; //��ǰ���������� 
	int group = 0; //���� 
	while(q.size() != 1){
		//ÿ�����ڱȽϽ����� ���·��� 
		if(temp % N_g == 0){
			group = temp / N_g;
		}else{
			group = temp / N_g +  1;
		}
		//���з��� 
		for(int i = 0; i < group;i++){
	
			int max = q.front();
			 //ÿ���� 
			for(int j = 0;j < N_g;j++){
				//���һ���鳬�� 
				if(i * N_g + j >= temp){
					break;
				}
				int front = q.front();
				max = mouse[front].weight > mouse[max].weight ? front : max;
				//��������
				mouse[front].rank = group + 1; 
				q.pop();
			}

			//����ѡ�ν��� 
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
