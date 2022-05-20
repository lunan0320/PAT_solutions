#include <cstdio>
#include <set>
#include <map>
#include <iterator>
#include <iostream>
using namespace std;
#define K 6
int N = 0;

//map数组，每个元素对应了1-6的一类，每个元素也是一个map 
map<string,set<int> > m[K];

int main(){
	scanf("%d", &N);
	string temp_str;
	int id;
	//输入信息 
	for(int user = 0; user < N; user++){
		scanf("%d\n",&id);
		for(int i = 1;i < K; i++){	
			if(i == 3){
				while(cin >> temp_str){
					m[i][temp_str].insert(id);
					//遇到keywords终止 
					if(getchar() == '\n'){
						break;
					}
				}
			}else{
				getline(cin,temp_str);
				m[i][temp_str].insert(id);
			}
		}
	}
	int num;
	scanf("%d",&num);
	int query_class = 0;
	string str;
	for(int i = 0; i < num;i++){
		scanf("%d: ",&query_class);
		getline(cin,str);
		cout << query_class << ": "<<str<<endl;
		map<string,set<int> > &temp_map = m[query_class];
		//找到这set 
		if(temp_map.find(str)!=temp_map.end()){
			set<int>::iterator it = temp_map[str].begin();
			for(;it!=temp_map[str].end();it++){
				printf("%07d\n",*it);
			}
		}else{
			printf("Not Found\n");
		}
	} 
	return 0;
}

/*
测试样例
3
1111111
The Testing Book
Yue Chen
test code debug sort keywords
ZUCS Print
2011
3333333
Another Testing  
Yue Chen
test code sort keywords
ZUCS Print2
2012
2222222
The Testing Book
CYLL
keywords debug book
ZUCS Print2
2011
6
1: The Testing Book
2: Yue Chen
3: keywords
4: ZUCS Print
5: 2011
3: blablabla
 

*/
