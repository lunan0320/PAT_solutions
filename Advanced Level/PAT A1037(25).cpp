#include <cstdio>
#include <algorithm>


using namespace std;

int N1,N2;

const int maxn = 100010;

int C1[maxn],C2[maxn];

int main(){
	scanf("%d",&N1);
	for(int i = 0; i < N1;i++){
		scanf("%d",&C1[i]);
	}
	scanf("%d",&N2);
	for(int i = 0; i < N2; i++){
		scanf("%d",&C2[i]);
	}
	
	sort(C1,C1+N1);
	sort(C2,C2+N2);
	int  res = 0;
	int i = 0;
	while(i < N1 && i < N2 && C1[i] < 0 && C2[i] < 0){
		res += C1[i] * C2[i];
		i++;
	}
	i = N1 - 1;
	int j = N2 - 1;
	while(i >= 0 && j >= 0 && C1[i] > 0 && C2[j] > 0){
		res += C1[i] * C2[j];
		i--;
		j--;
	}
	printf("%d\n",res);
	return 0;
}
