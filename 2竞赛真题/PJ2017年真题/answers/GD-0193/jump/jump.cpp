#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
using namespace std;

int n,d,k,s[500010],w[500010];

void work1()
{
	int inf=21474836;
	int ans=inf;
	for (int i=1; i<(1<<n); i++)
	  {
	  	int zs=0,t=0;
	  	int tM=0,tm=inf;
	  	for (int j=0; j<n; j++)
	  	  {
	  	  	int x=(1<<j);
	  	  	if ((i&x)>=1) {zs+=w[j+1]; tM=max(s[j+1]-t,tM); tm=min(s[j+1]-t,tm); t=s[j+1]; }
	  	  }
	  	if (zs<k) continue;
	  	ans=min(max(abs(d-tM),abs(d-tm)),ans);
	  }
	if (ans==inf) cout<<-1; else cout<<ans;
}

void work2()
{
	int L=0,R=n+1;
	while (L+1!=R)
	  {
	  	int mid=(L+R)/2;
	  	int m=0,cnt=0,zs=0,flag=0;
	  	for (int i=1; i<=n; i++)
	  	  {
	  	  	cnt++;
	  	  	if (w[i]>m) {flag=i; m=w[i];} 
	  	  	if (cnt==mid) {i=flag; zs+=m; cnt=0; m=0; continue;}
	  	  }
	  	if (zs>=k) R=mid; else L=mid;	  	
	  }
	cout<<R;
}

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);

	scanf("%d%d%d",&n,&d,&k);
	
	for (int i=1; i<=n; i++)
	  scanf("%d%d",&s[i],&w[i]);
	
	if (n<=20) {work1(); return 0;}
	
	if (n>20||d==1) {work2(); return 0;}
	
	cout<<-1;

	return 0;
}

