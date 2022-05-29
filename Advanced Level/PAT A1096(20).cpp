#include <cstdio>
#include <cmath>
typedef long long ll;
using namespace std;


ll N;

int main(){
	scanf("%lld",&N);
	ll sqr = sqrt(1.0 * N);
	int ansLen = 0;
	int ansSt = 0;
	//i是起始点 
	for(int i = 2; i<= sqr;i++){
		//temp表示连续的乘积，j是当前值 
		int temp = 1,j = i,size = 0; 
		while(1){
			temp *= j;
			if(N%temp != 0){
				break;
			} 
			size++;
			if(size > ansLen){
				ansLen = size;
				ansSt = i; 
			}
			j++;
		}
	}
	if(ansLen == 0){
		printf("1\n%d",N);
	}else{
		printf("%d\n",ansLen);
		for(int i = ansSt; i < ansLen + ansSt;i++){
			printf("%d",i);
			if(i < ansLen + ansSt - 1){
				printf("*");
			}else{
				printf("\n");
			}
		}		
	}

	return 0;
}
