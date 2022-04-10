#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct Student {
	char id[15];  //此处对于准考证号直接用数组，而不是long long
	int score;
	int final_rank;			//总排名
	int location_number;	//考场号
	int location_rank;		//考场内排名
} stu[100];

bool cmp (Student a, Student b) {
	if (a.score != b.score)
		return a.score > b.score;	//得分从高到低
	return strcmp(a.id, b.id) < 0;  //同分后，按id的大小排序
}

int main() {
	int n, k, num = 0;
	scanf("%d", &n); 						//考场数
	for (int i = 0; i < n; i++) {			//依次对每个考场处理
		scanf("%d", &k);					//该考场的人数
		for (int j = 0; j < k; j++) {		//依次对每个人处理
			scanf("%s %d", &stu[num].id, &stu[num].score);
			stu[num].location_number = i + 1;
			num++;							//num是总人数
		}
		//对该考场内排序
		sort(stu + num - k, stu + num, cmp);
		//对考场内排名
		stu[num - k].location_rank = 1;
		for (int i = 1; i < k; i++) {
			if (stu[i].score != stu[i + 1].score) {
				stu[i].location_rank = i + 1;
			} else {
				stu[i].location_rank = stu[i - 1].location_rank;
			}
		}
		//对所有人排序
		sort(stu, stu + num, cmp);
		//对所有人排名
		stu[0].final_rank = 1;
		for (int i = 1; i < num; i++) {
			if (stu[i].score != stu[i - 1].score) {
				stu[i].final_rank = i + 1;
			} else {
				stu[i].final_rank = stu[i - 1].final_rank;
			}
		}


	}
	//输出结果
	printf("%d\n", num);  //打印总人数
	for (int i = 0; i < num; i++) {
		printf("%s %d %d %d\n", stu[i].id, stu[i].final_rank, stu[i].location_number, stu[i].location_rank);
	}


}

















//struct node {
//	int x, y;
//} ssd[10];
//
//bool cmp(node a, node b) {
//	if (a.x != b.x )
//		return a.x > b.x;
//	return a.y < b.y;
//}
//
//int main() {
//	ssd[0].x = 2;
//	ssd[0].y = 2;
//	ssd[1].x = 1;
//	ssd[1].y = 3;
//	ssd[2].x = 2;
//	ssd[2].y = 1;
//
//	sort(ssd, ssd + 3, cmp);
//	for (int i = 0; i < 3; i++) {
//		printf("%d %d\n", ssd[i].x, ssd[i].y);
//	}
//	return 0;
//}