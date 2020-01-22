#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int m,n,x,y,c,s[102][102],money=0;
bool YN=false,YN1=false;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(s,2,sizeof(s));
	scanf("%d%d",&m,&n);
	for(int j=1;j<=n;j++)
	{
		scanf("%d%d%d",&x,&y,&c);
		s[x][y]=c;
	}
	x=1;
	y=1;
	while(x+1<=m && y+1<=m)
	{
		YN1=false;
		if(s[x+1][y]==0 || s[x+1][y]==1 || s[x+1][y]==3 || s[x+1][y]==4)
		{
			if(s[x+1][y]%2==s[x][y]%2)
			{
				x+=1;
				YN1=true;
			}
			else
			{
				x+=1;
				money+=1;
				YN1=true;
			}
		}
		else if(s[x+1][y]==2 && YN1==false && s[x][y]!=3 && s[x][y]!=4)
		{
			if(s[x][y]==1) s[x+1][y]=3;
			if(s[x][y]==0) s[x+1][y]=4;
			x+=1;
			money+=2;
			YN1=true;
		}
		else if((s[x][y+1]==0 || s[x][y+1]==1 || s[x][y+1]==3 || s[x][y+1]==4) && YN1==false)
		{
			if(s[x][y+1]%2==s[x][y+1]%2)
			{
				y+=1;
				YN1=true;
			}
			else
			{
				y+=1;
				money+=1;
				YN1=true;
			}
		}
		else if(s[x][y+1]==2 && YN1==false && s[x][y]!=3 && s[x][y]!=4)
		{
			if(s[x][y]==1) s[x][y+1]=3;
			if(s[x][y]==2) s[x][y+1]=4;
			y+=1;
			money+=2;
			YN1=true;
		}
		else if (YN1==false) break;
		if (x==m && y==m) 
		{
			YN=true;
			break;
		}
	}
	if(YN==true) printf("%d",money);
	x=1;
	y=1;
	YN1=false;
	money=0;
	while(x+1<=m && y+1<=m && YN==false)
	{
		YN1=false;
		if((s[x][y+1]==0 || s[x][y+1]==1 || s[x][y+1]==3 || s[x][y+1]==4) && YN1==false)
		{
			if(s[x][y+1]%2==s[x][y+1]%2)
			{
				y+=1;
				YN1=true;
			}
			else
			{
				y+=1;
				money+=1;
				YN1=true;
			}
		}
		else if(s[x][y+1]==2 && YN1==false && s[x][y]!=3 && s[x][y]!=4)
		{
			if(s[x][y]==1) s[x][y+1]=3;
			if(s[x][y]==0) s[x][y+1]=4;
			y+=1;
			money+=2;
			YN1=true;
		}
		if(s[x+1][y]==0 || s[x+1][y]==1 || s[x+1][y]==3 || s[x+1][y]==4)
		{
			if(s[x+1][y]%2==s[x][y]%2)
			{
				x+=1;
				YN1=true;
			}
			else
			{
				x+=1;
				money+=1;
				YN1=true;
			}
		}
		if(s[x+1][y]==2 && YN1==false && s[x][y]!=3 && s[x][y]!=4)
		{
			if(s[x][y]==1) s[x+1][y]=3;
			if(s[x][y]==2) s[x+1][y]=4;
			x+=1;
			money+=2;
			YN1=true;
		}
		else if (YN1==false)
		{
			printf("-1");
			break;
		}
		if (x==m && y==m) 
		{
			YN=true;
			printf("%d",money);
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
