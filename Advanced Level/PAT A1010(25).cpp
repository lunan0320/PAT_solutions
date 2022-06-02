#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
using namespace std;

typedef long long LL;
const LL inf = 100000000001;
char N1[20],N2[20],temp[20];

int tag,radix;



LL Map[256];
void init(){
	for(char c = '0'; c <= '9'; c++){
		Map[c] = c - '0';
	}
	for(char c = 'a'; c <= 'z'; c++){
		Map[c] = c - 'a'+10;
	}
}

LL convert10(char a[],LL radix,LL inf){
	int len = strlen(a);
	LL res = 0;
	int index = 0,temp = 0; 
	for(int i= 0 ; i < len; i++){
		res = res * radix + Map[a[i]];
		if(res > inf || res < 0){
			return -1;
		}
	}
	return res;
}

int find(char N2[]){
	int ans = -1;
	int len = strlen(N2);
	for(int i= 0; i< len;i++){
		if(Map[N2[i]] > ans){
			ans = Map[N2[i]];
		}
	}
	return ans+1;
}

int cmp(char N2[],LL radix,LL t){
	int len = strlen(N2);
	LL temp = convert10(N2,radix,t);
	if(temp < 0)  return 1;
	if(t > temp) return -1;
	else if(t == temp) return 0;
	else return 1;
}


LL binarySearch(char N2[],LL low,LL high,LL t){
	
	while(low <= high){
		LL mid = (low + high) /2;
		int flag = cmp(N2,mid,t);
		if(flag==0){
			return mid;
		}else if (flag > 0){
			high = mid -1;
		}else{
			low = mid +1;
		}
	}
	return -1;
}

int main(){
	init();
	scanf("%s %s %d %d",N1,N2,&tag,&radix);
	if(tag == 2){
		strcpy(temp,N1);
		strcpy(N1,N2);
		strcpy(N2,temp);
	}
	LL t = convert10(N1,radix,inf);
	LL low = find(N2);
	LL high = max(low,t) +1;
	LL res = binarySearch(N2,low,high,t);
	if(res == -1){
		printf("Impossible\n");
	}else{
		printf("%lld\n",res);
	}
	return 0;
}
