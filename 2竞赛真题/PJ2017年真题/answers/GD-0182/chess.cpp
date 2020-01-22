#include<bits/stdc++.h>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
long long m,n,i,j,ans,x[1001],y[1001],c[1001],a[101][101],f[101][101],p;
bool k[101][101];
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(i=1;i<=m;i++) for(j=1;j<=m;j++) a[i][j]=-1;
	for(i=1;i<=n;i++){
		cin>>x[i]>>y[i]>>c[i];
		a[x[i]][y[i]]=c[i];
	}
	f[1][1]=0;
	for(i=1;i<=m;i++) for(j=1;j<=m;j++){
	for(p=1;p<=4;p++){
		if(a[i+dx[p]][j+dy[p]]==a[i][j]&&a[i][j]>=0&&a[i+dx[p]][j+dy[p]]>=0) f[i+dx[p]][j+dy[p]]=min(f[i+dx[p]][j+dy[p]],f[i][j]);
		else if(a[i+dx[p]][j+dy[p]]!=a[i][j]&&a[i][j]>=0&&a[i+dx[p]][j+dy[p]]>=0) f[i+dx[p]][j+dy[p]]=min(f[i+dx[p]][j+dy[p]],f[i][j]+1);
		else if(!k[i][j]&&a[i][j]>=0){
			f[i+dx[p]][j+dy[p]]=min(f[i+dx[p]][j+dy[p]],f[i][j]+2);
			a[i+dx[p]][j+dy[p]]=a[i][j];
			k[i+dx[p]][j+dy[p]]=true;
		}
		else{
		cout<<-1;
		return 0;	
		}  
	}	
	}
	cout<<f[m][m];
}
