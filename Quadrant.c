#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	printf("%d", ((x > 0 && y > 0) || (x < 0 && y < 0) ? (x > 0 ? 1 : 3) : (x < 0 ? 2 : 4)));
	return 0;
}