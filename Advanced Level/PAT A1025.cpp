#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct Student {
	char id[15];  //�˴�����׼��֤��ֱ�������飬������long long
	int score;
	int final_rank;			//������
	int location_number;	//������
	int location_rank;		//����������
} stu[100];

bool cmp (Student a, Student b) {
	if (a.score != b.score)
		return a.score > b.score;	//�÷ִӸߵ���
	return strcmp(a.id, b.id) < 0;  //ͬ�ֺ󣬰�id�Ĵ�С����
}

int main() {
	int n, k, num = 0;
	scanf("%d", &n); 						//������
	for (int i = 0; i < n; i++) {			//���ζ�ÿ����������
		scanf("%d", &k);					//�ÿ���������
		for (int j = 0; j < k; j++) {		//���ζ�ÿ���˴���
			scanf("%s %d", &stu[num].id, &stu[num].score);
			stu[num].location_number = i + 1;
			num++;							//num��������
		}
		//�Ըÿ���������
		sort(stu + num - k, stu + num, cmp);
		//�Կ���������
		stu[num - k].location_rank = 1;
		for (int i = 1; i < k; i++) {
			if (stu[i].score != stu[i + 1].score) {
				stu[i].location_rank = i + 1;
			} else {
				stu[i].location_rank = stu[i - 1].location_rank;
			}
		}
		//������������
		sort(stu, stu + num, cmp);
		//������������
		stu[0].final_rank = 1;
		for (int i = 1; i < num; i++) {
			if (stu[i].score != stu[i - 1].score) {
				stu[i].final_rank = i + 1;
			} else {
				stu[i].final_rank = stu[i - 1].final_rank;
			}
		}


	}
	//������
	printf("%d\n", num);  //��ӡ������
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