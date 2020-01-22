#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

const int dirx[4]={0,0,1,-1};
const int diry[4]={1,-1,0,0};

struct jgt{int x,y,s,c;bool f;}opens[666666];

int n,m,x,y,c,map[105][105];
bool p[105][105];

void bfs()
{
  int head=1,tail=1,xx,yy,ss,t;bool tt;
  opens[1].x=1;opens[1].y=1;opens[1].s=0;opens[1].c=map[1][1];opens[1].f=true;
  p[1][1]=true;
  
  while (head<=tail)
  {
    for (int i=0;i<4;i++)
    {
	  xx=opens[head].x+dirx[i];
	  yy=opens[head].y+diry[i];
	  ss=opens[head].s;
	  
	  if (xx<1||yy<1||xx>n||yy>n||p[xx][yy]) continue;
	  if (map[xx][yy]==0&&!opens[head].f) continue;
	  
	  p[xx][yy]=true;
	  tail++;
	  opens[tail].x=xx;
 	  opens[tail].y=yy;
	  if (map[xx][yy]==0)
	    {opens[tail].s=ss+2;opens[tail].f=false;opens[tail].c=map[opens[head].x][opens[head].y];}
	      else
	  if (map[xx][yy]!=map[opens[head].x][opens[head].y])
	  {
	     if (opens[head].f)
		   {opens[tail].s=ss+1;opens[tail].f=true;}
		     else 
			 {
			   if (map[xx][yy]!=opens[head].c)
			     opens[tail].s=ss+1;
				   else opens[tail].s=ss;
			   opens[tail].f=true;
			 }
	  }
	    else {opens[tail].s=ss;opens[tail].f=true;}
	       
	  if (xx==n&&yy==n) {cout<<opens[tail].s;return;}
	  
	  int tail_=tail;
	  while (opens[tail_].s<opens[tail_-1].s)
	  {
	    t=opens[tail_].x;opens[tail_].x=opens[tail_-1].x;opens[tail_-1].x=t;
	    t=opens[tail_].y;opens[tail_].y=opens[tail_-1].y;opens[tail_-1].y=t;
	    t=opens[tail_].s;opens[tail_].s=opens[tail_-1].s;opens[tail_-1].s=t;
	    t=opens[tail_].c;opens[tail_].c=opens[tail_-1].c;opens[tail_-1].c=t;
	    tt=opens[tail_].f;opens[tail_].f=opens[tail_-1].f;opens[tail_-1].f=tt;
	    tail_--;
	  }
	}
	head++;
  }
  /*
  int ans=2147483647;
  for (int i=1;i<=tail;i++) cout<<opens[i].x<<' '<<opens[i].y<<endl;
    if (opens[i].x==n&&opens[i].y==n)
      ans=min(ans,opens[i].s);
  
  if (ans!=2147483647) cout<<ans; else*/
  cout<<-1;
}

int main()
{
  freopen("chess.in","r",stdin);
  freopen("chess.out","w",stdout);
  
  cin>>n>>m;
  
  memset(map,0,sizeof(map));
  memset(p,false,sizeof(p));
  while (m--)
  {
    cin>>x>>y>>c;
    map[x][y]=c+1;
  }
    
  bfs();
  return 0;
}
