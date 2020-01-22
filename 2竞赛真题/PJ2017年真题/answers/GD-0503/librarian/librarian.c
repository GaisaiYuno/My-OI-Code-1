#include <stdio.h>

long long bookNum[1010], bookStack[1010], requestCode[1010], foundDataIndex[1010], resultList[1010];

int libsearch(int index, int number){
	int j, count = 0, judgeDigit = 10;
	for (j = 1; j < bookStack[index]; j++){
		judgeDigit = judgeDigit * 10;
		//printf("RUNHERE\n");
	}
	//printf("the judgedigit: %d\n", judgeDigit);
	long long maxNum = 10000000;
	long long judgeNum = 0;
	for (j = 1; j <= number; j++) {
		//printf("We are judging bookNum[%d]: %d\n", j, bookNum[j]);
		//printf("the judgedigit INSIDE: %d\n", judgeDigit);
		if (bookNum[j] - requestCode[index] >= 0){
			judgeNum = (bookNum[j] - requestCode[index]) % judgeDigit;
		} else {
			judgeNum = -1;
		}
		//printf("We are judging reader no.%d, book no.%d : %d\n", index, j, judgeNum);
		if (judgeNum == 0) {
			foundDataIndex[count] = j;
			count++;
			//printf("We counted this: %d\n", bookNum[j]);
		}
	}
	if (count == 0) return -1;
	for (j = 0; j < count; j++) {
		if (bookNum[foundDataIndex[j]] < maxNum) maxNum = bookNum[foundDataIndex[j]];
	}
	return maxNum;
}

int main(){
	FILE *libin, *libout;
	int n, q, i;
	libin = fopen("librarian.in", "r");
	libout = fopen("librarian.out", "w");
	fscanf(libin, "%d%d", &n, &q);
	//printf("Entered data: n: %d, q: %d\n", n, q);
	for (i = 1; i <= n; i++) {
		fscanf(libin, "%d", &bookNum[i]);
		//printf("Entered data: bookNum[%d]: %d\n", i, bookNum[i]);
	}
	for (i = 1; i <= q; i++) {
		fscanf(libin, "%d%d", &bookStack[i], &requestCode[i]);
		//printf("Entered data: bookStack[%d]: %d\n", i, bookStack[i]);
		//printf("Entered data: requestCode[%d]: %d\n", i, requestCode[i]);
	}
	for (i = 1; i <= q; i++) {
		resultList[i] = libsearch(i, n);
	}
	for (i = 1; i <= q; i++) {
		fprintf(libout, "%d\n", resultList[i]);
	}
	fclose(libin);
	fclose(libout);
	return 0;
}
