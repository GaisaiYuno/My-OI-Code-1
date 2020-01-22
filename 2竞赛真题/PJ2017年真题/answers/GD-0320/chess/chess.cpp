#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[101][101],m,n,x[101],y[101],c[101],ans,minn=99999;
bool ff=true;
void dfs(int kx,int ky){
	if (kx==m&&ky==m) {
		minn=min(minn,ans);
		ans=0;
	}
	else{
	if (a[kx+1][ky]!=-1&&a[kx+1][ky]==a[kx][ky]) {
		dfs(kx+1,ky);
	}
	if (a[kx][ky+1]!=-1&&a[kx][ky+1]==a[kx][ky]) {
		dfs(kx,ky+1);
	}
	if (a[kx+1][ky]!=-1&&a[kx+1][ky]!=a[kx][ky]) {
		ans++;
		dfs(kx+1,ky);
	}
	if (a[kx][ky+1]!=-1&&a[kx][ky+1]!=a[kx][ky]) {
		ans++;
		dfs(kx,ky+1);
	}
	if (a[kx][ky+1]==-1&&a[kx+1][ky]==-1&&a[kx+1][ky+1]==a[kx][ky]) {
		ans+=2;
		dfs(kx+1,ky+1);
	}
	if (a[kx][ky+1]==-1&&a[kx+1][ky]==-1&&a[kx+1][ky+1]!=-1&&a[kx+1][ky+1]!=a[kx][ky]) {
		ans+=3;
		dfs(kx+1,ky+1);
	}
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
    for (int i=1;i<=m;i++)
       for (int j=1;j<=m;j++) a[i][j]=-1;
	for (int i=1;i<=n;i++){
		cin>>x[i]>>y[i]>>c[i];
		a[x[i]][y[i]]=c[i];
	}
	for (int i=1;i<=n;i++){
		if (a[x[i]+1][y[i]]==-1&&a[x[i]+1][y[i]+1]==-1&&a[x[i]][y[i]+1]==-1){
			cout<<"-1"<<endl;
			ff=false;
			break;
		}
	}
	if (ff==true){
		dfs(1,1);
		cout<<minn;
	}
}
