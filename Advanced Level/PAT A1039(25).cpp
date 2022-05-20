#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

int  N = 0, K = 0;
//通过string vector的格式保存
int main(){
	map<string, vector<int> > data;
	scanf("%d %d",&N,&K);
	string name;
	//为每个学生读入course编号 
	for(int i = 0 ; i < K; i++){
		int id = 0,number = 0;
		scanf("%d %d",&id,&number);
		
		for(int j = 0; j < number; j++){
			//读入字符串name 
			cin >> name; 
			data[name].push_back(id);	
		}
	}
	//排序输出
	vector<int> *temp = NULL;
	for(int i = 0; i < N;i++){
		cin >>name;
		temp = &data[name];
		sort(temp->begin(),temp->end());
		printf("%s %ld",name.c_str(),temp->size());
		vector<int >::iterator it = temp->begin();
		for(; it != temp->end(); it++){
			printf(" %d",*it);
		}
		printf("\n");
	} 
	return 0;
}
/*
测试样例:
11 5
4 7
BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
1 4
ANN0 BOB5 JAY9 LOR6
2 7
ANN0 BOB5 FRA8 JAY9 JOE4 KAT3 LOR6
3 1
BOB5
5 9
AMY7 ANN0 BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
ZOE1 ANN0 BOB5 JOE4 JAY9 FRA8 DON2 AMY7 KAT3 LOR6 NON9
 

*/

