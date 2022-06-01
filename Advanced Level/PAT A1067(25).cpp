#include <cstdio>
#include <algorithm>
using namespace std;


const int maxn = 100001;

int N;

int index[maxn] = {0};




int main(){
	scanf("%d",&N);
	int a;
	int left = N-1; // 除0外不在本位上的数字 
	for(int i = 0; i < N; i++){
		scanf("%d",&a);
		index[a] = i;
		if(a==i && a != 0){
			left--;
		}
	}
	int swap_num = 0;
	int k = 1; //除0外当前不在本位上的最小的数 

	while(left > 0){
		if(index[0] == 0){
			while(k < N){
				if(index[k] != k){
					swap(index[0],index[k]);
					swap_num++;
					break;
				}
				k++;
			}
		}
		while(index[0]!=0){
			left--;
			//index[index[0]]是0所在位置的数的当前所处位置  与  此时0所在的位置交换 
			swap(index[0],index[index[0]]);
			swap_num++;
		}	
	}
	
	printf("%d\n",swap_num);
	
	return 0;
}
 
