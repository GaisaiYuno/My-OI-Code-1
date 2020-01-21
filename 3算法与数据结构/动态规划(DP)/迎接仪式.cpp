//洛谷 迎接仪式
#include<iostream>
#include<cstring>
#define maxn 505
using namespace std;
char s[maxn];
int f[maxn][101][101];//f[i][j][k]表示前i个字符，改变了j个j和k个z'的jz串数。
int n,m,ans=0;
int main() {
	cin>>n>>m;
	for(int u=1; u<=n; u++) cin>>s[u];
	 memset(f,~0x3f,sizeof(f));
	f[0][0][0]=f[1][0][0]=0;
	if(s[1]=='z') f[1][0][1]=0;
	else f[1][1][0]=0;
	for(int i=2; i<=n; i++) {
		for(int j=0; j<=m; j++) {
			for(int k=0; k<=m; k++) {
				f[i][j][k]=f[i-1][j][k];			
				if(s[i]=='z' && s[i-1]=='j') f[i][j][k]=max(f[i][j][k],f[i-2][j][k]+1);
				if(s[i]=='z' && s[i-1]=='z' && k) f[i][j][k]=max(f[i][j][k],f[i-2][j][k-1]+1);
				if(s[i]=='j' && s[i-1]=='j' && j) f[i][j][k]=max(f[i][j][k],f[i-2][j-1][k]+1);
				if(s[i]=='j' && s[i-1]=='z' && j && k) f[i][j][k]=max(f[i][j][k],f[i-2][j-1][k-1]+1);
				if(j==k) ans=max(ans,f[i][j][k]);

			}
		}
	}
    cout<<ans;
	return 0;
}
