#include <bits/stdc++.h>

using namespace std;

const int maxM = 1290;
const int maxN = 130;
const int maxL = 61;

int X[6] = {1,-1,0,0,0,0};
int Y[6] = {0,0,1,-1,0,0};
int Z[6] = {0,0,0,0,1,-1};

int pixels[maxM][maxN][maxL];

struct Node{
	int x,y,z;
	Node(int _x,int _y,int _z){
		x = _x;
		y = _y;
		z = _z;
	}
};
int M, N, L, T;

bool isStroke(Node a){
	if(pixels[a.x][a.y][a.z] == 1){
		return true;
	}
	return false;
}

bool inque[maxM][maxN][maxL] = {false};

int BFS(int x,int y,int z){
	Node a(x,y,z);
	queue<Node> q;
	q.push(a);
	inque[x][y][z] = true;
	int ans = 0;
	while(!q.empty()){
		Node front = q.front();
		q.pop();
		if(isStroke(front)){
			ans++;
			for(int i = 0; i < 6 ;i++){
				int newX = front.x + X[i];
				int newY = front.y + Y[i];
				int newZ = front.z + Z[i];
				if(newX < 0 || newX >= M || newY < 0 || newY >= N || newZ < 0 || newZ >= L){
					continue;
				}
				if(!inque[newX][newY][newZ]){
					inque[newX][newY][newZ] = true;
					Node newNode(newX,newY,newZ);
					q.push(newNode); 
				}
			}
		}
	}
	if(ans >= T){
		return ans;
	}else{
		return 0;
	}
}

int main(){
	scanf("%d%d%d%d",&M,&N,&L,&T);
	for(int i = 0; i < L; i++){
		for(int j = 0; j < M;j++){
			for(int k = 0; k < N; k++){
				scanf("%d",&pixels[j][k][i]);
			}
		}
	}
	
	
	int ans = 0;
	for(int z = 0; z < L; z++){
		for(int x = 0; x < M; x++){
			for(int y = 0; y < N; y++){
				ans += BFS(x,y,z);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
