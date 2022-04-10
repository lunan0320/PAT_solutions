#include <cstdio>
#include <cstring>

#define MAX_LEN 100

int main() {

	char str[MAX_LEN];
	int leftNumP[MAX_LEN] = {0};   //当前位置（包括当前位）P的个数
	int ans = 0; //结果
	gets(str);
	int len = strlen(str);
	//遍历，找P
	for (int i = 0; i < len; i++) {
		if (str[i] == 'P') {
			if (i > 0) {
				leftNumP[i] = leftNumP[i - 1] + 1;
			} else if (i == 0) {
				leftNumP[i] = 1;
			}
		} else {
			leftNumP[i] = leftNumP[i - 1];
		}

	}

	//打印当前值之前的p的个数（包括当前值）
	printf("打印当前值之前的p的个数（包括当前值）");
	for (int i = 0; i < len; i++) {
		printf("%d ", leftNumP[i]);
	}
	printf("\n");


	int rightNumT = 0;
	for (int i = len - 1; i > 0; i--) {
		if (str[i] == 'T') {
			rightNumT += 1;
		}
		if (str[i] == 'A') {
			ans += (leftNumP[i] * rightNumT);
		}
	}
	printf("%d", ans);
	return 0;
}