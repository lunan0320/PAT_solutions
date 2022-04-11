#include <cstdio>


const int maxn = 101;

int n;

int request[maxn];

int stay = 5;
int up = 6;
int down = 4;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &request[i]);
	}
	int pre = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (request[i] > pre) {
			sum += (request[i] - pre) * up + stay;
		} else {
			sum += (pre - request[i]) * down + stay;
		}
		pre = request[i];
	}
	printf("%d", sum);
}