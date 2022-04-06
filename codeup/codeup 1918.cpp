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
	bool flag;  //true为操作数
};

string str;
stack<node> st;
queue<node> que; //存放后缀表达式
map<char, int> op;



//中缀表达式变为后缀表达式  对str操作
void change() {
	double num;
	for (int i = 0; i < str.length(); ) {
		num = 0;
		node temp;
		if (str[i] >= '0' && str[i] <= '9') { //操作数入队列
			//注意此处不能直接取 需要减0的ascii
			num = str[i++] - '0';
			temp.flag = true;
			//判断之后的位是否是操作数 当作一个数处理
			while (i < str.length() && str[i] >= '0' && str[i] <= '9' ) {
				num = num * 10 + (str[i++] - '0');
			}
			temp.num = num;
			//将操作数入队列
			que.push(temp);
		} else { // 对于操作符的处理  入栈
			temp.flag = false;
			// 当前优先级比栈中的低 那就出栈 入队列
			while (!st.empty() && op[str[i]] <= op[st.top().op]) {
				que.push(st.top());
				st.pop();
			}
			// 将当前优先级比栈中高的操作符入栈
			temp.op = str[i++];
			st.push(temp);
		}
	}
	//处理完所有字符后，对栈中操作符直接移到队列中
	while (!st.empty()) {
		que.push(st.top());
		st.pop();
	}
}


//后缀表达式的计算
double calculate() {

	node cur;
	node temp;
	double temp1, temp2;
	//之前的st栈现在是空了，因此可以继续使用
	//对队列中的元素依次处理
	while (!que.empty()) {
		cur = que.front();
		que.pop();
		// 如果是操作符 直接入栈
		if (cur.flag) {
			st.push(cur);
		} else {
			//操作符
			//取出前面的两个操作数
			//此处注意是从栈中取 不是从que中取 导致找错半天！！！
			temp1 = st.top().num;
			st.pop();
			temp2 = st.top().num;
			st.pop();
			printf("%lf,%lf\n", temp1, temp2);

			// 注意这里一定要小心顺序问题，是2-1和2/1
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
		//处理其中的空格
		string::iterator it = str.begin();
		for (it; it != str.end(); it++) {
			if (*it == ' ') {
				str.erase(it);
			}
		}
		//中缀转后缀
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
////此处用结构体是因为栈中既有操作数又有op
//struct node {
//	double num;
//	char op;
//	bool flag;  // 是操作数，flag为true
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
//		if (str[i] >= '0' && str[i] <= '9') { //操作数直接入栈
//			temp.num = str[i++] - '0' ; //设置这个的第一位数字
//			temp.flag = true;
//			while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
//				temp.num = temp.num * 10 + (str[i++] - '0'); //这个操作数不只有一位
//			}
//			que.push(temp);
//		} else { //是操作符
//			temp.flag = false;
//			//操作符优先级小于等于栈顶操作符 则弹出 入后缀表达式队列
//			while (!st.empty() && op[str[i]] <= op[st.top().op]) {
//				que.push(st.top());
//				st.pop();
//			}
//			//如果操作符的优先级大于栈顶操作符 或者栈为空了 则入栈
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
////		//去除空格
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