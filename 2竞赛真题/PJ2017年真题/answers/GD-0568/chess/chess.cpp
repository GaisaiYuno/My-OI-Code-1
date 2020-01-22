#include<cstdio>
#include<memory.h>
using namespace std;
int a[101][101];
bool b[101][101];
bool c[101][101];  
long long ans=1e9,m,n;
const int dx[4]={0,1,-1,0};
const int dy[4]={1,0,0,-1};
inline int read(){
	int x=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) print(x/10);
	putchar(x%10+'0');
}
void fun(int x,int y,int cost);
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	m=read();n=read();
	memset(a,-1,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	for(int i=1;i<=n;i++){
		int a1,a2,a3;
		a1=read();a2=read();a3=read();
		a[a1][a2]=a3;
	}
	c[1][1]=1;
	fun(1,1,0);
	if(ans==1e9) print(-1);
	else print(ans*2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
void fun(int x,int y,int cost){
	if(x<1||y<1||x>m||y>m) return;
	if(x==m&&y==m){
		if(cost<ans) ans=cost;
		return;
	}
	for(int i=0;i<4;i++){
		int yx=x,yy=y;
		yx=yx+dx[i];
		yy=yy+dy[i];
		if(!c[yx][yy]){
			if(a[yx][yy]==a[x][y]){
				c[yx][yy]=1;
				fun(yx,yy,cost);
				c[yx][yy]=0;
			}
			else{
				if((a[yx][yy]==-1)&&(!b[x][y])){
					a[yx][yy]=a[x][y];
					b[yx][yy]=1;
					c[yx][yy]=1;
					fun(yx,yy,cost+2);
					a[yx][yy]=-1;
					b[yx][yy]=0;
					c[yx][yy]=0;
				}
				else{
					c[yx][yy]=1;
					fun(yx,yy,cost+1);
					c[yx][yy]=0;
				}
			}
		}
	}
}
