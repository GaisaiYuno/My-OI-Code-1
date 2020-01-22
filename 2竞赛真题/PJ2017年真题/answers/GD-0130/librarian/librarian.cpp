#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
int n,q,l,x,p,ans;
int num[1001];
bool can;
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
		scanf("%d",num+i);
	for(int i=1;i<=q;++i){
		scanf("%d%d",&l,&x);
		p=1;ans=0x7fffffff;can=false;
		for(int j=1;j<=l;++j)
			p*=10;
		for(int j=1;j<=n;++j){
			if(num[j]%p==x){
				can=true;
				ans=min(ans,num[j]);
			}
		}
		printf("%d\n",can?ans:-1);
	}
	return 0;
}
