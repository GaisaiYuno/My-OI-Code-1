//mine
#include<iostream>
#include<cstdio>
#define maxn 105
using namespace std;
char a[maxn][maxn];
int b[maxn][maxn];
int xx[8]= {0,0,1,-1,1,1,-1,-1};
int yy[8]= {1,-1,0,0,1,-1,1,-1};
int n,m;
int main() {
	freopen("mine.in","r",stdin);
	freopen("mine.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) cin>>a[i][j];
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(a[i][j]=='*') b[i][j]=-1;
			else {
				for(int k=0; k<8; k++) {
					if(a[i+xx[k]][j+yy[k]]=='*') b[i][j]++;
				}
			}
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(b[i][j]==-1) cout<<'*';
			else cout<<b[i][j];
		}
		cout<<endl;
	}
}
