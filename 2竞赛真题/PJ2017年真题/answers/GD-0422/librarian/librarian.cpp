#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<ctime>
#include<algorithm>
#include<vector>
#include<queue>
#define ll long long
#define inf 1<<30
ll read()
{
	ll tmp=0; char c=getchar(),f=1;
	while(c<'0'||'9'<c){if(c=='-')f=-1; c=getchar();}
	while('0'<=c&&c<='9'){tmp=tmp*10+c-'0'; c=getchar();}
	return tmp*f;
}
using namespace std;
int id[1010];
int n,m;
bool check(int id,int x)
{
	while(id>0&&x>0){
		if(id%10!=x%10)break;
		id/=10; x/=10;
	}
	if(x>0)return 0;else return 1;
}
int main()
{
	freopen("librarian.in","r",stdin); freopen("librarian.out","w",stdout);
	int i,j;
	n=read(); m=read();
	for(i=1;i<=n;i++)id[i]=read();
	for(i=1;i<=m;i++){
		int tmp=read(),x=read(),ans=inf;
		for(j=1;j<=n;j++)if(check(id[j],x))ans=min(ans,id[j]);
		if(ans<inf)printf("%d\n",ans);else printf("-1\n");
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
