#include<cstdio>
#include<fstream>
#include<algorithm>
using namespace std;
unsigned long long n,q,a[110000],b[110000],c[110000];
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=q;i++){
		scanf("%d%d",&b[i],&c[i]);
		long long k=1;
		bool f=false;
		for (int j=1;j<=b[i];j++) k*=10;
		for (int j=1;j<=n;j++){
			if (a[j]%k==c[i]){
				printf("%lld\n",&a[j]);
				f=true;
				break;
			}
		}
		if (f==false) printf("-1\n");
	}
	return 0;
}
