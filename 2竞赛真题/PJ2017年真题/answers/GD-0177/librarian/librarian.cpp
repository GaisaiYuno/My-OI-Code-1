#include<cstdio>
#include<algorithm>
using namespace std;
int n,q,a[1010];
int quick_pow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)
			ans*=a;
		a*=a;
		b>>=1;
	}
	return ans;
}
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	while(q--){
		int m,b,p;
		scanf("%d%d",&m,&b);
		p=quick_pow(10,m);
		bool flag=1;
		for(int i=1;i<=n;i++)
			if(a[i]%p==b){
				printf("%d\n",a[i]);
				flag=0;
				break;
			}
		if(flag)
			puts("-1");
	}
}
