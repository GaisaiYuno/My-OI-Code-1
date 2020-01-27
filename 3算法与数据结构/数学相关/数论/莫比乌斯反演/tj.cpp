#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<vector>
#include<queue>
#define re register int
#define rl register ll
using namespace std;
typedef long long ll;
int read() {
	re x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9') {
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') {
		x=10*x+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void write(int x) {
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
namespace I_Love {

const int Size=100005;
int tot,p[Size],prime[Size];
bool vis[Size];
void getp(int x) {
	//筛莫比乌斯函数
	p[1]=1;
	for(re i=2; i<=x; i++) {
		if(!vis[i]) {
			prime[++tot]=i;
			p[i]=-1;
		}
		for(re j=1; j<=tot && i*prime[j]<=x; j++) {
			vis[i*prime[j]]=true;
			if(i%prime[j]==0)	break;
			p[i*prime[j]]=-p[i];
		}
	}
}
void Fujibayashi_Ryou() {
	getp(100000);
	int T=read();
	for(re Case=1; Case<=T; Case++) {
		int a=read();
		int b=read();
		int c=read();
		int d=read();
		int k=read();
		if(!k) {
			printf("Case %d: 0\n",Case);
			continue;
		}
		//a=c=1,不用管 
		b/=k;
		d/=k;
		ll ans=0;
		int n=max(b,d);
		int m=min(b,d);
		for(re i=1; i<=m; i++) {
			ans+=(ll)p[i]*(n/i)*(m/i);
		}
		ll repeat=0;
		for(re i=1; i<=m; i++) {
			repeat+=(ll)p[i]*(m/i)*(m/i);
		}
		//repeat是出现了两次的数对的个数，所以要除以2 
		printf("Case %d: %lld\n",Case,ans-(repeat>>1ll));
	}
}

}
int main() {
	I_Love::Fujibayashi_Ryou();
	return 0;
}

