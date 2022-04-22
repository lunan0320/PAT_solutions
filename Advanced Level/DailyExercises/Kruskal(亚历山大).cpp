#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1000;
const int INF = 1000000;

struct edge{
	int u,v;
	int cost;
}Edge[maxn]; 

//顶点数和边数 
int N, M; 
int ans = 0; //最小生成树的边权之和 

//并查集数组 
int father[maxn]; 

//重写比较函数 ，用于排序 
bool cmp(edge a, edge b){
	return a.cost < b.cost;
}

//并查集部分
int findFather(int x){
	int a = x;
	//此处找到了根节点x 
	while(x != father[x]){
		x = father[x];
	}
	//此处是路径压缩的过程 
	//将路径上的点的根节点都设置为x，方便后序查询 
	while(a != father[a]){
		  int z = a;
		  a = father[a];
		  father[z] = x;
	}
	return x;
} 

int kruskal(){
	//对边权从小到大排序 
	sort(Edge,Edge+M,cmp);
	//并查集的初始化 
	for(int i = 0; i < maxn; i++){
		father[i] = i;
	}
	int num = 0; //num表示此时在最小生成树中的边的数量 
	for(int i = 0; i < M; i++){
		int faU = findFather(Edge[i].u);
		int faV = findFather(Edge[i].v);
		int cost = Edge[i].cost;
		//如果这两个不在同一个连通块，就连通 
		if(faU != faV){
			//合并两个集合 
			father[faU] = faV;
			//此边加入到最小生成树中 
			ans += Edge[i].cost;
			num++;
			if(num ==N-1){
				return ans;
			} 
		}
	}
	//表示没有构成连通的  边数不满足顶点数-1 
	if(num != N-1){
		return -1;
	}
	return ans; 
}

int main(){
	scanf("%d%d",&N, &M);
	int c1,c2,w;
	for(int i = 0; i < M; i++){
		scanf("%d%d%d",&c1, &c2, &w);
		Edge[i].u = c1;
		Edge[i].v = c2;
		Edge[i].cost = w;
	}
	int res = kruskal();
	printf("最小生成树的边权为：%d\n", res); 
	
	return 0;
} 


 /*
 测试样例 
 6 10
0 1 4
0 4 1
0 5 2
1 2 6
1 5 3
2 3 6
2 5 5
3 4 4
3 5 5
4 5 3 
 */
