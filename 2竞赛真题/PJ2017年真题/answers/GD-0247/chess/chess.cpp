#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int m,n,i,j,k,ki,k1,c[101][101],ans=0,ansi,aans=401,a;

int road(int r,int s){
		if(k>=0&&k==c[r][s]){
			ans=ans+0;a=0;
		}
		else if(k>=0&&k!=c[r][s]&&c[r][s]>=0){
			ans=ans+1;a=0;
		}
		else if(c[r][s]==-1){
			ans=ans+2;a=1;
			if(a!=1) c[r][s]=k;
		}
		if(r==m&&s==m&&aans>ans&&ans!=-1){
			aans=ans;
		} 
		if(r<m||s<m){
			if(c[r][s]!=-2) k=c[r][s];int k1=c[r][s];
		if(c[r+1][s]>=0||c[r][s+1]>=0){
			
			if(c[r+1][s]>=0){
				c[r][s]=-2;ki=c[r+1][s];ansi=ans;road(r+1,s);ans=ansi;c[r+1][s]=ki;
			}
			if(c[r][s+1]>=0){
			c[r][s]=-2;ki=c[r][s+1];ansi=ans;road(r,s+1);ans=ansi;c[r][s+1]=ki;
			}
			c[r][s]=-2;
		}
		else if(c[r-1][s]>=0||c[r][s-1]>=0){
		
			if(c[r-1][s]>=0){
				c[r][s]=-2;ki=c[r-1][s];ansi=ans;road(r-1,s);ans=ansi;c[r-1][s]=ki;
			}
			if(c[r][s-1]>=0){
					c[r][s]=-2;ki=c[r][s-1];ansi=ans;road(r,s-1);ans=ansi;c[r][s-1]=ki;
			}
			c[r][s]=-2;
		}
		else if(c[r+1][s]==-1||c[r][s+1]==-1){
			
			if(c[r+1][s]==-1){
			c[r][s]=-2;ki=c[r+1][s];ansi=ans;road(r+1,s);ans=ansi;c[r+1][s]=ki;
			}
			if(c[r][s+1]==-1){
		c[r][s]=-2;ki=c[r][s+1];ansi=ans;road(r,s+1);c[r][s+1]=ki;
			}
			c[r][s]=-2;ans=ansi;
		}
		else ans=-1;
		}
	}

int main(){
	ifstream fin("chess.in");
	fin>>m>>n;
	for(i=1;i<=100;i++)
	for(j=1;j<=100;j++) c[i][j]=-3;
	for(i=1;i<=m;i++)
	for(j=1;j<=m;j++) c[i][j]=-1;
	for(i=0;i<n;i++){
		int x,y;
		fin>>x>>y;
		fin>>c[x][y];
	}
	k=c[1][1];
	road(1,2);road(2,1);
	ofstream fout("chess.out");
	if(aans==401) fout<<-1;
	else fout<<aans+1;
}
