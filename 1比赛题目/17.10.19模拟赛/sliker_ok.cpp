#include<iostream>
#include<cstdio>
#define inf 0x7fffffff
using namespace std;
int n,m,bx,by,ex,ey;
int t,w;
int xx[4]={1,-1,0,0},yy[4]={0,0,1,-1};
char ch[55];
bool mp[55][55];
int tim[55][55];
struct data{int x;
int y;
int step;
int f;
}q[10005];
void input(){
	cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            tim[i][j]=inf;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",ch);
        for(int j=1;j<=m;j++)
        {
            if(ch[j-1]=='D'){ex=i;ey=j;}
            if(ch[j-1]=='S'){bx=i;by=j;}
            if(ch[j-1]=='X')mp[i][j]=1;
            if(ch[j-1]=='*'){q[w].x=i;q[w].y=j;tim[i][j]=0;w++;}
        }
    }
}
void bfs1()
{
     while(t!=w)
     {
         int x=q[t].x,y=q[t].y;t++;
         for(int i=0;i<4;i++)
         {
             int nowx=x+xx[i],nowy=y+yy[i];
             if(nowx>n||nowy>m||nowx<1||nowy<1||mp[nowx][nowy])continue;
             if((nowx==ex&&nowy==ey)||tim[nowx][nowy]!=inf)continue;
             tim[nowx][nowy]=tim[x][y]+1;
             q[w].x=nowx;q[w].y=nowy;w++;
         }
     }
}
void bfs2()
{
     t=0,w=1;q[0].x=bx;q[0].y=by;
     while(t!=w)
     {
               
         int x=q[t].x,y=q[t].y,step=q[t].step;t++;
         for(int i=0;i<4;i++)
         {
             int nowx=x+xx[i],nowy=y+yy[i];
             if(nowx>n||nowy>m||nowx<1||nowy<1||mp[nowx][nowy]||step+1>=tim[nowx][nowy])
                 continue;
             mp[nowx][nowy]=1;
             if(nowx==ex&&nowy==ey){printf("%d",step+1);return;}
             q[w].x=nowx;q[w].y=nowy;q[w].step=step+1;w++;
         }
     }
     printf("ORZ hzwer!!!");
}
int main()
{
    freopen("slikar.in","r",stdin);
    freopen("slikar.out","w",stdout);
	input();
    bfs1();
    bfs2();
    return 0;
}
