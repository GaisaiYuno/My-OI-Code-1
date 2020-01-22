#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int m,n,ans=0;
int a[111][111],d[111][111];
bool f[111][111],ff[111][111];
int main() {
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    int i,j;
    scanf("%d%d",&n,&m);
    memset(f,false,sizeof(f));memset(ff,false,sizeof(ff));memset(a,-1,sizeof(a));memset(d,0x7f,sizeof(d));
    for(i=1;i<=m;i++) {
        int x,y,c;
        scanf("%d%d%d",&x,&y,&c);
        a[x][y]=c;ff[x][y]=true;
    }
    f[1][1]=true;
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++) {
        if(i!=1||j!=1) {
            if(a[i][j]!=-1){if(f[i+1][j]||f[i-1][j]||f[i][j-1]||f[i][j+1])f[i][j]=true;}else {
                if((f[i+1][j]&&a[i+1][j]!=-1)||(f[i-1][j]&&a[i-1][j]!=-1)||(f[i][j+1]&&a[i][j+1]!=-1)||(f[i][j-1]&&a[i][j-1]!=-1))f[i][j]=true;
            }
        }
    }
    if(f[n][n]==false) {
        printf("-1\n");return 0;
    }
    d[1][1]=0;
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++) {
        if((i!=1||j!=1)&&f[i][j]==true) {
            int q,q1,q2,q3,w1=0x7f,w2=0x7f,w3=0x7f,w4=0x7f,f1,f2,f3,f4;
            f1=f2=f3=f4=false;
            if(f[i][j+1]==true&&(ff[i][j]||ff[i][j+1])) {
                if(a[i][j]!=-1&&a[i][j+1]!=-1)q=abs(a[i][j]-a[i][j+1]);else q=2,f1=true;w1=q+d[i][j+1];
            }
            if(f[i][j-1]==true&&(ff[i][j]||ff[i][j-1])){if(a[i][j]!=-1&&a[i][j-1]!=-1)q1=abs(a[i][j]-a[i][j-1]);else q1=2,f2=true;
                w2=q1+d[i][j-1];
            }
            if(f[i+1][j]==true&&(ff[i][j]||ff[i+1][j])){if(a[i][j]!=-1&&a[i+1][j]!=-1)q2=abs(a[i][j]-a[i+1][j]);else q2=2,f3=true;
                w3=q2+d[i+1][j];
            }
            if(f[i-1][j]==true&&(ff[i][j]||ff[i-1][j])){if(a[i][j]!=-1&&a[i-1][j]!=-1)q3=abs(a[i][j]-a[i-1][j]);else q3=2,f4=true;
                w4=q3+d[i-1][j];
            }
            d[i][j]=min(d[i][j],min(min(w1,w2),min(w3,w4)));
            if(d[i][j]==w1&&f1)a[i][j]=a[i][j+1];else
            if(d[i][j]==w2&&f2)a[i][j]=a[i][j-1];else
            if(d[i][j]==w3&&f3)a[i][j]=a[i+1][j];else
            if(d[i][j]==w4&&f4)a[i][j]=a[i-1][j];
        }
    }
    printf("%d\n",d[n][n]);
}
