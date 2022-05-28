#include <cstdio>

int main(){
	int n, a = 1,ans = 0;
	scanf("%d",&n);
	int left,now,right;
	while(n/a != 0){
		left = n/(a*10);
		now = n/a %10;
		right = n%a;
		if(now == 0){
			ans += left * a;
		}else if(now == 1){
			ans += left * a + right +1;
		}else{
			ans += (left + 1) * a;
		}
		a*=10;
	}
	printf("%d",ans);
	return 0;
}
