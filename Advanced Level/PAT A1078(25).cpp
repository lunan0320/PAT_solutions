#include <cstdio>
#include <cmath>

using namespace std;


int N,Msize;
int Tsize;
const int maxn = 11111;
bool HashTable[maxn] = {false};

bool isPrime(int m){
	if(m <= 1){
		return false;
	} 
	int k = sqrt(1.0*m);
	for(int i = 2;i <=k;i++){
		if(m%i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	scanf("%d%d",&Tsize,&N);
	while(isPrime(Tsize) == false){
		Tsize++;
	}
	int temp;
	for(int i = 0; i < N; i++){
		scanf("%d",&temp);
	
		if(HashTable[temp%Tsize] == false){
			HashTable[temp%Tsize] = true;
			printf("%d",temp%Tsize);
		}else{
			int step = 1;
			//二次探查法 
			for(;step < Tsize;step++){
				int new_temp = temp + step * step;
				if(HashTable[new_temp%Tsize] == false){
					HashTable[new_temp%Tsize] = true;
					printf("%d",new_temp%Tsize);
					break;
				}
			}
			if(step >= Tsize ){
				printf("-");
			}
		}
		if(i < N-1){
			printf(" ");
		}else{
			printf("\n");
		}
	}
	return 0;
} 



