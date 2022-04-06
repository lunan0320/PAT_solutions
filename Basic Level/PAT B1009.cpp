#include <cstdio>
#include <cstring>


/*
input: Hello World Here I Come
output: Come I Here Word Hello

*/



#define max_int 100

int main() {
	char str_in[max_int];
	char ans[max_int][max_int];
	gets(str_in);
	int length = strlen(str_in);
	int rows = 0, cols = 0;
	int count = 0; //numbers of words
	for (int i = 0; i < length; i++) {
		if (str_in[i] != ' ') {
			ans[rows][cols] = str_in[i];
			cols++;
		} else {
			ans[rows][cols] = '\0'; //表示一个字符串结束
			rows++;
			cols = 0;
			count++;
		}
	}
	while (count >= 0) {
		printf("%s ", ans[count ]);
		count--;

	}

}