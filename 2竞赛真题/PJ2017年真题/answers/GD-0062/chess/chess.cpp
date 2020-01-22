#include<bits/stdc++.h>
using namespace std;
int fx[8][2]={{1,0},{-1,0},{0,-1},{0,1},{1,1},{1,-1},{-1,1},{-1,-1}};
int n,m,x,y,c;
long long a[101][101],f[101][101];
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>n>>m;
	memset(a,-1,sizeof(a));
	for(int i=1;i<=m;i++){
		cin>>x>>y>>c;
		a[x][y]=c;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			bool flag=false;
			for(int i=0;i<8;i++){
				int xx=i+fx[i][0],yy=j+fx[i][1];
				if(a[xx][yy]!=-1) flag=true;
			}
			if(flag==false&&a[i][j]!=-1){
				cout<<"-1";
				return 0;
			}
		}
	}
	memset(f,2372183718931,sizeof(f));
	f[1][1]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=1||j!=1){
				if(a[i][j]!=-1){
				   if(a[i][j-1]==-1){
					  if(a[i-1][j]==-1){
						 /*if(a[i-1][j-1]==-1){
							cout<<"-1";
							return 0;
						 }
					     else{*/
						     if(a[i-1][j-1]==a[i][j]) f[i][j]=min(f[i][j],a[i-1][j-1]+2);
						     else f[i][j]=min(f[i][j],f[i-1][j-1]+3);
					     //}
					  }
					  else{
						  if(a[i-1][j]==a[i][j]) f[i][j]=min(f[i][j],f[i-1][j]);
						  else f[i][j]=min(f[i][j],f[i-1][j]+1);
					  }
				   }
				   else{
					   if(a[i-1][j]==-1){
						  if(a[i][j]==a[i][j-1]) f[i][j]=min(f[i][j],f[i][j-1]);
						  else f[i][j]=min(f[i][j],f[i][j-1]+1);
					   }
					   else{
						   if(a[i][j-1]==a[i][j]){
							  if(a[i-1][j]==a[i][j]) f[i][j]=min(f[i][j],min(f[i][j-1],f[i-1][j]));
							  else f[i][j]=min(f[i][j],min(f[i][j-1],f[i-1][j]+1));
						   }
						   else{
							   if(a[i-1][j]==a[i][j]) f[i][j]=min(f[i][j],min(f[i][j-1]+1,f[i-1][j]));
							   else f[i][j]=min(f[i][j],min(f[i][j-1]+1,f[i-1][j]+1));
						   }
					   }
				   }
			    }
			}
			
			
		}
	}
	cout<<f[n][n];
}
/*
5 7
1 1 0
1 2 0
2 2 1
3 3 1
3 4 0
4 4 1
5 5 0
*/
