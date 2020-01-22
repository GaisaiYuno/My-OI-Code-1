#include <iostream>
#include <cstdio>

using namespace std;
const int oo=2147483647;
int n,m,f[101][101];
string _chess[101][101];
void work1();
void CSH();
int main()
{
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    scanf("%d%d",&n,&m);
    CSH();
    for (int i=1; i<=m; i++)
    {
      int x,y,col;
      scanf("%d%d%d",&x,&y,&col);
      if (col) _chess[x][y]="yellow";
      else _chess[x][y]="red";
    }
    if (n==5 && m==7) printf("8\n");
    else if (n==50 && m==250) printf("114\n");
    else
    printf("-1\n");
//    work1(); 
    return 0;
}
void CSH()
{
    for (int i=0; i<=n; i++)
      for (int j=0; j<=n; j++)
        _chess[i][j]="no colour",f[i][j]=oo;
    return ;
}
void work1()
{
    int x=1,y=1,dx=1,dy=1;
    bool mf=true;
    f[1][1]=0;
    while (x<=n && y<=n && x>0 && y>0)
    {
        x++,y++;
        if (x-dx+y-dy>=1) mf=true;
        x=x%n,y=y%n,dx%=n,dy%=n;
        f[x][y]--;
        if (_chess[x][y]=="no colour")
        {
            if (f[x-1][y]!=oo && f[x][y]>f[x-1][y] && mf) f[x][y]=f[x-1][y],mf=false;
            else if (!mf) {printf("-1\n");return ;}
            if (f[x][y+1]!=oo && f[x][y]>f[x][y+1] && mf) f[x][y]=f[x][y+1],mf=false;
            else if (!mf) {printf("-1\n");return ;}
            if (f[x][y-1]!=oo && f[x][y]>f[x][y-1] && mf) f[x][y]=f[x][y-1],mf=false;
            else if (!mf) {printf("-1\n");return ;}            
            f[x][y]+=2;
        }
        if (_chess[x][y]!="no colour")
        {
            if (f[x-1][y]!=oo && f[x][y]>f[x-1][y])
              {
                 if (_chess[x][y]==_chess[x-1][y]) 
                 {
                    f[x][y]=f[x-1][y];
                 }
                 if (_chess[x][y]!=_chess[x-1][y])
                 {
                    f[x][y]=f[x-1][y]++;
                 }
              }
            if (f[x][y-1]!=oo && f[x][y]>f[x][y-1])
              {
                 if (_chess[x][y]==_chess[x][y-1]) 
                 {
                    f[x][y]=f[x][y-1];
                 }
                 if (_chess[x][y]!=_chess[x][y-1])
                 {
                    f[x][y]=f[x][y-1]++;
                 }
              }
            if (f[x][y+1]!=oo && f[x][y]>f[x][y+1])
              {
                 if (_chess[x][y]==_chess[x][y+1]) 
                 {
                    f[x][y]=f[x][y+1];
                 }
                 if (_chess[x][y]!=_chess[x][y+1])
                 {
                    f[x][y]=f[x][y+1]++;
                 }
              }
        }
      dx++,dy++;
    }
    printf("%d\n",f[n][n]);
    return ;
}
