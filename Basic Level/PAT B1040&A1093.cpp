#include <cstdio>
#include <cstring>

#define MAX_LEN 100

int main() {

	char str[MAX_LEN];
	int leftNumP[MAX_LEN] = {0};   //��ǰλ�ã�������ǰλ��P�ĸ���
	int ans = 0; //���
	gets(str);
	int len = strlen(str);
	//��������P
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

	//��ӡ��ǰֵ֮ǰ��p�ĸ�����������ǰֵ��
	printf("��ӡ��ǰֵ֮ǰ��p�ĸ�����������ǰֵ��");
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