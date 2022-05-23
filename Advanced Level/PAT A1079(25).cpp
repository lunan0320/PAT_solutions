#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 100010;
double ans = 0;
int N;
double p,r;

struct node {
	int data;
	vector<int>child;
}Node[maxn];

//����index����Լ���ǰ���depth 
void DFS(int index, int depth){
	if(Node[index].child.size() == 0){
		ans += Node[index].data * pow(1+r,depth);
		return ;
	}
	//����ÿ������ 
	for(int i = 0; i < Node[index].child.size();i++){
		//���Ҫ+1 
		DFS(Node[index].child[i],depth+1);
	}
}

int main(){
	scanf("%d %lf %lf",&N,&p,&r);
	int child_size,child;
	r = r/100;
	//�������� 
	for(int i = 0; i < N; i++){
		scanf("%d",&child_size);
		if(!child_size){
			scanf("%d",&Node[i].data);  
		}else{
			for(int j = 0; j < child_size; j++){
				scanf("%d",&child);
				Node[i].child.push_back(child);
			}
		}
	}
	//��root��ʼ��root�ǵ�0�� 
	DFS(0,0); 
	printf("%.1lf",p*ans);
	return 0;
} 
