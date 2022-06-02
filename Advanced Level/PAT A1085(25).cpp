#include <cstdio>
#include <algorithm>

using namespace std;

int N;
double p;
const int maxn = 100001;

int arr[maxn];

int main(){
	scanf("%d%lf",&N,&p);
	for(int i = 0; i < N; i++){
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+N);
	int min_index = 0;
	int max_index = N - 1;
	int res = 1;
	
	for(int i = 0; i < N;i++){
		int j = upper_bound(arr + i + 1,arr + N,(long long)arr[i] * p) - arr;
		res = max(res,j - i);
	}

	printf("%d\n",res);
	return 0;
}
