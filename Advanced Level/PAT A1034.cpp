#include <cstdio>
#include <map>
#include <string>
#include <iostream>
using namespace std;

const int maxn = 2010;
const int INF = 100000000;

//定义map映射 
map<string,int> string2int;
map<int,string> int2string;
map<string,int> Gang;

//标记是否被访问
bool visit[maxn] = {false};
 
//定义数组
int G[maxn][maxn] = {0},Weight[maxn] = {0};//定义图和点权
 

int N = 0,  K = 0, numPerson = 0; //定义通话次数、阈值和总人数
 
//将string转换为int 
int changeString(string temp){
	if(string2int.find(temp) != string2int.end()){//如果该id已经出现过 
		return string2int[temp];
	}else{//如果没有出现，就新建一个映射关系 
		numPerson++;
		string2int[temp] = numPerson;
		int2string[numPerson] = temp;
		return numPerson; 
	}
}

void DFS(int nowVis, int& head,int& totalNum, int& totalWeight){
	//递归终止条件 
	if(visit[nowVis]){
		return;
	} 
	//设置当前已经访问 以及总人数+1 
	visit[nowVis] = true;
	totalNum ++;
	//判断是否需要更新head
	if(Weight[head] < Weight[nowVis]){
		head = nowVis;
	} 
	//遍历与之相关的每个结点 
	for(int i = 1; i <= numPerson; i++){
		if(G[nowVis][i] > 0){ //表示从nowVis到i结点有边 
			//更新这个Gang的总权重 
			totalWeight += G[nowVis][i];
			//记录之后删除这条边 
			G[nowVis][i] = G[i][nowVis] = 0; 
			DFS(i,head,totalNum,totalWeight);
		} 
	}
}
void DFS_Traverse(){
	//遍历所有的人 此处id是从1开始 
	for(int i = 1; i <= numPerson;i++){
		if(!visit[i]){
			int totalNum = 0, head = i, totalWeight = 0; //定义这个Gange的总人数，头目，总权重 
			DFS(i,head,totalNum,totalWeight);
			//判断是否总人数以及阈值都满足 则判定为一个Gange 
			if(totalNum > 2 && totalWeight > K){
				//将此haed --> totalNum的映射记录下来
				// 此处map自动实现了按照字母表排序 
				Gang[int2string[head]] = totalNum;
			}
		}
	}
} 


/*

测试样例：
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10 

8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10 


*/
int main(){
	string str1,str2;
	int id1, id2;
	int w;
	scanf("%d%d",&N, &K);
	//输入，以及建图，建点权 
	for (int i = 0; i < N;i++){
		cin >> str1 >> str2 >> w;
		id1 = changeString(str1);
		id2 = changeString(str2);
		G[id1][id2] += w;
		G[id2][id1] += w;
		Weight[id1] += w;
		Weight[id2] += w;
	}
	//深度递归遍历 找到每个Gang 
	DFS_Traverse();
	//输出Gang数量 
	cout << Gang.size() << endl;
	//用迭代器去遍历每个Gang的信息 
	map<string,int>::iterator it = Gang.begin();
	//依次输出 
	for(it;it!=Gang.end();it++){
		cout << it->first <<" "<< it->second << endl;
	} 
	return 0;
} 
