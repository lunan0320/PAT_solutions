#include<cstdio>
#include <map>
#include <iterator>
using namespace std;

int M, N;

map<int,int>cnt;

int main(){
	scanf("%d %d",&M,&N);
	
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			int temp = 0;
			scanf("%d",&temp);
			if(cnt.find(temp) == cnt.end()){
				cnt[temp] = 0;
			}	
			cnt[temp]++;
		}
	}
	map<int,int>::iterator it = cnt.begin();
	int maxCount = -1;
	int maxNum = 0;
	while(it!=cnt.end()){
		if(it->second > maxCount){
			maxCount = it->second;
			maxNum = it->first; 
		}
		it++;
	}
	printf("%d",maxNum);
	return 0;
} 

/*
²âÊÔÑùÀı£º
5 3
0 0 255 16777215 24
24 24 0 0 24
24 0 24 24 24 


*/

