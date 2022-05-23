#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int N, K, P;
int bestSum = -1;
vector<int> fac, ans ,temp;


void init(){
//	for(int i = 0; i < N; i ++){
//		int temp = pow(i,P);
//		if(temp <= N){
//			fac.push_back(temp);
//		}else{
//			return;
//		}
//	}
	int i = 0,temp = 0;
	while(temp <= N){
		fac.push_back(temp);
		temp = pow(++i,P);
	}
}

//index��ʾ��ǰ�ĵ�����nowK��ʾѡ�˼�����sum��ʾ�ݴκͣ�facSum��ʾ���Ӻ� 
void  DFS(int index,int nowK,int sum,int facSum){
	if(nowK == K && sum == N){
		if(facSum > bestSum){
			ans = temp;
			bestSum=facSum;
		}
		return;
	} 
	//��������� 
	if(sum > N || nowK > K) {
		return;
	} 
	//�ݹ�
	if(index > 0){ //fac[0]��0 
		temp.push_back(index);
		DFS(index,nowK+1,sum+fac[index],facSum+index);
		temp.pop_back();
		DFS(index-1,nowK,sum,facSum);
	} 
} 

int main(){
	scanf("%d %d %d",&N, &K, &P);
	init();
	//�����һ����ʼdfs 
	DFS(fac.size() - 1,0,0,0);
	if(bestSum == -1){
		printf("Impossible\n");
	}else{
		printf("%d = %d^%d",N,ans[0],P);
		for(int i = 1; i < ans.size(); i++){
			printf(" + %d^%d",ans[i],P);
		}
	}
	return 0;
}
