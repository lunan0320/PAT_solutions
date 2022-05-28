#include <cstdio>



const int maxn = 10010;

int K;
int G[maxn];

//表示以第i个为终点的最大子序列和 
int d[maxn];

int main(){
	scanf("%d",&K);
	int neg_num = 0;
	for(int i = 0; i< K; i++){
		scanf("%d",&G[i]);
		if(G[i] < 0){
			neg_num++;
		}
	}
	if(neg_num == K){
		printf("0 %d %d",G[0],G[K-1]);
		return 0;
	}
	
	d[0] = G[0];
	
	for(int i = 1; i < K;i++){
		if(d[i-1]  > 0){
			d[i] = d[i-1] + G[i];
		}else{
			d[i] = G[i];
		}
	}
	int max = -1000000, st,ed;

	int st_id,ed_id;
	
	for(int i= 0; i < K;i++){
		if(d[i] > max){
			ed = G[i];
			ed_id = i;
			max = d[i];
		}
	}
	int temp_max = max;
	for(int i = ed_id; i>=0;i--){
		temp_max -=G[i];
		if(temp_max == 0){
			st = G[i];
			break;
		}
	}
	printf("%d %d %d",max,st,ed);
	return 0;
}
