#include <cstdio>
#include <algorithm>


using namespace std;


const int maxn = 1000;
const int INF = 1000000;

int dis[maxn][maxn];
int n, m;  //¶¥µãÊý£¬±ßÊý

 
void Floyd(){
	for(int k =0; k< n; k++){
		for(int i = 0;i < n; i++){
			for(int j = 0; j <n ;j++){
				if(dis[i][k]!=INF && dis[k][j]!=INF && dis[i][k] + dis[k][j] < dis[i][j]){
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}
}

int main(){
	scanf("%d%d",&n, &m);
	fill(dis[0],dis[0]+maxn*maxn,INF);
	for(int i =0 ; i < n; i++){
		dis[i][i] =0;
	}
	int c1,c2,temp;
	for(int i = 0; i < m; i++){
		scanf("%d%d%d",&c1,&c2,&temp);
		dis[c1][c2] = temp;
	}
	Floyd();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%d ",dis[i][j]); 
		}
		printf("\n");
	}
	return 0;
} 

/*

6 8
0 1 1
0 3 4
0 4 4
1 3 2
2 5 1
3 2 2
3 4 3
4 5 3
*/
