#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


/*ģ���������Ͷ����� 
����������бȽ� 

*/

//�������飬�������飬Ŀ������ 
vector<int> orign, bar,object;
int N;

//ģ���������Ĺ��̣���ʱ����true��ʾ�ҵ���һ�����������ʾ�� 
bool insertSort() {
	//��2������ʼ�������� 
	for(int i = 2; i < N; i++){
		sort(bar.begin(),bar.begin() + i);
		if(bar == object){
			//˵��Ŀ�������Ǵ�begin �� begin + i 
			sort(bar.begin(),bar.begin() + i +1);
			return true;
		}
	}
	return false;
}


//ģ�������ĵ�������
//С���� 
void downAdjust(int low,int high){
	int i = low;	//�������Ľ�� 
	int j = low * 2 + 1; //����(��Ϊ����root�Ǵ�0��ʼ�����������low * 2 +1 �Һ�����low * 2 + 2)
	//ֻҪ�������� �Ͳ������µ���	 
	while(j <= high){
		//�ҽ����ڣ��� �Һ��Ӹ��� ,��ʹ���Һ��� 
		if(j + 1 <= high && bar[j] < bar[j + 1]){
			j = j + 1;
		}
		//������׽��С���ӽڵ��еĽϴ�ֵ ,�򽻻���������i��j 
		if(bar[j] > bar[i]){
			swap(bar[j],bar[i]); 
			i = j;
			j = 2 * i + 1;
		}else{
			//���ӽ���Ȩֵ���ȸ��׽��С������� 
			return;
		}
	}
} 

void heapSort(){
	//���ѵĹ��� (�ӷ�Ҷ�ӽ�㿪ʼ���ѣ�Ҷ�ӽ��û�ӽڵ㲻������)
	for(int i = N/2 - 1; i >= 0; i--){
		downAdjust(i,N - 1);
	}
	bool flag = false;
	//�������ÿ�����£������һ����Ԫ�ؿ�ʼ 
	for(int i = N - 1; i > 0;i--){
		//�����Ѷ��͵�i�� 
		swap(bar[i],bar[0]);
		//��ʱ��i���Ѿ�ȷ������������0��i-1 
		downAdjust(0,i - 1);	
		if(bar == object){
			swap(bar[--i],bar[0]);
			downAdjust(0,i-1);
			return;
		} 
	} 	
} 

int main(){
	scanf("%d",&N);
	int temp;
	for(int i = 0; i < N; i++){
		scanf("%d",&temp);
		orign.push_back(temp);
	}
	//����һ��ԭʼ���� 
	bar = orign;
	for(int i = 0; i < N; i++){
		scanf("%d",&temp);
		object.push_back(temp);
	}
	if(insertSort()){
		printf("Insertion Sort\n");
		for(int i = 0; i < N; i++){
			printf("%d",bar[i]);
			if(i < N-1){
				printf(" ");
			}
		} 
	}else{
		bar = orign;
		heapSort();
		printf("Heap Sort\n");
		for(int i = 0; i < N; i++){
			printf("%d",bar[i]);
			if(i < N-1){
				printf(" ");
			}
		} 
	}
	return 0;
} 
