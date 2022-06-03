#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> temp_vec,square,res;

int bestSum = -1;

int N, K, P;


void init(){
	int temp = 0;
	while(temp <= N){
		square.push_back(temp);
		temp = pow(++i,P);
	} 
}


void DFS(int index,int nowK,int sumTotal,int facSum){
	if(sumTotal > N){
		return;
	}
	if(nowK > K){
		return ;
	}
	if(nowK == K && sumTotal == N){
		if(facSum > bestSum){
			res = temp_vec;
			bestSum = facSum;
			return ;	
		}

	}
	if(index > 0){
		
		//加入这个元素 
		temp_vec.push_back(index);
		DFS(index ,nowK+1,sumTotal + square[index],facSum + index);
		temp_vec.pop_back();
		//不加入这个元素
		DFS(index-1,nowK, sumTotal,index); 
	}

}

int main(){
	scanf("%d%d%d",&N,&K,&P);
	init();
	
	DFS(square.size()-1,0,0,0);
	
	if(bestSum == -1){
		printf("Impossible\n");
	}else{
		printf("%d = %d^%d",N,res[0],P);
		for(int i = 1; i < res.size(); i++){
			printf(" + %d^%d",res[i],P);
		}
	}
	return 0;
}
