#include<algorithm>
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,h,x,g,z,a[1010];
int main()
{
    freopen("librarian.in","r",stdin);
    freopen("librarian.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d",&h,&x);
        z=0;
        g=1;
        for (int j=1;j<=h;j++)
            g=g*10;
        for (int j=1;j<=n;j++)
        {
            if (a[j]%g==x)
            {
                z=1;
                printf("%d\n",a[j]);
                break;
            }
        }
        if (z==0) cout<<-1<<endl;
    }
    return 0;
}
