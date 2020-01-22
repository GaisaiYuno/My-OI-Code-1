#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
int f[102][102],s[102][102],n,m,c[102][102];
const int oo=999999999;
void init(){
	cin>>m>>n;
	for(int i=0;i<n;i++){
		int ii,jj,cc;
		cin>>ii>>jj>>cc;
		if(cc==1)c[ii][jj]=1;
		else c[ii][jj]=2;
	}
	f[1][1]=0;s[1][1]=0;
}
void work(){
	for(int i=1,j=2;j<=m;j++){
		if(f[i][j-1]==-1 || s[i][j-1]==1 && c[i][j]==0)f[i][j]=-1;//不能走到前一个或者前面一个用了变色而且当前格子无色 
		else if(c[i][j-1] && c[i][j]==0)f[i][j]=f[i][j-1]+2,s[i][j]=1,c[i][j]=c[i][j-1];//前一个有色而且当前格子无色
		else if(c[i][j-1] && c[i][j]){//两个格子都有色 
			if(c[i][j-1]!=c[i][j])//颜色不同
				f[i][j]=f[i][j-1]+1;
			else//颜色相同
				f[i][j]=f[i][j-1]; 
		}
	}
	for(int i=2,j=1;i<=m;i++){
		if(f[i-1][j]==-1 || s[i-1][j]==1 && c[i][j]==0)f[i][j]=-1;//不能走到前一个或者前面一个用了变色而且当前格子无色 
		else if(c[i-1][j] && c[i][j]==0)f[i][j]=f[i-1][j]+2,s[i][j]=1,c[i][j]=c[i-1][j];//前一个有色而且当前格子无色
		else if(c[i-1][j] && c[i][j]){//两个格子都有色 
			if(c[i-1][j]!=c[i][j])//颜色不同
				f[i][j]=f[i-1][j]+1;
			else//颜色相同
				f[i][j]=f[i-1][j]; 
		}
	}
	for(int i=2;i<=m;i++)
		for(int j=2;j<=m;j++){
			int ans1=0,c1=0,ans2=0,c2=0;
			if(f[i][j-1]==-1 || s[i][j-1]==1 && c[i][j]==0)ans1=oo;//不能走到前一个或者前面一个用了变色而且当前格子无色 
			else if(c[i][j-1] && c[i][j]==0)ans1=f[i][j-1]+2,c1=1,c[i][j]=c[i][j-1];//前一个有色而且当前格子无色
			else if(c[i][j-1] && c[i][j]){//两个格子都有色 
				if(c[i][j-1]!=c[i][j])//颜色不同
					ans1=f[i][j-1]+1;
				else//颜色相同
					ans1=f[i][j-1]; 
			}
			if(f[i-1][j]==-1 || s[i-1][j]==1 && c[i][j]==0)ans2=oo;//不能走到前一个或者前面一个用了变色而且当前格子无色 
			else if(c[i-1][j] && c[i][j]==0)ans2=f[i-1][j]+2,c2=1,c[i][j]=c[i-1][j];//前一个有色而且当前格子无色
			else if(c[i-1][j] && c[i][j]){//两个格子都有色 
				if(c[i-1][j]!=c[i][j])//颜色不同
					ans2=f[i-1][j]+1;
				else//颜色相同
					ans2=f[i-1][j]; 
			}
			if(ans1<ans2){
				f[i][j]=ans1;
				s[i][j]=c1;
			}
			else if(ans1>ans2){
				f[i][j]=ans2;
				s[i][j]=c2;
			}
			else{
				if(ans1==oo && ans2==oo)
					f[i][j]=-1;
				else if(c1==c2 || c1==0 && c2==1)
					f[i][j]=ans1,
					s[i][j]=c1;
				else if(c1==1 && c2==0)
					f[i][j]=ans2,
					s[i][j]=c2;
			}
		}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	init();
	work();
	cout<<f[m][m]<<endl;
	return 0;
}
