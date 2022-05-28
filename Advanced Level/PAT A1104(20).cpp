#include <cstdio>
#include <iostream>
using namespace std;
int N;

int main(){
	scanf("%d",&N);

	long long ans = 0;
	double v ;
	for(int i = 1;i <= N;i++){
		cin >> v;
		int size = N + 1- i;
		ans += (long long)(v * 1000) * i *(size);
	}
	printf("%.2f",ans/1000.0);
	return 0;
}
