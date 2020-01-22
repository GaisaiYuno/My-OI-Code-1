#include<iostream>
#include<fstream>
using namespace std;
int m,n,x,y,c,k;
int sum;
int a[23][23];
bool pd[23][23];
int main()
{
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    cin>>m>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>x>>y>>c;
        a[x][y]=c;
        if (c==0)
        a[x][y]=2;
    }
    x=1;y=1;
    k=a[1][1];
    int h=0;
    pd[1][1]=true;
    bool p;
    while (x!=m&&y!=m)
    {
        h++;
        if (!p&&(a[x][y-1]==0||pd[x][y-1]==true)&&(a[x][y+1]==0||pd[x][y+1]==true)&&(a[x+1][y]==0||pd[x+1][y]==true)&&(a[x-1][y]==0||pd[x-1][y]==true))
        {
            y++;
            if ((a[x][y-1]==0||pd[x][y-1]==true)&&(a[x][y+1]==0||pd[x][y+1]==true)&&(a[x+1][y]==0||pd[x+1][y]==true)&&(a[x-1][y]==0||pd[x-1][y]==true))
            {
                y--;x++;
            }
            if ((a[x][y-1]==0||pd[x][y-1]==true)&&(a[x][y+1]==0||pd[x][y+1]==true)&&(a[x+1][y]==0||pd[x+1][y]==true)&&(a[x-1][y]==0||pd[x-1][y]==true))
            {
                x--;
                cout<<-1;
                return 0;
            }
            sum=sum+2;
            p=true;
        }
        else
        {
            if (p)
            p=false;
            if (a[x+1][y]!=0&&x!=m&&pd[x+1][y]==false)
        {
            x=x+1;
            if (k!=a[x][y])
            sum++;
            k=a[x][y];
            pd[x][y]=true;
        }
        else
        {
            if (a[x][y+1]!=0&&y!=m&&pd[x][y+1]==false)
            {
               y=y+1;
               if (k!=a[x][y])
                sum++;
                k=a[x][y];
                pd[x][y]=true;
            }
            else
            {
            if (a[x-1][y]!=0&&x!=1&&pd[x-1][y]==false)
            {
                 x=x-1;
                 if (k!=a[x][y])
                 sum++;
                 k=a[x][y];
                 pd[x][y]=true;
            }
             else
             {
            if (a[x][y-1]!=0&&y!=1&&pd[x][y-1]==false)
             {
                     y=y-1;
                     if (k!=a[x][y-1])
                     sum++;
                     k=a[x][y];
                     pd[x][y]=true;
             }
            }
            }
        }
    }
        if(p&&(a[x][y-1]==0||pd[x][y-1]==true)&&(a[x][y+1]==0||pd[x][y+1]==true)&&(a[x+1][y]==0||pd[x+1][y]==true)&&(a[x-1][y]==0||pd[x-1][y]==true))
        {
            cout<<-1;
            return 0;
       }
    }
    if (a[m][m]!=k)
    sum++;
    cout<<sum;
    return 0;
}
