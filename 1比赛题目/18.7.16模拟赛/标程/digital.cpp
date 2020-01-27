#include<iostream>
#include<cstdio>
using namespace std;
int k,n,bx,hx,ans[201];
int c[512][512][100];
void plus1(int x[],int y[],int z[]) {
	z[0]=max(x[0],y[0]);
	for(int i=1; i<=z[0]; i++) {
		z[i]+=x[i]+y[i];
		z[i+1]+=z[i]/10;
		z[i]%=10;
	}
	if(z[z[0]+1]!=0)z[0]++;
}
void plus2(int x[],int y[]) {
	x[0]=max(x[0],y[0]);
	for(int i=1; i<=x[0]; i++) {
		x[i]+=y[i];
		x[i+1]+=x[i]/10;
		x[i]%=10;
	}
	if(x[x[0]+1]!=0)x[0]++;
}
int main() {
	freopen("digital.in","r",stdin);
	freopen("digital.out","w",stdout);
	cin>>k>>n;
	bx=1<<k;//2^k
	hx=1<<(n%k);
	for(int i=0; i<=bx; i++)
		for(int j=0; j<=i; j++) {
			if(j==0)c[i][j][0]=c[i][j][1]=1;
			else plus1(c[i-1][j],c[i-1][j-1],c[i][j]);
		}
	for(int i=2; i<=n/k&&i<bx; i++)plus2(ans,c[bx-1][i]);
	for(int i=1; i<hx&&n/k+i<bx; i++)plus2(ans,c[bx-i-1][n/k]);
	for(int i=ans[0]; i>=1; i--)cout<<ans[i];
	cout<<endl;
	return 0;
}
