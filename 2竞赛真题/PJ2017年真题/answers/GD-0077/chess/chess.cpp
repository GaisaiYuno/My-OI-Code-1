#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int m,n,book[110][110],
	a[110][110],minn=-1;
void dfs(int x,int y,int c,bool h,int sum){
	if (x==m&&y==m){
		if (minn==-1){
			minn=sum;
		}
		else {
			if (minn>sum)
				minn=sum;
		}
		return;
	}
	int tx,ty;
	for (int k=0;k<4;++k){
		if (k==0) ty=y+1;
		if (k==1) ty=y-1;
		if (k==2) tx=x+1;
		if (k==3) tx=x-1;
		
		
		if (tx<1||tx>m||ty<1||ty>m)
			continue;
		if (book[tx][ty]==1)
			continue;
	//		
		if (a[tx][ty]==c){
			book[tx][ty]=1;
			dfs(tx,ty,a[tx][ty],1,sum);
			book[tx][ty]=0;
		}
		else if(a[tx][ty]!=c&&a[tx][ty]!=0){
			book[tx][ty]=1;
			dfs(tx,ty,a[tx][ty],1,sum+1);
			book[tx][ty]=0;
		}
		else if(a[tx][ty]==0&&h==1){
			book[tx][ty]=1;
			dfs(tx,ty,c,0,sum+2);
			book[tx][ty]=0;
		}
	
	}
	return ;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	int x,y,c;
	for (int i=0;i<n;++i) {
		cin>>x>>y>>c;
		c++;
		a[x][y]=c;
	}
	
	book[1][1]=1;
	dfs(1,1,a[1][1],1,0);
	cout<<minn;
	return 0;
}
