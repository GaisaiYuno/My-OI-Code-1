#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
struct point{
	int x,y,cs;
	bool magic;
}b[1000010];
int color[110][110],n1,k,ans,t,w;
bool hm[110][110];
void bfs(int n){
	int x1,y1,lx=-1,ly=-1;
	b[0].x=0;n--;
	b[0].y=0;b[0].cs=0;hm[0][0]=1;
	while (t<=w){
		x1=b[t].x;
		y1=b[t].y;
		if (y1>0&&color[x1][y1-1]==0&&!hm[x1][y1-1]&&!b[t].magic){
			b[++w].x=x1;b[w].y=y1-1;b[w].cs=b[t].cs+2;b[w].magic=1;color[x1][y1-1]=3;
			hm[x1][y1-1]=1;
			if (x1==n&&y1-1==n) {
				if (b[w].cs>0){
					if (ans==-1) ans=b[w].cs;
					ans=min(ans,b[w].cs);
				}
			}
		}
		else if (y1>0&&((color[x1][y1-1]==color[x1][y1]||color[x1][y1]==3)&&!hm[x1][y1-1]||b[t].magic)){
			b[++w].x=x1;b[w].y=y1-1;b[w].cs=b[t].cs;
			hm[x1][y1-1]=1;
			if (x1==n&&y1-1==n) {
				if (b[w].cs>0){
					if (ans==-1) ans=b[w].cs;
					ans=min(ans,b[w].cs);
				}
			}
		}
		else if (y1>0&&(color[x1][y1-1]!=color[x1][y1]&&color[x1][y1-1]!=0&&!hm[x1][y1-1]||b[t].magic)){
			b[++w].x=x1;b[w].y=y1-1;b[w].cs=b[t].cs; if (!b[t].magic) b[w].cs++;
			hm[x1][y1-1]=1;
			if (x1==n&&y1-1==n) {
				if (b[w].cs>0){
					if (ans==-1) ans=b[w].cs;
					ans=min(ans,b[w].cs);
				}
			}
		}
		if (x1<n&&color[x1+1][y1]==0&&!hm[x1+1][y1]&&!b[t].magic){
			b[++w].x=x1+1;b[w].y=y1;b[w].cs=b[t].cs+2;b[w].magic=1;color[x1+1][y1]=3;
			hm[x1+1][y1]=1;
			if (x1+1==n&&y1==n) {
				if (b[w].cs>0){
					if (ans==-1) ans=b[w].cs;
					ans=min(ans,b[w].cs);
				}
			}
		}
		else if (x1<n&&((color[x1+1][y1]!=color[x1][y1]||color[x1][y1]==3)&&color[x1+1][y1]!=0&&!hm[x1+1][y1]||b[t].magic)){
			b[++w].x=x1+1;b[w].y=y1;b[w].cs=b[t].cs; if (!b[t].magic) b[w].cs++;
			hm[x1+1][y1]=1;
			if (x1+1==n&&y1==n) {
				if (b[w].cs>0){
					if (ans==-1) ans=b[w].cs;
					ans=min(ans,b[w].cs);
				}
			}
		}
		else if (x1<n&&(color[x1+1][y1]==color[x1][y1]&&!hm[x1+1][y1]||b[t].magic)){
			b[++w].x=x1+1;b[w].y=y1+1;b[w].cs=b[t].cs;
			hm[x1+1][y1]=1;
			if (x1+1==n&&y1==n) {
				if (b[w].cs>0){
					if (ans==-1) ans=b[w].cs;
					ans=min(ans,b[w].cs);
				}
			}
		}
		if (y1<n&&((color[x1][y1+1]!=color[x1][y1]||color[x1][y1]==3)&&color[x1][y1+1]!=0&&!hm[x1][y1+1]||b[t].magic)){
			b[++w].x=x1;b[w].y=y1+1; b[w].cs=b[t].cs; if (!b[t].magic) b[w].cs++;
			hm[x1+1][y1]=1;
			if (x1+1==n&&y1==n) {
				if (b[w].cs>0){
					if (ans==-1) ans=b[w].cs;
					ans=min(ans,b[w].cs);
				}
			}
		}
		else if (y1<n&&color[x1][y1+1]==0&&!hm[x1][y1+1]&&!b[t].magic){
			b[++w].x=x1;b[w].y=y1+1;b[w].cs=b[t].cs+2;b[w].magic=1;color[x1][y1+1]=3;
			hm[x1][y1+1]=1;
			if (x1==n&&y1+1==n) {
				if (b[w].cs>0){
					if (ans==-1) ans=b[w].cs;
					ans=min(ans,b[w].cs);
				}
			}
		}
		else if (y1<n&&(color[x1][y1+1]==color[x1][y1]&&!hm[x1][y1+1]||b[t].magic)){
			b[++w].x=x1;b[w].y=y1+1;b[w].cs=b[t].cs;
			hm[x1][y1+1]=1;
			if (x1==n&&y1+1==n) {
				if (b[w].cs>0){
					if (ans==-1) ans=b[w].cs;
					ans=min(ans,b[w].cs);
				}
			}
		}
		if (x1>0&&(color[x1-1][y1]==0&&!hm[x1-1][y1]&&!b[t].magic)){
			b[++w].x=x1-1;b[w].y=y1;b[w].cs=b[t].cs+2;b[w].magic=1;color[x1-1][y1]=3;
			hm[x1-1][y1]=1;
			if (x1-1==n&&y1==n) {
				if (b[w].cs>0){
					if (ans==-1) ans=b[w].cs;
					ans=min(ans,b[w].cs);
				}
			}
		}
		else if (x1>0&&((color[x1-1][y1]!=color[x1][y1]||color[x1][y1]==3)&&color[x1-1][y1]!=0&&!hm[x1-1][y1]||b[t].magic)){
			b[++w].x=x1-1;b[w].y=y1; b[w].cs=b[t].cs; if (!b[t].magic) b[w].cs++;
			hm[x1-1][y1]=1;
			if (x1-1==n&&y1==n) {
				if (b[w].cs>0){
					if (ans==-1) ans=b[w].cs;
					ans=min(ans,b[w].cs);
				}
			}
		}
		else if (x1>0&&(color[x1-1][y1]==color[x1][y1]&&!hm[x1-1][y1]||b[t].magic)){
			b[++w].x=x1-1;b[w].y=y1;b[w].cs=b[t].cs;
			hm[x1-1][y1]=1;
			if (x1-1==n&&y1==n) {
				if (b[w].cs>0){
					if (ans==-1) ans=b[w].cs;
					ans=min(ans,b[w].cs);
				}
			}
		}
		b[t].magic=0;
		if (t>0) {
			if (color[b[t-1].x][b[t-1].y+1]==3) color[b[t-1].x][b[t-1].y+1]=0;
			if (color[b[t-1].x][b[t-1].y-1]==3) color[b[t-1].x][b[t-1].y-1]=0;
			if (color[b[t-1].x-1][b[t-1].y]==3) color[b[t-1].x-1][b[t-1].y]=0;
			if (color[b[t-1].x+1][b[t-1].y]==3) color[b[t-1].x+1][b[t-1].y]=0;
		}
		t++;
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n1,&k);
	for (int i=0,x1,y1,c1;i<k;i++){
		scanf("%d%d%d",&x1,&y1,&c1);
		color[--x1][--y1]=c1+1;
	}
	memset(hm,0,sizeof(hm));
	ans=-1;
	bfs(n1);
	printf("%d\n",ans);
	return 0;
}
