#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n,q,l,x;
bool flag;
int a[1005];
int f[105]={0,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=q;++i){
		scanf("%d%d",&l,&x);
		flag=0;
		for(int j=1;j<=n;++j){
			if(a[j]%f[l]==x){
				printf("%d\n",a[j]);
				flag=1;
				break;
			}
		}
		if(!flag) puts("-1");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
