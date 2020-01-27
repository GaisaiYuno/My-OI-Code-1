#include<iostream>
#include<cstring>
#define maxn 100000
int t,n,ans;
int a[maxn],f[maxn];
using namespace std;
int main(){
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n;
	    for(int i=1;i<=n;i++) cin>>a[i];
	    ans=0;
		memset(f,-9999,sizeof(f));
	    for(int j=1;j<=n;j++){
	    	f[j]=a[j];
	    	f[j]=max(f[j-1]+a[j],f[j]);
	    	ans=max(ans,f[j]);
		}
	    printf("Case #%d:\n",k);
	    cout<<ans<<endl;
	}
} 
/*状态转移方程
   f[j]表示第j个位置上最大的和 
   f[j]=max(f[j-1]+a[j],f[j])
*/
