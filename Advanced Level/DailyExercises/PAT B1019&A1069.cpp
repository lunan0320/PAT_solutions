#include <cstdio>
#include <algorithm>

using namespace std;

//������nת��������A
void to_array(int n, int A[]) {
	for (int i = 0; i < 4; i++) {
		A[i] = n % 10;
		n /= 10;
	}
}

//������Aת��������n
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