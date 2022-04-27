#include <cstdio>
#include <stack>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 100001;
const int sqrN = 500;
 
int N;

stack<int> st;

int block[sqrN] = {0}; //表示第i个分块有多少个元素
int table[maxn] = {0}; //表示第i个元素出现了多少次 

void func_push(int x){
	st.push(x);
	//在入栈后对block和table数组更新
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
	//在弹出之后对block和table数组更新
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
	//表示此时要找第k大的 
	if(K%2==0){
		K = K/2;
	}else{
		K = (K+1) / 2;
	}
	int sum = 0; //sum表示当前是当前累计的元素的个数
	int idx = 0; //块号
	//找到第 K大元素所在的第idx个块 
	while(sum + block[idx] < K){
		sum = sum + block[idx];
		idx++;
	} 
	//num表示在第idx块的起始索引 
	int num = idx * sqrN;
	//在这个idx块中找这个第K大的
	while(sum + table[num] < K){
		sum += table[num];
		num++;
	}
	//此时num就是第k大的元素
	printf("%d\n",num);
	
	
}

int main(){
	scanf("%d", &N);
	char op[20]; 
	for(int i = 0; i < N; i++){
		//这个地方需要注意是读取字符串的时候遇到空格就断开了 
		scanf("%s",  &op);
		if(strcmp(op,"Pop") == 0){ 
			func_pop();
		}else if(strcmp(op,"Push") == 0){
			//因此在push 的时候空格断开的地方可以再读入操作数
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
《算法笔记》 page 468

输入用例： 
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

预期输出：
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
