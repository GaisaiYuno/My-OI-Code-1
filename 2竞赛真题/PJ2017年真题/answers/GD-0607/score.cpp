#include<cstdio>
int a,b,c;
float ans;
int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d %d %d",&a,&b,&c);
	ans=a*0.2+b*0.3+c*0.5;
	printf("%.0f",ans);
	return 0;
}
