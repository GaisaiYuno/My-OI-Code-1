#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 1000001
using namespace std;
int n;
int a[maxn],f[maxn][4][2];
int comp(int p,int q) {
	return p>q;
}
int main() {
	freopen("jx.in","r",stdin);
	freopen("jx.out","w",stdout);
	bool flag=true;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		if(a[i]>=0) flag=false;
	}
	if(flag){//特判 全为负数
		sort(a+1,a+1+n,comp);
		cout<<a[1]+a[2]+a[3];
		return 0;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=3; j++) {
			f[i][j][1]=max(f[i-1][j][1],f[i-1][j][0]);
			f[i][j][0]=max(f[i][j][0],f[i-1][j-1][1]+a[i]);
			f[i][j][0]=max(f[i][j][0],f[i-1][j][0]+a[i]);
		}
	}
	cout<<max(f[n][3][0],f[n][3][1]);
	return 0;
}
/*递推公式
f[i][j][0]前i个，第j段，第i个取到
f[i][j][1] 前i个，第j段，第i个没取到
f[i][j][1]=max(f[i-1][j][1],f[i-1][j][0]);
f[i][j][0]=max(f[i][j][0],f[i-1][j-1][1]+a[i]);
f[i][j][0]=max(f[i][j][0],f[i-1][j][0]+a[i]);
*/
