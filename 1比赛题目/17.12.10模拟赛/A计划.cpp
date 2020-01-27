//HDU 2102
#include<iostream>
#include<cstring>
#define maxn 11
using namespace std;
int c,n,m,maxt;
int xa,ya;
char a[maxn][maxn][2];
bool used[maxn][maxn][2];
const int walkx[4]={1,-1,0,0},walky[4]={0,0,1,-1};
int flag=0;
int dfs(int x,int y,int floor,int t){
	int xx,yy;
	if(a[x][y][floor]=='P'){
		if(t<=maxt) return 1;
		else return 0;
	}
	for(int i=0;i<4;i++){
		xx=x+walkx[i];
		yy=y+walky[i];
		if(xx>=0&&xx<n&&yy>=0&&yy<m&&!used[xx][yy][1-floor]&&a[xx][yy][floor]=='#'&&a[xx][yy][1-floor]!='*'&&a[xx][yy][1-floor]!='#'){
			used[xx][yy][1-floor]=true;
			if(dfs(xx,yy,1-floor,t+1)==1)  return 1;
		    used[xx][yy][1-floor]=false;
		}
		else if(xx>=0&&xx<n&&yy>=0&&yy<m&&!used[xx][yy][floor]&&a[xx][yy][floor]!='#'&&a[xx][yy][floor]!='*'){
			used[xx][yy][floor]=true;
			if(dfs(xx,yy,floor,t+1)==1)  return 1;
		    used[xx][yy][floor]=false;
		}
	}
	return 0;
}
int main(){
	cin>>c;
	while(c--){
		cin>>n>>m>>maxt;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>a[i][j][0];
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>a[i][j][1];
				if(a[i][j][1]=='P') {
				   xa=i;
				   ya=j;
			    }
			}
		}
		flag=0;
		memset(used,false,sizeof(used));
		used[0][0][0]=true;
		if(dfs(0,0,0,0)==1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
