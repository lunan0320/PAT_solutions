#include <cstdio>

#define num 10

int main() {
	int count[num];
	int min = num;
	bool flag = false;
	for (int i = 0; i < num; i++) {
		scanf("%d", &count[i]);
		if (!flag && count[i] && i) {
			min = i;
			flag = true;
		}
	}
	printf("%d", min);
	count[min]--;
	for (int i = 0; i < num; i++) {
		while (count[i]) {
			printf("%d", i);
			count[i]--;
		}
	}
	return 0;
}