/*

Calculate a + b and output the sum in standard format — that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

Input

Each input file contains one test case. Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. The numbers are separated by a space.

Output

For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

Sample Input

-1000000 9

Sample Output

-999,991

*/



//自己写的代码 一直是19分，差了一分没有调试出来


//#include <cstdio>



//#include <stack>
//using namespace std;
//
//int a, b;
//
//
//
//
//struct node {
//	bool isNum = true;
//	int data = 0;
//};
//
//
//stack<node> st;
//
//int main() {
//	if(scanf("%d%d", &a, &b)){
//		int res = a + b;
//		//对负号处理
//		if (res < 0) {
//			res = 0 - res;
//			printf("-");
//
//		}
//		int count = 0;
//		while (res > 0) {
//			if (count > 0 && count % 3 == 0) {
//				node temp;
//				temp.isNum = false;
//				st.push(temp);
//			}
//			node Node ;
//			Node.data = res % 10;
//			st.push(Node);
//			res /= 10;
//			count ++;
//		}
//		int num = st.size();
//		for (int i = 0; i < num; i++) {
//			node temp = st.top();
//			if (temp.isNum) {
//				printf("%d", temp.data);
//			} else {
//				printf(",");
//			}
//			st.pop();
//		}
//		return 0;
//	}
//	return -1;
//
//}




//改进代码

//学习到对于一个整数可以使用to_string()的用法
//以及如何表示满3位的技巧   (len - 1 -i) % 3 == 0


#include <iostream>

using namespace std;

int a, b;

int main() {
	if (scanf("%d%d", &a, &b)) {
		//将一个整数转换成字符串 to_string()
		string s = to_string(a + b);
		int len = s.length();
		for (int i = 0; i < len; i++) {
			printf("%c", s[i]);
			if (s[i] == '-') {
				continue;
			}
			//如果当前所在位和总的索引长度之间相差是3的倍数
			//说明剩下的未打印的字符是3的倍数，打印一个逗号
			if (((len - 1) - i) % 3 == 0 && i != len - 1) {
				printf(",");
			}

		}
	}
	return 0;
}