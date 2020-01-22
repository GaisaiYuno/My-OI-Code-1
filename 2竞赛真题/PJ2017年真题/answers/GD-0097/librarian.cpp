#include<bits/stdc++.h>
using namespace std;
int a[1100],n,q;
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=q;i++){
		int k=1,l,x;
		bool flag=0;
		scanf("%d%d",&l,&x);
		while(l){
			l--;
			k*=10;
		}
		for(int i=1;i<=n;i++){
			if(a[i]%k==x){
				printf("%d\n",a[i]);
				flag=1;
				break;
			}
		}
		if(!flag) printf("-1\n");
	}
}
