#include<bits/stdc++.h>
using namespace std;
/*int fx(int x,int y,int c){
	if(x==1 and y==1) ans=0;
	int n=-99999,m=-99999,z=-99999,int ans=0;
	if(x==1 and y==2){
		if(a[1][2]==a[1][1]){
		    ans=1;
	    }
	    if(a[1][2]!=a[1][1] and a[1][2]==-1 and (a[1][3]!=-1 or a[2][2]!=-1)){
	        ans=2;
	    }
	    if(a[1][2]!=a[1][1] and a[1][2]!==-1){
	        
	    }
	}
	if(x==2 and y==1){
		
	}
	if(x==1 and y>=3){
		if(a[x][y-1]==-1 and a[x][y-2]) n=
	}
	if(x==1 and y>=3){
		
	}
	if(x!=1 and y!=1){
		
	}
	return ans;
}*/
bool fl;
int m,n;
int i,j;
int a[110][110];
struct qomolongma{
	int x,y,c;
	bool go;
}chessboard[1100];
int main(){
	fl=true;
	int foundy;
	memset(a,-1,sizeof(a));
	freopen("chess.in","r",stdin);
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;i++){
		scanf("%d%d%d",&chessboard[i].x,&chessboard[i].y,&chessboard[i].c);
    }
    a[1][1]=chessboard[1].c;
    for(i=2;i<=n;i++){
    	a[chessboard[i].x][chessboard[i].y]=chessboard[i].c;
		if(chessboard[i].x-chessboard[i-1].x>1||chessboard[i].y-chessboard[i-1].y>1){
			fl=false;
			break;
		}
    }
    if(a[m][m]==-1) fl=false;
    freopen("chess.out","w",stdout);
    if(fl==false) scanf("-1");
 /*   if(fl==true){
    	foundy=fx(m,m,chessboard[n].c);
    	scanf("%d",&foundy);
    }*/
}
