#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
using namespace std;
int main()
{
int a,b,c,d1,d2,temp=0;
int i,j;
freopen("jump.in","r",stdin);
freopen("jump.out","w",stdout);
scanf("%d%d%d",&a,&b,&c);
for(i=1;i<=a;i++)
{
	scanf("%d%d",&d1,&d2);
	if(d2>0) temp=temp+d2;
}
if(temp>=c)printf("%d",b-1);
else printf("-1");
fclose(stdin);
fclose(stdout);
return 0;
}
