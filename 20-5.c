#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int birthmonth;
	char name[40];
}Worker;


void AddWorker(int* tolist, int listsize, Worker* workerptr, int ptrsize, int workercount) {
	tolist[workerptr[workercount].birthmonth - 1]++;
}


int main() {
	int month[12] = { 0, };
	int input;
	int workercount = 0;
	
	FILE* fp_read = fopen("birthdays.bin", "rb");

	if (fp_read != NULL) {
		printf("파일 읽기 성공\n");
		fread(month, sizeof(month), 1, fp_read);
		fclose(fp_read);
	}
	else {
		printf("읽을 파일 없음, 저장 시 새 파일 생성\n");
	}
	Worker* workerptr = (Worker*)malloc(sizeof(Worker) * 1);

	while (1) {
		scanf("%d", &input);
		getchar();
		if (input == 4) {
			FILE* fp_write = fopen("birthdays.bin", "wb");
			fwrite(month, sizeof(month), 1, fp_write);
			break;
		}
		if (input == 1) {
			char buffer[100];
			int birth_temp = 999;
			char name_temp[50];
			while (1) {
				fgets(buffer, sizeof(buffer), stdin);
				int inputable = sscanf(buffer, "%d %s", &birth_temp, name_temp);
				if (birth_temp == -1) {
					printf("추가 등록 종료\n");
					break;
				}
				if (inputable != 2) {
					printf("적절한 입력값 아님\n");
					break;
				}
				if (birth_temp > 12 || birth_temp < 1) {
					printf("잘못된 생일 입력\n");
					break;
				}
				Worker* tempptr = (Worker*)realloc(workerptr, sizeof(Worker) * (workercount + 1));
				if (tempptr == NULL) {
					printf("메모리 공간 부족\n");
					break;
				}
				workerptr = tempptr;
				strcpy(workerptr[workercount].name, name_temp);
				workerptr[workercount].birthmonth = birth_temp;
				AddWorker(month, sizeof(month) / sizeof(int), workerptr, sizeof(workerptr), workercount);
				workercount++;
			}
		}
		else if (input == 2) {
			for (int i = 0; i < 12; i++) {
				printf("%d월: %d명\n", i + 1, month[i]);
			}
			//전체 출력(n월: m명) 이거 쭈루룩
		}
		else if (input == 3) {
			int max = 0;
			int maxmonth = 0;
			for (int i = 0; i < 12; i++) {
				if (max < month[i]) {
					max = month[i];
					maxmonth = i + 1;
				}
			}
			printf("최다 생일자 월: %d월 / %d명\n", maxmonth, max);
			//가장 많은 생일자 달 출력 (ex: 3월)
		}

	}


	free(workerptr);
	return 0;
}