#include <cstdio>
#include <set>
#include <iterator>
using namespace std;

int N = 0;

int main(){
	scanf("%d",&N);
	set<int> data[N];
	int num = 0; //每个set的元素数 
	int elem = 0;//每个元素 
	for(int i = 0; i < N; i++){
		scanf("%d",&num);
		for(int j = 0; j < num; j++){
			scanf("%d",&elem);
			data[i].insert(elem);
		} 
	}
	//查询
	int query = 0;
	scanf("%d",&query);
	int p = 0, q = 0; //要查询的集合 
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
