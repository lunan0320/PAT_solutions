#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 100001;


struct student{
	int id;
	char name[9];
	int grade;
}stu[maxn];

int N,C;

bool cmp1(student a,student b){
	return a.id < b.id;
}

bool cmp2(student a,student b){
	int s = strcmp(a.name,b.name);
	if(s == 0){
		return a.id < b.id;
	}else{
		return s < 0;
	}
}

bool cmp3(student a,student b){
	if(a.grade != b.grade){
		return a.grade < b.grade;
	}else{
		return a.id < b.id;
	}
}
int main(){
	scanf("%d%d",&N,&C);
	for(int i = 0; i < N; i++){
		scanf("%d%s%d",&stu[i].id,stu[i].name,&stu[i].grade);
	}
	if(C == 1){
		sort(stu,stu+N,cmp1);
	} else if(C == 2){
		sort(stu,stu+N,cmp2);
	}else if(C == 3){
		sort(stu,stu+N,cmp3);
	}
	for(int i = 0; i < N; i++){
		printf("%06d %s %d\n",stu[i].id,stu[i].name,stu[i].grade);
	}
	return 0;
} 
