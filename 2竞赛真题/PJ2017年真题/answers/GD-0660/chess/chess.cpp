#include<cstdio>
#include<algorithm>
using namespace std;
int zl[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int MAP[101][101],M,T;
bool B[101][101];
int MIN=19398434;
void DFS(int X,int Y,int cost,int last){
	if(X==M && Y==M){
		MIN=min(MIN,cost); 
		return;
	}
	B[X][Y]=true;
	for(int i=0;i<=3;i++){
		if(X+zl[i][0]>=1 && X+zl[i][0]<=M && Y+zl[i][1]>=1 && Y+zl[i][1]<=M && !B[X+zl[i][0]][Y+zl[i][1]])
			if(!MAP[X+zl[i][0]][Y+zl[i][1]] && !MAP[X][Y]) continue;
			else if(!MAP[X+zl[i][0]][Y+zl[i][1]] && MAP[X][Y]) DFS(X+zl[i][0],Y+zl[i][1],cost+2,MAP[X][Y]);
			else if(MAP[X+zl[i][0]][Y+zl[i][1]] && !MAP[X][Y] && last==MAP[X+zl[i][0]][Y+zl[i][1]]) DFS(X+zl[i][0],Y+zl[i][1],cost,0);
			else if(MAP[X+zl[i][0]][Y+zl[i][1]] && !MAP[X][Y] && last!=MAP[X+zl[i][0]][Y+zl[i][1]]) DFS(X+zl[i][0],Y+zl[i][1],cost+1,0);
			else if(MAP[X+zl[i][0]][Y+zl[i][1]]!=MAP[X][Y]) DFS(X+zl[i][0],Y+zl[i][1],cost+1,0);
			else if(MAP[X+zl[i][0]][Y+zl[i][1]]==MAP[X][Y]) DFS(X+zl[i][0],Y+zl[i][1],cost,0);
	}
	B[X][Y]=false;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d %d",&M,&T);
	for(int i=1;i<=T;i++){
		int X,Y,color;
		scanf("%d %d %d",&X,&Y,&color);
		MAP[X][Y]=color+1;
	}
	DFS(1,1,0,0);
	if(MIN!=19398434) printf("%d",MIN);
	else printf("-1");
	fclose(stdin);
	fclose(stdout);
}
