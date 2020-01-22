#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int ny[2]={0,1};
int nx[2]={1,0};
int co[103][103];
int ju[103][103];
int anss=2147483647;
int m,n;
void dfs(int ox,int oy,int cu,int oc,int mo,int om,int ans,int oox,int ooy)
{
   if(ox<1||ox>m||oy<1||oy>m) return ;
   if(cu!=oc&&cu>=0&&oc>=0) ans++;
   if(cu!=oc&&oc>=0&&cu<0)
   {
   	 if(mo==0) return ;
	 else 
	  { mo=0; ans=ans+2; cu=oc; om=1;} 
   }
   if(om!=1) mo=1;
   if(ox==m&&oy==m) 
   {
   	anss=min(ans,anss);
   	return ;
   }
   for(int i=0;i<=1;i++)
    {	
    if(ox+nx[i]==oox&&oy+ny[i]==ooy)
    continue;
    dfs(ox+nx[i],oy+ny[i],co[ox+nx[i]][oy+ny[i]],cu,mo,0,ans,ox,oy);		
    }
}
int main()
{
	freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    for(int y=1;y<=m;y++)
    co[i][y]=-1;
    int x,y,c;
    for(int i=1;i<=n;i++)
    {
    	cin>>x>>y>>c;
    	co[x][y]=c;
    }
    ju[1][1]=1;
    dfs(1,1,co[1][1],co[1][1],1,0,0,0,0);
    if(anss==2147483647)
    {
    	cout<<-1;
    	return 0;
    }
    cout<<anss;
	return 0;
}

