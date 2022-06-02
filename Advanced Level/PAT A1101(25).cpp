#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>res;

const int maxn = 100010;
const int INF = 10000000000;
int N;

int arr[maxn];


int left[maxn];   //��¼i��������� 
int right[maxn]; //��¼i �ұ���С���� 

int ans[maxn],num = 0;

int main(){
	scanf("%d",&N);
	for(int i = 0; i < N; i++){
		scanf("%d",&arr[i]);
	}
	//0�����������0 
	left[0] = 0;
	for(int i = 1; i < N; i++){
		left[i] = max(left[i-1],arr[i-1]);
	}

	//���һ��Ԫ���ұ���С������ΪINF 
	right[N-1] = INF;
	for(int i = N - 2; i >= 0; i--){
		right[i] = min(right[i+1],arr[i+1]);
 	}

 	for(int i = 0; i < N; i++){
 		if(arr[i] > left[i] && arr[i] < right[i]){
 		//	res.push_back(arr[i]);
 			ans[num++] = arr[i];
		 }
	 }
	 sort(res.begin(),res.end());
	 printf("%d\n",num);
	 for(int i = 0;i < num;i++){
	 	printf("%d",ans[i]);
	 	if(i<num- 1){
	 		printf(" ");
		 }
	 }
	 printf("\n");
	return 0;
}



//
//
//int main(){
//	scanf("%d",&N);
//	for(int i = 0; i < N; i++){
//		scanf("%d",&arr[i]);
//	}
//	for(int i = 0; i < N; i++){
//		arr2[i] = arr[i];
//	}
//	
//	sort(arr2,arr2+N);
//	for(int i = 0; i < N;i++){
//		if(arr[i] == arr2[i]){
//			res.push_back(arr[i]);
//		}
//	}
//	
//	int size = res.size();
//	sort(res.begin(),res.end());
//	printf("%d\n",size);
//	for(int i = 0; i < size;i++){
//		printf("%d",res[i]);
//		if(i!=size-1){
//			printf(" ");
//		}else{
//			printf("\n");
//		}
//	} 
//	return 0;
//}
//

