#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <cassert>
#define MAXN 1000005
#define MAXM 2000020
using namespace std;
int x[MAXN];
int L[MAXN],R[MAXN];
pair<int,int>P[MAXN];
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
inline int Abs(int x){
	return x>0?x:-x;
}
int cnt[MAXM];
int sum[MAXM]; 
int main(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int minx=0x7fffffff;
	int lower=0x7fffffff,upper=-0x7fffffff;
	for (register int i=1;i<=n;++i){
		x[i]=read();
		//lower=min(x[i],lower);
		//upper=max(x[i],upper);
	}
	int minl=0x7fffffff,maxl=-0x7fffffff;
	for (register int i=1;i<=m;++i){
		L[i]=read(),R[i]=read();
//		minl=min(minl,l),minl=min(minl,r);
//		maxl=max(maxl,l),maxl,max(maxl,r);
//		cnt[l+MAXN]++,cnt[r+1+MAXN]--;
	}
//	for (regi/*ster int i=-MAXN;i<=MAXN;++i){
//		sum[i+MAXN]=sum[i-1+MAXN]+cnt[i+MAXN];
//	}
//	for (register int i=-MAXN;i<=MAXN;++i){
//		sum[i+MAXN]=sum[i+MAXN]>0?1:0;
//	}*/
	int maxans=-0x7fffffff;
	int dis=0x7fffffff;
	for (register int delta=-2000;delta<=2000;++delta){
		register int ans=0;
		for (register int i=1;i<=n;++i){
			bool check=false;
			int t=x[i]+delta;
			for (register int j=1;j<=m;++j){
				if (L[j]<=t&&t<=R[j]){
					check=true;
					break;
				}
			}
			ans+=check;
//			if (sum[x[i]+delta+MAXN]){
//				ans++;
//			}
		}
		if (maxans<ans||(maxans==ans&&Abs(delta)<dis)){
			maxans=ans;
			dis=Abs(delta);
		}
	}
	//printf("\n");
	printf("%d %d\n",dis,maxans);
}
