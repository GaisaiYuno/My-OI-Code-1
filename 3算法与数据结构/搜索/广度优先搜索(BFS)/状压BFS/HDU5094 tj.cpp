/**
hdu5094 状态压缩+bfs
题目大意：给定一个棋盘，从(1,1)走到(n,m)有的任意两个格子之间的边视为：通路，门，墙。通路可以直接走，门必须早到相应的钥匙，墙永远不能通过。钥匙在一些给定点的
          格子中(同一个格子中可能有多把钥匙)，问采取怎样的走法可以得到最少的移动步数
解题思路：vis[x][y][s]表示状态为s时到达(x,y)点是否已经到达过，s表示钥匙的得到情况的状态。然后进行bfs即可
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int a[53][53][53][53],key[53][53],vis[53][53][1<<11];
int dx[4][2]= {0,1,0,-1,-1,0,1,0};
int n,m,k,p;
struct note
{
    int x,y,dep,s;
    note() {}
    note(int _x,int _y,int _dep,int _s)
    {
        x=_x;
        y=_y;
        dep=_dep;
        s=_s;
    }
};
bool judge(int xx,int yy)
{
    if(xx>=1 && xx<=n && yy>=1 && yy<=m)  return true;
    return false;
}
int bfs()
{
    queue<note>q;
    memset(vis,0,sizeof(vis));
    q.push(note(1,1,0,key[1][1]));
    vis[1][1][key[1][1]]=1;
    while(!q.empty())
    {
        int x=q.front().x;
        int y=q.front().y;
        int dep=q.front().dep;
        int s=q.front().s;
        q.pop();
        if(x==n&&y==m)return dep;
        for(int i=0; i<4; i++)
        {
            int xx=x+dx[i][0];
            int yy=y+dx[i][1];
            int ss=s|key[xx][yy];
            int t=a[x][y][xx][yy];
            int w=1<<(t-1);
            if(judge(xx,yy)&&((t==-1)||(ss&w)&&t!=0)&&!vis[xx][yy][ss])
            {
                vis[xx][yy][ss]=1;
                q.push(note(xx,yy,dep+1,ss));
                //printf("(%d,%d) key=%d step=%d door=%d keys[x][y]=%d\n",xx,yy,nex.key,nex.step+1,door[now.x][now.y][nex.x][nex.y],keys[nex.x][nex.y]); 
            }
        }
    }
    return -1;
}
int main()
{   freopen("data.txt","r",stdin);
    while(~scanf("%d%d%d",&n,&m,&p))
    {
        scanf("%d",&k);
        memset(a,-1,sizeof(a));
        for(int i=0; i<k; i++)
        {
            int x,y,xx,yy,q;
            scanf("%d%d%d%d%d",&x,&y,&xx,&yy,&q);
            a[x][y][xx][yy]=a[xx][yy][x][y]=q;
        }
        int S;
        scanf("%d",&S);
        memset(key,0,sizeof(key));
        while(S--)
        {
            int x,y,g;
            scanf("%d%d%d",&x,&y,&g);
            g--;
            if((key[x][y]&(1<<g))==0)
            {
                key[x][y]|=(1<<g);
            }
        }
        printf("%d\n",bfs());
    }
    return 0;
}

