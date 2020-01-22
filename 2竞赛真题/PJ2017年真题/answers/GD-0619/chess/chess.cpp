#include<bits/stdc++.h>
using namespace std;
int a[110][110],f[110][110],k[110][110],p,n,m,x,y,v;
int main(){
	freopen("chess.in.txt","r",stdin);
	freopen("chess.out.txt","w",stdout);
	memset(f,21000,sizeof(f));
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&x,&y,&v);
		if(v==0) a[x][y]=2;
		else a[x][y]=1;
	}
	a[1][0]=1; a[0][1]=2; f[1][0]=0; f[0][1]=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]!=0){
				if(a[i][j-1]==0){
					if(k[i][j-1]==a[i][j]) p=0;
					if(k[i][j-1]!=a[i][j]) p=1;
				}
				else if(a[i][j-1]==a[i][j]) p=0;
				else if(a[i][j-1]!=a[i][j]) p=1;
				f[i][j]=min(f[i][j],f[i][j-1]+p);
				
				if(a[i-1][j]==0){
					if(k[i-1][j]==a[i][j]) p=0;
					if(k[i-1][j]!=a[i][j]) p=1;
				}
				else if(a[i-1][j]==a[i][j]) p=0;
				else if(a[i-1][j]!=a[i][j]) p=1;
				f[i][j]=min(f[i][j],f[i-1][j]+p);
			}
			else if(a[i][j]==0){
				if(a[i][j-1]!=0){
					if(f[i][j-1]+2<f[i][j]){
						f[i][j]=f[i][j-1]+2;
						k[i][j]=a[i][j-1];
					}
				} 
				if(a[i-1][j]!=0){
					if(f[i-1][j]+2<f[i][j]){
						f[i][j]=f[i-1][j]+2;
						k[i][j]=a[i-1][j];
					}
				} 
			}
		}
	}
	if(f[m][m]<21000) cout<<f[m][m];
	else cout<<-1;
}
