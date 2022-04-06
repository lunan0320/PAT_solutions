#include <cstdio>

#define maxint 100

struct stuinfo {
	int id;
	int score;
} stuers[maxint];

int main () {
	int schools[maxint] = {0};
	int numbers;
	scanf("%d", &numbers);
	int count = 0;
	while (count < numbers) {
		scanf("%d %d", &stuers[count].id, &stuers[count].score);
		schools[stuers[count].id] += stuers[count].score;
		count++;
	}
	//find the max score;
	int max = 0;
	int max_index = 0;
	for (int i = 0; i < numbers; i++) {
//		max = max > schools[i] ? max : schools[i];
		if (max < schools[i]) {
			max = schools[i];
			max_index = i;
		}
	}
	printf("index = %d, score = %d", max_index, max);
}