/*

Calculate a + b and output the sum in standard format �� that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

Input

Each input file contains one test case. Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. The numbers are separated by a space.

Output

For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

Sample Input

-1000000 9

Sample Output

-999,991

*/



//�Լ�д�Ĵ��� һֱ��19�֣�����һ��û�е��Գ���


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
//		//�Ը��Ŵ���
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




//�Ľ�����

//ѧϰ������һ����������ʹ��to_string()���÷�
//�Լ���α�ʾ��3λ�ļ���   (len - 1 -i) % 3 == 0


#include <iostream>

using namespace std;

int a, b;

int main() {
	if (scanf("%d%d", &a, &b)) {
		//��һ������ת�����ַ��� to_string()
		string s = to_string(a + b);
		int len = s.length();
		for (int i = 0; i < len; i++) {
			printf("%c", s[i]);
			if (s[i] == '-') {
				continue;
			}
			//�����ǰ����λ���ܵ���������֮�������3�ı���
			//˵��ʣ�µ�δ��ӡ���ַ���3�ı�������ӡһ������
			if (((len - 1) - i) % 3 == 0 && i != len - 1) {
				printf(",");
			}

		}
	}
	return 0;
}