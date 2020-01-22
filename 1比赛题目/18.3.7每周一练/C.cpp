#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#define maxn 105
#define INF 2147483647
using namespace std;
int c,r;
int h[maxn][maxn],step[maxn][maxn];
int walkx[4]={1,-1,0,0},walky[4]={0,0,1,-1};
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	} 
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar(); 
	}
	return x*sign;
}
int dfs(int x,int y){
	if(step[x][y]!=0) return step[x][y];
	for(int i=0;i<4;i++){
		int tx=x+walkx[i];
		int ty=y+walky[i];
		if(tx<=c&&tx>=1&&ty<=r&&ty>=1&&h[tx][ty]<h[x][y]){
			step[x][y]=max(dfs(tx,ty)+1,step[x][y]);
		}
	}
	return step[x][y];
}
int main(){
	while(cin>>c>>r){
		memset(step,0,sizeof(step));
		for(int i=1;i<=c;i++){
			for(int j=1;j<=r;j++){
				h[i][j]=qread();
			}
		}
		//freopen("debug.txt","w",stdout);
		int ans=0; 
		for(int i=1;i<=c;i++){
			for(int j=1;j<=r;j++){
			    ans=max(ans,dfs(i,j));
			}
		}
		cout<<ans+1<<endl;
	}
}
