#include <cstdio>
#include <algorithm>

using namespace std;

struct mooncake {
	double store;  //���
	double price;  //����
	double sell;   //���ۼ�
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


	//�Ե�������
	sort(cakes, cakes + n, cmp);
	for (int i = 0; i < n; i++) {
		printf("%.2f ", cakes[i].store);
	}
	//��n��mooncakeȥ���ǳ���
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