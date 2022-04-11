#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;


struct game {
	double win;
	double tie;
	double lose;
} games[3];

char res[3];
double profit = 1.0;

void findMax() {
	for (int i = 0; i < 3; i++) {
		double temp = max(games[i].win, games[i].tie);
		double ans = max(temp, games[i].lose);
		if (ans == games[i].win) {
			printf("W ");
		} else if (ans == games[i].tie) {
			printf("T ");
		} else {
			printf("L ");
		}
		profit *= ans;
	}
	printf("%.2lf", (profit * 0.65 - 1) * 2);
}

int main() {
	for (int i = 0; i < 3; i++) {
		scanf("%lf%lf%lf", &games[i].win, &games[i].tie, &games[i].lose);
	}
	findMax();
	return 0;
}