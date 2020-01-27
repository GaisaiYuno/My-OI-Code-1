#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 0x3f3f3f3f
#define maxn 4
using namespace std;
const int n=4;
char tmp[maxn+5];
int a[maxn+5][maxn+5];
int b[maxn+5][maxn+5];
const int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
inline void flip(int x,int y){
	b[x][y]^=1;
	for(int i=0;i<4;i++){
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx>=1&&xx<=n&&yy>=1&&yy<=n){
			b[xx][yy]^=1;
		}
	}
}
int solve(int type){
	int ans=INF;
	for(int i=0;i<(1<<n);i++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				b[i][j]=a[i][j];
			}
		}
		int tot=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				flip(n,j+1);
				tot++;
			}
		}
		for(int i=n-1;i>=1;i--){
			for(int j=1;j<=n;j++){
				if(b[i+1][j]!=type){
					flip(i,j);
					tot++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(b[1][i]!=type){
				tot=INF;
				break;
			}
		}
		ans=min(ans,tot);
	}
	
	return ans;
}

int main(){
	for(int i=1;i<=n;i++){
		scanf("%s",tmp+1);
		for(int j=1;j<=n;j++){
			a[i][j]=(tmp[j]=='b');
		}
	}
	int ans=INF;
	ans=min(ans,solve(0));
	ans=min(ans,solve(1));
	if(ans==INF) printf("Impossible");
	else printf("%d\n",ans);
}
