#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 200001;
const int INF  = 0x7ffffffff;
int N1,N2;

int arr1[maxn];
int arr2[maxn];

int main(){
	scanf("%d",&N1);
	for(int i = 0; i < N1; i++){
		scanf("%d",&arr1[i]);
	}
	scanf("%d",&N2);
	for(int i = 0; i < N2; i++){
		scanf("%d",&arr2[i]);
	}
	arr1[N1] = arr2[N2] = INF; 
	int mid = (N1 + N2 - 1) / 2;
	
	int i = 0, j = 0;
	for(int count = 0; count < mid; count++){
		if(arr1[i] < arr2[j]){
			i++;
		}else{
			j++;
		}
	}
	if(arr1[i] < arr2[j]){
		printf("%d\n",arr1[i]);
	} else{
		printf("%d\n",arr2[j]);
	}
	return 0;
}
