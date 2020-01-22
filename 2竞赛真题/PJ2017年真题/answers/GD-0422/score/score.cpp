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
int main()
{
	freopen("score.in","r",stdin); freopen("score.out","w",stdout);
	int a=read(),b=read(),c=read();
	double ans=a*0.2+b*0.3+c*0.5;
	printf("%d",(int)ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
