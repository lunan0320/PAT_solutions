#include <cstdio>
#include <algorithm>

using namespace std;
 
const int maxn = 1000;
const int INF = 1000000;

//顶点数和边数 
int N, M;

//集合S是表示已经访问过的结点 
int G[maxn][maxn];
int d[maxn]; //d[]记录的是顶点到集合S中的最小距离 
bool visit[maxn] = {false}; //记录这个点是否在集合S中 
int ans = 0;

int prim(){ //默认从0开始 
	fill(d,d+maxn,INF);
	d[0] = 0;
	//有多少个顶点就执行多少次 
	for(int i = 0; i < N; i++){
		//在未访问的集合中，找一个距离集合S距离最近的 
		int u = -1, MIN = INF;
		for(int j = 0; j < N; j++){
			if(!visit[j] && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		//如果找不到，表示都访问结束
		if(u==-1){
			return -1;
		} 
		//如果找到之后，就将该结点加入S并优化更新
		visit[u] = true;
		ans += d[u];
		for(int j = 0; j < N; j++){
			//此时u已经在S中，只要u到j的距离更小，那就说明j到集合S的距离更小 
			if(!visit[j] && G[u][j] != INF && G[u][j] < d[j]){
				d[j] = G[u][j];
			}
		} 
	}
	return  ans;
	
}
 
int main(){
	
	fill(G[0],G[0] + maxn * maxn, INF);
	scanf("%d%d", &N, &M);
	int c1,c2,w;
	for(int i = 0; i < M; i++){
		scanf("%d%d%d",&c1, &c2, &w);
		G[c1][c2] = w;
		G[c2][c1] = w; 
	}
	int res = prim();
	printf("最小生成树的最短访问距离：%d\n",res);
	
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
