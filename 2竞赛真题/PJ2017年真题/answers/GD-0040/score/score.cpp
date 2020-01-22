#include<cstdio>
using namespace std;
int ts,as,qms;
int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&as,&ts,&qms);
	printf("%d",as*2/10+ts*3/10+qms*5/10);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
