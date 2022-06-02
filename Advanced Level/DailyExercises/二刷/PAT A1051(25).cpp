#include <cstdio>
#include <stack>

using namespace std;

const int maxn = 1001;

int arr[maxn]; //�洢һ��

stack<int> st;

//ջ��������������г��ȣ����и��� 
int M, N, K;

int main(){
	scanf("%d%d%d",&M,&N,&K);
	for(int i = 0; i < K; i++){
		for(int j = 1; j <= N; j++){
			scanf("%d",&arr[j]);
		}
		//���ջ 
		while(!st.empty()){
			st.pop();
		}
		//����ջ�����жϱ߽�����
		int k = 1;
		bool flag = true;
		for(int j = 1; j <= N; j++){
			st.push(j);
			//����ջ���������� 
			if(st.size() > M){
				flag = false;
				printf("NO\n");
				break;
			}
			
			//�ж��Ƿ��������ȣ������pop
			while(!st.empty() && st.top() == arr[k]){
				st.pop();
				k++;
			} 	
		} 
		if(st.empty() && flag){
			printf("YES\n");
		}
	}
	return 0;
} 
