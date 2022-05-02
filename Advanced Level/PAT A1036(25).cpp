#include <cstdio>

struct Person{
	char name[15];
	char gender;
	char ID[15];
	int grade;
	Person(){
	}
	Person(int _grade){
		grade = _grade;
	}
};

int N;

//cmp函数用于求出两个人之间的较低成绩的人 
bool cmp(Person a, Person b){
	if(a.grade < b.grade){
		return true;
	}else{
		return false;
	}
}

int main(){
	scanf("%d", &N);
	Person temp;
	Person female(-1);
	Person male(101);
	
	for(int i = 0; i < N; i++){
		scanf("%s %c %s %d", &temp.name, &temp.gender, &temp.ID, &temp.grade);
		if(temp.gender == 'M'){
			if(cmp(temp,male)){
				male = temp;
			}
		}else if (temp.gender == 'F'){
			if(cmp(female,temp)){
				female = temp;
			}
		}
	}
	bool tag = false;
	if(female.grade == -1){
		printf("Absent\n");
		tag = true;
	}else{
		printf("%s %s\n",female.name,female.ID);
	}
	if(male.grade == 101){
		printf("Absent\n");
		tag = true;
	}else{
		printf("%s %s\n",male.name,male.ID);
	}
	if(tag){
		printf("NA\n");
	}else{
		printf("%d\n",female.grade - male.grade);
	}
}


/*
测试用例：
3
Joe M Math990112 89
Mike M CS991301 100
Mary F EE990830 95

预期输出：
Mary EE990830
Joe Math990112 
6

测试用例：
1
Jean M AA980920 60

预期输出：
Absent
Jean AA980920
NA

*/
