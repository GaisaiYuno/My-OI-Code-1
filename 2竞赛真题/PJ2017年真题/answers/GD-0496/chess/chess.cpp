#include<cstdio>
using namespace std;
int s[101][101]={{0}};
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int m,n,x,y,color,count=0;
	scanf("%d%d", &m,&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d", &x, &y,&color);
		s[x][y]=color;
	}
	color=s[0][0];
	x=0;y=0;
	while(x<m && y<m)
	{
		if(s[x][y+1]==s[x][y] && s[x][y+1]!=0)
		y++;
		else if(s[x+1][y]==s[x][y] && s[x+1][y]!=0)
		x++;
		else
		{
			if(s[x+1][y]==0 && s[x][y+1]==0)
			count+=2;
			else 
			count++;
			x++;
		}
	}
	printf("-1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
