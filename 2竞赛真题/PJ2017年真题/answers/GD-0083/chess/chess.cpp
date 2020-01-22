#include<bits/stdc++.h>
using namespace std;
int a[105][105],m,n,k,l,tot=999999999,b[5][5]={{1,0},{-1,0},{0,1},{0,-1}};
bool flag=false;
void dfs(int x,int y,int cost,bool kb,int ys,int bs){
	if(x==m&&y==m){
		tot=min(tot,cost);
		flag=true;
		return;
	}
	if(bs>k) return;
	for(int i=0;i<=3;i++){
		if(1<=x+b[i][0]&&x+b[i][0]<=m&&1<=y+b[i][1]&&y+b[i][1]<=m){
			if(a[x+b[i][0]][y+b[i][1]]==0){
				if(kb==true) continue;
				else dfs(x+b[i][0],y+b[i][1],cost+2,true,ys,bs+1);
			}
			else{
				if(a[x+b[i][0]][y+b[i][1]]==ys) dfs(x+b[i][0],y+b[i][1],cost,false,ys,bs+1);
				else dfs(x+b[i][0],y+b[i][1],cost+1,false,a[x+b[i][0]][y+b[i][1]],bs+1);
			}
		}
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	k=m*m*3/4;
	int i,j,x,y,c;
	for(i=1;i<=n;i++){
		cin>>x>>y>>c;
		a[x][y]=c+1;
	}
	if(m==1){
		cout<<"0";
		return 0;
	}
	if(n<m){
		cout<<"-1";
		return 0;
	}
	dfs(1,1,0,false,a[1][1],1);
	if(flag==true) cout<<tot;
	else cout<<"-1";
	return 0;
}
