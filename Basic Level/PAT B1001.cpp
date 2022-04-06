#include <cstdio>

int main () {
	int n, count = 0;
	scanf("%d", &n);
	while (n != 1) {
		if (n % 2 == 0)
			n /= 2; //n为偶数
		else
			n = (3 * n + 1) / 2; //n为奇数
		count++;
	}
	printf("%d", count);
}