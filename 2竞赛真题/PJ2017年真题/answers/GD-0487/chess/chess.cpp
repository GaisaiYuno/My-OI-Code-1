#include<iostream>
#include<cstdio>
using namespace std;
int a,b,c,d,MAX=1000000;
int ans[200][200]={0};
int whh[200][200]={0};
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=b;i++){
		int x,y,z;
		cin>>x>>y>>z;
		whh[x][y]=z+1;
	}
	for(int i=1;i<=a;i++)ans[0][i]=ans[i][0]=MAX;
	ans[0][1]=-1;
	ans[1][0]=-1;
	for(int i=1;i<=a;i++)
	for(int j=1;j<=a;j++){
		if(whh[i][j]>0){
			if(whh[i-1][j]>0&&whh[i-1][j]!=whh[i][j])
			ans[i][j]++;
			if(whh[i][j-1]>0&&whh[i][j-1]!=whh[i][j])
			ans[i][j]++;
			ans[i][j]+=min(ans[i-1][j],ans[i][j-1]);
			if(whh[i-1][j]==whh[i][j])
			ans[i][j]=ans[i-1][j];
			if(whh[i][j-1]=whh[i][j])
			ans[i][j]=ans[i][j-1];
		}
		if(whh[i][j]==0){
			if(whh[i-1][j]==whh[i][j-1]==0)ans[i][j]==MAX;
			int x,y;
			if(ans[i][j]!=MAX){
			    if(whh[i-1][j]>0&&whh[i][j-1]==0)ans[i][j]=ans[i-1][j]+2;
			    if(whh[i-1][j]==0&&whh[i][j-1]>0)ans[i][j]=ans[i][j-1]+2;
			}
		}
	}
	if(whh[a][a-1]!=whh[a][a]||whh[a-1][a]!=whh[a][a]){cout<<min(ans[a][a-1],ans[a-1][a])+1<<endl;return 0;}
	if(whh[a-1][a]==whh[a][a]){cout<<ans[a-1][a]<<endl;return 0;}
	if(whh[a][a-1]==whh[a][a]){cout<<ans[a][a-1]<<endl;return 0;}	
	cout<<-1<<endl;
	return 0;
}
