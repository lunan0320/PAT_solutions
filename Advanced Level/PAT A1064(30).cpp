#include <cstdio>
#include <algorithm>

using namespace std;
 
const int maxn = 1010;


int N;
int number[maxn] ;
int CBT[maxn];
int index = 0;
 
void inOrder(int root){
	if(root > N){
		return;
	}
	inOrder(2 * root);
	CBT[root] = number[index++];
	inOrder(2 * root + 1);
}
int main(){
	scanf("%d",&N);
	for(int i = 0; i < N; i++){
		scanf("%d",&number[i]);
	}
	sort(number,number + N);
	inOrder(1);
	for(int i = 1; i <= N; i++){
		printf("%d",CBT[i]);
		if( i < N ){
			printf(" ");
		}else{
			printf("\n");
		}
	}
	
	return 0;
}
