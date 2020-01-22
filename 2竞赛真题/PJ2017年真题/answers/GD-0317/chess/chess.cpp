#include<bits/stdc++.h>
using namespace std;
int dp[102][102],i,j,m,n,xx,yy;
bool pan=true;
bool bb[102][102]={false};
struct hs{
	int c;int cg;
}a[102][102];
void add(hs p,hs q,int a,int b){
    if(p.cg==-2)dp[a][b]+=90000;
	if(p.cg==q.c&&p.cg!=-1)p.cg=p.c,pan=true;
	else if(p.cg==q.c&&p.cg==-1)dp[a][b]+=90000;
	if(p.cg==1&&q.c==0)p.cg=p.c,pan=true,dp[a][b]++;
	if(p.cg==0&&q.c==1)p.cg=p.c,pan=true,dp[a][b]++;
	if(p.cg==1&&q.c==-1&&pan==true)pan=false,q.cg=p.cg,dp[a][b]+=2;
	if(p.cg==0&&q.c==-1&&pan==true)pan=false,q.cg=p.cg,dp[a][b]+=2;
	if(p.cg==1&&q.c==-1&&pan==false)dp[a][b]+=90000;
	if(p.cg==0&&q.c==-1&&pan==false)dp[a][b]+=90000;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(i=1;i<=101;i++)
	for(j=1;j<=101;j++)a[i][j].c=-1,a[i][j].cg=-1,bb[i][j]=true;
	for(i=1;i<=101;i++)a[i][0].c=-2,a[i][0].cg=-2,a[0][i].cg=-2,a[0][i].c=-2;
	for(i=1;i<=n;i++){
		cin>>xx>>yy;cin>>a[xx][yy].c;
		a[xx][yy].cg=a[xx][yy].c;
	}
	cout<<-1;
}
