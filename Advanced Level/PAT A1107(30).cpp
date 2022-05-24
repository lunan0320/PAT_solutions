//���鼯

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1010;

int N;

int father[maxn];
int isRoot[maxn] = {0};
int course[maxn] = {0}; //��ʾ˭�ǵ�һ��ϲ������γ�  


//�Զ���Ӵ�С���� 
bool cmp(int A,int B){
	return A > B;
}
//Ѱ��x�ĸ��׽�� 
int Findfather(int x){
	int a = x;
	while(x != father[x]){
		x = father[x];
	}
	//·��ѹ��������һ�飩 
	while(a != father[a]){
		int z = a;
		a = father[a];
		//���cluster ����Ϊx 
		father[z] = x;
	}
	return x; 
} 

//�ϲ�a��b���ڵļ��� 
void Union(int a,int b){
	int faA = Findfather(a);
	int faB = Findfather(b);
	if(faA != faB){
		father[faA] = faB;
	} 
} 


void init(int n){
	for(int i = 1; i <= n; i++){
		father[i] = i;
	}
}


int main(){
	scanf("%d",&N);
	int k,h;
	init(N);
	for(int i = 1; i <= N; i++){
		scanf("%d:",&k);
		for(int j = 0; j < k; j++){
			scanf("%d",&h);
			if(course[h] == 0){
				//��ʾcourse k �ǵ�i���˵�һ��ϲ�� 
				course[h] = i;
			}
			//����ǰ�˺�ϲ������γ̵��˺ϲ� 
			Union(i,Findfather(course[h])); 
		}
	}
	for(int i = 1;i <= N; i++){
		isRoot[Findfather(i)]++;
	} 
	//cluster��Ϊ0����� 
	int count = 0;
	for(int i = 1;i <= N; i++){
		if(isRoot[i] != 0){
			count++;
		} 
	} 
	printf("%d\n",count); 
	
	sort(isRoot+1,isRoot+N+1,cmp);
	
	for(int i = 1;i <= count ; i++){
		printf("%d",isRoot[i]);
		if(i < count){
			printf(" ");
		}else{
			printf("\n");
		}
	}
	
	return 0;
}
