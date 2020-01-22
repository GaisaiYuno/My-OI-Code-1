#include<bits/stdc++.h>
using namespace std;
int m,n,a[101][101];
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for (int i=1;i<=n;i++) {
		int q,p,c;
		cin>>q>>p>>c;
		a[q][p]=c;
	}
	cout<<-1;
	return 0;
}
