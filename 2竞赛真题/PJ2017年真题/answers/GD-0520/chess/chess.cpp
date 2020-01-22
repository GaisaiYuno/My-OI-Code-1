#include<iostream>
#include<cstdio>
using namespace std;
const int gs[4]={1,-1,0,0};
const int gz[4]={0,0,1,-1};
int m,n,i,j,h,l,colour,jl[1001][1001],s[1001][1001];
void mdzz(int xx,int yy,int tt,int mf)
{
	int hh,ll;
	if (xx<1||yy<1||xx>m||yy>m||tt>=s[xx][yy]||mf==0&&jl[xx][yy]==0) return;
	s[xx][yy]=tt;
	for (int i=0; i<=3; i++)
	 {
	 	hh=xx+gs[i];
		ll=yy+gz[i];
		if (hh>=1&&hh<=m&&ll>=1&&ll<=m)
		{
		if (jl[hh][ll]==0)
		{
			if (mf==1) {jl[hh][ll]=jl[xx][yy];mdzz(hh,ll,tt+2,0);jl[hh][ll]=0;}
	    } else
	    if (jl[hh][ll]==jl[xx][yy]) mdzz(hh,ll,tt,1); else
	    mdzz(hh,ll,tt+1,1);
   		}
	 }
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for (i=1; i<=n; i++)
	 {
	 	cin>>h>>l>>colour;
	 	jl[h][l]=colour+1;
     }
    for (i=1; i<=m; i++)
     for (j=1; j<=m; j++)
      s[i][j]=2147483647;
    mdzz(1,1,0,1);
    if (s[m][m]!=2147483647) cout<<s[m][m]; else cout<<-1;
	return 0;
}
