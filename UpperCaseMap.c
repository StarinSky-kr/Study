#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	char code1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char code2[] = "hknopijxyzqfgmvwulastbcrde";

	char input[100];
	fgets(input, sizeof(input), stdin);

	int errorcount = 0;

	for (int i = 0; input[i] != '\n'; i++) {
		int found = 0;
		if (input[i] == ' ') {
			printf("%c", ' ');
			continue;
		}
		for (int j = 0; code1[j] != '\0'; j++) {
			if (code1[j] == input[i]) {
				printf("%c", code2[j]);
				found = 1;
				break;
			}
		}
		if (found == 0) {
			errorcount++;
		}
	}
	if (errorcount != 0) {
		printf("\n%d개의 문자가 대문자가 아닙니다.", errorcount);
	}

	return 0;
}