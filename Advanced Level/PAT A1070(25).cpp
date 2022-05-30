#include <cstdio>
#include <algorithm>

using namespace std;


int N;
double Need;

const int maxn = 1001;

struct mooncake{
	double weight;
	double total_price;
	double pre_price; //µ¥¼Û 
}cake[maxn];



bool cmp(mooncake a,mooncake b){
	return a.pre_price > b.pre_price;
}

int main(){
	scanf("%d%lf",&N,&Need);
	for(int i = 0; i < N; i++){
		scanf("%lf",&cake[i].weight);
	} 
	for(int i = 0; i < N; i++){
		scanf("%lf",&cake[i].total_price);
		cake[i].pre_price = cake[i].total_price / cake[i].weight;
	}
	sort(cake,cake+N,cmp);

	double res = 0;
	for(int i= 0; i < N; i++){
		if(Need < cake[i].weight){
			res += cake[i].pre_price * Need;
			break;
		}else{
			Need -= cake[i].weight;
			res += cake[i].total_price;
		}
	}
	printf("%.2f\n",res);
	
	return 0;
}
