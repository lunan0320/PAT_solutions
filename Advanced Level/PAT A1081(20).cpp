#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn = 101;
int N;

struct node{
	ll up;
	ll down;
};

ll gcd(ll a,ll b){
	if(b == 0){
		return a;
	}
	return gcd(b,a%b);
}
node reduction(node res){
	if(res.down < 0){
		res.down = - res.down;
		res.up = - res.up;
	}
	if(res.up == 0){
		res.down = 1;
	}else{
		int d = gcd(abs(res.up),abs(res.down));
		res.down /= d;
		res.up /= d;
	}
	return res;
}
node add(node a,node b){
	node res;
	res.down = a.down * b.down;
	res.up = a.up * b.down + a.down * b.up;
	return reduction(res);
}

void print(node res){
	reduction(res);
	if(res.down == 1){
		printf("%lld\n",res.up);
	}else{
		if(abs(res.up) > abs(res.down)){
			printf("%lld %lld/%lld",res.up/res.down,abs(res.up)%res.down,res.down );
		}else{
			printf("%lld/%lld\n",res.up,res.down);
		}
		
	}
}	
int main(){
	scanf("%d",&N);
	node sum,temp;
	sum.up = 0;
	sum.down = 1;
	for(int i = 0; i < N; i++){
		scanf("%lld/%lld",&temp.up,&temp.down);
		sum = add(sum,temp);
	}
	print(sum);
	return 0;
}
