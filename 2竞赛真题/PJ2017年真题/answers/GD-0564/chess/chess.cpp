#include<algorithm>
#include<iostream>
#include<fstream>
#include<cstdio>
#include<cmath>
using namespace std;
long long n,m,x,y,colour,temp;
int p[150][150][4];
char c[150][150];
void t(char x,char y,int money,char use,char last)
{
  if (money>=p[x][y][last])
   return ;
  if (x==0||y==0||x>m||y>m)
   return ;
  p[x][y][last]=money;

  if(c[x+1][y]==last)
                 t(x+1,y,money  ,0,last);
  if(c[x+1][y]==0&&!use)
   {if (last!=1) t(x+1,y,money+3,1,   1);
    else t(x+1,y,money+2,1,1);
    if (last!=2) t(x+1,y,money+3,1,   2);
	else         t(x+1,y,money+2,1,   2);}
  if (c[x+1][y]!=0&&c[x+1][y]!=last)
                 t(x+1,y,money+1,0,c[x+1][y]);

  if(c[x-1][y]==last)
                 t(x-1,y,money  ,0,last);
  if(c[x-1][y]==0&&!use)
   {if (last!=1) t(x-1,y,money+3,1,   1);
    else         t(x-1,y,money+2,1,   1);
    if (last!=2) t(x-1,y,money+3,1,   2);
	else         t(x-1,y,money+2,1,   2);}
  if (c[x-1][y]!=0&&c[x-1][y]!=last)
                 t(x-1,y,money+1,0,c[x-1][y]);

  if(c[x][y-1]==last)
                 t(x,y-1,money  ,0,last);
  if(c[x][y-1]==0&&!use)
   {if (last!=1) t(x,y-1,money+3,1,   1);
    else         t(x,y-1,money+2,1,   1);
    if (last!=2) t(x,y-1,money+3,1,   2);
	else         t(x,y-1,money+2,1,   2);}
  if (c[x][y-1]!=0&&c[x][y-1]!=last)
                 t(x,y-1,money+1,0,c[x][y-1]);  

  if(c[x][y+1]==last)
                 t(x,y+1,money  ,0,last);
  if(c[x][y+1]==0&&!use)
   {if (last!=1) t(x,y+1,money+3,1,   1);
    else         t(x,y+1,money+2,1,   1);
    if (last!=2) t(x,y+1,money+3,1,   2);
	else         t(x,y+1,money+2,1,   2);}
  if (c[x][y+1]!=0&&c[x][y+1]!=last)
                 t(x,y+1,money+1,0,c[x][y+1]);
}
int main()
{
  freopen("chess.in","r",stdin);
  freopen("chess.out","w",stdout);
  cin>>m>>n;
  for (int i=1;i<=n;i++)
   {scanf("%d%d%d",&x,&y,&colour);
    c[x][y]=colour+1;}
  for (int i=1;i<=m;i++)
   for (int j=1;j<=m;j++)  
    {p[i][j][1]=m*m*m;p[i][j][2]=m*m*m;}
  t(1,1,0,0,c[1][1]);
  temp=min(p[m][m][1],p[m][m][2]);
  if (temp==m*m*m)
   {cout<<"-1";return 0;} 
  cout<<temp;
  return 0;
}
