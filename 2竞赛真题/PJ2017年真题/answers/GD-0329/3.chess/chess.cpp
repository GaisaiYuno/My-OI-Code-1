#include<iostream>
#include<cstdio>
using namespace std;
int c[110][110],f[110][110],m,n,i,j,x,y;
int pp(int x,int y,int nowx,int nowy){
	if (!c[nowx][nowy]) return 999999999;
	else if (c[x][y]) {
		if (c[nowx][nowy]==c[x][y]) return 0;
		return 1;
	}
	return 2;
}
int min(int a,int b,int c,int d){
	if (a>b) a=b;
	if (a>c) a=c;
	if(a>d) a=d;
	return a;
}
bool flag=false;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for (i=1;i<=n;i++){
		cin>>x>>y;
		cin>>c[x][y];
		c[x][y]+=1;
	}
	f[1][1]=0;
	f[1][2]=pp(1,2,1,1),f[2][1]=pp(2,1,1,1);
	for (i=1;i<=m;i++){
		for (j=1;j<=m;j++){
			f[i][j]=min(pp(i,j,i+1,j)+f[i+1][j],pp(i,j,i-1,j)+f[i-1][j],pp(i,j,i,j+1)+f[i][j+1],pp(i,j,i,j-1)+f[i][j-1]);
			/*if (f[i][j]>=9999999999){
				if (flag) {
					cout<<-1;
					return 0;
				}
				else flag=true;
			}
			else flag=false;*/
		}
	}
	if (f[m][m]>=999999999) cout<<-1;
	else cout<<f[m][m];
	return 0;
}
