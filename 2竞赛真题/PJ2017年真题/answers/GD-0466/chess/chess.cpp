#include <bits/stdc++.h>
using namespace std;

int m,n,f[1001][1001],s[101][101] ;
int fx[2]={1,0} , fy[2]={0,1} ;

int main()
{
	freopen ("chess.in" , "r" , stdin) ;
	freopen ("chess.out" , "w" , stdout) ;
	printf ("-1") ; return 0 ;
	memset(f,0x7f,sizeof(f)) ;
	memset(s,-1,sizeof(s)) ;
	scanf ("%d%d" ,&m ,&n) ;
	for (int i=1 ; i<=n ; i++)
	{
		int x,y,c ;
		scanf ("%d%d%d" ,&x ,&y ,&c) ;
		s[x][y]=c ;
	}
	f[1][1]=1 ;
	/*
	int ff=0 , fff=0 ;
	for (int i=2 ; i<=n ; i++)
	{
		if (s[1][i]==-1 && ff!=1)
			f[1][i]=f[1][i-1]+2 , s[1][i]=s[1][i-1] , ff=1 ;
		if (s[i][1]==-1 && fff!=1)
			f[i][1]=f[i-1][1]+2 , s[i][1]=s[i-1][1] , fff=1 ;
		if (s[1][i]!=-1)
			f[1][i]=f[1][i-1]+(s[1][i]==s[1][i-1] ? 0 : 1) , ff=0 ;
		if (s[i][1]!=-1)
			f[i][1]=f[i-1][1]+(s[i][1]==s[i-1][1] ? 0 : 1) , fff=0 ;
	}
	*/
	int ff=0 ;
	for (int i=1 ; i<=m ; i++)
		for (int j=1 ; j<=m ; j++)
		{
			if (i!=1 || j!=1)
			{
				if (ff==1)
			{
				int kk=0 ;
				for (int ii=1 ; ii<3 ; ii++)
					if (s[i+fx[ii]][j+fy[ii]]!=-1) kk=1 ;
				if (kk==0) {printf ("-1") ; return 0 ;}
			}
			if (s[i][j]==-1 && ff!=1)
			{
				f[i][j]=min(f[i][j] , f[i-1][j]+2) ;
				f[i][j]=min(f[i][j] , f[i][j-1]+2) ;
//				f[i][j]=min(f[i-1][j] , f[i][j-1])+2 ;
				s[i][j]=(f[i-1][j]<f[i][j-1] ? s[i-1][j] : s[i][j-1]) ;
				ff=1 ;
			}
			if (s[i][j]!=-1)
			{
				f[i][j]=min(f[i][j] , f[i-1][j]+(s[i][j]==s[i-1][j] ? 0 : 1)) ;
				f[i][j]=min(f[i][j] , f[i][j-1]+(s[i][j]==s[i][j-1] ? 0 : 1)) ;
				ff=0 ;
			}
		}//f[i][j]=min(f[i-1][j]+(s[i][j]==s[i-1][j] ? 0 : 1) , f[i][j-1]+(s[i][j]==s[i][j-1] ? 0 : 1)) , ff=0 ;
		}
	printf ("%d" ,f[m][m]) ;
}
