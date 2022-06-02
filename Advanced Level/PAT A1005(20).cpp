#include <cstdio>
#include <cstring>
using namespace std;

char words[10][6]={
"zero","one","two","three","four","five","six","seven","eight","nine"
};

char arr[101];

int main(){
	scanf("%s",arr);
	int len = strlen(arr);
	int res = 0;
	for(int i = 0; i < len; i++){
		res += arr[i] - '0';
	}
	int ans[len];
	int k = 0;
	while(res > 0){
		ans[k++] = res % 10;
		res /= 10;
	}
	for(int i = k-1; i >=0; i--){
		int c = ans[i];
		printf("%s",words[c]);
		if(i > 0){
			printf(" ");
		}else{
			printf("\n");
		}
	}
	return 0;
}
