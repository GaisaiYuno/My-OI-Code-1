#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int n,q,a[1001],l[1001],x[1001],p,m=1;
bool flg;

int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=q;++i){
		scanf("%d%d",&l[i],&x[i]);
		flg=true;
		p=0;
		m=1;
		while(p<l[i]){
			++p;
			m*=10;
		}
		for(int j=1;j<=n;++j)if(a[j]%m==x[i]){
			printf("%d\n",a[j]);
			flg=false;
			break;
		}
		if(flg)puts("-1");
	}
}
