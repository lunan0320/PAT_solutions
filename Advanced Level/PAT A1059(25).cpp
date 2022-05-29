#include <cstdio>
#include <cmath>
typedef  long long ll;
using namespace std;

const ll maxn = 100010;

//素数判定 
bool isPrime(ll m){
	if(m == 1){
		return false;
	}
	ll k = sqrt(1.0*m);
	for(int i = 2;i <= k; i++){
		if(m % i == 0){
			return false;
		}
	}
	return true;
}

//求素数表 
ll prime[maxn] ,num = 0;
void createPrime(){
	for(int i = 2; i < maxn; i++){
		if(isPrime(i)){
			prime[num++] = i;
		}
	}
}

struct node{
	int x;
	int exp;
	node(){
		x = 0;
		exp = 0;
	}
}fac[20];


int main(){
	ll N;
	createPrime();
	scanf("%lld",&N);
	printf("%lld=",N);
	int cnt = 0;
	for(int i = 0; i < num; i++){
		bool flag = false;
		int temp = prime[i];
		while(1){
			if(N%temp == 0){
				flag = true;
				fac[cnt].x = temp;
				fac[cnt].exp++;
				N /= temp;
			}else{
				break;
			}
		}
		if(flag){
			cnt++;
		}
		
	}
	if(cnt == 0){
		printf("%d",N);
	}
	for(int i = 0; i <cnt;i++){
		printf("%d",fac[i].x);
		if(fac[i].exp != 1){
			printf("^%d",fac[i].exp);
		}
		if(i < cnt - 1){
			printf("*");
		}else{
			printf("\n");
		}
	}
	return 0;
} 


