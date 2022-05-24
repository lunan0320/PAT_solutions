//并查集

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1010;

int N;

int father[maxn];
int isRoot[maxn] = {0};
int course[maxn] = {0}; //表示谁是第一个喜欢这个课程  


//自定义从大到小排序 
bool cmp(int A,int B){
	return A > B;
}
//寻找x的父亲结点 
int Findfather(int x){
	int a = x;
	while(x != father[x]){
		x = father[x];
	}
	//路径压缩（再走一遍） 
	while(a != father[a]){
		int z = a;
		a = father[a];
		//这个cluster 更新为x 
		father[z] = x;
	}
	return x; 
} 

//合并a和b所在的集合 
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
				//表示course k 是第i个人第一个喜欢 
				course[h] = i;
			}
			//将当前人和喜欢这个课程的人合并 
			Union(i,Findfather(course[h])); 
		}
	}
	for(int i = 1;i <= N; i++){
		isRoot[Findfather(i)]++;
	} 
	//cluster不为0的情况 
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
