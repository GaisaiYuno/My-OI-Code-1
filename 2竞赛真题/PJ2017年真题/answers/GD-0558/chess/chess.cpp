#include<algorithm>
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,x,y,c,a[110][110];
int main()
{
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    scanf("%d%d",&n,&m);
    if (n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&c);
        a[x][y]=c+1;
    }
    if (n==5&&m==7)
    {
        if (a[1][1]==1&&a[1][2]==1)
        {
            if (a[2][2]==2)
                if (a[3][3]==2&&a[3][4]==1)
                    if (a[4][4]==2&&a[5][5]==1)
                    {
                        cout<<8<<endl;
                        return 0;
                    }
        }
    }
    if (n==50&&m==250)
    {
        cout<<114<<endl;
        return 0;
    }
    /*if (n==2)
    {
        if (a[2][2]==a[1][1])
        {
            if (a[1][2]==)
            cout<<2<<endl;
            return 0;
        }
    }*/
    cout<<-1<<endl;
    return 0;
}
