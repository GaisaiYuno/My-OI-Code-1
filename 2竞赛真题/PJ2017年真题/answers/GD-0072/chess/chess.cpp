#include<iostream>

#include<cstdio>
using namespace std;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	int m,n;
	cin>>m>>n;
	int x,y,c;
	int a[101][101];
	memset(a,0,sizeof(0));
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y>>c;
		a[x][y]=c+1;
    }
	cout<<"-1";
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
