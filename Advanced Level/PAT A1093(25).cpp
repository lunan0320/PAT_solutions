#include <cstdio>
#include <cstring>

using namespace std;


const int maxn = 100001;
const int MOD = 1000000007;
char arr[maxn];

int main(){
	scanf("%s",arr);
	int len = strlen(arr);
	int leftP[len] = {0};  //记录i左边的P的个数 
	if(arr[0] == 'P'){
		leftP[0] = 1;
	} 
	for(int i = 1; i < len; i++){
		if(arr[i] == 'P'){
			leftP[i] = leftP[i-1] + 1;
		}else{
			leftP[i] = leftP[i-1];
		}
	}

	int rightT[len] = {0}; //记录i右边的T的个数
	if(arr[len-1] == 'T'){
		rightT[len-1] = 1;
	}
	for(int j = len - 2;j >= 0; j--){
		if(arr[j] == 'T'){
			rightT[j] = rightT[j+1] +1;
		}else{
			rightT[j] = rightT[j+1];
		}
	} 
	
	//统计所有的
	int res = 0;
	for(int i = 0; i < len; i++){
		if(arr[i] == 'A'){
			res = (res + leftP[i] * rightT[i]) % MOD;
		}
	} 
	printf("%d\n",res);
	return 0;
} 



//暴力枚举 
//int main(){
//	scanf("%s",arr);
//	int len = strlen(arr);
//
//	int count = 0;
//	for(int p = 0; p < len - 2;p++){
//		if(arr[p] == 'P'){
//			for(int a = p + 1; a < len - 1; a++){	
//				if(arr[a] == 'A'){
//					for(int t = a+1; t < len; t++){
//						if(arr[t] == 'T'){
//							
//							count++;
//							count = count % 1000000007;
//						}
//					}
//				}
//			}
//		}
//	}
//	printf("%d\n",count);
//	
//	return 0;
//}
