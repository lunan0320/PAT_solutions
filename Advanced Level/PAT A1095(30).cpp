#include <cstdio>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <iterator>
using namespace std;

const int maxn = 10010;

struct Car{
	char id[8];
	int time;
	char status[4]; //in or out
}cars[maxn],valid[maxn];

map<string,int> parkTime; 

int N, K;
 
 
bool cmp1(Car a,Car b){
	int s = strcmp(a.id,b.id);
	if(s != 0){
		return s < 0;
	}else{
		return a.time < b.time;
	}
} 

bool cmp2(Car a,Car b){
	return a.time < b.time;
}
int main(){
	scanf("%d%d",&N,&K);
	int hh,mm,ss;
	
	for(int i = 0; i < N; i++){
		scanf("%s %02d:%02d:%02d %s",cars[i].id,&hh,&mm,&ss,cars[i].status);
		cars[i].time = hh * 3600 + mm * 60 + ss;
	}
	sort(cars,cars+N,cmp1);
	//筛选有效车辆 
	int validNum = 0;
	int maxTime = -1;
	for(int i = 0; i < N-1; i++){
		//有效车辆 
		if(strcmp(cars[i].id,cars[i + 1].id) == 0 && strcmp(cars[i].status,"in") == 0&&
		strcmp(cars[i + 1].status,"out") == 0){
			valid[validNum++] = cars[i];
			valid[validNum++] = cars[i+1];
			//记录该车辆的时间 
			if(parkTime.count(cars[i].id) == 0){
				parkTime[cars[i].id] = 0; 
			}
			parkTime[cars[i].id] += cars[i+1].time - cars[i].time;
			maxTime = max(maxTime,parkTime[cars[i].id]);
		}
	}
	//按时间排序 
	int j = 0;
	sort(valid,valid+validNum,cmp2);
	hh = 0,mm = 0,ss= 0;
	int query_num = 0;
	for(int i = 0; i < K; i++){
		scanf("%02d:%02d:%02d",&hh,&mm,&ss);
		int query = hh * 3600 + mm * 60 +ss;
		
		while(j < validNum &&valid[j].time <= query){
			if(!strcmp(valid[j].status,"in")){
				query_num++;
			}else{
				query_num--;
			}
			j++;
		}
		printf("%d\n",query_num);
	}
	
	//输出最长时间 
	map<string,int>::iterator it = parkTime.begin();
	
	for(;it!=parkTime.end();it++){
		if(it->second == maxTime){
			printf("%s ",it->first.c_str());
		}
	}
	hh = maxTime / 3600;
	maxTime = maxTime %3600;
	mm = maxTime /60;
	maxTime = maxTime % 60;
	ss = maxTime;
	printf("%02d:%02d:%02d",hh,mm,ss);
	
	
	return 0;
}
