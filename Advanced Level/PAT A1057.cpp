#include <cstdio>
#include <stack>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 100001;
const int sqrN = 500;
 
int N;

stack<int> st;

int block[sqrN] = {0}; //��ʾ��i���ֿ��ж��ٸ�Ԫ��
int table[maxn] = {0}; //��ʾ��i��Ԫ�س����˶��ٴ� 

void func_push(int x){
	st.push(x);
	//����ջ���block��table�������
	block[x/sqrN] ++;
	table[x]++; 
}

void func_pop(){
	if(st.empty()){
		printf("Invalid\n");
		return ;
	}
	int temp = st.top();
	st.pop();
	//�ڵ���֮���block��table�������
	block[temp/sqrN] --;
	table[temp]--; 
	printf("%d\n",temp);
}

void func_median(){
	if(st.empty()){
		printf("Invalid\n");
		return;
	}
	int K = st.size();
	//��ʾ��ʱҪ�ҵ�k��� 
	if(K%2==0){
		K = K/2;
	}else{
		K = (K+1) / 2;
	}
	int sum = 0; //sum��ʾ��ǰ�ǵ�ǰ�ۼƵ�Ԫ�صĸ���
	int idx = 0; //���
	//�ҵ��� K��Ԫ�����ڵĵ�idx���� 
	while(sum + block[idx] < K){
		sum = sum + block[idx];
		idx++;
	} 
	//num��ʾ�ڵ�idx�����ʼ���� 
	int num = idx * sqrN;
	//�����idx�����������K���
	while(sum + table[num] < K){
		sum += table[num];
		num++;
	}
	//��ʱnum���ǵ�k���Ԫ��
	printf("%d\n",num);
	
	
}

int main(){
	scanf("%d", &N);
	char op[20]; 
	for(int i = 0; i < N; i++){
		//����ط���Ҫע���Ƕ�ȡ�ַ�����ʱ�������ո�ͶϿ��� 
		scanf("%s",  &op);
		if(strcmp(op,"Pop") == 0){ 
			func_pop();
		}else if(strcmp(op,"Push") == 0){
			//�����push ��ʱ��ո�Ͽ��ĵط������ٶ��������
			int x = 0;
			scanf("%d", &x); 
			func_push(x);
		}else if(strcmp(op,"PeekMedian") == 0){
			func_median();
		}
	}
	return 0;
}

/*
���㷨�ʼǡ� page 468

���������� 
17 
Pop
PeekMedian
Push 3
PeekMedian
Push 2
PeekMedian
Push 1
PeekMedian
Pop
Pop
Push 5
Push 4
PeekMedian
Pop
Pop
Pop
Pop

Ԥ�������
Invalid
Invalid
3
2
2
1
2
4
4
5
3
Invalid 

*/
