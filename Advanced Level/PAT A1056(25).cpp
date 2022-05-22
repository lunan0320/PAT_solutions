#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 1010;

struct mouse{
	int weight;
	int rank;
}mouse[maxn];




int main(){
	queue<int> q;
	int N_p, N_g;
	//�������� 
	scanf("%d %d",&N_p,&N_g);
	for(int i = 0; i < N_p; i++){
		scanf("%d",&mouse[i].weight);
	}
	int order;
	for(int i = 0; i < N_p;i++){
		scanf("%d",&order);
		q.push(order);
	}
	
	//tmep ��ʾ��ǰ���ж��ٸ�mouse��group�Ǳ�ʾ�ж����� 
	int temp = N_p, group;
	while(q.size() != 1){
		//�������� 
		if(!(temp%N_g)){
			group = temp / N_g;
		}else{
			group = temp / N_g + 1;
		} 
		//��ÿһ�鴦��
		for(int i = 0 ; i < group; i++){
			//max��ʾ��ǰ�����ص�mouse 
			int max = q.front();
			//����ÿ���� 
			for(int j = 0; j < N_g; j++){
				//���һ����� 
				if(i * N_g + j >= temp){
					break;
				}
				int front = q.front();
				if(mouse[front].weight > mouse[max].weight){
					max = front;
				} 
				mouse[front].rank = group + 1;
				//���������� 
				q.pop();
			} 
			//�Ѹ���������mouse push 
			q.push(max); 	
		} 
		//������һ�� 
		temp = group;
	}
	mouse[q.front()].rank = 1;
	for(int i = 0; i < N_p; i++){
		if(i == N_p -1){
			printf("%d",mouse[i].rank);
		}else{
			printf("%d ",mouse[i].rank);
		}
	}	
	return 0;
}


/*
����������
11 3
25 18 0 46 37 3 19 22 57 56 10
6 0 8 7 10 5 9 1 4 2 3

Ԥ�������
5 5 5 2 5 5 5 3 1 3 5
 

*/
