#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

struct node{
	ll up;
	ll down;
};


node fac1,fac2;

ll gcd(ll a,ll b){
	if(b == 0){
		return a;
	}
	return gcd(b,a%b);
}


node reduction(node a){
	if(a.down < 0){
		a.down = -a.down;
		a.up = -a.up;
	}
	if(a.up == 0){
		a.down = 1;
	}else{
		int k = gcd(abs(a.up),abs(a.down));
		a.up /= k;
		a.down /= k;		
	}
	return a;
}

void show(node a){	
	a = reduction(a);
	if(a.up <0){
		printf("(");
	} 
	if(a.down == 1){
		printf("%lld",a.up);
	}else if(abs(a.up) > a.down){
		printf("%lld %lld/%lld",a.up/a.down,abs(a.up)%a.down,a.down);	
	}else{
		printf("%lld/%lld",a.up,a.down);
	}
	if(a.up < 0){
		printf(")");
	}
}

void print(node res,char c){
	if(c == '+'){
		show(fac1);
		printf(" + ");
		show(fac2);
		printf(" = ");
		show(res);
		printf("\n");
	}else if (c == '-'){
		show(fac1);
		printf(" - ");
		show(fac2);
		printf(" = ");
		show(res);
		printf("\n");
	}else if (c == '*'){
		show(fac1);
		printf(" * ");
		show(fac2);
		printf(" = ");
		show(res);
		printf("\n");
	}else if(c == '/'){
		show(fac1);
		printf(" / ");
		show(fac2);
		fac2 = reduction(fac2);
		if(fac2.down == 1 && fac2.up ==0){
			printf(" = Inf\n");
		}else{
			printf(" = ");
			show(res);
			printf("\n");
		}
		
	}
}


void add(node a,node b){
	node res;
	res.down = a.down * b.down;
	res.up = a.up * b.down + a.down * b.up;
	res = reduction(res);
	print(res,'+');

}


void dec(node a,node b){
	node res;
	res.down = a.down * b.down;
	res.up = a.up * b.down - b.up * a.down;
	res = reduction(res);
	print(res,'-');
}


void multi(node a,node b){
	node res;
	res.down = a.down * b.down;
	res.up = a.up * b.up;
	res = reduction(res);
	print(res,'*');
}

void division(node a,node b){
	node res;
	res.down = a.down * b.up;
	res.up = a.up * b.down;
	print(res,'/');
}

int main(){
	
	scanf("%lld/%lld %lld/%lld",&fac1.up,&fac1.down,&fac2.up,&fac2.down);
	add(fac1,fac2);
	dec(fac1,fac2);
	multi(fac1,fac2);
	division(fac1,fac2);
	return 0;
}
