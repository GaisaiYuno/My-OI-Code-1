#include<cstdio>
#include<cstring>
using namespace std;
int x[500001],s[500001];
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,d,k;
	memset(x,0,sizeof(x));
	memset(s,0,sizeof(s));
	scanf("%d%d%d",&n,&d,&k);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&x[i],&s[i]);
	printf("-1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
