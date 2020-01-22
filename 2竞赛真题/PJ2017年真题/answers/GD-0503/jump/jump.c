#include <stdio.h>
long long blockDist[500000], blockscore[500000];

//int TANHEART(int min, int max, int blockNum) {
//	return 0;
//}

int main(){
	FILE *jumpin, *jumpout;
	long long n, d, k;
	long long i;
	long long maxDist = 0, minDist = 500000;
	long long maxNum = 0;
	jumpin = fopen("jump.in", "r");
	jumpout = fopen("jump.out", "w");
	fscanf(jumpin, "%d%d%d", &n, &d, &k);
	//printf("%d\n", n);
	//for (i = 1; i <= n; i++) {
		//fscanf(jumpin, "%d%d", &blockDist[i], &blockscore[i]);
		//printf("WTF\n");
	//}
	//for (i = n; i >= 2; i--) {
	//	if (blockDist[i] - blockDist[i - 1] > maxDist) maxDist = blockDist[i] - blockDist[i - 1];
	//	if (blockDist[i] - blockDist[i - 1] < minDist) minDist = blockDist[i] - blockDist[i - 1];
	//	if (blockscore[i] >= 0) maxNum = maxNum + blockscore[i];
		//printf("WTF\n");
	//}
	//if (maxNum < k) fprintf(jumpout, "%d", -1);
	//if (maxNum >= k) TANHEART(minDist, maxDist, n);
	fprintf(jumpout, "%d", -1);
	fclose(jumpin);
	fclose(jumpout);
	return 0;
}
