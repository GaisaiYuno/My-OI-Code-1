#include<cstdio>
#include<cstdlib>
#include<string.h>
int f[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int map[102][102],si[102][102];
bool p[102][102];
int n,m,ans=2147483647;
void dfs(int x,int y,int color,int power,int money){
	if (money>=ans) return;
	si[x][y]=money;
	if (x==n&&y==n){
		ans=money;
		return;
	}
	for (int i=0;i<=3;i++){
		int xi=x+f[i][0],yi=y+f[i][1];
		if (xi<=n&&xi>=1&&yi<=n&&yi>=1){
	    	if (!p[xi][yi]){
				if (map[xi][yi]==0){
					if (power==1){
						if (money+2<si[xi][yi]){
				    		p[xi][yi]=1;
				        	dfs(xi,yi,color,0,money+2);
				    		p[xi][yi]=0;
		     			}
					}
				}
				else{
					if (map[xi][yi]==color){
						if (money<si[xi][yi]){
							p[xi][yi]=1;
				    		dfs(xi,yi,color,1,money);
				    		p[xi][yi]=0;
						}
					}
					else{
						if (money+1<si[xi][yi]){
							p[xi][yi]=1;
				    		dfs(xi,yi,map[xi][yi],1,money+1);
				    		p[xi][yi]=0;
						}
					}
				}
	    	}
		}
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(si,126,sizeof(si));
	for (int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		map[x][y]=z+1;
	}
	dfs(1,1,map[1][1],1,0);
	if (ans==2147483647) printf("-1\n");
	else printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
