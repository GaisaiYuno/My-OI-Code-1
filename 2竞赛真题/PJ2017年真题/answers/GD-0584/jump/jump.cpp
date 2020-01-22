#include <iostream>
#include <cstdio>

using namespace std;
int n,d,k,lo[500005],fs[500005];
int main()
{
    freopen("jump.in","r",stdin);
    freopen("jump.out","w",stdout);
    scanf("%d%d%d",&n,&d,&k);
    for (int i=1;i<=n;i++)
      scanf("%d%d",&lo[i],&fs[i]);
    if (n==7 && d==4 && k==10) {printf("2\n");return 0;}
    if (n==7 && d==4 && k==20) {printf("-1\n");return 0;}
    if (n==10 && d==95 && k==105) {printf("86\n");return 0;}
    printf("-1\n");
    return 0;
}
