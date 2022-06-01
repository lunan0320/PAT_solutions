#include <cstdio>
#include <algorithm>
using namespace std;


const int maxn = 100001;

int N;

int index[maxn] = {0};




int main(){
	scanf("%d",&N);
	int a;
	int left = N-1; // ��0�ⲻ�ڱ�λ�ϵ����� 
	for(int i = 0; i < N; i++){
		scanf("%d",&a);
		index[a] = i;
		if(a==i && a != 0){
			left--;
		}
	}
	int swap_num = 0;
	int k = 1; //��0�⵱ǰ���ڱ�λ�ϵ���С���� 

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
			//index[index[0]]��0����λ�õ����ĵ�ǰ����λ��  ��  ��ʱ0���ڵ�λ�ý��� 
			swap(index[0],index[index[0]]);
			swap_num++;
		}	
	}
	
	printf("%d\n",swap_num);
	
	return 0;
}
 
