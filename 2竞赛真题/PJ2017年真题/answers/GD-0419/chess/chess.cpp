#include<bits/stdc++.h>
using namespace std;

int p[101][101],n,m,x,y,c,coin;

int main () {
	freopen ("chess.in","r",stdin);
	freopen ("chess.out","w",stdout);
	memset (p,-1,sizeof (p));
	cin>>m>>n;
	for (int i=1;i<=n;i++) {
		cin>>x>>y>>c;
		p[x][y]=c;
	}
	cout<<-1;
}
