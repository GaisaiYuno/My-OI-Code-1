#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int a[105][105];
	int m,n;
	int s,b,c;
	cin>>m>>n;
	for (int i=1;i<=m;i++)
	  for (int j=1;j<=m;j++)
	    a[i][j]=3;
	for (int i=1;i<=n;i++){
		cin>>s>>b>>c;
		a[s][b]=c;
	}
	int z=1,x=1;
	int ans=0;
	int v=0;
	while(z!=m&&x!=m){
		if (a[z+1][x]==a[z][x]&&a[z+1][x]!=3&&z+1<=m) {
			z+=1;
			v=0;
		}
		else if (a[z][x+1]==a[z][x]&&a[z][x+1]!=3&&x+1<=m) {
			x+=1;
			v=0;
		}
		else if (a[z+1][x]!=a[z][x]&&a[z+1][x]!=3&&z+1<=m) {
			z+=1;
			v=0;
			ans++;
		}
		else if (a[z][x+1]!=a[z][x]&&a[z][x+1]!=3&&x+1<=m) {
			x+=1;
			v=0;
			ans++;
		}
		else {
		if (z+1<=m&&v==0){
			a[z+1][x]==a[z][x];
		  v=1;
		  z+=1;
		  ans+=2;
		}
		else{
		if (v==0){
			a[z][x+1]==a[z][x];
		  v=1;
		  x+=1;
		  ans+=2;
	}
		
		else {
			cout<<-1;
			return 0;
		}
	}
	}
	}
	cout<<ans<<endl;
	return 0;
}
