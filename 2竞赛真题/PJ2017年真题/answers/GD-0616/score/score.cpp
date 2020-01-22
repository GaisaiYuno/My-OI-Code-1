#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
using namespace std;
int a,b,c;
int main()
{
freopen("score.in","r",stdin);
freopen("score.out","w",stdout);
scanf("%d%d%d",&a,&b,&c);
printf("%d",a/5+b*3/10+c/2);
fclose(stdin);
fclose(stdout);
return 0;
}
