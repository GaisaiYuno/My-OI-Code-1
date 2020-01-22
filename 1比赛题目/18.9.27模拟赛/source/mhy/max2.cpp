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
	int n=read();
	int maxn=-0x7fffffff;
	for (int i=0;i<n;++i){
		a[i]=read();
		maxn=max(maxn,a[i]);
	}
	int ans=-0x7fffffff;
	sort(a,a+n);
	n=unique(a,a+n)-a;
	for (int j=0;j<n;++j){
		for (int k=1;k<(int)(maxn/a[j])+1;++k){
			int t=lower_bound(a+j+1,a+n,a[j]*k)-a-j-1;
			printf("%d\n",t);
			ans=max(ans,a[t]%a[j]);
		}
	}
	printf("%d\n",ans);
}
