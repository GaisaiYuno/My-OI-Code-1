#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 25
#define INF 99999999
using namespace std;
int map[maxn][maxn];
int walkx[4]= {1,-1,0,0};
int walky[4]= {0,0,1,-1};
int n,m;
inline int qread() {
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
int ans;
bool out_range(int x,int y){
	if(x>=1&&y>=1&&x<=n&&y<=m) return false;
	else return true;
}
void dfs(int x,int y,int cnt,int sx,int sy,int ex,int ey) {
	if(x==ex&&y==ey) {
		ans=min(cnt,ans);
		return;
	}
	if(cnt>=ans||cnt==10) return;
	for(int i=0; i<4; i++) {
		int xx=x+walkx[i];
		int yy=y+walky[i];
		while(!out_range(xx,yy)&&map[xx][yy]!=1){ 
			if(xx==ex&&yy==ey) {
				cnt++;
				ans=min(cnt,ans);
				return;
			}
			xx+=walkx[i];
			yy+=walky[i]; 
		} 
		if((xx==x+walkx[i]&&yy==y+walky[i])||out_range(xx,yy)) continue;//说明该方向立刻会碰到障碍 
		map[xx][yy]=0;
		cnt++;
		dfs(xx-walkx[i],yy-walky[i],cnt,sx,sy,ex,ey); 
		map[xx][yy]=1;
		cnt--; 
	}
}
int main() {
	//freopen("data_a.txt","r",stdin);
	int sx,sy,ex,ey;
	while(cin>>n>>m) {
		if(n==0&&m==0) break;
		swap(n,m);
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				map[i][j]=qread();
				if(map[i][j]==2) {
					map[i][j]=0;
					sx=i;
					sy=j;
				} else if(map[i][j]==3) {
					ex=i;
					ey=j;
				}
			}
		}
		ans=11;
		dfs(sx,sy,0,sx,sy,ex,ey);
		if(ans==11) ans=-1;
		cout<<ans<<endl;
	}
	return 0;
}
