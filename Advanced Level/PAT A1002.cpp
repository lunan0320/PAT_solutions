
/*
This time, you are supposed to find A+B where A and B are two polynomials.

Input

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 aN1 N2 aN2 … NK aNK, where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, …, K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10，0 <= NK < … < N2 < N1 <=1000.

Output

For each test case you should output the sum of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.

Sample Input

2 1 2.4 0 3.2
2 2 1.5 1 0.5

Sample Output

3 2 1.5 1 2.9 0 3.2

*/


/*
思路：多项式相加，直接对应的指数相加。
用一个大数组表示，数组索引表示指数，值表示系数。
*/

#include <cstdio>

const int maxn = 1001;

//k1 k2代表输入的不为0的组
int k1, k2;
//设置两个传值  指数和系数
int exp;
double coef;
//大数组 索引表示指数，值表示系数
double res[maxn] = {0.0};

int main() {
	//输入第一个多项式
	scanf("%d", &k1);
	for (int i = 0; i < k1; i++) {
		scanf("%d%lf", &exp, &coef);
		res[exp] = coef;
	}
	//输入第二个多项式
	scanf("%d", &k2);
	for (int i = 0; i < k2; i++) {
		scanf("%d%lf", &exp, &coef);
		res[exp] += coef;
	}
	//计算不为0的数量
	int cnt = 0;
	for (int i = 0; i < maxn; i++) {
		if (res[i] != 0) {
			cnt++;
		}
	}
	//打印结果
	printf("%d", cnt);
	//按照多项式的从高到低的指数打印
	for (int i = maxn - 1; i >= 0; i--) {
		if (res[i] != 0) {
			printf(" %d %.1lf", i, res[i]);
		}
	}
	return 0;
}