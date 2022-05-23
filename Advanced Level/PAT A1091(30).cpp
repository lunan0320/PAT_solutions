#include <cstdio>
#include <queue>

using namespace std;

int N,M,L,T;

int X[6] = {0,0,0,0,1,-1};
int Y[6] = {0,0,1,-1,0,0};
int Z[6] = {1,-1,0,0,0,0};

int pixels[1290][130][61];
int inque[1290][130][61] = {false};

struct node{
	int x;
	int y;
	int z;
}Node;

bool judge(int x, int y,int z){
	if(x >= N || x < 0 || y >= M || y < 0 || z >= L || z < 0){
		return false;
	}
	if(pixels[x][y][z] == 0 || inque[x][y][z]){
		return false;
	}
	return true;
}

int BFS(int x,int y,int z){
	Node.x = x;
	Node.y = y;
	Node.z = z;
	queue<node> q;
	q.push(Node);
	inque[x][y][z] = true;
	int tmp_res = 0;
	while(!q.empty()){
		node front = q.front();
		q.pop();
		tmp_res++;
		for(int i = 0; i < 6; i++){
			int new_x = front.x + X[i];
			int new_y = front.y + Y[i];
			int new_z = front.z + Z[i];
			if(judge(new_x,new_y,new_z)){
				Node.x = new_x;
				Node.y = new_y;
				Node.z = new_z;
				inque[new_x][new_y][new_z] = true;
				q.push(Node);
			}
		} 
	}
	if(tmp_res >= T){
		return tmp_res;
	}else{
		return 0;
	}
}

int main(){
	scanf("%d%d%d%d",&N,&M,&L,&T);
	for(int z = 0; z < L;z++){
		for(int x = 0; x < N; x++){
			for(int y = 0; y < M; y++){
				scanf("%d",&pixels[x][y][z]);
			}
		}
	}
	
	int ans = 0;
	for(int z = 0; z < L; z++){
		for(int x = 0; x < N; x++){
			for(int y = 0; y < M; y++){
				if(pixels[x][y][z] == 1 && inque[x][y][z] == false){
					ans += BFS(x,y,z);
				}
			}
		}
	}
	printf("%d",ans);
}

