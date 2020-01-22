#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int m,n;
	int c[102][102]={-1},a[102],b[102];
	cin>>m>>n;
	for(int i=0;i<n;i++)
	    cin>>a[i]>>b[i]>>c[a[i]][b[i]];
	for(int i=0;i<m;i++)
	{
		if((a[i]-a[i-1])>1||(b[i]-b[i-1])>1)
	    {
	        cout<<"-1";
	    }
	    else cout<<"11";
	} 
	fclose(stdin);fclose(stdout);
	return 0;
}
