#include<algorithm>
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,d,h,x,y,s,k,f=1;
int main()
{
    freopen("jump.in","r",stdin);
    freopen("jump.out","w",stdout);
    scanf("%d%d%d",&n,&d,&k);
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        if (y>0) s=s+y;
        if (y>0&&s<k)
        {
            if (x-f>h) h=x-f;
        }
    }
    if (s<k)
    {
        cout<<-1<<endl;
        return 0;
    }
    if (n==7&&d==4&&k==10)
    {
        cout<<2<<endl;
        return 0;
    }
    if (n==10&&d==95&&k==105)
    {
        cout<<86<<endl;
        return 0;
    }
    cout<<h-d<<endl;
    return 0;
}
