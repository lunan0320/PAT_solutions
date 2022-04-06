#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


const int maxn = 101;

struct Node {
	int weight;
	vector<int> child;
} node[maxn];

int N = 0, M = 0, W = 0;
vector<int> res;

bool cmp(int a, int b) {
	return node[a].weight > node[b].weight;
}

void DFS(int index, int sum) {
	if (sum > W) {
		return;
	}
	if (sum == W) {
		if (node[index].child.size() == 0) {
			for (int i = 0; i < res.size(); i++) {
				printf("%d", node[res[i]].weight);
				if (i < res.size() - 1) {
					printf(" ");
				} else {
					printf("\n");
				}

			}
			//res.clear();
			return;
		}
		return;
	}
	for (int i = 0; i < node[index].child.size(); i++) {
		int child = node[index].child[i];
		res.push_back(child);
		DFS(child, sum + node[child].weight);
		res.pop_back();
	}

}

int main() {

	scanf("%d%d%d", &N, &M, &W);
	for (int i = 0; i < N; i++) {
		scanf("%d", &node[i].weight);
	}
	int id, k, child;
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &id, &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &child);
			node[id].child.push_back(child);
		}
		sort(node[id].child.begin(), node[id].child.end(), cmp);
	}
	res.push_back(0);
	DFS(0,  node[0].weight);

	return 0;
}





//#include <cstdio>
//#include <queue>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//
//const int maxn = 101;
//
//struct Node {
//	int weight;
//	vector<int> child;
//} node[maxn];
//
//int N = 0, M = 0, W = 0;
//vector<int> res;
//
//bool cmp(int a, int b) {
//	return node[a].weight > node[b].weight;
//}
//
//void DFS(int index, int numNode, int sum) {
//	if (sum > W) {
//		return;
//	}
//	if (sum == W) {
//		if (node[index].child.size() == 0) {
//			for (int i = 0; i < res.size(); i++) {
//				printf("%d", node[res[i]].weight);
//				if (i < numNode - 1) {
//					printf(" ");
//				} else {
//					printf("\n");
//				}
//
//			}
//			//res.clear();
//			return;
//		}
//		return;
//	}
//	for (int i = 0; i < node[index].child.size(); i++) {
//		int child = node[index].child[i];
//		res.push_back(child);
//		DFS(child, numNode + 1, sum + node[child].weight);
//		res.pop_back();
//	}
//
//}
//
//int main() {
//
//	scanf("%d%d%d", &N, &M, &W);
//	for (int i = 0; i < N; i++) {
//		scanf("%d", &node[i].weight);
//	}
//	int id, k, child;
//	for (int i = 0; i < M; i++) {
//		scanf("%d%d", &id, &k);
//		for (int j = 0; j < k; j++) {
//			scanf("%d", &child);
//			node[id].child.push_back(child);
//		}
//		sort(node[id].child.begin(), node[id].child.end(), cmp);
//	}
//	res.push_back(0);
//	DFS(0, 1, node[0].weight);
//
//	return 0;
//}
/*
20 9 24
10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
00 4 01 02 03 04
02 1 05
04 2 06 07
03 3 11 12 13
06 1 09
07 2 08 10
16 1 15
13 3 14 16 17
17 2 18 19
*/
