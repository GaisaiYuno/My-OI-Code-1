#include<bits/stdc++.h>
using namespace std;
int m,n,i,x,y,col,j,pd,xx,yy,a1,a2,f[121][121][5],p[121][121];
int fx[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int an(int a){
	if(a==1) return 2;
	if(a==2) return 1;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	memset(p,0,sizeof(p));
	for(i=1;i<=n;i++){
		cin>>x>>y>>col;
		p[x][y]=col+1;
	}
	memset(f,0X7f,sizeof(f));
	pd=f[m][m][0];
	f[1][1][1]=0;
	f[1][1][2]=0;
	f[1][1][3]=0;
	f[1][1][4]=0;
	for(i=1;i<=m;i++)
	  for(j=1;j<=m;j++)
	  	for(x=0;x<=3;x++){
	  		xx=i+fx[x][0];yy=j+fx[x][1];
	  		if(p[xx][yy]>0){
	  		  f[xx][yy][p[xx][yy]]=min(f[xx][yy][p[xx][yy]],f[i][j][p[xx][yy]]);
	  		  f[xx][yy][p[xx][yy]]=min(f[xx][yy][p[xx][yy]],f[i][j][an(p[xx][yy])]+1);
	  		  f[xx][yy][p[xx][yy]]=min(f[xx][yy][p[xx][yy]],f[i][j][p[xx][yy]+2]);
	  		  f[xx][yy][p[xx][yy]]=min(f[xx][yy][p[xx][yy]],f[i][j][an(p[xx][yy])+2]+1);
	  		  }else{
	  		  	f[xx][yy][3]=min(f[xx][yy][3],f[i][j][1]+2);
	  		  	f[xx][yy][4]=min(f[xx][yy][4],f[i][j][2]+2);
	  		  }
	  	}
	if(f[m][m][1]==pd&&f[m][m][2]==pd&&f[m][m][3]==pd&&f[m][m][4]==pd)
	  cout<<-1<<endl;
	else{
		a1=min(f[m][m][1],f[m][m][2]);
		a2=min(f[m][m][3],f[m][m][4]);
		cout<<min(a1,a2)<<endl;
	}
    return 0;
}
