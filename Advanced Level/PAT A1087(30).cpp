#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

const int maxn = 201;
const int INF = 100000000;


int N, K;

string start;
int start_id = 0;

string end = "ROM";
int end_id ;
	
int num_path = 0;

map<string,int> citys;
map<int,string> index2str;

vector<int>pre[maxn];

int G[maxn][maxn];
int happys[maxn];

//是否访问 
bool visit[maxn] = {false};

//最短路径
int d[maxn]; 


vector<int>temp_path;
vector<int>res_path;
 
 
double res_avg; 

int max_happy ;


void Dijkstra(int start_id){
	fill(d,d+maxn,INF);
	//初始化 
	d[start_id] = 0;
	//枚举每个结点 
	for(int i = 0; i < N; i++){
		int u = -1, min = INF;
		for(int j = 0; j < N; j++){
			if(!visit[j] && d[j] < min){
				min = d[j];
				u = j;
			}
		}
		//没有找到 
		if(u == -1){
			return;
		}
		//找到这样的u
		visit[u] = true;
		//更新 
		for(int j = 0; j < N; j++){
			if(!visit[j] && G[u][j] > 0){
				if(d[u] + G[u][j] < d[j]){
					d[j] = d[u] + G[u][j];
					pre[j].clear();
					pre[j].push_back(u);
				}else if(d[u] + G[u][j] == d[j]){
					pre[j].push_back(u);
				}
			}
		} 
	}
}


void DFS(int v){
	//递归边界 
	if(v == start_id){
		num_path ++;
		temp_path.push_back(v);
		int temp_happy = 0;
		
		for(int i = 0; i < temp_path.size() ; i++){
			int id = temp_path[i];
			temp_happy += happys[id];
		}
//		for(int i = temp_path.size() - 2; i>=0;i--){
//			int id = temp_path[i];
//			temp_happy += happys[id];
//		}
		double temp_avg = 1.0 * temp_happy /(temp_path.size() - 1);
		if(temp_happy > max_happy){
			max_happy = temp_happy;
			res_path = temp_path;
			res_avg = temp_avg;
		}else if (temp_happy == max_happy && temp_avg > res_avg){
			res_avg = temp_avg;
			res_path = temp_path;
		}
		temp_path.pop_back();
		return;
	}
	temp_path.push_back(v);
	for(int i = 0;i < pre[v].size(); i++){
		DFS(pre[v][i]);
	}
	temp_path.pop_back();
}

int main(){
	cin >> N >> K >> start;
	citys[start] = 0;
	index2str[0] = start; 
	
	string c;
	int happy;
	for(int i = 1; i < N; i++){
		cin >> c >> happy;
		citys[c] = i;
		happys[i] = happy;
		index2str[i] = c;
	}
	fill(G[0],G[0]+maxn*maxn,INF);
	string c1,c2;
	int id1,id2,len;
	for(int i = 0; i < K;i++){
		cin >> c1 >> c2 >> len;
		id1 = citys[c1];
		id2 = citys[c2];
		G[id1][id2] = len;
		G[id2][id1] = len;
	}
	
	Dijkstra(0);
	
	DFS(citys["ROM"]);
	
	printf("%d %d %d %d\n",num_path,d[citys["ROM"]],max_happy,(int)res_avg);
	for(int i = res_path.size() - 1; i >=0; i--){
		cout << index2str[res_path[i]];
		if(i > 0){
			printf("->");
		}
	}
	return 0;
}
