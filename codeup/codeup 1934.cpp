#include <cstdio>
#include <cstdlib>

int main() {
	int n;
	scanf("%d", &n);
	int *nums = (int *)malloc(sizeof(int) * n);
	if (!nums)
		exit(-1);
	int count = 0;

	while (count < n) {
		scanf("%d", &nums[count]);
//		nums[count] = getchar();
		count++;
	}

	int target = 0;
	scanf("%d", &target);
	for (int i = 0; i < n; i++) {
		if (nums[i] == target) {
			printf("%d", i);
			break;
		}
	}
}