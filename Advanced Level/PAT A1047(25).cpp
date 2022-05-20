#include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

map<int,vector<string> > course;
int N, K;

int main(){
	scanf("%d %d",&N,&K);
	string name;
	int count = 0; //表示这个人对应的课程数 
	int id = 0;   //课程id 
	for(int i = 0; i < N; i++){
		cin >> name;
		scanf("%d",&count);
		for(int j = 0; j < count; j++){
			scanf("%d",&id);
			course[id].push_back(name);
		}
	}
	vector<string>* temp = NULL;
	for(int i = 1; i < K+1;i++){
		temp = &course[i];
		vector<string>::iterator it = temp->begin();
		sort(temp->begin(),temp->end());
		printf("%d %d\n",i,temp->size());
		for(;it!=temp->end();it++){
			printf("%s\n",it->c_str()); 
		}
	}
	return 0;
}

/*
输入样例：
10 5
ZOE1 2 4 5
ANN0 3 5 2 1
BOB5 5 3 4 2 1 5
JOE4 1 2
JAY9 4 1 2 5 4
FRA8 3 4 2 5
DON2 2 4 5
AMY7 1 5
KAT3 3 5 4 2
LOR6 4 2 4 1 5

预期输出：
1 4
ANN0
BOB5
JAY9
LOR6
2 7
ANN0
BOB5
FRA8
JAY9
JOE4
KAT3
LOR6
3 1
BOB5
4 7
BOB5
DON2
FRA8
JAY9
KAT3
LOR6
ZOE1
5 9
AMY7
ANN0
BOB5
DON2
FRA8
JAY9
KAT3
LOR6
ZOE1
 
*/
