#include<cstdio>

using namespace std;

int main(){
	freopen ("score.in","r",stdin);
	freopen ("score.out","w",stdout);
	int a,b,c,sum;
	scanf ("%d%d%d",&a,&b,&c);
	sum=a*0.2+b*0.3+c*0.5;
	printf ("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
