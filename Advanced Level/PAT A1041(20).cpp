#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int bets[10010] = {0};

int main()
{
	int N;
	scanf("%d",&N);
	int a;
	int arr[100010];
	for(int i = 0; i < N; i++){
		scanf("%d",&a);
		arr[i] = a;
		bets[a]++;
	}
	bool flag  = false;
	for(int i = 0; i < N; i++){
		int b = arr[i];
		if(bets[b] == 1){
			flag = true;
			printf("%d\n",b);
			break;
		}
	}
	if(!flag){
		printf("None\n");
	}
	return 0;
}
 

