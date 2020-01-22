#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<ctime>
#include<algorithm>
#include<vector>
#include<queue>
#define ll long long
#define inf 1ll<<60
ll read()
{
	ll tmp=0; char c=getchar(),f=1;
	while(c<'0'||'9'<c){if(c=='-')f=-1; c=getchar();}
	while('0'<=c&&c<='9'){tmp=tmp*10+c-'0'; c=getchar();}
	return tmp*f;
}
using namespace std;
int n,d,k;
int x[500010],s[500010];
int main()
{
	freopen("jump.in","r",stdin); freopen("jump.ans","w",stdout);
	int i,j;
	n=read(); d=read(); k=read();
	for(i=1;i<=n;i++)x[i]=read(),s[i]=read();
	int ans=1<<30;
	for(i=1;i<1<<n;i++){
		int sum=0,last=0,mx=-1<<30,mn=1<<30;
		for(j=0;j<n;j++)if(i&(1<<j))sum+=s[j+1],mx=max(mx,x[j+1]-last),mn=min(mn,x[j+1]-last),last=x[j+1];
		if(sum>=k)ans=min(ans,max(abs(mx-d),abs(mn-d)));
	}
	if(ans<1<<30)printf("%d",ans);else printf("-1\n");
	fclose(stdin); fclose(stdout);
	return 0; 
}
