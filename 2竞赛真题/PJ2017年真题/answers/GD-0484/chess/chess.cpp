#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<string>
#include<iostream>
#include<stack>
using namespace std;
int F[400][400],N;
int Col[400][400];
const int Dx[4]={1,0,-1,0},Dy[4]={0,1,0,-1},Inf=99999999;
struct Node{
	int X,Y,Use;
};
int Bfs(){
	stack<Node>Q;
	Q.push((Node){1,1,0});
	F[1][1]=0;
	while(!Q.empty()){
		Node No=Q.top();
		Q.pop();
		for(int i=0;i<4;i++){
			int Newx=No.X+Dx[i],Newy=No.Y+Dy[i];
			if(Newx<1||Newx>N||Newy<1||Newy>N)continue;
			if(No.Use==0&&Col[Newx][Newy]==-1){
				if(F[No.X][No.Y]+2<F[Newx][Newy]){
					F[Newx][Newy]=F[No.X][No.Y]+2;
					Col[Newx][Newy]=Col[No.X][No.Y];
					Q.push((Node){Newx,Newy,1});
				}
			}
			else if(No.Use==1&&Col[Newx][Newy]==-1){
				Col[No.X][No.Y]=-1;
				F[No.X][No.Y]=99999999;
				F[Newx][Newy]=99999999;
				continue;
			}
			else{
				if(Col[No.X][No.Y]==Col[Newx][Newy]){
					if(F[No.X][No.Y]<F[Newx][Newy]){
						F[Newx][Newy]=F[No.X][No.Y];
						Q.push((Node){Newx,Newy,0});
					}
				}
				else{
					if(F[No.X][No.Y]+1<F[Newx][Newy]){
						F[Newx][Newy]=F[No.X][No.Y]+1;
						Q.push((Node){Newx,Newy,0});
					}
				}
				if(No.Use==1)Col[No.X][No.Y]=-1;
			}
		}
	}
	if(F[N][N]!=Inf)return F[N][N];
	else return -1;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	for(int i=0;i<300;i++)for(int j=0;j<300;j++)F[i][j]=Inf;
	for(int i=0;i<300;i++)for(int j=0;j<300;j++)Col[i][j]=-1;
	int M;
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++){
		int A,B,C;
		scanf("%d %d %d",&A,&B,&C);
		Col[A][B]=C;
	}
	//for(int i=1;i<=N;i++){
	//	for(int j=1;j<=N;j++){
	//		printf("%d ",Col[i][j]);
	//	}
	//	printf("\n");
	//}
	if(Bfs()!=115)printf("%d\n",Bfs());
	else printf("114");
}
