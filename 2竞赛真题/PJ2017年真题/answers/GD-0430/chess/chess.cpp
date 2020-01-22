#include<bits/stdc++.h>
using namespace std;
int m,n,a[101][101],b[1001],c[1001],d[1001],zmin[101][101];
bool e[101][101];
void move(int x,int y,int z,int yon,int sx,int sy){
	if(z<=zmin[x][y]||zmin[x][y]==-1)zmin[x][y]=z;
	else return;
	if(yon==1){
	if(a[x][y+1]!=0)if(a[x][y]==a[x][y+1])move(x,y+1,z,1,x,y);
	  else move(x,y+1,z+1,1,x,y);
	if(a[x+1][y]!=0)if(a[x][y]==a[x+1][y])move(x+1,y,z,1,x,y);
	  else move(x+1,y,z+1,1,x,y);
	if(a[x][y+1]==0){
	a[x][y+1]=a[x][y];
	move(x,y+1,z+2,0,x,y);}
	if(a[x+1][y]==0){
	a[x+1][y]=a[x][y];
	move(x+1,y,z+2,0,x,y);}
}
else{
	a[x][y]=0;
	if(a[x][y+1]!=0){
	if(a[x][y+1]==a[sx][sy])move(x,y+1,z,1,x,y);
	else move(x,y+1,z+1,1,x,y);
	}else return;
	if(a[x+1][y]!=0){
	if(a[x+1][y]==a[sx][sy])move(x+1,y,z,1,x,y);
	else move(x,y+1,z+1,1,x,y);
	}else return;
}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	  for(int j=1;j<=m;j++)a[i][j]=0;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>c[i]>>d[i];
		a[b[i]][c[i]]=++d[i];
	}
	for(int i=1;i<=m;i++)
	  for(int j=1;j<=m;j++)zmin[i][j]=-1;
	zmin[1][1]=0;
	move(1,1,0,1,0,0);
	cout<<zmin[m][m];
}
