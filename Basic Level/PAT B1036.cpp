#include <cstdio>


int main () {
	int n;
	char tag;
	scanf("%d %c", &n, &tag);
	int columns = n;
	int lines = n / 2;
	for (int i = 0; i < lines; i++) {
		if (i == 0 || i == lines - 1) {
			for (int j = 0; j < columns; j++) {
				printf("%c", tag);
			}
			printf("\n");
		} else {
			for (int j = 0; j < columns; j++) {
				if (j == 0 || j == columns - 1) {
					printf("%c", tag);
				} else {
					printf(" ");
				}
			}
			printf("\n");
		}
	}
}