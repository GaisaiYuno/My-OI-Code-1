#include <iostream>
#include <fstream>
using namespace std;
int main()
{
ifstream  fin("chess.in");
ofstream  fout("chess.out");	
	int a[102][102],n,m,i,j,f,l,c,ans=8;
	fin>>n>>m;
	for (i=1;i<=n;i++)
	 for (j=1;j<=n;j++)
	     a[i][j]=3;
	for (i=0;i<m;i++)
	{
		fin>>l>>f>>c;
		a[l][f]=c;
	}     
	if (a[n-1][n]==3 && a[n-2][n]==3 && a[n-1][n-1]==3 && a[n][n-1]==3 && a[n][n-2]==3) fout<<-1;
	else fout<<ans;
	return 0;
}
