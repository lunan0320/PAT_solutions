#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 101;

int N;

int arr1[maxn];
int arr2[maxn];

int temp[maxn];

bool isSame(int a[],int b[]){

	for(int i = 0;i < N;i++){
		if(a[i] != b[i]){
			return false;
		}
	} 
	return true;
}


bool insertSort(){
	
	int now = 1; //temp中元素的个数 
	temp[0] = arr1[0];
	bool flag = false;
	for(int i = 1; i < N; i++){
		if(isSame(arr2,temp)){
			flag = true;
		}
		int j = i - 1;
		for(;j >= 0; j--){
			if(temp[j] > arr1[i]){
				temp[j+1] = temp[j];
			}else{
				break;
			}
		}
		temp[j + 1] = arr1[i]; 
		if(flag){
			return true;
		}
	}
	return false;
}


void Merge(int A[],int L[],int len1, int R[], int len2){

	int i = 0, j = 0,k = 0;
	while(i < len1 && j < len2){
		if(L[i] < R[j]){
			A[k++] = L[i++];
		}else{
			A[k++] = R[j++];
		}
	}
	while( i < len1){
		A[k++] = L[i++];
	}
	while( j  < len2){
		A[k++] = R[j++];
	}
	
}

void MergeSort(int a[],int n){
	if (n < 2) return;
	int mid = n /2;
	
	int L[mid];
	for(int i = 0; i < mid; i++){
		L[i] = a[i]; 
	}
	int R[n-mid];
	for(int i = 0; i < n-mid;i++){
		R[i] = a[i + mid ];
	}
	MergeSort(L,mid);
	MergeSort(R,n-mid);
	Merge(a,L,mid,R,n-mid);
}

void mergesort(){
	bool flag = false;
	for(int step = 2; step/2 <=N;step*=2){
		if(step!= 2 && isSame(temp,arr2)){
			flag = true;
		}
		for(int i = 0; i < N; i+=step){
			sort(temp+i,temp+min(i+step,N));
		}
		if(flag){
			break;
		}
	}
}

int main(){
	scanf("%d",&N);
	for(int i = 0;i < N; i++){
		scanf("%d",&arr1[i]);
	}
	for(int i = 0; i < N; i++){
		scanf("%d",&arr2[i]);
	}
	
	

	for(int i = 0; i < N; i++){
		temp[i] = arr1[i];
	}

	if(insertSort()){
		printf("Insertion Sort\n");
		for(int i = 0; i < N; i++){
			printf("%d",temp[i]);
			if(i != N - 1){
				printf(" ");
			}
		}
	}else{
		for(int j = 0; j < N; j++){
			temp[j] = arr1[j];
		}
		printf("Merge Sort\n");
		mergesort();
		for(int i = 0; i < N; i++){
			printf("%d",temp[i]);
			if(i != N - 1){
				printf(" ");
			}
		}
		
	}
	
	return 0;
}
