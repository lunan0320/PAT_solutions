#include <cstdio>

const int maxn = 3;

double W[maxn];
double T[maxn];
double L[maxn];
double sum = 1.0;

double findMax(int m){
	double temp = W[m];
	if(temp >= T[m]){
		if(temp >= L[m]){
			printf("W ");
			return temp;
		}else{
			printf("T ");
			return T[m];
		}
	}else{
		if(T[m] > L[m]){
			printf("T ");
			return T[m];
		}else{
			printf("L ");
			return L[m];
		}
	}
}

int main(){
	for(int i = 0; i < maxn; i++){
		scanf("%lf%lf%lf", &W[i], &T[i], &L[i]);
		printf("%lf %lf %lf \n",W[i], T[i], L[i]);
	}
	for(int i = 0; i < maxn; i++){
		sum *= findMax(i);
	}
	sum = (sum*0.65 - 1) * 2;
	printf(" %.2f",sum);
	return 0;
} 


/*
²âÊÔÑùÀı£º
1.1 2.5 1.7
1.2 3.1 1.6
4.1 1.2 1.1

Ô¤ÆÚÊä³ö£º
T T W 39.31
*/
