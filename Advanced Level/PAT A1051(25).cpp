#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;

const int maxn = 1010;

//���鱣����������� 
int arr[maxn];

stack<int> st;



int main(){
	int M, N, K;
	scanf("%d %d %d",&M,&N,&K);
	//K������ 
	for(int i = 0; i < K; i++){
		bool flag = true;
		//����һ��popֵ 
		for(int j = 1; j <= N; j++){
			scanf("%d",&arr[j]);
		}
		//���ջ
		while(!st.empty()){
			st.pop();
		} 
		//k��ʾ��������ĵڼ��� 
		int k = 1;
		//t��ʾstack��ʱpush�˶��ٸ� 
		for(int t = 1; t <= N; t++){
			st.push(t); 
			//�����涨��push���� 
			if(st.size() > M){
				flag = false;
				break;
			}
				
			while(!st.empty() && st.top() == arr[k]){
				st.pop();
				k++;
			}
		} 

		
		if(st.empty()==true && flag == true){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}


/*
����������
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2
 
*/
