#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <stack>
#define max(a,b) a>b?a:b
#define MAXN 300005
using namespace std;
int A[MAXN];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int n,m,type;
	scanf("%d%d%d",&n,&m,&type);
	for (register int i=1;i<=n;++i){
		A[i]=read();
	}
	int lst=0;
	while (m--){
		int l=read(),r=read();
		if (type==1){
			int u=(l+lst-1)%(n+1),v=(r+lst-1)%(n+1);
			l=min(u,v),r=max(u,v);
		}
		if (l==r){
			puts("0");
			continue;
		}
		int ans=r-l;
		for (register int i=l;i<=r-2;++i){
			int rcnt=i+2;
			int maxn=A[i+1];
			while (rcnt<=r){
				if (maxn<min(A[i],A[rcnt])){
					++ans;
				}
				if (A[rcnt]>A[i]){
					break;
				}
				maxn=max(maxn,A[rcnt]);
				++rcnt;
			}
		}
		lst=ans;
		printf("%d\n",ans);
	}
}
