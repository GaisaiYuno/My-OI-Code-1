#include<cstdio>
using namespace std;
int a,b,c,d;
int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	d=a/5+b*3/10+c/2;
	printf("%d",d);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
