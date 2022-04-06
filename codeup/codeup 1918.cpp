#include <iostream>
#include <cstdio>
#include <stack>
#include <map>
#include <queue>
#include <string>

using namespace std;

struct node {
	double num;
	char op;
	bool flag;  //trueΪ������
};

string str;
stack<node> st;
queue<node> que; //��ź�׺���ʽ
map<char, int> op;



//��׺���ʽ��Ϊ��׺���ʽ  ��str����
void change() {
	double num;
	for (int i = 0; i < str.length(); ) {
		num = 0;
		node temp;
		if (str[i] >= '0' && str[i] <= '9') { //�����������
			//ע��˴�����ֱ��ȡ ��Ҫ��0��ascii
			num = str[i++] - '0';
			temp.flag = true;
			//�ж�֮���λ�Ƿ��ǲ����� ����һ��������
			while (i < str.length() && str[i] >= '0' && str[i] <= '9' ) {
				num = num * 10 + (str[i++] - '0');
			}
			temp.num = num;
			//�������������
			que.push(temp);
		} else { // ���ڲ������Ĵ���  ��ջ
			temp.flag = false;
			// ��ǰ���ȼ���ջ�еĵ� �Ǿͳ�ջ �����
			while (!st.empty() && op[str[i]] <= op[st.top().op]) {
				que.push(st.top());
				st.pop();
			}
			// ����ǰ���ȼ���ջ�иߵĲ�������ջ
			temp.op = str[i++];
			st.push(temp);
		}
	}
	//�����������ַ��󣬶�ջ�в�����ֱ���Ƶ�������
	while (!st.empty()) {
		que.push(st.top());
		st.pop();
	}
}


//��׺���ʽ�ļ���
double calculate() {

	node cur;
	node temp;
	double temp1, temp2;
	//֮ǰ��stջ�����ǿ��ˣ���˿��Լ���ʹ��
	//�Զ����е�Ԫ�����δ���
	while (!que.empty()) {
		cur = que.front();
		que.pop();
		// ����ǲ����� ֱ����ջ
		if (cur.flag) {
			st.push(cur);
		} else {
			//������
			//ȡ��ǰ�������������
			//�˴�ע���Ǵ�ջ��ȡ ���Ǵ�que��ȡ �����Ҵ���죡����
			temp1 = st.top().num;
			st.pop();
			temp2 = st.top().num;
			st.pop();
			printf("%lf,%lf\n", temp1, temp2);

			// ע������һ��ҪС��˳�����⣬��2-1��2/1
			switch (cur.op) {
				case '+':
					temp.num = temp1 + temp2;
					break;
				case '-':
					temp.num = temp2 - temp1;
					break;
				case '*':
					temp.num = temp1 * temp2;
					break;
				case '/':
					temp.num = temp2 / temp1;
					break;
			}
			temp.flag = false;
			st.push(temp);
		}
	}
	return st.top().num;
}



int main() {
	op['+'] = op['-'] = 0;
	op['*'] = op['/'] = 1;
	while (getline(cin, str), str != "0") {
		//�������еĿո�
		string::iterator it = str.begin();
		for (it; it != str.end(); it++) {
			if (*it == ' ') {
				str.erase(it);
			}
		}
		//��׺ת��׺
		change();
		double ans = calculate();
		printf("%.2lf\n", ans);
	}
	return 0;
}













































































//
//
//
//#include <cstdio>
//#include <stack>
//#include <string>
//#include <iostream>
//#include <map>
//#include <queue>
//using namespace std;
//
////�˴��ýṹ������Ϊջ�м��в���������op
//struct node {
//	double num;
//	char op;
//	bool flag;  // �ǲ�������flagΪtrue
//};
//
//stack<node> st;
//map<char, int> op;
//queue<node> que;
//string str;
//stack<double>res;
//
//
//void change() {
//	node temp;
//	for (int i = 0; i < str.length();) {
//		if (str[i] >= '0' && str[i] <= '9') { //������ֱ����ջ
//			temp.num = str[i++] - '0' ; //��������ĵ�һλ����
//			temp.flag = true;
//			while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
//				temp.num = temp.num * 10 + (str[i++] - '0'); //�����������ֻ��һλ
//			}
//			que.push(temp);
//		} else { //�ǲ�����
//			temp.flag = false;
//			//���������ȼ�С�ڵ���ջ�������� �򵯳� ���׺���ʽ����
//			while (!st.empty() && op[str[i]] <= op[st.top().op]) {
//				que.push(st.top());
//				st.pop();
//			}
//			//��������������ȼ�����ջ�������� ����ջΪ���� ����ջ
//			temp.op = str[i++];
//			st.push(temp);
//		}
//	}
//	while (!st.empty()) {
//		que.push(st.top());
//		st.pop();
//	}
//}
//
//double calculate() {
//	double temp1, temp2;
//	node cur;
//	node temp;
//	while (!que.empty()) {
//		cur = que.front();
//		que.pop();
//		if (cur.flag) {
//			res.push(cur.num);
//		} else {
//			temp1 = res.top();
//			res.pop();
//			temp2 = res.top();
//			printf("%lf,%lf\n", temp1, temp2);
//			res.pop();
////			temp.flag = true;
////			if (cur.op == '+')
////				temp.num = temp1 + temp2;
////			else if (cur.op == '-')
////				temp.num = temp2 - temp1;
////			else if (cur.op == '*')
////				temp.num = temp1 * temp2;
////			else if (cur.op == '/')
////				temp.num = temp2 / temp1;
////			st.push(temp);
//			switch (cur.op) {
//				case '+':
//					res.push(temp1 + temp2);
//					break;
//				case '-':
//					res.push(temp2 - temp1);
//					break;
//				case '*':
//					res.push(temp1 * temp2);
//					break;
//				case '/':
//					res.push(temp2 / temp1);
//					break;
//			}
//		}
//	}
//	return res.top();
//}
//
//
//
//int main() {
//	op['+'] = 0;
//	op['-'] = 0;
//	op['*'] = 1;
//	op['/'] = 1;
//	while (getline(cin, str), str != "0") {
////		string::iterator it = str.begin();
////		//ȥ���ո�
////		for (it; it != str.end(); it++) {
////			if (*it == ' ') {
////				str.erase(it);
////			}
////		}
//		change();
//		double ans = calculate();
//		printf("%.2lf\n", ans);
//	}
//	return 0;
//
//}