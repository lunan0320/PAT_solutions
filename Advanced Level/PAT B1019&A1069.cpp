#include <cstdio>
#include <algorithm>

using namespace std;

//将数字n转换到数组A
void to_array(int n, int A[]) {
	for (int i = 0; i < 4; i++) {
		A[i] = n % 10;
		n /= 10;
	}
}

//将数组A转换到数字n
int to_num(int A[], int n) {
	int base = 1;
	for (int i = 0; i < 4; i++) {
		n += A[i] * base;
		base *= 10;
	}
	return n;
}

int main() {
	int n;
	scanf("%d", &n);

	return 0;
}