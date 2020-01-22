#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
namespace StandardIO{
	template<typename T>inline void read(T &x){
		x=0;T f=1;char c=getchar();
		for(;c<'0'||c>'9';c=getchar())if(c=='-')f=-1;
		for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
		x*=f;
	}
	template<typename T>inline void write(T x){
		if(x<0)putchar('-'),x*=-1;
		if(x>=10)write(x/10);
		putchar(x%10+'0');
	}
}
using namespace StandardIO;
namespace Solve{
	const int N=200200;
	int n,ans;
	int a[N];
	inline void task1(){
		for(register int i=n;i>0;--i){
			if(a[i]<ans)break;
			for(register int j=n;j>i;--j){
				ans=max(ans,a[j]%a[i]);
				if(ans==a[i]-1)break;
			}
		}
		write(ans);
	}
	inline void task2(){
		for(register int i=1;i<n;++i){
//			int k=(a[n]/a[1]+1)/2;
			for(register int k=2;k<=(a[n]/a[i])+1;++k){
				int l=i+1,r=n,mid;
				while(l<=r){
					mid=(l+r+1)>>1;
					if(a[mid]<k*i)l=mid+1,ans=l;
					else r=mid-1;
				}
				ans=max(ans,a[l]%a[i]);
			}
		}
		write(ans);
	}
	inline void solve(){
		read(n);
		for(register int i=1;i<=n;++i){
			read(a[i]);
		}
		sort(a+1,a+n+1);
		if(n>2020)task2();
		else task1();
	}
}
using namespace Solve;
int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	solve();
}
