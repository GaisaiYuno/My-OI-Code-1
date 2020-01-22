#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 200005
using namespace std;
inline int read(){
	char ch=getchar();
	int x=0;
	while (ch<='9'&&ch>='0'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}
int a[MAXN];
int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	int n=read();
	for (register int i=1;i<=n;++i){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	n=unique(a+1,a+1+n)-a-1;
	int ans=-0x7fffffff;
	for (register int i=n;i>=1;--i){
		if (a[i]<=ans){
			break;
		}
		int j=i;
		while(--j){
			if (j==0||a[j]<=ans){
				break;
			}
			ans=max(ans,a[i]%a[j]);
		}
	}
	printf("%d\n",ans);
}
