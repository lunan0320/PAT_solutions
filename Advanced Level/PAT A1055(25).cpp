	#include <cstdio>
	#include <algorithm>
	#include <cstring>
	using namespace std;
	
	const int maxn = 100001;
	
	int N, K;
	
	struct Rich{
		char name[9];
		int age;
		int worth; 
	}rich[maxn],valid[maxn];
	
	//某年龄段的人数 
	int Age[maxn];
	
	
	bool cmp(Rich a,Rich b){
		return a.age < b.age;
	}
	bool cmp1(Rich a, Rich b){
		if(a.worth != b.worth){
			return a.worth > b.worth;
		}else if(a.age != b.age){
			return a.age < b.age;
		}else return strcmp(a.name,b.name) < 0;
	}
	
	
	int main(){
		scanf("%d%d",&N,&K);
		for(int i = 0;i < N;i++){
			scanf("%s %d %d",rich[i].name,&rich[i].age,&rich[i].worth);
		}
		int query,age1 ,age2 ;
//	预处理 避免超时 
		sort(rich,rich+ N,cmp1);
		int validNum = 0;
		for(int i = 0; i < N; i++){
			if(Age[rich[i].age] < 100){
				Age[rich[i].age] ++;
				valid[validNum++] = rich[i];
			}
		} 		
		
		for(int i = 0; i < K; i++){
			int age1_index = -1,age2_index = -1;
			scanf("%d%d%d",&query,&age1,&age2);
			printf("Case #%d:\n",i+1);
			int count = 0;
			for(int j = 0; j < N && count < query; j++){
				if(valid[j].age >= age1 && valid[j].age <= age2){
					printf("%s %d %d\n",valid[j].name,valid[j].age,valid[j].worth);
					count ++;
				}
			} 
			if(count == 0){
				printf("None\n");
			}
	
		}
		return 0;
	}
