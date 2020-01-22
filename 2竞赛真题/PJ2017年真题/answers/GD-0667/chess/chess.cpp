#include<bits/stdc++.h>
using namespace std;
int m,n,x,y,i,j,mon,l,c[101][101];
bool b;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(i=1;i<=m;i++){
		for(j=1;j<=m;j++){
			c[i][j]=-1;
		}
	}
	for(i=1;i<=n;i++){
		cin>>x>>y>>l;
		c[x][y]=c[x][y]+l+1;
	}
	x=1;y=1;
	walk:while(x!=m&&y!=m){
		if(c[x][y+1]==c[x][y]){
			y=y+1;b=1;goto walk;
		}else if(c[x][y]==c[x+1][y]){
			x++;b=1;goto walk;
		}else if(c[x][y+1]!=-1){
			y++;b=1;mon++;goto walk;
		}else if(c[x+1][y]!=-1){
			x++;b=1;mon++;goto walk;
		}else if(b){
			x++;mon=mon+1;b=0;goto walk;
		}else{
			cout<<-1;
			return 0;
		}
	}
	cout<<mon;
	return 0;
}
