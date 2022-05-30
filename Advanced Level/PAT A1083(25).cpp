#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 10001;

struct student{
	char name[11];
	char id[11];
	int grade;
}stu[maxn];

bool cmp(student a,student b){
	return a.grade > b.grade;
} 

int N;
int grade1,grade2;

int main(){
	scanf("%d",&N);
	for(int i = 0; i < N; i++){
		scanf("%s %s %d",stu[i].name,stu[i].id,&stu[i].grade);
	}
	scanf("%d%d",&grade1,&grade2);
	sort(stu,stu+maxn,cmp);
	bool flag = false;
	for(int i = 0; i < N; i++){
		if(stu[i].grade >= grade1 && stu[i].grade <= grade2){
			flag = true;
			printf("%s %s\n",stu[i].name,stu[i].id);
		}
	}
	if(!flag){
		printf("NONE\n");
	}
	return 0;
}
