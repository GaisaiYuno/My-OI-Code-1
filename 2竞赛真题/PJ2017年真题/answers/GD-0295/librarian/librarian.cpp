#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,b[1010],len[1010],a[1010];
bool check(int x,int y,int len){
	for(int i(1);i<=len;++i,x/=10,y/=10)
		if(x%10!=y%10)
			return false;
	return true;
}
int main(void)
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i(1);i<=n;++i)
		scanf("%d",&b[i]);
	sort(b+1,b+1+n);
	
	for(int i(1);i<=m;++i){
		scanf("%d%d",&len[i],&a[i]);
		bool tf(true);
		for(int k(1);k<=n;++k)
			if(check(a[i],b[k],len[i])){
				printf("%d\n",b[k]);
				tf=false;
				break;
			}
		if(tf)
			printf("-1\n");
	}
	return 0;
}
