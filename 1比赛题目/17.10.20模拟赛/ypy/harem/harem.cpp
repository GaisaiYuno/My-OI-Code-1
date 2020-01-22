#include<iostream>
#include<cstdio>
#define maxn 2000
#define mod 1000000007
using namespace std;
int n,m;
int num[maxn];
int f[maxn][maxn][2];
int main() {
	freopen("harem.in","r",stdin);
	freopen("harem.out","w",stdout);
	char t;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin>>t;
			if(t=='0') {
				num[i]++;
				num[j]++;
			}
		}
	}
	f[1][1][0]=1;
	f[1][1][1]=1;
	for(int i=2; i<=n; i++) {
		for(int j=2; j<=m; j++) {
			f[i][j][0]=(f[i-1][j][0]+f[i-1][j-1][0]*num[j-1]+f[i-1][j][1]*m)%mod;
			f[i][j][1]=(f[i-1][j][1]+f[i-1][j][0]+f[i-1][j-1][0])%mod;
			//debug();
		}
	}
	//debug();
	cout<<max(f[n][m][0],f[n][m][1])%mod;
	return 0;
}
/*×´Ì¬×ªÒÆ·½³Ì

*/
