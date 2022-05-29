#include <cstdio>
#include <cmath>
using namespace std;


const int maxn = 10010;

struct Node{
	int N;
	int D;
}node[maxn]; 


bool isPrime(int m){
	int q = sqrt(1.0*m);
	if(m <= 1){
		return false;
	}
	for(int i = 2;i <= q;i++){
		if(m%i == 0){
			return false;
		}
	}
	return true;
}



int main(){
	int n,d;
	int num = 0;
	while(1){
		scanf("%d",&n);
		if(n < 0){
			break;
		}
		scanf("%d",&d);
		node[num].N = n;
		node[num++].D = d;
	}
	int arr[maxn];
	for(int i = 0; i < num; i++){
		int len = 0;
		if(isPrime(node[i].N)){
			do{
				arr[len++] = node[i].N % node[i].D;
				node[i].N /= node[i].D;	
			}while(node[i].N != 0);
			for(int j= 0; j < len;j++){
				node[i].N = node[i].N * node[i].D + arr[j];
			}
			if(isPrime(node[i].N)){
				printf("Yes\n"); 
			}else{
				printf("No\n");
			}
		}else{
			printf("No\n");
		}
	}
	return 0;
}
