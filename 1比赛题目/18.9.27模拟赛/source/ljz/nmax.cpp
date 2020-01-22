#include<iostream>
#include<cstdio>
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
	const int N=500500;
	int Q,last=-1;
	int top;
	int a[N],sum[N];
	inline void solve(){
		read(Q);
		while(Q--){
			int op,x;
			read(op);
			if(op==1){
				read(x);
				if(x==last)continue;
				a[++top]=x,last=x;
				sum[top]=sum[top-1]+x;
			}else{
				double mean=0;
				if(top==1){
					mean=a[top];
				}else if(top==2){
					mean=((double)a[top]+(double)a[1])/2;
				}else{
					int l=1,r=top-1,mid,ans;
					while(l<=r){
						mid=(l+r+1)>>1;
						if(((double)sum[mid]+(double)a[top])/(double)(mid+1)>(double)a[mid+1])l=mid+1,ans=l;
						else r=mid-1;
					}
					mean=((double)sum[ans]+(double)a[top])/(double)(ans+1);	
				}
				printf("%.10lf\n",(double)a[top]-mean);
			}
		}
	}
}
using namespace Solve;
int main(){
	freopen("nmax.in","r",stdin);
	freopen("nmax.out","w",stdout);
	solve();
}
