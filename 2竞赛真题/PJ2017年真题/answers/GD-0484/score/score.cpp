#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int A,B,C;
	scanf("%d %d %d",&A,&B,&C);
	int Result=A/5+B/10*3+C/2;
	printf("%d",Result);
	return 0;
}
