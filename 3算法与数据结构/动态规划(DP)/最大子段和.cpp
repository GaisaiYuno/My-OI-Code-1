//洛谷 最大子段和
#include<iostream>
#define maxn 200000
using namespace std;
int n,ans;
int a[maxn],f[maxn];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	f[1]=a[1];
	int tmp;
	for(int i=2;i<=n;i++){
		tmp=-99999999;
		tmp=max(tmp,f[i-1]+a[i]);
		tmp=max(tmp,a[i]);
		f[i]=tmp;
	}
	ans=-99999999;
	for(int i=1;i<=n;i++) ans=max(f[i],ans);
	cout<<ans; 
	return 0;
} 
/*f[i]=max(a[i],f[i-1]+a[i])
*/ 
