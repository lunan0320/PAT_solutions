#include<cstdio>
#include <map>
#include <string>
#include <iostream>

using namespace std;

int N = 0, K = 0;
const int maxn = 2100;

int G[maxn][maxn] = {0},Weight[maxn] = {0};
int numPerson;

map<string,int> string2int;
map<int,string> int2string;
map<string,int> Gang;
bool visit[maxn] = {false};

int str2int(string str){
	if(string2int.find(str) != string2int.end()){
		return string2int[str];
	}else{
		numPerson++;
		string2int[str] = numPerson;
		int2string[numPerson] = str;
		return numPerson;
	}
}

void DFS(int nowVis,int& head, int& totalNum, int& totalWeight){
	totalNum++;
	visit[nowVis] = true;
	if(Weight[head] < Weight[nowVis]){
		head = nowVis;
	}
	for(int i = 1; i <= numPerson; i++){
		if(G[nowVis][i] > 0){
			
			totalWeight += G[nowVis][i];
			G[nowVis][i] = G[i][nowVis] = 0;
			if(!visit[i]){
				DFS(i,head,totalNum,totalWeight);
			}
			
		}
	}
}

void DFS_Traverse(){
	for(int i = 1; i <= numPerson; i++){
		if(!visit[i]){
			int head = i, totalNum = 0, totalWeight = 0;

			DFS(i,head,totalNum,totalWeight);
			if(totalNum > 2 && totalWeight > K){
				Gang[int2string[head]] = totalNum;
			}
		}
	}
}
int main(){
	scanf("%d%d", &N, &K);
	string str1, str2;
	int id1,id2;
	int w;
	for(int i =  0; i < N; i++){
		cin >> str1 >> str2 >> w;
		id1 = str2int(str1);
		id2 = str2int(str2);
		G[id1][id2] += w;
		G[id2][id1] += w;
		Weight[id1] += w;
		Weight[id2] += w;
	} 
	DFS_Traverse();
	cout << Gang.size() << endl;
	map<string,int>::iterator it = Gang.begin();
	for(it;it!=Gang.end();it++){
		cout << it->first << " " << it->second << endl; 
	} 
	
	return 0;
}

 
