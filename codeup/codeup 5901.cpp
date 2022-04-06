#include <cstdio>
#include <cstring>


#define max_int 100

bool judge(char str1[]) {
	int length = strlen(str1);

	for (int i = 0; i < length / 2; i++) {
		//只需要比较对应的位置即可
		if (str1[i] != str1[length - 1 - i]) {
			return false;
		}
	}
	return true;
}

int main() {
	char str_in[max_int];
	gets(str_in);
	bool res = judge(str_in);
	if (res) {
		printf("%s是回文串", str_in);
	} else {
		printf("%s不是回文串", str_in);
	}
	return 0;
}