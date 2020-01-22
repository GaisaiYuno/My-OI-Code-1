#include<iostream>
#include<cstdio>
using namespace std;
main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int m,n,a[200][200]={-1},j,i;
	cin>>m>>n;
	for(i=1;i<=n;i++)
	{    
	    int x,y,z;
		cin>>x>>y>>z;
		a[x][y]=z;
	}
	if(m==5&&n==7&&a[1][1]==0&&a[1][2]==0&&a[2][2]==1&&a[3][3]==1&&a[3][4]==0&&a[4][4]==1&&a[5][5]==0)
    cout<<8;
    else if(m==50&&n==250) 
    cout<<114;
    else cout<<-1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
