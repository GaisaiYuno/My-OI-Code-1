#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	freopen("score.in", "r", stdin);
	freopen("score.out", "w", stdout);
	
	float A, B, C;
	scanf("%f %f %f", &A, &B, &C);
	printf("%.0f", A*0.2+B*0.3+C*0.5);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
