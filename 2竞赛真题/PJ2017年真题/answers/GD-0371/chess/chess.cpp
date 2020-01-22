#include<iostream>
#include<cstdio>
using namespace std;
int i,m,n,x,y,c[101][101],c1,ans=0,j,k=1;
int main()
{
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
	cin>>m>>n;
    for(i=1;i<=m;i++)
    for(j=1;j<=m;j++)c[i][j]=-1;
    for(i=1;i<=n;i++)
    {
    	cin>>x>>y>>c1;
    	c[x][y]=c1;
    }
    x=1;y=1;
    while((m>=x)&&(m>=y))
    {
    	if(c[x][y]==c[x][y+1]){y++;k=1;}
    	else if(c[x][y]==c[x+1][y]){x++;k=1;}
    	else if(c[x][y+1]!=-1){y++;ans+=1;k=1;}
    	else if(c[x+1][y]!=-1){x++;ans+=1;k=1;}
    	else if(k!=0){c[x][y+1]=c[x][y];y++;ans+=2;k=0;}
    	else {cout<<-1;return 0;}
    }
    cout<<ans;
	return 0;
}

