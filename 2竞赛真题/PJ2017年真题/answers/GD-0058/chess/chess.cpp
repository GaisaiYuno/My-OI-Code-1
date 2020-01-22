#include<cstdio>
#include<algorithm>
using namespace std;
int map[100][100]={2};
int jb(int m,int h,int l)
{
	int a,b,c,d,e,f,ans=0;
	if(h==m-1&&l==m-1)
	return ans;
	if(map[h+1][l+1]==2&&map[h+1][l]==2&&map[h][l+1]==2&&map[h+2][l]==2&&map[h][l+2]==2)
	return ans=100000;
		if(map[h+1][l]!=2)
		{	if(map[h+1][l]==map[h][l])
			{	
			a=jb(m,h+1,l);
			}
			else
			{
		b=jb(m,h+1,l)+1;
			}
		}
		else
		{
			e=jb(m,h+1,l)+2;
		}
		if(map[h][l+1]!=2)
		{	if(map[h][l+1]==map[h][l])
				{
					c=jb(m,h,l+1);
				}
				else
				{
					d=jb(m,h,l+1)+1;
				}
			}
		 else
		 {
		 	f=jb(m,h,l+1)+2;
		 }
		ans+=min(min(min(a,b),min(c,d)),min(e,f));
	return ans;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int a,b,c,m,n,ans;
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		map[a-1][b-1]=c;
	}
	printf("-1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
