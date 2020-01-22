#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

const int maxn=100+2;
int m,n;
int moved[2]={0,1};
int rmove[2]={1,0};
int x,y,c;
int chess[maxn][maxn];
int i,j,k,l;
int gold=0;
bool use=false,brde;

void bfs(int xp,int yp){
	int xb,yb;
	if(xp==m&&yp==m){
		brde=true;
		return;
	}
	else{
		for(j=0;j<2;j++){
			xb=xp+moved[i];
			yb=yp+rmove[i];
			if(xb<=m&&yb<=m){
				if(chess[xb][yb]==-1&&!use){
					gold+=2;
					use=true;
					bfs(xb,yb);
				}
				else if(chess[xb][yb]==-1&&!use)continue;
				else if(chess[xp][yp]==chess[xb][yb]&&chess[xb][yb]==-1)
					continue;
				else if(chess[xb][yb]==chess[xp][yp]&&chess[xb][yb]!=-1){
					bfs(xb,yb);
				}
				else if(chess[xb][yb]!=chess[xp][yp]&&chess[xb][yb]!=-1&&chess[xp][yp]!=-1){
					gold+=1;
					bfs(xb,yb);
				}
			}
		}
	}
	brde=false;
	return;
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(chess,-1,sizeof(chess));
	scanf("%d %d",&m,&n);
	for(i=0;i<n;i++){
		scanf("%d %d %d",&x,&y,&c);
		chess[x][y]=c;
	}
//	bfs(1,1);
	if(gold==0&&!brde){
		printf("-1");
	}
	else printf("%d",gold);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
