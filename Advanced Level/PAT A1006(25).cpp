#include <cstdio>
#include <string>
using namespace std;


const int maxn = 20;

int M;


struct Node{
	char ID[20];
	int hh;
	int mm;
	int ss;
	Node(){
		
	}
	Node(int _hh, int _mm, int _ss){
		hh = _hh;
		mm = _mm;
		ss = _ss;
	}
}; 

//返回时间较小的 
bool cmp(Node a,Node b){
	if(a.hh < b.hh){
		return true;
	}else if (a.hh > b.hh){
		return false;
	}else{
		if(a.mm < b.mm){
			return true;
		}else if(a.mm > b.mm){
			return false;
		}else{
			if(a.ss < b.ss){
				return true;
			}else{
				return false;
			}
		}
	}
}



int main(){
	//res1表示更早的时间  
	Node res1(13,61,61);
	//res2表示更晚的时间
	Node res2(-1,-1,-1); 
	scanf("%d", &M);
	Node temp;
	for(int i = 0; i < M; i++){
		scanf("%s %d:%d:%d", &temp.ID, &temp.hh, &temp.mm, &temp.ss);
		//比较temp是否比res1更早 
		if(cmp(temp,res1)){
			res1 = temp; 
		}
		scanf("%d:%d:%d", &temp.hh, &temp.mm, &temp.ss);
		//比较temp是否比ress2更晚 
		if(cmp(res2,temp)){
			res2 = temp; 
		}
		
	}
	printf("%s %s",res1.ID,res2.ID);
}

/*
测试样例：
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 24:45:00 21:58:40


*/

