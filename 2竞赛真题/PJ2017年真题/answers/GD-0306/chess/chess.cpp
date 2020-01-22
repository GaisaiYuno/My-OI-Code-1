#include<iostream>
#include<cstdio>
#include<algorithm>
#include<math.h>
#include<string>
#include<cstring>
using namespace std;
long n,m,a,b,c,f[1005][1005],iii;
int ff(int x_,int y_,int money,int magic,int colour)
{
	if(f[x_][y_]!=colour&&f[x_][y_]!=0){money++;magic=0;colour=f[x_][y_];}
	if(f[x_][y_]==0&&magic==1&&(x_!=m||y_!=m))return 2147480000;
	if(f[x_][y_]==0){magic=1;money+=2;}
	if(x_==m&&y_==m)return money;
	return min(ff(x_+1,y_,money,magic,colour),ff(x_,y_+1,money,magic,colour));
	
	return 0;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{cin>>a>>b>>c;f[a][b]=c+1;}
	iii=ff(1,1,0,0,f[1][1]);
	if(iii==2147480000)cout<<"-1";
	else cout<<iii;
	return 0;
}

