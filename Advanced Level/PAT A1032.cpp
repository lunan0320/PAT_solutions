#include <cstdio>

const int maxn = 100001;

struct Node {
	char val;
	int next;
	bool flag;
} node[maxn];

void deal_list1( int addr1) {
	int addr = addr1;
	while (addr != -1) {
		node[addr].flag = true;
		addr = node[addr].next;
	}
}

void deal_list2( int addr2) {
	int addr = addr2;
	bool flag = false;
	while (addr != -1) {
		if (node[addr].flag) {
			flag = true;
			break;
		} else {
			addr = node[addr].next;
		}
	}
	int ans ;
	if (flag) {
		ans = addr;
		printf("%05d", ans);
	} else {
		printf("-1");
	}
}

int main() {
	int add1, add2;
	int n = 0;
	//接受数据
	scanf("%d%d%d", &add1, &add2, &n);
	int add, next_addr;
	char value;
	for (int i = 0; i < n; i++) {
		scanf("%d %c %d", &add, &value, &next_addr);
		node[add].val = value;
		node[add].next = next_addr;
		node[add].flag = false;
	}
	//处理第一个链表
//	int addr = add1;
//	while (addr != -1) {
//		node[addr].flag = true;
//		addr = node[addr].next;
//	}
	deal_list1(add1);
	//处理第二个链表
//	addr = add2;
//	bool flag = false;
//	while (addr != -1) {
//		if (node[addr].flag) {
//			flag = true;
//			break;
//		} else {
//			addr = node[addr].next;
//		}
//	}
	deal_list2(add2);

//	int ans ;
//	if (flag) {
//		ans = addr;
//		printf("%05d", ans);
//	} else {
//		printf("-1");
//	}



}

