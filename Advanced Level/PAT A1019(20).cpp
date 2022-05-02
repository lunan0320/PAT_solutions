#include <cstdio>

int N, b;
int z[50];
int length = 0;
//����ת�� ��bȡ�� 
void trans2b(){	
	while(N){
		z[length++] = N % b;
		N = N / b;
	}
}

//�ж��ǲ��ǻ����� 
bool judgePnumber(){
	for(int i = 0; i < length / 2; i++){
		if(z[i] != z[length - i -1]){
			return false;
		}
	}
	return true;
}


int main(){
	scanf("%d %d", &N, &b);
	trans2b();
	bool res = judgePnumber();
	if(res){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	for(int i = length - 1; i >= 0; i--){
		if(i == 0){
			printf("%d",z[i]);
		}else{
			printf("%d ",z[i]);
		}
	}
}

/*
����������
27 2
Ԥ�������
Yes
1 1 0 1 1

����������
121 5
Ԥ�������
No
4 4 1
 
*/
