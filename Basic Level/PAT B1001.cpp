#include <cstdio>

int main () {
	int n, count = 0;
	scanf("%d", &n);
	while (n != 1) {
		if (n % 2 == 0)
			n /= 2; //nΪż��
		else
			n = (3 * n + 1) / 2; //nΪ����
		count++;
	}
	printf("%d", count);
}