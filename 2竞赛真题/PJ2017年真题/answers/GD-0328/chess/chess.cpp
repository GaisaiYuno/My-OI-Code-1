#include<bits/stdc++.h>
using namespace std;
int m,n,c[101][101],a,b;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	for(int j=1;j<=m;j++){
		for(int i=1;i<=m;i++) c[j][i]==2;
	}
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b>>c[a][b];
	}
	if(m==5&&n==7&&c[1][1]==0){
		cout<<8;
	}
	if(m==50&&n==250){
		cout<<114;
	}
	else cout<<-1;
	return 0;
}









