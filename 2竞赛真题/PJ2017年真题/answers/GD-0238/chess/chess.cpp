#include<iostream>
#include<cstdlib>
#include<cstdio>
int a[101][101],as[101][101];
int m,n,z,h,t;
using namespace std;
void dfs(int x,int y){
	//if(x==5&&y==6)
	//cout<<x<<" "<<y<<" "<<a[x][y]<<" "<<as[x][y]<<endl<<endl;
	int aks=0;
	if(a[x][y]>0){
		for(int i=-1;i<=1;i++)
			for(int j=-1;j<=1;j++){
				if((i!=0&&j!=0)||i==j)continue;
				//cout<<i<<" "<<j<<endl;
				if(x+i<=m&&x+i>0&&y+j<=m&&y+j>0){
					if(a[x+i][y+j]!=a[x][y])
						if(a[x+i][y+j]>0)aks=1;
						else {
							aks=2;
							a[x+i][y+j]=-a[x][y];
						}
				}
				if(as[x+i][y+j]==-1||as[x+i][y+j]>as[x][y]+aks||a[x+i][y+j]==0){
					as[x+i][y+j]=as[x][y]+aks;
					dfs(x+i,y+j);
				}
			}
	}
	if(a[x][y]<0){
		int s=a[x][y];
		for(int i=-1;i<=1;i++)
			for(int j=-1;j<=1;j++){
				if((i!=0&&j!=0)||i==j)continue;
				if(a[x+i][y+j]==0)continue;
				//cout<<x+i<<" "<<y+j<<endl;
				if(x+i<=m&&x+i>0&&y+j<=m&&y+j>0){
					if(a[x+i][y+j]!=-a[x][y]&&a[x+i][y+j]>0)aks=1;
				}
				if(as[x+i][y+j]==-1||as[x+i][y+j]>as[x][y]+aks){
					as[x+i][y+j]=as[x][y]+aks;
					a[x][y]=0;
					dfs(x+i,y+j);
					a[x][y]=s;
				}
			}
		a[x][y]=0;
	}
	return ;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m;++i)
		for(int j=1;j<=m;++j)as[i][j]=-1;
	for(int i=0;i<n;++i){
		cin>>h>>t>>z;
		a[h][t]=z+1;
	}
	/*for(int i=1;i<=m;++i){
		for(int j=1;j<=m;++j)
			printf("%d ",a[i][j]);
		cout<<endl;
	}*/
	as[1][1]=0;
	dfs(1,1);
	/*for(int i=1;i<=m;++i){
		for(int j=1;j<=m;++j)
			printf("%3d ",as[i][j]);
		cout<<endl;
	}*/
	cout<<as[m][m];
	return 0;
}
