#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

int n,q,x,y,a[1005];

int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&y,&x);
		int ans=0x7fffffff;
		int k=(int)pow(10,y);
		for(int j=1;j<=n;j++){
			if(a[j]%k==x)ans=min(ans,a[j]);
		}
		printf("%d\n",ans!=0x7fffffff?ans:-1);
	}
	return 0;
}
