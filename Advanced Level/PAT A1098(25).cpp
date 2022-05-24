#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


/*模拟插入排序和堆排序 
与给定的序列比较 

*/

//输入数组，备份数组，目标数组 
vector<int> orign, bar,object;
int N;

//模拟插入排序的过程，此时返回true表示找到了一个插入排序的示例 
bool insertSort() {
	//从2个数开始遍历排序 
	for(int i = 2; i < N; i++){
		sort(bar.begin(),bar.begin() + i);
		if(bar == object){
			//说明目标数组是从begin 到 begin + i 
			sort(bar.begin(),bar.begin() + i +1);
			return true;
		}
	}
	return false;
}


//模拟堆排序的调整过程
//小顶堆 
void downAdjust(int low,int high){
	int i = low;	//待调整的结点 
	int j = low * 2 + 1; //左孩子(因为这里root是从0开始，因此左孩子是low * 2 +1 右孩子是low * 2 + 2)
	//只要满足条件 就不断向下调整	 
	while(j <= high){
		//右结点存在，且 右孩子更大 ,则使用右孩子 
		if(j + 1 <= high && bar[j] < bar[j + 1]){
			j = j + 1;
		}
		//如果父亲结点小于子节点中的较大值 ,则交换，并更新i、j 
		if(bar[j] > bar[i]){
			swap(bar[j],bar[i]); 
			i = j;
			j = 2 * i + 1;
		}else{
			//孩子结点的权值都比父亲结点小，则结束 
			return;
		}
	}
} 

void heapSort(){
	//建堆的过程 (从非叶子结点开始建堆，叶子结点没子节点不用向下)
	for(int i = N/2 - 1; i >= 0; i--){
		downAdjust(i,N - 1);
	}
	bool flag = false;
	//步骤二的每步更新，从最后一个堆元素开始 
	for(int i = N - 1; i > 0;i--){
		//交换堆顶和第i个 
		swap(bar[i],bar[0]);
		//此时第i个已经确定，继续调整0到i-1 
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
	//复制一份原始数组 
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
