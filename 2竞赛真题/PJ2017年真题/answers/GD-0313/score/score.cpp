#include<cstdio>
using namespace std;
int main(){
//	freopen("score.in","r",stdin);
//	freopen("score.out","w",stdout);
	int a,b,c;
	double s=0;
	scanf("%d%d%d",&a,&b,&c);
	if(a==0&&b==0)
		s=c*0.5;
	else
		if(a==100&&b==100)
			s=50+c*0.5;
		else
			s=a*0.2+b*0.3+c*0.5;
	printf("%.0lf",s);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
