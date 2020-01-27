#include<bits/stdc++.h>
using namespace std;
#define MAXR 60
#define MAXN 1005 
const int nx[4] = {1,0,-1,0};
const int ny[4] = {0,1,0,-1};
char a[MAXR][MAXR];//地图 
int b[MAXR][MAXR][MAXN];//一个点是否在某时走过 
int r,c,n;
char d[MAXN][10]; 
int sx,sy;
inline void rd()//输入 
{
    scanf("%d%d",&r,&c);
    for(int i = 1; i <= r; i ++)
        scanf("%s",a[i]+1);
    scanf("%d",&n);
    for(int i = 1; i <= n; i ++)
    {
        scanf("%s",d[i]);
     }
     for(int i = 1; i <= r; i ++)//寻找出发点 
         for(int j = 1; j <= c; j ++)
        {
            if(a[i][j] == '*')
            {
                sx = i;
                sy = j;
                break;
            }
         } 
    a[sx][sy] = '.';
}
bool zj(int x,int y)//是否越界 
{
    return x<=r&&y<=c&&x>0&&y>0;
}
int hua(char x) 
{
    if(x == 'N')//上 
        return 2;
    if(x == 'S')//下 
        return 0;
    if(x == 'E')//左 
        return 1;
    if(x == 'W')//右 
        return 3;
}
void dfs(int x,int y,int s)//深搜（x，y为x行y列，记录仪的第s个方向） 
{
    if(b[x][y][s])//去重，没有这个30分  
        return;
    b[x][y][s] = 1;//标记
    if(s == n + 1)
    {
        a[x][y] = '*';
        return;
    }
    else
    {
        int ex = x,ey = y,p;
        p = hua(d[s][0]);
        ex += nx[p];
        ey += ny[p];
        while(zj(ex,ey)&&a[ex][ey] != 'X')
        {
            dfs(ex,ey,s+1);
            ex += nx[p];
            ey += ny[p];
        }
    }
}
int main()
{
    rd();
    dfs(sx,sy,1);
    for(int i = 1; i <= r; i ++)//输出答案 
        printf("%s\n",a[i]+1);
    return 0;
 } 

