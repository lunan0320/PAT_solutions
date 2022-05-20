#include <cstdio>
#include <set>
#include <iterator>
using namespace std;

int N = 0;

int main(){
	scanf("%d",&N);
	set<int> data[N];
	int num = 0; //ÿ��set��Ԫ���� 
	int elem = 0;//ÿ��Ԫ�� 
	for(int i = 0; i < N; i++){
		scanf("%d",&num);
		for(int j = 0; j < num; j++){
			scanf("%d",&elem);
			data[i].insert(elem);
		} 
	}
	//��ѯ
	int query = 0;
	scanf("%d",&query);
	int p = 0, q = 0; //Ҫ��ѯ�ļ��� 
	set<int>* qSet = NULL;
	set<int>* pSet = NULL; 
	while(query > 0){
		scanf("%d %d",&p,&q);
		pSet = &data[p-1];
		qSet = &data[q-1];
		set<int>::iterator it = qSet->begin();
		int count = 0;
		for(;it!= qSet->end();it++){
			if(pSet->count(*it) == 1){
				count ++;
			}
		}
		printf("%.1f\%\n",(float)count*100/(qSet->size()+pSet->size()-count));
		query--;
	} 
	return 0;	
}
