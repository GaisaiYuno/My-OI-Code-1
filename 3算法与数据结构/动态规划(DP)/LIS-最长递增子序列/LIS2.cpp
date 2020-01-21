#include<iostream>
#include<cstring>
#define maxn 10000
using namespace std;
int a[maxn],f[maxn];
int ans=0,n;
int main() {
	while(1) {
	    cin>>n;
	    if(n==0) break;
	    memset(f,0,sizeof(f));
	    memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++) cin>>a[i]; 
		ans=0;
		for(int i=1; i<=n+1; i++) { //i从1~n+1
			f[i]=a[i];
			for(int j=1; j<i; j++) {
				if(a[j]<a[i]) f[i]=max(f[i],a[i]+f[j]);
			}
			ans=max(ans,f[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*状态转移方程
   f[i]=max(f[j]+a[j],1),且a[j]<a[i]
*/
