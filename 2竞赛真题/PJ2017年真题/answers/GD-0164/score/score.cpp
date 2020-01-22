#include <iostream>
#include <cstdio>
using namespace std;

int a,b,c;
double f;
int ans;

int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	
	scanf("%d%d%d",&a,&b,&c);
	f=a*0.2+b*0.3+c*0.5;
	ans=f;
	printf("%d\n",ans);
	
	fclose(stdin);fclose(stdout);
	return 0;	
}
