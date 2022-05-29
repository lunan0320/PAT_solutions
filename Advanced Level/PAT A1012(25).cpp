#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M;

const int maxn = 1000001;

struct Stu{
	int id;
	int grade[4];
}stu[maxn];


char course[4] = {'A','C','M','E'};

int query[maxn];

int now;
//表示id为i的人的第j门成绩的排名 
int Rank[maxn][4] = {0};

bool cmp(Stu a,Stu b){
	return a.grade[now] > b.grade[now];
}

int main(){
	//输入 
	scanf("%d%d",&N,&M);
	for(int i = 0; i < N; i++){
		scanf("%d%d%d%d",&stu[i].id,&stu[i].grade[1],&stu[i].grade[2],&stu[i].grade[3]);
		stu[i].grade[0] = round((stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3])/3);
	}
	for(int i = 0;i < M; i++){
		scanf("%d",&query[i]);
	}
	//成绩排名 
	for(now = 0; now <4; now++){
		sort(stu,stu+N,cmp);
		Rank[stu[0].id][now] = 1;
		for(int i = 1; i < N; i++){
			//成绩相同 
			if(stu[i].grade[now] == stu[i-1].grade[now]){
				Rank[stu[i].id][now] = 1;
			}else{
				Rank[stu[i].id][now] = i + 1;
			}	
		}
	} 
	for(int i = 0; i < M; i++){
		int id = query[i];
		if(Rank[id][0] == 0){
			printf("N/A\n");
			continue;
		}
		int min_Rank = 100;
		int min_index;
		for(int j = 0; j < 4;j++){
			if(Rank[id][j] < min_Rank){
				min_Rank = Rank[id][j];
				min_index= j;
			}
		}
		printf("%d %c\n",min_Rank,course[min_index]);
	}
	return 0;
}
