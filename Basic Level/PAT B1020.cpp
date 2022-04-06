#include <cstdio>
#include <algorithm>

using namespace std;

struct mooncake {
	double store;  //库存
	double price;  //单价
	double sell;   //总售价
} cakes[1100];

bool cmp (mooncake A, mooncake B) {
	return A.price > B.price;
}

int main() {
	int n = 0;
	double Demand = 0;
	scanf("%d %lf", &n, &Demand);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &cakes[i].store);
	}
	for (int i = 0; i < n; i++) {
		scanf("%lf", &cakes[i].sell);
		cakes[i].price = cakes[i].sell / cakes[i].store;
	}


	//对单价排序
	sort(cakes, cakes + n, cmp);
	for (int i = 0; i < n; i++) {
		printf("%.2f ", cakes[i].store);
	}
	//对n种mooncake去考虑出售
	double res = 0;
	for (int i = 0; i < n; i++) {
		if (Demand > cakes[i].store) {
			Demand -= cakes[i].store;
			res += cakes[i].sell;
		} else {
			res += Demand * cakes[i].price;
			break;
		}
	}
	printf("%.2f", res);
	return 0;
}