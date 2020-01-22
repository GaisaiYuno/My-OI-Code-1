#include <iostream>
#include <cstdio>
using namespace std;
int M, N, C[102][102], F[102][102];
int D[4][2]={{0,-1}, {0,1}, {-1,0}, {1,0}};
bool book[102][102]={false}, ma[102][102]={false};

void DFS(int i, int j){
	book[i][j] = true;
	if (i==M&&j==M) return;
	for(int i=1; i<=M; i++){
		for(int j=1; j<=M; j++){
			for(int k=0; k<4; k++){
				int x=i+D[k][0], y=j+D[k][1];
				if (x==0||y==0) continue;
				if (book[x][y]) continue;
				if (C[x][y]==-1&&ma[i][j]) continue;
				if(C[x][y]>=0){//xy has color
					if(C[x][y]==C[i][j]){
						if (F[i][j]<F[x][y]) { F[x][y]=F[i][j]; DFS(x, y); }
					}else{
						if(F[i][j]+1<F[x][y]) { F[x][y]=F[i][j]+1;DFS(x, y); }
					}
				}else{//doesn't have color
					if(F[i][j]+2<F[x][y]){
						ma[x][y]=true; C[x][y]=C[i][j];
						F[x][y]=F[i][j]+2;
						DFS(x, y);
						C[x][y]=-1;
					}
				}
			}
		}
	}
	book[i][j]=false;
}

int main(){
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout); 
	
	scanf("%d %d", &M, &N);
	for(int i=1; i<=M; i++)
		for(int j=1; j<=M; j++)
			{ C[i][j]=-1; F[i][j]=1<<30; }
	while(N--){
		int x, y, co;
		scanf("%d %d %d", &x, &y, &co);
		C[x][y]=co;
	}
	
	F[1][1]=0;
	DFS(1, 1);
	
	if (F[M][M]==1<<30) printf("-1");
	else printf("%d\n", F[M][M]);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
