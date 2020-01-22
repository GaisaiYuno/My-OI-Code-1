#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001][1001],b[1001][1001];
void dfs(int x,int y,int z,int l){
	if(l>=b[x][y])return;
	b[x][y]=l;
	if(x==n&&y==n)return;
	if(x>1){
		if(!a[x-1][y]&&!z)dfs(x-1,y,a[x][y],l+2);
		else if(a[x-1][y]){
			if(!z){
				if(a[x][y]!=a[x-1][y])dfs(x-1,y,0,l+1);
			else dfs(x-1,y,0,l);
			}
			else{
				if(z!=a[x-1][y])dfs(x-1,y,0,l+1);
			else dfs(x-1,y,0,l);
			}
		}
	}
	if(y>1){
		if(!a[x][y-1]&&!z)dfs(x,y-1,a[x][y],l+2);
		else if(a[x][y-1]){
			if(!z){
				if(a[x][y]!=a[x][y-1])dfs(x,y-1,0,l+1);
			else dfs(x,y-1,0,l);
			}
			else{
				if(z!=a[x][y-1])dfs(x,y-1,0,l+1);
			else dfs(x,y-1,0,l);
			}
		}
	}
	if(y<n){
		if(!a[x][y+1]&&!z)dfs(x,y+1,a[x][y],l+2);
		else if(a[x][y+1]){
			if(!z){
				if(a[x][y]!=a[x][y+1])dfs(x,y+1,0,l+1);
			else dfs(x,y+1,0,l);
			}
			else{
				if(z!=a[x][y+1])dfs(x,y+1,0,l+1);
			else dfs(x,y+1,0,l);
			}
		}
	}
	if(x<n){
		if(!a[x+1][y]&&!z)dfs(x+1,y,a[x][y],l+2);
		else if(a[x+1][y]){
			if(!z){
			if(a[x][y]!=a[x+1][y])dfs(x+1,y,0,l+1);
			else dfs(x+1,y,0,l);
			}
			else{
			if(z!=a[x+1][y])dfs(x+1,y,0,l+1);
			else dfs(x+1,y,0,l);
			}
		}
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)b[i][j]=0x7fffffff;
	}
	while(m--){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		a[x][y]=z+1;
	}
	dfs(1,1,0,0);
	if(b[n][n]!=0x7fffffff)printf("%d\n",b[n][n]);
	else printf("-1\n");
	return 0;
}
