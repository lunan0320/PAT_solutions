#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;


int N,cite_num;

const int maxn = 30001;

struct Student{
	char id[14];
	int score;
	int cite;
	int cite_rank;
}stu[maxn];

bool cmp(Student a,Student b){
	if(a.score != b.score){
		return a.score > b.score;
	}else return strcmp(a.id,b.id) < 0;
	
}

int main(){
	scanf("%d",&N);
	int num = 0;//总考生数量 
	for(int i = 1; i <= N;i++){
		scanf("%d",&cite_num);
		for(int j = 0; j < cite_num;j++){
			scanf("%s %d",stu[num].id,&stu[num].score);
			stu[num++].cite = i; //当前考场 
		}
		//考场内部排名 
		sort(stu + num - cite_num,stu + num,cmp);
		stu[num - cite_num].cite_rank = 1;
		for(int j = num - cite_num + 1; j < num;j++){
			if(stu[j].score == stu[j-1].score){
				stu[j].cite_rank = stu[j-1].cite_rank;
			}else{
				stu[j].cite_rank = j - num + cite_num + 1;
			}
		} 
	}
	printf("%d\n",num);
	sort(stu,stu + num,cmp);
	int r = 1; //当前考生排名 
	for(int i = 0; i  < num;i++){
		if(i > 0 && stu[i].score != stu[i -1].score){
			r = i+1;
		} 
		printf("%s ",stu[i].id);
		printf("%d %d %d\n",r,stu[i].cite,stu[i].cite_rank);
	}
	return 0;
} 
