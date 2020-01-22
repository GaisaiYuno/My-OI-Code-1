#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int m,n,x,y,c,col[101][101],cos[101][101],cos1,cos2,fcos,i,j;
bool tcol[101][101];
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++)
		for(j=1;j<=m;j++){
			col[i][j]=-1;cos[i][j]=20170;
		}
	for(i=1;i<=n;i++){
		scanf("%d%d%d",&x,&y,&c);
		col[x][y]=c;
	}
	for(i=1;i<=m;i++)
		for(j=1;j<=m;j++){
			if(i==1&&j==1) cos[1][1]=0;
			else if(i==1){
				if(col[1][j]==col[1][j-1]) cos[1][j]=cos[1][j-1];
				else if(col[1][j]+col[1][j-1]==1) cos[1][j]=cos[1][j-1]+1;
				else if(!tcol[1][j-1]&&col[1][j]==-1){
					col[1][j]=col[1][j-1];
					tcol[1][j]=true;
					cos[1][j]=col[1][j-1]+2;
				}
			}
			else if(j==1){
				if(col[i][1]==col[i-1][1]) cos[i][1]=cos[i-1][1];
				else if(col[i][1]+col[i-1][1]==1) cos[i][1]=cos[i-1][1]+1;
				else if(!tcol[i-1][1]&&col[i][1]==-1){
					col[i][1]=col[i-1][1];
					tcol[i][1]=true;
					cos[i][1]=col[i-1][1]+2;
				}
			}
			else{
				int u=20170,ucol=col[i][j],l=20170,lcol=col[i][j];
				bool utcol=false,ltcol=false;
				if(col[i][j]==col[i][j-1]) l=cos[i][j-1];
				else if(col[i][j]+col[i][j-1]==1) l=cos[i][j-1]+1;
				else if(!tcol[i][j-1]&&col[i][j]==-1){
					lcol=col[i][j-1];
					ltcol=true;
					l=cos[i][j-1]+2;
				}
				if(col[i][j]==col[i-1][j]) u=cos[i-1][j];
				else if(col[i][j]+col[i-1][j]==1) u=cos[i-1][j]+1;
				else if(!tcol[i-1][j]&&col[i][j]==-1){
					ucol=col[i-1][j];
					utcol=true;
					u=cos[i-1][j]+2;
				}
				if(u>l){
					cos[i][j]=l;
					col[i][j]=lcol;
					tcol[i][j]=ltcol;
				}
				else{
					cos[i][j]=u;
					col[i][j]=ucol;
					tcol[i][j]=utcol;
				}
			}
		}
	if(cos[m][m]>=20170) cout<<-1<<endl;
	else cout<<cos[m][m]<<endl;
	return 0;
}
