#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int m,n,a[301][301]={0},i,b,c,d,j=1,u=0,jb=0,y=0,p=0;
	cin>>m>>n;
	for(i=1;i<=n;i++){
		cin>>b>>c>>d;
		a[b][c]=d+1;
	}
	for(i=1;i<=m-1;i++){
		for(j=j;j<=m-1;j++){
			if(y==1) jb+=1;
			if(y==1) p=a[i][j];
			y=0;
			if(a[i+1][j]==0&&a[i][j+1]==0){
				if(a[i+1][j+1]!=0){
					i++;
					jb+=2;
					continue;
				}
				else{
					u=1;
					break;
				}
			}
			else if(a[i+1][j]!=0){
				if(a[i+1][j]!=p) y=1;
				break;
			} 
			else if(a[i][j+1]!=0){
				if(a[i][j+1]!=p) y=1;
				continue;
			}
		}
		if(u==1) break;
	}
	if(u==1) cout<<-1;
	else cout<<jb;
	fclose(stdin);
	fclose(stdout);
}

