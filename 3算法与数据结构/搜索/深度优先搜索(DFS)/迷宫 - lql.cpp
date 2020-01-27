#include<cstdio>
  #include<cstdlib>
 #include<cstring>
 #include<iostream>
 using namespace std;
 #define N 110
  
  char s[N][N];
  int v[N][N],a[4]={1,-1,0,0},b[4]={0,0,1,-1};
 int n,xx,yy;
 
int goit(int x,int y)
 {
     if (x<0||y<0||x>=n||y>=n) return 0;
     if (s[x][y]=='#'||v[x][y]) return 0;
    if (x==xx && y==yy) 
	   return 1;
    v[x][y]=1;
     for (int i=0;i<4;i++)
       if (goit(x+a[i],y+b[i])) 
	      return 1;
     return 0;
 }
 
 int main()
 {

    int T;
    scanf("%d",&T);
    while (T--)
    {
      scanf("%d",&n);
     for (int i=0;i<n;i++)
        scanf("%s",s[i]);
      memset(v,0,sizeof(v));
      int x,y;
      scanf("%d%d%d%d",&x,&y,&xx,&yy);
      int tf=goit(x,y);
       if (tf) printf("YES\n");
       else printf("NO\n");
     }
     return 0;
 }
