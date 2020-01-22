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
struct data{
	int x,s;
}a[500010];
bool cmp(data a,data b){return a.x<b.x;}
int main()
{
	freopen("jump.in","w",stdout);
	int i;
	srand(time(0));
	int n=10,d=10,k=10;
	for(i=1;i<=n;i++)a[i].x=rand()%100+1,a[i].s=rand()%21-10;
	sort(a+1,a+n+1,cmp);
	printf("%d %d %d\n",n,d,k);
	for(i=1;i<=n;i++)printf("%d %d\n",a[i].x,a[i].s);
	fclose(stdout);
	return 0;
}
