#include <cstdio>
#include <map>
#include <cstring>
#include <iostream>
#include <iterator> 
using namespace std;


const int maxn = 10010;

map<string,int> str2int;
map<int,string> int2str;

//head --> ���� 
map<string,int> Gang;

int N, K;

//��Ȩ 
int weight[maxn];

//���ӵı� 
int G[maxn][maxn];

//�Ƿ���ʹ�
bool visit[maxn] = {false}; 

//������ 
int numPerson = 0;

int change(string str){
	if(str2int.find(str) != str2int.end()){
		return str2int[str];
	}else{
		str2int[str] = numPerson;
		int2str[numPerson] = str;
		return numPerson++;
	}
}

void DFS(int index,int& head,int& numGang,int& totalValue){
	//����ͷĿ 
	if(weight[head] < weight[index]){
		head = index;
	} 
	numGang++;
	visit[index] = true;
	
	for(int i = 0; i < numPerson;i++){
		//�б� 
		if(G[index][i] > 0){
			totalValue += G[index][i];
			//�ۼӺ�ɾ�������� 
			G[index][i] = G[i][index] = 0;	
			//�����i����û�з��� 
			if(!visit[i]){
				DFS(i,head,numGang,totalValue);
			}
		}
	}
}
void DFSTravel(){
	//����ÿһ����� 
	for(int i = 0; i < N; i++){
		if(!visit[i]){
			int head = i;
			int numGang = 0;
			int totalValue = 0;
			DFS(i,head,numGang,totalValue);		
			//�ж��Ƿ���������	
			if(numGang > 2 && totalValue > K){
				Gang[int2str[head]] = numGang;
			}
		}
	}
}

int main(){
	scanf("%d%d",&N,&K);
	string str1, str2;
	int time;
	for(int i = 0; i < N; i++){
		cin >> str1 >> str2 >> time;
		 int id1 = change(str1);
		 int id2 = change(str2);
		 //��Ȩ 
		 weight[id1] += time;
		 weight[id2] += time;
		 //��Ȩ 
		 G[id1][id2] += time;
		 G[id2][id1] += time; 
	}
	
	DFSTravel();
	cout << Gang.size() << endl;
	map<string,int>::iterator it = Gang.begin();
	while(it != Gang.end()){
		cout << it->first <<" " << it->second << endl;
		it++;
	}
 	return 0;
} 

